#include<bits/stdc++.h>
using namespace std;
#define size 10
struct process{
	int at,bt,ct,tat,wt,pid,check,bt1;
};
bool compareArrivalTime(process p1,process p2)
{
	return (p1.at<p2.at);
}
bool compareBurstTime(process p1,process p2)
{
	return (p1.bt<p2.bt);
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
	}
	int time=0,hasRun=0;
	sort(p,p+n,compareArrivalTime);
	time=p[0].at;
	while(1)
	{
		process pro[n];int k=0;
		for(int j=0;j<n;j++)
		{	
			if(time>=p[j].at && p[j].check==0)
			{	
				pro[k]=p[j];
				k++;
			}
		}	
		sort(pro,pro+k,compareBurstTime);
		time+=1;
		for(int l=0;l<n;l++)
		{
			if(p[l].pid==pro[0].pid)
			{
				p[l].bt1-=1;
				if(p[l].bt1==0)
				{
					p[l].check=1;
					p[l].ct=time;
					p[l].tat=p[l].ct-p[l].at;
					p[l].wt=p[l].tat-p[l].bt;
					cout<<endl<<p[l].pid<<" "<<p[l].at<<" "<<p[l].bt<<" "<<p[l].ct<<" "<<p[l].tat<<" "<<p[l].wt;
					hasRun+=1;
				}
			}
		}
		if(hasRun==n)
		break;
	}
	return 0;
}				
