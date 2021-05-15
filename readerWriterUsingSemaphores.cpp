//NOTE : THIS PROGRAM WILL RUN ONLY ON 32-BIT DEBUG MODE

#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#ifdef _WIN32  				//for Sleep function
#include<Windows.h>
#else
#include <unistd.h>
#endif


//sem_t is a typedef defined in a headerFile .we use it to create a semaphore.
sem_t mutex,writeblock;

int data = 0,rcount = 0;

void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex); //on success the return value is 0,and on failure,the return value is -1(and the value of the semaphore
  //is unchanged) for eg let value is 1 so it will return 1-1 = 0 
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&writeblock); //after this function call , value of writeblock will reduced to 1.
  sem_post(&mutex);
  printf("Data read by the reader %d is %d\n",f,data);
  
  Sleep(1);
  
  sem_wait(&mutex);
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg); //at starting f=1
  sem_wait(&writeblock);  //after this function call , value of writeblock will reduced to 1.
  data++; // from 0 to 1 increase
  printf("Data written by the writter%d is %d\n",f,data);
  Sleep(1);
  sem_post(&writeblock);
}

int main()
{
  int i,b; 
  //declaring array of thread
  pthread_t rtid[5],wtid[5];//read thread id      //write thread id 

  //sem_init initialize the semaphore
  
  //sem_init(sem_t* sem,int,int pshared,unsigned int value)
  sem_init(&mutex,0,1);// if 0=pshared means semaphore is shared among all the process  and 3rd argument is the value of mutex
  sem_init(&writeblock,0,1);
  
  for(i=0;i<=2;i++)
  {
  	//pythread_create function starts a new thread in the calling process.the new thread start executing by
  	// invoking start_routine(); here start_routine() is writer()
  	
  	//pthread_create(pthread_t *thread,const pthread_attr_t *attr,void *(start_routine)(void *),void *arg);
  		//&wtid[i] is the address of a thread 
  		//writer is a function which take void * in parameter and return void *
  		//and i is int type of value so we have to type cast it into void *
    pthread_create(&wtid[i],NULL,writer,(void *)i); //creating writter thread
    pthread_create(&rtid[i],NULL,reader,(void *)i);	//creating reader thread
  }
  
  //joining of thread-joining a thread means that one waits for the other to end,so that you can safely access its result
  //or continue after both have finished their jobs.
  for(i=0;i<=2;i++)
  {
  	//pthread_join() waits for the thread to terminate.if that thread has already terminated,then pthread_join()
  	//return immediately.after termination it joins other threads.
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  return 0;
}
