// Basics of array

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

int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> a1(5, 1); // {1,1,1,1,1}
  cout << "a1 (1,5) = ";
  printarray(a1);

  // ========== SORT function (vector) ==========
  vector<int> as1 = {4, 3, 5, 2, 1};
  cout << "Before sorting arr: ";
  printarray(as1);
  sort(as1.begin(), as1.end());
  cout << "After sorting arr: ";
  printarray(as1);


  // ========== REVERSE function (vector) ==========
  reverse(as1.begin(), as1.end());
  cout << "After reversing arr: ";
  printarray(as1);

  cout<<"first ele of array: "<<*as1.begin();


  cout << "\n\n=======================";
  return 0;
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