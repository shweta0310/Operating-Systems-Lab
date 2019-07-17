#include<bits/stdc++.h>
using namespace std;
int head,size;
int req[100];
void getinput(){
	cout<<"Enter position of head: ";cin>>head;
	cout<<"Enter size of request array: ";cin>>size;
	cout<<"Enter request array: ";
	for(int i=0;i<size;i++){
		cin>>req[i];
	}
}
int find_nearest_track(int val){
	int min=INT_MAX,ans;
	for(int i=0;i<size;i++){
		if(req[i]!=-1){
			int temp=abs(val-req[i]);
			if(temp<min){
				min=temp;
				ans=i;
			}
		}
	}
	return ans;
}
int find_movements(){
	int move=0;
	for(int i=0;i<size;i++){
		int index=find_nearest_track(head);
		move+=abs(head-req[index]);
		head=req[index];
		req[index]=-1;
	}
	return move;
}
int main(){
	getinput();
	cout<<"No. of movements= "<<find_movements()<<endl;
	return 0;
}