// 229. Majority Element II

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

vector<int> majorityElement(vector<int>& nums) {
  vector<int> res;
  int n = nums.size();
  int ele1,ele2;
  int cnt1 = INT_MIN, cnt2 = INT_MIN;
  // time complexity - O(N)
  for (int i = 0; i < n; i++)
  {
    if(cnt1 == 0 && ele2 != nums[i]){
      cnt1 = 1; 
      ele1 = nums[i];
    }
    else if(cnt2 == 0 && ele1 != nums[i]){
      cnt1 = 1; 
      ele2 = nums[i];
    }
    else if(ele1 == nums[i])  cnt1++;
    else if(ele2 == nums[i])  cnt2++;
    else{
      cnt1--;
      cnt2--;
    }
  }

  // manual conformation 
  cnt1 = 0,cnt2 = 0;
  for (int i = 0; i < n; i++)
  {
    if(ele1 == nums[i]) cnt1++;
    if(ele2 == nums[i]) cnt2++;
  }
  if(cnt1 >= (int)n/3 + 1)  res.push_back(ele1);
  if(cnt2 >= (int)n/3 + 1)  res.push_back(ele2);
  // time complex - O(2 log 2)
  sort(res.begin(),res.end());
  return res;
  
}

int main()
{
  cout << "\n\n=======================\n\n";

  cout << "\n\n=======================";
  return 0;
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

