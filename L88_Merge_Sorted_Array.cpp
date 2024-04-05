// 88. Merge Sorted Array

/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int x = m;
  for (int c = 0; c < n; c++)
  {
    nums1[x] = nums2[c];
    x++;
  }
  printarray(nums1);
  sort(nums1.begin(), nums1.end());
  printarray(nums1);
}

void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  vector<int> ans;
  int i = 0, j = 0;
  while ((i + j) != (m + n))
  {
    if (nums1[i] <= nums2[j])
    {
      ans.push_back(nums1[i]);
      i++;
    }
    else
    {
      ans.push_back(nums2[j]);
      j++;
    }
  }
  nums1 = ans;
  printarray(nums1);
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int a = m - 1, b = n - 1, last = m + n - 1;
  // cout<<"a: "<<a<<" b: "<<b<<" last: "<<last<<endl;
  while (last > 0)
  {
    if (nums1[a] >= nums2[b])
      nums1[last--] = nums1[a--];
    else
      nums1[last--] = nums2[b--];
  }
}

int main()
{
  cout << "\n\n==============\n";

  vector<int> arr1 = {1, 3, 5, 0, 0, 0};
  vector<int> arr2 = {2, 4, 6};

  merge(arr1, 3, arr2, 3);
  printarray(arr1);

  return 0;
}