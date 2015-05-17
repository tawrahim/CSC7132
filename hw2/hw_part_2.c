#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

    void *f1();
    void *f2();

    int n;
    int m;
    pthread_mutex_t count_mutex     = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t  condition_var   = PTHREAD_COND_INITIALIZER;

    main()
    {
       pthread_t thread1, thread2;

       pthread_create( &thread1, NULL, &f1, NULL);
       pthread_create( &thread2, NULL, &f2, NULL);

       pthread_join( thread1, NULL);
       pthread_join( thread2, NULL);

       exit(0);
    }



    void *f1(void *arg)
    {
     int r;
     m = 5;

     // wait for  f2 to run
     pthread_mutex_lock( &count_mutex );
     pthread_cond_wait( &condition_var, &count_mutex );

     r = n + m;

     printf("f1 = %d\n", r);
     return NULL;
    }

    void *f2(void *arg)
    {
     int r;
     n = 2;
     r = m - n;
     printf("f2 = %d\n", r);

     // Signal  f1 to continue with its execution
     pthread_mutex_unlock( &count_mutex );
     pthread_cond_signal( &condition_var );

     return NULL;
    }
