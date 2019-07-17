#include<iostream>
#include<semaphore.h>
using namespace std;
sem_t write;
sem_t read;

void writer(int ele){
	sem_wait(&write);
	cout<<endl<<"Writer writing: "<<ele;
	sem_post(&read);
}

void reader(){
	sem_wait(&read);
	cout<<endl<<"Reader reading: ";
	sem_post(&write);
}
int main(){
	sem_init(&write,0,1);
	sem_init(&read,0,1);
	writer(2);
	reader();
	reader();
	writer(45);
	reader();
	return 0;
}

