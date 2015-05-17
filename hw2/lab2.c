  /* Code for mutex-hellothread.c */ 
  #include <pthread.h>
  #include <stdio.h> 
  /* Function run when the thread is created */
  void* compute_thread (void*);
  /* This is the lock for thread synchronization */
  pthread_mutex_t    my_sync;
  main( )
  {
  /* This is data describing the thread created */
  pthread_t   tid;
  pthread_attr_t   attr;
  char hello[ ] = {"Hello, "};
  char thread[ ] = {"thread"};
  /* Initialize the thread attributes */
  pthread_attr_init (&attr);
  /* Initialize the mutex (default attributes) */
  pthread_mutex_init (&my_sync,NULL);
  /* Create another thread. ID is returned in &tid */
  /* The last parameter is passed to the thread function */
  /* Note reversed the order of "hello" and "thread" */  pthread_create(&tid, &attr, compute_thread, hello);
  sleep(1);
  /* Let the thread get started */ 
  /* Lock the mutex when it's our turn to do work */ pthread_mutex_lock(&my_sync);
  printf(thread);
  printf("\n");
  pthread_mutex_unlock(&my_sync);
  exit(0);  
  }
  /* The thread function to be run */
  void* compute_thread(void* dummy)
  {  
  /* Lock the mutex when its our turn */
  pthread_mutex_lock(&my_sync);
  printf(dummy);
  pthread_mutex_unlock(&my_sync);
  sleep(1);
  return;
  }  