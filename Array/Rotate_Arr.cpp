// rotating an array to d ele

#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;


// optimized way
void rotate(vector<int> &arr,int rotateEle){

  reverse(arr.begin(),arr.begin()+rotateEle);
  reverse(arr.begin()+rotateEle,arr.end());
  reverse(arr.begin(),arr.end());
 
}


int main()
{
  cout << "\n\n=======================\n\n";

  vector <int> v1 = {4,5,6,1,2,3};
  int rotateEle = 3;
  // vector <int> v1 = {1,4,3,2,1,2,3,4,1,2,3,4};


  // removingDuplicatesSet(v1);
  rotate(v1,rotateEle);
  cout<<"\nElements of the vector:\n";
  for(int i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";



  cout << "\n\n=======================";
  return 0;
}
