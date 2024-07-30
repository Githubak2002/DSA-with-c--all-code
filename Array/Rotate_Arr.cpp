// rotating an array to d ele

#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;


// rotating an array - optimized way 
void rotate(vector<int> &arr,int rotateEle){

  reverse(arr.begin(),arr.begin()+rotateEle);
  reverse(arr.begin()+rotateEle,arr.end());
  reverse(arr.begin(),arr.end());
 
}

void moveZeroToEnd(vector<int> &a){

  int j = 0;
  while(a[j]!=0)
    j++;
  
  for (int i = j+1; i < a.size(); i++)
  {
    // int j=0;
    // if(a[j]!=0)
    if(a[i]!=0){
      int tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      j++;
    }
  }
  

}

int main()
{
  cout << "\n\n=======================\n\n";

  vector <int> v1 = {4,5,6,1,2,3};
  int rotateEle = 3;

  vector <int> arrWithZeros = {1,0,2,3,0,0,4,0,0,5};
  // vector <int> v1 = {1,4,3,2,1,2,3,4,1,2,3,4};


  // removingDuplicatesSet(v1);
  rotate(v1,rotateEle);
  cout<<"\nElements of the vector:\n";
  for(int i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";

  // move Zero To End
  moveZeroToEnd(arrWithZeros);
  cout<<"\nElements after moving zeros to end:\n";
  for(int i=0;i<arrWithZeros.size();i++)
    cout<<arrWithZeros[i]<<" ";



  cout << "\n\n=======================";
  return 0;
}
