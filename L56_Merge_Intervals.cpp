// L56. Merge Intervals

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

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  vector<vector<int>> res;
  int n = intervals.size(),start,end; 
  sort(intervals.begin(),intervals.end());

  cout<<"After sorting arr\n"; print2Darr(intervals);

  for (int i = 0; i < n; i++)
  {
    if(res.empty() || intervals[i][0] > res.back()[1]){
      res.push_back(intervals[i]);
    }
    else{
      res.back()[1] = max(res.back()[1],intervals[i][1]);
    }
  }
  return res;  
}

int main()
{
  cout << "\n\n=======================\n\n";

  // vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {12, 18}},;
  // vector<vector<int>> arr = {{1,3},{4,5},{6,12},{7,8},{9,12},{13,14}};
  // vector<vector<int>> arr = {{1,3},{4,5},{6,12},{7,8},{9,10},{12,14}};
  vector<vector<int>> arr = {{1,2},{8,9},{2,4},{9,12},{2,6}};

  vector<vector<int>> res = merge(arr);
  cout<<"Result\n";
  print2Darr(res);

  cout << "\n\n=======================";
  return 0;
}