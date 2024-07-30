

#include<bits/stdc++.h>
using namespace std;

int main (){

  
  vector<int> v1 =  {1,2,3};
  int arr[] =  {10,20,30,40,50,60};
  int size = sizeof(arr)/sizeof(arr[0]);
  int len = v1.size();
  
  reverse(arr,arr+3);

  // int arr[3] = {6,7,8};
  // arr.reverse(); 
  for (int i = 0; i < size; i++)
    cout<<arr[i]<<" ";
  

  return 0;
}