// <bits/stdc++.h> includes -  <iostream> <iomanip> <fstream> <sstream> <cmath> <cstdio> <cstdlib> <algorithm> <string> <vector> <deque> <queue> <stack> <set> <map> <unordered_set> <unordered_map> <bitset> <list> <iterator> <functional> <numeric> <cassert> <cstddef>
#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

int main()
{
  cout << "\n\n=======================\n\n";

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



char toLowerCaseFun(char ch)
{
  if (ch >= 'a' && ch <= 'z')
    return ch;
  else
    return ch + 32;
}

// sort(arr.begin(), arr.end());
// reverse(arr.begin(), arr.end());

// char ch = '1';   int n = ch - '0';   // cout<<n;  n = 1

// vector<int> ans (6,0);      // ans = {0,0,0,0,0,0}

//  vector<int> arr = {1,2,3};   cout<<"first ele "<<*arr.begin();

// string str;
// cout<<"enter a string"<<endl;
// getline(cin,str);
// cout<<"String = "<<str;