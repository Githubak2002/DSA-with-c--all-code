#include <bits/stdc++.h>
#include <iostream>
#include <vector>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

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

int main()
{
  cout << "\n\n=======================\n\n";
  vector<vector<int>> arr2d = { {06,12,16,18,35},
                                {15,17,32,38,55},
                                {25,27,44,46,75},
                                {36,37,48,56,85}};

  print2Darr(arr2d);
  int cols = 5,rows = 4;
  int j = cols,i=0;
  int s_ele = 37;

  int flag = false;
  while(j>=0 && i<=rows){
    if(s_ele == arr2d[i][j-1]){
      cout<<"\nEle "<<s_ele<<" is present in the array\n";
      cout<<"row: "<<i+1<<" col: "<<j<<endl;
      flag = true;
      break;
    }
    else if(s_ele < arr2d[i][j-1])
      j--;
    else  
      i++;
  }

  if(!flag)
  cout<<"Ele not exists\n";

  cout << "\n\n=======================";
  return 0;
}

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}


