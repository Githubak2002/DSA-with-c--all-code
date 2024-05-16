// L40. Combination Sum II

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

// print arr ele
void printarray(vector<int> arr){
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// print 2D arr ele
void print2Darr(vector<vector<int>> arr){
  int rows = arr.size();
  int cols;
  for (int row = 0; row < rows; row++)
  {
    cols = arr[row].size();
    for (int col = 0; col < cols; col++)
    {
      cout << arr[row][col] << " ";
    }
    cout << endl;
  }
}


void combiSum(int index,vector<vector<int>> &ans,int target,vector<int> arr,vector<int> ds){
  if(target == 0){
    ans.push_back(ds);
    return;
  }
  for (int i = index; i < arr.size(); i++)
  {
    if(i>index && arr[i] == arr[i-1]) continue;
    if(arr[i] > target) break;
    ds.push_back(arr[i]);
    combiSum(i+1,ans,target-arr[i],arr,ds);
    ds.pop_back();

  }
  
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> ds;
  sort(candidates.begin(),candidates.end());
  combiSum(0,ans,target,candidates,ds);

  return ans;
}


int main(){
  cout << "\n\n=======================\n\n";
  vector<int> q = {10,1,2,7,6,1,5};          // [ [1,1,6], [1,2,5], [1,7], [2,6] ]
  vector<int> q1 = {2,3,6,7};        
  vector<int> q2 = {2,1,1,1,2};        
  int target = 8;
  vector<vector<int>> ans;
  vector<int> ds;

  ans = combinationSum2(q,target);
  cout<<"All combinations are:"<<endl;
  print2Darr(ans);

  cout << "\n\n=======================";
  return 0;
}

