// GFG - Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.
/**
Input: n = 2   arr[] = {2, 3}
Output: 0 2 3 5
*/

#include<iostream>
using namespace std;

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// print 2D arr ele
void print2Darr(vector<vector<int>> arr)
{
  int rows = arr.size(), cols = arr[0].size();
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
}

void subsetSum (int index, int sum,vector<int> arr,vector<int> &ans){
  if(index == arr.size()){
    ans.push_back(sum);
    return;
  }

  // sum = sum+arr[index];
  // sum = sum-arr[index];
  subsetSum(index+1,sum+arr[index],arr,ans);
  subsetSum(index+1,sum,arr,ans);

}

int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> arr = {1,2,3};
  vector<int> ans;
  subsetSum(0,0,arr,ans);
  sort(ans.begin(),ans.end());
  printarray(ans);

  cout << "\n\n=======================";
  return 0;
}


