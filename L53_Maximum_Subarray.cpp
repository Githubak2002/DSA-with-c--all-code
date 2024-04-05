// L53. Maximum Subarray

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

int maxSubArray(vector<int>& nums) {
  int sum = 0,max = INT_MIN;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
    if(sum > max)
      max = sum;
    if(sum < 0)
      sum = 0;
  }
  return max;
}

int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};    // o/p - 6
  vector<int> arr2 = {5,4,-1,7,8};               // o/p - 23
  cout<<"Result: "<<maxSubArray(arr2);


  cout << "\n\n=======================";
  return 0;
}
