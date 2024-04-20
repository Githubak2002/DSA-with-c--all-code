//L11. Container With Most Water

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

int maxArea(vector<int> &height)
{
  int start = 0, end = height.size() - 1;
  int currArea, maxArea = 0;
  while (start < end)
  {
    currArea = min(height[start],height[end]) * (end-start);
    maxArea = max(maxArea,currArea);
    if (height[start] < height[end]) start++;
    else  end--;
  }
  return maxArea;
}

int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> a = {1,8,6,2,5,4,8,3,7};
  int res = maxArea(a);
  cout<<"Max area can be: "<<res<<endl;

  cout << "\n\n=======================";
  return 0;
}