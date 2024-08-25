/*
Array?
Where the array is stored? -
  first index 0 can be random, but next address can be predicted if we know 0th index
  How to calculate the address of an ele

*/

#include <bits/stdc++.h>
using namespace std;

// initillay all the ele will have values = 0, max size = 10^7
// int globalArr[3];

// ===================================
// 1.a rainwater trap   1.b max Area of reactangle
// Print subArray with sum = 0

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

// ============== STRIVER ==============

// Second largest ele in the array [O(n)]
int secondLargest(vector<int> arr)
{
  int max = INT_MIN, secondMax = INT_MIN;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > max)
    {
      secondMax = max;
      max = arr[i];
    }
    else if (arr[i] < max && arr[i] > secondMax)
      secondMax = arr[i];
  }
  return secondMax;
}

// removing duplicates from the array
int removingDuplicates(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  int i = 0;
  for (int j = 1; j < arr.size(); j++)
  {
    if (arr[i] != arr[j])
    {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1; // length of new arr (unique ele)
}

// rotate arr by D places
vector<int> rotateArray(vector<int> arr, int k)
{
  int n = arr.size();
  k = k % n;
  if (k == 0)
    return arr;
  vector<int> tmpArr;
  for (int i = 0; i < k; i++)
    tmpArr.push_back(arr[i]);

  for (int i = k; i < n; i++)
  {
    arr[i - k] = arr[i];
  }
  for (int i = n - k; i < n; i++)
  {
    arr[i] = tmpArr[i - (n - k)];
  }
  return arr;
}

vector<int> rotateArrayOptimized(vector<int> arr, int k)
{
  // optimized
  int n = arr.size();
  reverse(arr.begin(), arr.begin() + k);
  reverse(arr.begin() + k, arr.begin() + n);
  reverse(arr.begin(), arr.end());
  return arr;
}

// moving zeros to end [O(n)]
vector<int> moveZeros(int n, vector<int> a)
{
  int j = -1;
  // finding first zero
  for (int i = 0; i < n; i++)
  {
    if (a[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
    return a;
  for (int i = j + 1; i < n; i++)
  {
    if (a[i] != 0)
      swap(a[j++], a[i]);
  }
  return a;
}

// Medium - Find the UNION of two array
vector<int> sortedArray(vector<int> a, vector<int> b)
{
  int lena = a.size(), lenb = b.size();
  vector<int> arr;
  int i = 0, j = 0;
  while (i < lena && j < lenb)
  {
    if (a[i] <= b[j])
    {
      if (arr.size() == 0 || arr.back() != a[i])
        arr.push_back(a[i]);
      i++;
    }
    else
    {
      if (arr.size() == 0 || arr.back() != b[j])
        arr.push_back(b[j]);
      j++;
    }
  }

  while (i < lena)
  {
    if (arr.size() == 0 || arr.back() != a[i])
      arr.push_back(a[i]);
    i++;
  }

  while (j < lenb)
  {
    if (arr.size() == 0 || arr.back() != b[j])
      arr.push_back(b[j]);
    j++;
  }
  return arr;
}

// Median - intersection of two array
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
  vector<int> ans;
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (arr1[i] == arr2[j])
    {
      ans.push_back(arr1[i]);
      i++;
      j++;
    }
    else if (arr1[i] < arr2[j])
      i++;
    else
      j++;
  }
  return ans;
}

// Easy - missing no in an array (XOR) [O(n)]
int missingNumber(vector<int> &a, int N)
{
  int i, xor1 = 0, xor2 = 0;
  for (i = 0; i < N - 1; i++)
  {
    xor1 = xor1 ^ a[i];
    xor2 = xor2 ^ (i + 1);
  }
  xor2 = xor2 ^ (i + 1);
  return xor2 ^ xor1;
  // long long sum = n*(n+1)/2; // extra space compared to xor
}

// Easy - return ele appares once  (XOR) [O(n)]
int getSingleElement(vector<int> &arr)
{
  int ans = 0;
  for (int i = 0; i < arr.size(); i++)
    ans = ans ^ arr[i];
  return ans;
}

// Length of sub array giving sum = k
int longestSubarrayWithSumK(vector<int> a, long long k)
{
  int left = 0, right = 0, len = 0, n = a.size();
  long long sum = a[0];
  while (right < n)
  {
    while (sum > k && left <= right)
      sum -= a[left++];
    if (sum == k)
      len = max(len, right - left + 1);
    right++;
    if (right < n)
      sum += a[right];
  }
  return len;
}

// Length of sub array giving sum = k [with zeros and negative no - vodeo 4]

// two sum - returning the index/yes or no
string twoSum(int n, vector<int> book, int target)
{
  // map<int,int> mpp;
  // for (int i = 0; i < n; i++)
  // {
  //   int a = book[i];
  //   int more = target - a;
  //   if(mpp.find(more) != mpp.end())
  //     return {mpp[more],i};
  //   mpp[a] = i;
  // }
  // return {-1,-1};
  
  sort(book.begin(), book.end());
  int left = 0, right = n - 1, sum = 0;
  while (left <= right)
  {
    sum = book[left] + book[right];
    if (sum == target)
      return "YES";
    else if (sum > target)
      right--;
    else
      left++;
  }
  return "NO";
}

// sort 0, 1, 2
vector<int> sort012(vector<int> arr)
{
  int n = arr.size();
  int start=0,mid=0,end = n-1;
  while(mid <= end)
  {
    if(arr[mid] == 0)
      swap(arr[mid++],arr[start++]);
    else if(arr[mid] == 2)
      swap(arr[mid],arr[end--]);
    else
      mid++;    
  }
  return arr;
}


int main()
{

  cout << "====================\n\n";

  vector<int> a = {1,0,0,0,2,1,2}, b = {1, 4, 5, 6};
  // int ans = 0;
  vector<int> ans;
  // cout << "Original array: ";
  // printarray(arr);
  ans = sort012(a);
  // cout << "\n\nans: " << ans;
  printarray(ans);

  cout << "\n\n====================";
  return 0;
}

/*

  int arr[3];
  for (int i = 0; i < 3; i++)
    cout<<arr[i]<<" ";

  for (int i = 0; i < 3; i++)
    cout<<globalArr[i]<<" ";    // 0 0 0




*/