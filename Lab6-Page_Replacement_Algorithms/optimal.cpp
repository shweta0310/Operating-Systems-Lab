#include<bits/stdc++.h>
using namespace std;
bool find(int val,vector<int>& fr){
	for(int i=0;i<fr.size();i++){
		if(val==fr[i])
			return true;
	}
	return false;
}
int find_optimal_page(vector<int>& page, vector<int>& frame, int index){
	int ans=-1,far=index,j;
	for(int i=0;i<frame.size();i++){
		for(j=index;j<page.size();j++){
			if(page[j]==frame[i]){
				if(j>far){
					far=j;
					ans=i;
				}
				break;
			}
		}
		if(j==page.size())
			return i;
	}
	return ans;
}

void optimal_page_replace(vector<int> &page, int frame_size){

	vector<int> frame;
	int hit=0;
	for(int i=0;i<page.size();i++){
		if(find(page[i],frame)){
			cout<<"hits: "<<i<<endl;
			hit++;
			continue;
		}
		if(frame.size()<frame_size){
			frame.push_back(page[i]);
		}
		else{
			int farthest=find_optimal_page(page,frame,i+1);
			frame[farthest]=page[i];
		}
	}
	cout<<"Final frame:"<<endl;
	for(int i=0;i<frame.size();i++)
		cout<<frame[i]<<" ";
	cout<<endl;
	cout<<"Hits= "<<hit<<endl;
	cout<<"Misses= "<<page.size()-hit<<endl;
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
   int frame_size;
   cout<<"Enter frame size: ";cin>>frame_size;
   optimal_page_replace(page,frame_size);
   return 0;
} 