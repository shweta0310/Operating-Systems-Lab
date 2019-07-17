#include<bits/stdc++.h>
using namespace std;
#define size 10
struct process{
	int at,bt,ct,tat,wt,pid,check,bt1,hasReached;
};

bool compareArrivalTime(process p1,process p2)
{
	return (p1.at<p2.at);
}
int main()
{
	int n;
	cout<<"Enter no. of processes: ";cin>>n;
	process p[n];
	cout<<"Enter pid,arr time,burst time: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].pid>>p[i].at>>p[i].bt;
		p[i].check=0;
		p[i].bt1=p[i].bt;
		p[i].hasReached=0;
	}
	int quantum;
	cout<<"\nEnter time quantum: ";cin>>quantum;
	int time=0,i;
	queue<process> queue;
	sort(p,p+n,compareArrivalTime);
	time=p[0].at;
	
	queue.push(p[0]);
	p[0].hasReached=1;
	int hasRun=0;
	while(1)
	{
		process x=queue.front();
		cout<<"\nelement dequeed= "<<x.pid;
		queue.pop();
		x.hasReached=0;
		if(x.bt1<=quantum)
		time+=x.bt1;
		else
		time+=quantum;
		for(int j=0;j<n;j++)
		{			
			if(time>=p[j].at && p[j].check==0 && p[j].pid!=x.pid && p[j].hasReached==0)//hasReached is to check if process is new
			{queue.push(p[j]);p[j].hasReached=1;}
		}
		if(x.bt1<=quantum)
		{
			for(int i=0;i<n;i++)
			{
				if(p[i].pid==x.pid)
				{
					p[i].check=1;
					p[i].ct=time;
					p[i].tat=p[i].ct-p[i].at;
					p[i].wt=p[i].tat-p[i].bt;
					cout<<endl<<p[i].pid<<" "<<p[i].at<<" "<<p[i].bt<<" "<<p[i].ct<<" "<<p[i].tat<<" "<<p[i].wt;
					hasRun++;
				}
			}
		}
		else
		{
			x.bt1-=quantum;
			queue.push(x);
			for(int j=0;j<n;j++)
			{
				if(p[j].pid==x.pid)
				p[j].hasReached=1;
			}
		}
		if(hasRun==n)
		break;
		if(queue.empty()==1){
			for(i=0;i<n;i++){
				if(time<p[i].at){
					cout<<endl<<"saj";
					time=p[i].at;
					queue.push(p[i]);
					cout<<endl<<time;
					break;
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
