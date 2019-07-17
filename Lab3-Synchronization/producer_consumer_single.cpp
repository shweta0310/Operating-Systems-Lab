#include<iostream>
#define SIZE 5
#include<semaphore.h>
using namespace std;
sem_t full;
sem_t empty;
int buff[SIZE];
int in;
int out;
void producer(int ele){

	sem_wait(&empty);
	buff[in]=ele;
	in=(in+1)%5;
	cout<<endl<<"Producer: "<<ele++;
	sem_post(&full);
	
}
void consumer(){

	sem_wait(&full);
	int item=buff[out];
	out=(out+1)%5;
	cout<<endl<<"Consumer: "<<item;
	sem_post(&empty);
	
}
int main(){
	sem_init(&full,0,0);
	sem_init(&empty,0,SIZE);
	producer(1);
	producer(5);
	producer(10);
	producer(2);
	consumer();
	consumer();
	consumer();
	producer(12);
	consumer();
	consumer();
	producer(13);
	consumer();
	return 0;
}
	

	
	
