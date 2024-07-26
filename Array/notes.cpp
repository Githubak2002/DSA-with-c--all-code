/*
Array?
Where the array is stored? - 
  first index 0 can be random, but next address can be predicted if we know 0th index
How to calculate the address of an ele

*/

#include<iostream>
using namespace std;

// initilaay all the ele will have values = 0, max size = 10^7
int globalArr[5];

int main (){

  // initilaay it will contain garbage values, max size = 10^6
  int arr[5];
  for (int i = 0; i < 5; i++)
  {
    cout<<arr[i]<<" ";
  }

  for (int i = 0; i < 5; i++)
  {
    cout<<globalArr[i]<<" ";
  }
  

  return 0;
}