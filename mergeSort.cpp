#include<iostream>
using namespace std;

void merge(int input[],int start,int mid,int end)
{
  int *output = new int[end-start+1];
  int i,j,k,w;
  k=0;
  for(i=start,j=mid+1;i<=mid && j<=end;)
  {
    if(input[i]>input[j])
    {
      output[k]=input[j];
      k++;
      j++;
    }
    else
    {
      output[k]=input[i];
      k++;
      i++;
    }
  }  
  if(i==mid+1 && j!=end+1)
  {
	while(j!=end+1)
    {
    	output[k++]=input[j++];  
    }
  }
  if(j==end+1 && i!=mid+1)
  {
  	  while(i!=mid+1)
        output[k++]=input[i++];
  }
  k=0;
  for(w=start;w<=end;w++,k++)
    input[w]=output[k];
  delete[] output;
}

void mergesort(int input[],int start,int end)
{
  if(end>start)
  {
    int mid;
    mid = (end+start)/2;
    mergesort(input,start,mid);
    mergesort(input,mid+1,end);
    merge(input,start,mid,end);
  }  
  else return;
}

void mergeSort(int input[], int size)
{
	// Write your code here
  mergesort(input,0,size-1);
}

int main()
{
  int n;
  cin >> n;
  int *arr = new int[n];
  for(int i= 0;i<n;i++)
    cin >> arr[i];
  mergeSort(arr,n);
  for (int i = 0; i < n; ++i)
  {
    /* code */
    cout << arr[i] << " ";
  }
  delete [] arr;
  return 0;

}