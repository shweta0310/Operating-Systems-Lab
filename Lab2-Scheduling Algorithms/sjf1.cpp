l#include<bits/stdc++.h>
using namespace std;
#define size 10
struct process{
	int at,bt,ct,tat,wt,pid,check;
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
	}
	int time=0;
	sort(p,p+n,compareArrivalTime);
	time=p[0].at;
	
	for(int i=0;i<n;i++)
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
		time+=pro[0].bt;
		for(int l=0;l<n;l++)
		{	
			if(p[l].pid==pro[0].pid)
			{
				p[l].check=1;
				pro[0].ct=time;
				pro[0].tat=pro[0].ct-pro[0].at;
				pro[0].wt=pro[0].tat-pro[0].bt;
			}
		}
		cout<<endl<<pro[0].pid<<" "<<pro[0].at<<" "<<pro[0].bt<<" "<<pro[0].ct<<" "<<pro[0].tat<<"  "<<pro[0].wt;
	}
	cout<<endl;
	return 0;
}
	
	

