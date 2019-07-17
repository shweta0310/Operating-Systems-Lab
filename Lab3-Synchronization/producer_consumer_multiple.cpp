#include<iostream>
#define SIZE 5
#include<semaphore.h>
using namespace std;
sem_t full;
sem_t empty;
int buff[SIZE];
int in;
int out;
pthread_mutex_t mutex;   
int data;
void* producer(void *arg){

	int ele=(long)arg;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	buff[in]=data;
	in=(in+1)%5;
	cout<<endl<<ele<<" Producer produces: "<<data++;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	
}
void* consumer(void *arg){

	int index=(long)arg;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	int item=buff[out];
	out=(out+1)%5;
	cout<<endl<<index<<" Consumer consumes: "<<item;
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	
}
int main(){
	pthread_t prod,cons;
	int index;
	sem_init(&full,0,0);
	sem_init(&empty,0,SIZE);
	for (index = 0; index < 5; index++)
    {
        /* Create a new producer */
        pthread_create(&prod, NULL, producer, (void*)index);
    }
    /*create a new Consumer*/
    for(index=0; index<5; index++)
    {
        pthread_create(&cons, NULL, consumer, (void*)index);
    }
    pthread_exit(NULL);
	return 0;
}
	

	
	
