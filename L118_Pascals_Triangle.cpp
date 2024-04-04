// 118. Pascal's Triangle

#include <iostream>
#include <vector>
// #include<algorithm>
using namespace std;

//  print 2D arr ele
void print2DArr(vector<vector<int>> arr)
{
  int rows = arr.size() ,cols;
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

// leet code solution - comination formula
vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> result;
  for (int i = 0; i < numRows; i++)
  {
    vector<int> row(i + 1, 1);
    for (int j = 1; j < i; j++)
    {
      row[j] = result[i - 1][j - 1] + result[i - 1][j];
    }
    result.push_back(row);
  }
  return result;
}

// my code - o/p [100%]
vector<vector<int>> generate3(int numRows){
  vector<vector<int>> res;
  vector<int> arr (1,1);
  vector<int> arr2 (2,1);
  if(numRows >= 1)
    res.push_back(arr);

  if(numRows >= 2)
    res.push_back(arr2);
  
  vector<int> tmpArr, preArr = arr2;
  int ele;

  for (int i = 3; i <= numRows; i++)
  {
    for (int x = 0; x < preArr.size(); x++)
    {
      if(x == 0)
        tmpArr.push_back(1);
      else
        tmpArr.push_back(preArr[x-1]+preArr[x]);
    }
    tmpArr.push_back(1);
    res.push_back(tmpArr);
    preArr = tmpArr;
    tmpArr.clear(); 
  }
  
  return res;
}

int main()
{
  cout << "\n\n=======================\n\n";

  int rows = 6;
  vector<vector<int>> ans;

  ans = generate(rows);
  print2DArr(ans);

  cout << "\n\n=======================";
  return 0;
}
