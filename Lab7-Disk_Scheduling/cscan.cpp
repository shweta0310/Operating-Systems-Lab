#include<bits/stdc++.h>
using namespace std;
int head,size,prev,dir,end;
int req[100];
void getinput(){
	cout<<"Enter position of head: ";cin>>head;
	cout<<"Enter position of previous request: ";cin>>prev;
	cout<<"Enter tail track no.: ";cin>>end;
	if(head-prev>=0)
		dir=1; //right
	else 
		dir=0; //left
	cout<<"Enter size of request array: ";cin>>size;
	cout<<"Enter request array: ";
	for(int i=0;i<size;i++){
		cin>>req[i];
	}
}
int cscan(){
	int move=0,i,j;
	int head1=head;
	sort(req,req+size);
	if(dir==0){
		move+=req[0];
		for(i=0;req[i]<head;i++);
		i--;
		for(;i>=0;i--){
			if(req[i]!=-1){
				move+=(head1-req[i]);
				head1=req[i];
				req[i]=-1;
			}
		}
		head1=end;
		for(j=size-1;req[j]>head;j--){
			if(req[j]!=-1){
				move+=(head1-req[j]);
				head1=req[j];
				req[j]=-1;
			}			
		}
	}
	else if(dir==1){
		move+=(end-req[size-1]);
		//cout<<"move1 "<<move<<endl;
		for(i=0;req[i]<head;i++);
		for(;i<size;i++){
			if(req[i]!=-1){
				move+=(req[i]-head1);//cout<<"move1 "<<move<<endl;
				head1=req[i];
				req[i]=-1;
			}
		}
		//cout<<"head1 "<<head1<<endl;
		head1=0;
		//cout<<"head1 "<<head<<endl;
		/*for(int k=0;k<size;k++)
			cout<<req[k]<<" ";
		cout<<endl;*/
		for(j=0;req[j]<head && j<size;j++){
			if(req[j]!=-1){
				move+=(req[j]-head1);//cout<<"move1 "<<move<<endl;
				head1=req[j];
				req[j]=-1;
				//break;
			}
		}
	}
	return move;
}
int main(){
	getinput();
	cout<<"no. of movements= "<<cscan()<<endl;
	return 0;
}