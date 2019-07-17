#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
int lru_replace(vector<int>& page,int capacity){
	unordered_set<int> set;
	unordered_map<int,int> index;
	int faults=0;
	for(int i=0;i<page.size();i++){
		if(set.size()<capacity){
			if(set.find(page[i])==set.end()){
				set.insert(page[i]);
				faults++;
			}
			index[page[i]]=i;	
		}
		else{
			if(set.find(page[i])==set.end()){
				int least=INT_MAX,ele;
				for(auto it=set.begin();it!=set.end();it++){
					if(index[*it]<least){
						least=index[*it];
						ele=*it;
					}
				}
				set.erase(ele);
				set.insert(page[i]);
				faults++;				
			}
			index[page[i]]=i;
		}
	}
	/*cout<<"Final frame set:"<<endl;
	for(auto it=set.begin();it!=set.end();it++){
		cout<<*it<<" ";
	}*/
	cout<<endl;
	return faults;
}
int main() 
{ 
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
   int faults=lru_replace(page,capacity);
   cout<<"No. of page fault= "<<faults<<endl;
   cout<<"No. of hits= "<<page.size()-faults<<endl;
   return 0;
} 
