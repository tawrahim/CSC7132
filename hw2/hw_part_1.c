#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

    pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

    void *printHello();
    void *printWorld();

    int  count = 0;
    #define COUNT_DONE  19

    main()
    {
       pthread_t thread1, thread2;

       pthread_create( &thread1, NULL, &printHello, NULL);
       pthread_create( &thread2, NULL, &printWorld, NULL);

       pthread_join( thread1, NULL);
       pthread_join( thread2, NULL);

       exit(0);
    }

    // Print hello
    void *printHello()
    {
       for(;;)
       {

          // Lock mutex and then wait for signal to relase mutex
          pthread_mutex_lock( &count_mutex );

          if (count % 2 != 0) {
              pthread_cond_wait( &condition_var, &count_mutex );
          }

          count++;
           printf("HELLO \n");
           pthread_cond_signal( &condition_var );

          if(count >= COUNT_DONE) {
             pthread_mutex_unlock( &count_mutex );
             return(NULL);
          }
          pthread_mutex_unlock( &count_mutex );
        }
    }


    // print world
    void *printWorld()
    {
       for(;;)
       {

          // Lock mutex and then wait for signal to relase mutex
          pthread_mutex_lock( &count_mutex );

          if (count % 2 == 0) {
              pthread_cond_wait( &condition_var, &count_mutex );
          }

          count++;
          printf("WORLD \n");

          pthread_cond_signal( &condition_var );

          if(count >= COUNT_DONE) {
             pthread_mutex_unlock( &count_mutex );
             return(NULL);
          }
          pthread_mutex_unlock( &count_mutex );
        }
    }
