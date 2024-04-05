// 75. Sort Colors

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

void sortColors(vector<int> &nums)
{
  int l = 0 , m = 0, h = nums.size()-1;
  while (nums[m] < nums[h]){
    if(nums[h] == 2)
      h--;
    else if(nums[m] == 2){
      swap(nums[m],nums[h]);
      h--;
    }else if(h==0){
      swap(nums[l],nums[h]);
      l++;
    }
  } 
}

int main()
{
  cout << "\n\n=======================\n\n";
  vector<int> a = {2,0,2,1,1,0} ;
  cout<<"Array is:";
  printarray(a);
  sortColors(a);
  cout<<"After sorting 0,1,2 array is:";
  printarray(a);

  cout << "\n\n=======================";
  return 0;
}
