#include<bits/stdc++.h>
using namespace std;
const int p=5,r=3;
void cal_need(int need[][r],int max[][r],int alloc[][r]){
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	/*cout<<endl;
	for(int i=0;i<p;i++){
		cout<<endl;
		for(int j=0;j<r;j++){
			cout<<need[i][j];
		}
	}*/
}
bool safe(int avail[r],int max[][r],int alloc[][r],int need[][r],int ch){
	//int need[p][r];
	if(ch=1)
	cal_need(need,max,alloc);
	int work[r];
	for(int i=0;i<r;i++)
	work[i]=avail[i];
	
	bool finish[p];
	int safeseq[p],j;
	for(int i=0;i<p;i++)
	finish[i]=false;
	int c=0;
	while(c<p){
		bool temp=true;
		for(int i=0;i<p;i++){
			if(finish[i]==false){
				for(j=0;j<r;j++){
					if(need[i][j]>work[j])
					{//cout<<"sugi "<<i<<j<<r<<endl;
					break;}
				}
				if(j==r){
					for(int l=0;l<r;l++){
						work[l]+=alloc[i][l];
					}
					//cout<<"hsadiuja"<<endl;
					safeseq[c++]=i;
					finish[i]=true;
					temp=false;
				}
			}
		}
		if(temp==true){
			cout<<"System not in safe state"<<endl;
			return false;
		}
	}
	cout<<"System is in safe state \nSafe Sequence"<<endl;
	for(int i=0;i<c;i++)
	cout<<safeseq[i]<<"\t";
	return true;
}
void enter(int avail[r],int max[][r],int alloc[][r]){
	cout<<"Enter resources available: "<<endl;
	for(int i=0;i<r;i++)
	cin>>avail[i];
	cout<<"\nEnter Maximum matrix: "<<endl;
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cin>>max[i][j];
		}
		for(int j=r;j<10;j++)
		max[i][j]=0;
	}
	/*cout<<endl;
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cout<<max[i][j];
		}
	}*/
	cout<<"\nEnter Allocation Matrix: "<<endl;
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cin>>alloc[i][j];
		}
	}
	/*cout<<endl;
	for(int i=0;i<p;i++){
		for(int j=0;j<r;j++){
			cout<<alloc[i][j];
		}
	}*/
}
int main(){
	//cout<<"Enter no. of processes: ";cin>>p;
	//cout<<"\nEnter no. of resorces: ";cin>>r;
	int avail[r],max[p][r],alloc[p][r],need[p][r];
	enter(avail,max,alloc);
	safe(avail,max,alloc,need,0);
	int pro;
	cout<<"\nEnter process to request: ";cin>>pro;
	/*for(int pr=0;pr<p;pr++){
		if(pr==pro)
		break;
	}*/
	int req[r],flag=0,flag1=0;
	cout<<"Enter request array: ";
	for(int i=0;i<r;i++)
	cin>>req[i];
	
	for(int i=0;i<r;i++){
		if(req[i]>need[pro][i]){
		flag=1;break;}
	}
	for(int i=0;i<r;i++){
		if(req[i]>avail[i]){
		flag1=1;break;}
	}
	if(flag==0 && flag1==0){
		for(int i=0;i<r;i++)
		avail[i]-=req[i];
		for(int i=0;i<r;i++){
			alloc[pro][i]+=req[i];
			need[pro][i]-=req[i];
		}
	}
	safe(avail,max,alloc,need,1);
	
	
		
	return 0;
}
	
				
