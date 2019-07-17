#include<bits/stdc++.h>
using namespace std;
struct frame{
	int pno,freq;
};
int page_found(int p,vector<frame>& fr){
	for(int i=0;i<fr.size();i++){
		if(fr[i].pno==p)
			return i;
	}
	return -1;
}
int frameFree(vector<frame>& fr){
	for(int i=0;i<fr.size();i++){
		if(fr[i].pno==-1)
			return i;
	}
	return -1;
}
int mfu(vector<int>& page, vector<frame>& fr, int capacity){
	int faults=0;
	for(int i=0;i<page.size();i++){
		if(page_found(page[i],fr)==-1){
			int k=frameFree(fr);
			if(k==-1){
				int max_index=0;
				for(int j=1;j<fr.size();j++){
					if(fr[j].freq>fr[max_index].freq)
						max_index=j;
				}
				faults++;
				fr[max_index].pno=page[i];
				fr[max_index].freq=1;
				
			}
			else{
				faults++;
				fr[k].pno=page[i];
				fr[k].freq=1;
			}
		}
		else{
				int j=page_found(page[i],fr);
				fr[j].freq++;
		}
	}
	cout<<"Final frame structure: "<<endl;
	for(int i=0;i<fr.size();i++)
		cout<<fr[i].pno<<" ";
	cout<<endl;
	return faults;
}
int main(){
	vector<int> page;
   int size;
   cout<<"Enter page size: ";cin>>size;
   for(int i=0;i<size;i++){
   	int ele;
   	cin>>ele;
   	page.push_back(ele);
   }
   int capacity;
   cout<<"Enter capacity: ";cin>>capacity;

   vector<frame> fr;
   frame f={-1,0};
   for(int i=0;i<capacity;i++){
   	fr.insert(fr.end(),f);
   }
   int faults=mfu(page,fr,capacity);
   cout<<"No. of page fault= "<<faults<<endl;
   return 0;
} 