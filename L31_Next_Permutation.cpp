// L31. Next Permutation - Finding a no just greater than given no [using same digits]

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

void nextPermutation(vector<int> &nums)
{
  int tmp = 0, index = -1;
  for (int i = nums.size() - 2; i >= 0; i--)
  {
    if (nums[i] < nums[i + 1])
    {
      index = i;
      // cout<<"index = "<<index<<endl;
      break;
    }
  }
  if(index == -1){
    reverse(nums.begin(),nums.end());
    return;
  }

  for (int k = nums.size() - 1; k > index; k--)
  {
    if (nums[index] < nums[k])
    {
      swap(nums[index], nums[k]);
      break;
    }
  }
  sort(nums.begin() + index + 1, nums.end());
}

int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> arr2 = {3, 2, 1}, arr1 = {6, 2, 7, 4, 3, 2, 1}, arr4 = {1, 3, 2}, arr = {2, 1, 5, 4, 3, 0, 0}, a1 = {7, 8, 4, 3, 1};
  cout << "Finding a no just greater than given no [using same digits]\n";
  cout << "Initial arr" << endl;
  printarray(arr2);
  cout << "Next permutation" << endl;
  nextPermutation(arr2);
  printarray(arr2);

  cout << "\n\n=======================";
  return 0;
}
