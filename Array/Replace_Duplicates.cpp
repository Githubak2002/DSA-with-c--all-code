// replacing the duplicates and modifying the array

#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;


// optimized way
void removingDuplicatesoptimizeWay(vector<int> &arr){
  sort(arr.begin(),arr.end());

  int last = arr[1],j=1;
  for (int i = 2; i < arr.size(); i++)
  {
    if(arr[i]!=last){
      arr[j++] = arr[i];
      last = arr[i];
    }
  }
  
}

// using SET
void removingDuplicatesSet(vector<int> &arr){
  set<int> set1;
  int i = 0;
  for (i = 0; i < arr.size(); i++)
    set1.insert(arr[i]);

  i = 0;
  for (auto it:set1){
    arr[i++]=it;
    // cout<<"arr[i]: "<<arr[i]<<endl;;
  }
}


int main()
{
  cout << "\n\n=======================\n\n";

  vector <int> v1 = {4,4,2,2,3,3,1,1};
  // vector <int> v1 = {1,4,3,2,1,2,3,4,1,2,3,4};


  // removingDuplicatesSet(v1);
  removingDuplicatesoptimizeWay(v1);
  cout<<"\nElements of the vector:\n";
  for(int i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";



  cout << "\n\n=======================";
  return 0;
}
