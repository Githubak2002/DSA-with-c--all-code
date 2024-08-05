
// 2D ARRAY - start from here - https://www.youtube.com/watch?v=N0MgLvceX7M&list=PLgUwDviBIf0rENwdL0nEH0uGom9no0nyB&index=14
#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// ROTATING an array about n ele [use mod]
void rotate(vector<int> &arr, int rotateEle)
{
  reverse(arr.begin(), arr.begin() + rotateEle);
  reverse(arr.begin() + rotateEle, arr.end());
  reverse(arr.begin(), arr.end());
}

// removing duplicates from the array
void removingDuplicates(vector<int> &arr)
{
  sort(arr.begin(), arr.end());

  int last = arr[1], j = 1;
  for (int i = 2; i < arr.size(); i++)
  {
    if (arr[i] != last)
    {
      arr[j++] = arr[i];
      last = arr[i];
    }
  }
}

// sorting 0,1,2
void sortArray(vector<int> &arr, int n)
{
  int mid = 0, low = 0, high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low++], arr[mid++]);
    }
    else if (arr[mid] == 1)
    {
      mid++;
    }
    else
    { 
      swap(arr[mid], arr[high--]);
    }
  }
}

// finding majority ele of array appared more than n/2 times
int majorityElement(vector<int> v)
{
  sort(v.begin(), v.end());
  int index = v.size() / 2;
  int majorityEle = v[index];
  return majorityEle;
}

// rearrange arr ele as +ve,-ve,+ve...
vector<int> alternateNumbers(vector<int> &a)
{
  int pos = 0, neg = 1;
  vector<int> ans(a.size(), 0);
  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] > 0)
    {
      ans[pos] = a[i];
      pos += 2;
    }
    else
    {
      ans[neg] = a[i];
      neg += 2;
    }
  }
  return ans;
}

// Superior ele - ele > all the ele present to its right
vector<int> superiorElements(vector<int> &a)
{
  int maxEle, n = a.size();
  vector<int> ans;
  cout << "n = " << n << endl;
  if (n >= 1)
  {
    maxEle = a[n - 1];
    ans.push_back(a[n - 1]);
  }
  for (int i = n - 2; i >= 0; i--)
  {
    if (maxEle < a[i])
    {
      ans.push_back(a[i]);
      maxEle = max(maxEle, a[i]);
    }
  }
  return ans;
}

// finding the longest sequence in arr
int longestSuccessiveElements(vector<int> &a)
{
  sort(a.begin(), a.end());
  // printArray(a);
  // cout<<"\n";
  int count = 1, maxCount = 1;
  for (int i = 0; i < a.size() - 1; i++)
  {
      if(a[i] == a[i+1])
        continue;
    if (a[i]+1 == a[i+1])
    {
      count++;
      // cout<<"maxC: "<<count<<endl;
    }
    else
    {
      maxCount = max(maxCount,count);
      count = 1;
    }
  }
  maxCount = max(maxCount,count);
  return maxCount;
}

// KADANE's algo to find the maxsum of sub array
long long maxSubarraySum(vector<int> arr, int n)
{
  // Kadane's algo
  int startIndex = -1, endIndex = -1, start = 0;
  long long maxSum = LONG_MIN, sum = 0;
  for (int i = 0; i < n; i++)
  {
    if (sum == 0)
      start = i;
    sum += arr[i];
    if (sum > maxSum)
    {
      maxSum = sum;
      startIndex = start;
      endIndex = i;
    }
    if (sum < 0)
      sum = 0;
  }
  return maxSum;
}

// BEST TIME TO BUY AND SELL STOCK
int maximumProfit(vector<int> &prices)
{
  int cost, mini = prices[0], profit = 0;
  for (int i = 0; i < prices.size(); i++)
  {
    cost = prices[i] - mini;
    profit = max(profit, cost);
    mini = min(mini, prices[i]);
  }
  return profit;

  // int buy = 0,sell = 1;
  // int maxPro = prices[sell] - prices[buy];
  // while(sell<prices.size()-1){
  //     if(prices[buy]>prices[sell]){
  //         buy = sell;
  //         sell++;
  //         maxPro = max(maxPro,prices[sell] - prices[buy]);
  //     } else {
  //         sell++;
  //         maxPro = max(maxPro, prices[sell] - prices[buy]);
  //     }
  // }
  // return maxPro>0 ? maxPro : 0;
}

// finding next grater permutation [3,2,5,4,0] - [3,4,0,2,5]
vector<int> nextGreaterPermutation(vector<int> &A)
{
  int tmp = 0, index = -1;
  for (int i = A.size() - 2; i >= 0; i--)
  {
    if (A[i] < A[i + 1])
    {
      index = i;
      break;
    }
  }
  if (index == -1)
  {
    reverse(A.begin(), A.end());
    return A;
  }

  for (int k = A.size() - 1; k > index; k--)
  {
    if (A[index] < A[k])
    {
      swap(A[index], A[k]);
      break;
    }
  }
  sort(A.begin() + index + 1, A.end());
  return A;
}

// max length of sub array with a target
int maxLengthSubarray(int arr[], int n, int targetSum)
{
  unordered_map<int, int> m;
  int maxLen = 0;
  int currSum = 0;

  for (int i = 0; i < n; ++i)
  {
    currSum += arr[i];

    if (currSum == targetSum)
      maxLen = i + 1;
    else if (m.find(currSum - targetSum) != m.end())
      maxLen = max(maxLen, i - m[currSum - targetSum]);
    if (m.find(currSum) == m.end())
      m[currSum] = i;
  }

  return maxLen;
}

int main()
{
  cout << "=======================\n\n";

  // vector<int> arr= {7,1,2,4,6,2};
  int ans;
  // vector<int> arr = {5,8,3,2,1,4};
  vector<int> arr = {15,6,2,1,16,4,2,29,9,12,8,5,14,21,8,12,17,16,6,26,3};


  ans = longestSuccessiveElements(arr);
  cout<<"ans: "<<ans<<endl;





  cout << "\n\n=======================";
  return 0;
}

