/*
Array?
Where the array is stored? - 
  first index 0 can be random, but next address can be predicted if we know 0th index
  How to calculate the address of an ele

*/

#include<bits/stdc++.h>
using namespace std;

// initillay all the ele will have values = 0, max size = 10^7
int globalArr[3];

int main (){

  // initilaay it will contain garbage values, max size = 10^6
  /*
  int arr[3];
  for (int i = 0; i < 3; i++)
    cout<<arr[i]<<" ";

  for (int i = 0; i < 3; i++)
    cout<<globalArr[i]<<" ";    // 0 0 0 
  */

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