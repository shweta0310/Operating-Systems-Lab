#include "stdafx.h"
#include <iostream>

using namespace std;

void main()
{
 //INFORMATION ABOUT THE PROCESSES
 cout<<"Enter the number of processes: ";
 int nProc = 0;
 cin>>nProc;

 cout<<"Enter the size of each process: ";
 int data[10][3]; //we assume at most 10 processes

 for(int i = 0;i<nProc;++i)
 {
  cin>>data[i][0]; //size of the process
  data[i][1] = 0;  //0 means unallocated
  data[i][2] = i;  //id of the process
 }

 //INFORMATION ABOUT THE MEMORY BLOCKS
 cout<<"Enter the number of memory blocks: ";
 int nBlocks = 0;
 cin>>nBlocks;

 cout<<"Enter the size of each block: ";
 int dataBlocks[10][2];

 for(int i =0;i<nProc;++i)
 {
  cin>>dataBlocks[i][0];
  dataBlocks[i][1] = 0; //0 means unallocated
 }

 int bigAvail=0, size=0;
 //ALLOCATION TO BE DONE HERE
 for(int i = 0;i<nProc;++i)
 {
  for(int j = 0;j<nBlocks;++j)
  {
   if(data[i][1]==0&&dataBlocks[j][1]==0 /*these test if the block and image are free*/&&data[i][0]<=dataBlocks[j][0])
   {
    bigAvail=j;
    size=dataBlocks[j][0];
    for(int l=j;l<nBlocks;++l)
    {
     if(dataBlocks[l][0]>size&&dataBlocks[l][1]==0)
     {
      bigAvail=l;
      size=dataBlocks[l][0];
     }
    }
    data[i][1] = 1;    //allocated
    dataBlocks[bigAvail][1] = 1;  //allocated
    cout<<"Process id "<<i<<" allocated to memory block: "<<bigAvail<<endl;
   }
  }
 }

 for(int i = 0;i<nBlocks;++i)
 {
  if(data[i][1]==0)
  {
   cout<<"Process id "<<i<<" unallocated\n";
  }
 }
}
