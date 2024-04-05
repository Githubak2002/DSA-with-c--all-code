// 48. Rotate Image
// Link - https://leetcode.com/problems/rotate-image/description


#include<iostream>
#include<vector>
// #include<algorithm>
using namespace std;

// print 2D arr ele
void print2Darr(vector<vector<int>> arr){
  int ns = arr.size(),cols = arr[0].size();
  for (int row = 0; row < ns; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      cout<<arr[row][col]<<" ";
    }
    cout<<endl;
  }
}

void rotate(vector<vector<int>>& matrix){
  int n = matrix.size();
  int ans[n][n];

  int endingCol = n-1;
  int i=0,j=0;
  for (int col = endingCol; col >=0 ; col--)
  {
    j = 0;
    for (int row = 0; row < n; row++)
    {
      ans[row][col] = matrix[i][j++];
    }
    i++;
  }
  // result matrix
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[i][j] = ans[i][j];
    } 
  }
}

int main(){
  cout << "\n\n=======================\n\n";

  vector<vector<int>>arr = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>>arr2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

  cout<<"2D array"<<endl;
  print2Darr(arr);
  rotate(arr);
  cout<<"\n2D array after rotating to 90 deg"<<endl;
  print2Darr(arr);


  cout << "\n\n=======================";
  return 0;
}






// print arr ele
void printarray(vector<int> arr){
  for (int i = 0; i < arr.size(); i++)
    cout<<arr[i]<<" ";    
  cout<<endl;   
}
