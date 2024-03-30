// RECURSION with subsequence
#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}


// SUM OF N natural no - printing sum
void printSumOfN(int i,int sum){
  if(i<0){
    cout<<"sum = "<<sum<<endl;
    return;
  }
  printSumOfN(i-1,sum+i);
}

// SUM OF N natural no - returning sum
int returnSumOfN(int n){
  if(n == 0){
    return 0;
  }
  return n+returnSumOfN(n-1);
}

// REVERSE AN ARRAY
void reverseArr(int arr[],int start,int end){
  // void reverseArr(int arr[],int start,int n){
  // if(start >= n/2) return
  if(start >= end)
    return;

  swap(arr[start],arr[end]);
  reverseArr(arr,start+1,end-1);
}

void allSubSequences(int index,vector<int> &ds, int arr[],int n){
  if(index == n){
    for(auto x : ds){
      cout<<x<<" ";
    }
    if(ds.size() == 0)
      cout<<"{}";
    cout<<"\n";
    return;
  }
  // considering the ele
  ds.push_back(arr[index]);
  allSubSequences(index+1,ds,arr,n);
  ds.pop_back();
  // not including/considering the ele
  allSubSequences(index+1,ds,arr,n);
}


int main()
{
  cout<<"\n\n";

    // REVERSING AN ARRAY
  vector<int> ds;
  int arr[] = {3,1,2},n = 3;
  cout<<"Printing all the subsequences \n";
  allSubSequences(0,ds,arr,3);


  
  

  cout<<"\n\n";
  return 0;
}
