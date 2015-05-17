 #include<stdio.h>
 #include<pthread.h>
 void *increment(void*);
 void *watch(void*);
 pthread_mutex_t  my_mutex;
 pthread_cond_t  w_cond;
 int count=0;
 main()
 { 
 pthread_t tid1, tid2, tid3;
 pthread_mutex_init (&my_mutex, NULL);
 pthread_cond_init(&w_cond, NULL);
 pthread_create(&tid1,NULL,watch, NULL); pthread_create(&tid2,NULL,increment, NULL); pthread_create(&tid3,NULL,increment, NULL);
 pthread_join(tid1,NULL);
 pthread_mutex_destroy(&my_mutex);
 pthread_cond_destroy(&w_cond);
 printf("Parent is DONE ....\n");
 exit(0);
 }      
 void* increment(void *dummy)
 { 
 while(count<10)
 { 
 pthread_mutex_lock(&my_mutex);
 printf("Count =%d by thread %d\n",++count,pthread_self());
 if(count==10) pthread_cond_signal(&w_cond); pthread_mutex_unlock(&my_mutex);
 sleep(1);
 }
 return;
 }   
   void* watch(void *dummy)
   { 
   pthread_mutex_lock(&my_mutex);
   pthread_cond_wait(&w_cond,&my_mutex); pthread_mutex_unlock(&my_mutex);
   printf("Watch is DONE...\n");
   return;
   }                      
 