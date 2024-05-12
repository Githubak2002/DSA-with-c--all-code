// L39. Combination Sum
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


void combiSum(int index,vector<vector<int>> &ans,int target,vector<int> candidates,vector<int> ds){

  if(index == candidates.size()){
    if(target == 0){
      ans.push_back(ds);
    }
    return;
  }

  if(candidates[index]<=target){
    ds.push_back(candidates[index]);
    combiSum(index,ans,target-candidates[index],candidates,ds);
    ds.pop_back();
  }
  combiSum(index+1,ans,target,candidates,ds);
  
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> ds;
  combiSum(0,ans,target,candidates,ds);

  return ans;
}


int main(){
  cout << "\n\n=======================\n\n";
  vector<int> q1 = {2,3,6,7};
  vector<int> q = {1,2,7};
  int target = 9;
  vector<vector<int>> ans;
  vector<int> ds;

  ans = combinationSum(q,target);
  cout<<"All combinations are:"<<endl;
  print2Darr(ans);

  cout << "\n\n=======================";
  return 0;
}
