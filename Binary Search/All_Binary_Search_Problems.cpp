#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// binarySearch - TC = O(log n) - [log base 2 n]
int binarySearch(vector<int> arr, int x)
{
  int left = 0, right = arr.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] > x)
      right = mid - 1;
    else
      left = mid + 1;
  }
}

// finding square root
int floorSqrt(int n)
{
  int start = 1,end = n;
  long long mid;
  long long value;
  while(start<=end)
  {
    mid = start+(end-start)/2;
    value = mid*mid;
    if(value <= n){
      start = mid+1;
    }
    else
      end = mid-1;
  }
  return end;
}

// LOWERBOUND - array ele >= x (CEIL in sorted arr)
// cout<<"index: "<<lower_bound(a.begin(),a.end(),3) - a.begin();
int LowerBound(vector<int> &arr, int x, int n)
{
  int ans = n;
  int start = 0, end = n - 1;
  int mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] >= x)
    {
      ans = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return ans;
}

// upperBound - array ele > x (FLOOR in sorted arr >=)
int upperBound(vector<int> &arr, int x, int n)
{
  int ans = n;
  int start = 0, end = n - 1;
  int mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] > x)
    {
      ans = mid;
      end = mid - 1;
    }
    else
      start = mid + 1;
  }
  return ans;
}

// first and last index of the array ele
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
  int firstIndex = -1, lastIndex = -1;
  firstIndex = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
  if (arr[firstIndex] != k)
    return {-1, -1};

  lastIndex = upper_bound(arr.begin(), arr.end(), k) - arr.begin();
  lastIndex -= 1;

  return {firstIndex, lastIndex};
}

// SEARCH in a ROTATED sorted array
int searchInARotatedSortedArray(vector<int> &arr, int n, int k)
{
  int start = 0, end = n - 1, mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] == k)
      return mid;
    else if (arr[start] <= arr[mid]) // left part is sorted
    {
      if (arr[start] <= k && arr[mid] >= k)
        end = mid - 1;
      else
        start = mid + 1;
    }
    else // right part is sorted
      if (arr[mid] <= k && arr[end] >= k)
        start = mid + 1;
      else
        end = mid - 1;
  }
  return -1;
}

// search In a rotated sorted array II
bool searchInARotatedSortedArrayII(vector<int> &A, int key)
{
  int n = A.size();
  int start = 0, end = n - 1, mid;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (A[mid] == key)
      return true;
    if (A[mid] == A[start] && A[end] == A[mid])
    {
      start++;
      end--;
      continue;
    }
    else if (A[start] <= A[mid]) // left part is sorted
    {
      if (A[start] <= key && A[mid] >= key)
        end = mid - 1;
      else
        start = mid + 1;
    }
    else // right part is sorted
      if (A[mid] <= key && A[end] >= key)
        start = mid + 1;
      else
        end = mid - 1;
  }
  return false;
}

// search MIN In a rotated sorted array
int findMinInARotatedSortedArray(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1, mid;
  int mini = INT_MAX;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] <= arr[end])
    {
      mini = min(arr[mid], mini);
      end = mid - 1;
    }
    else
    {
      mini = min(mini, arr[start]);
      start = mid + 1;
    }
  }
  return mini;
}



// Find No of times sorted arr is ROTATED
int findKRotation(vector<int> &arr)
{
  int start = 0, end = arr.size() - 1, mid;
  int mini = INT_MAX, index;
  while (start <= end)
  {
    mid = start + (end - start) / 2;
    if (arr[mid] <= arr[end])
    {
      if (arr[mid] < mini)
      {
        mini = arr[mid];
        index = mid;
      }
      end = mid - 1;
    }
    else
    {
      if (arr[start] <= mini)
      {
        mini = arr[start];
        index = start;
      }
      start = mid + 1;
    }
  }
  return index;
}

// All ele appares twice except one, find that ele
int singleNonDuplicate(vector<int> &arr)
{
  int n = arr.size();
  // Edge cases:
  if (n == 1)
    return arr[0];
  if (arr[0] != arr[1])
    return arr[0];
  if (arr[n - 1] != arr[n - 2])
    return arr[n - 1];

  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = (low + high) / 2;

    // if arr[mid] is the single element:
    if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
      return arr[mid];

    // we are in the left: eliminate the left half:
    if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
      low = mid + 1;

    // we are in the right: eliminate the right half
    else
      high = mid - 1;
  }

  return -1;
}

// FINDING PEAK ELEMENT
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    if(n==1)   return 0;
    if(arr[0]>arr[1]) return 0;    
    if(arr[n-1]>arr[n-2]) return n-1;

    int start = 1,end = n-2,mid;

    while(start <= end)
    {
        mid = start+(end-start)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
            return mid;
        else if (arr[mid-1]<arr[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}







int maxInArr(vector<int> arr)
{
  int maxi = INT_MIN;
  for (int i = 0; i < arr.size(); i++)
  {
    if(arr[i]>maxi)
      maxi = arr[i];
  }
  return maxi;  
}

int calculateTotalHours(vector<int> arr,int hourly)
{
  int totalH = 0;
  for (int i = 0; i < arr.size(); i++)
    totalH += ceil(double(arr[i])/double(hourly));
  return totalH;
}

// Koko eating bananas
int minimumRateToEatBananas(vector<int> v, int h) {
  int start = 1,end = maxInArr(v);
  int mid,hrRate,ans=1;

  while(start <= end)
  {
    mid = start+(end-start)/2;
    int hrRate = calculateTotalHours(v,mid);
    // cout<<"hrRate: "<<hrRate<<endl;
    if(hrRate <= h){
      ans = mid;
      end = mid-1;
    }
    else start = mid+1;
  }
  return ans;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = maxInArr(v);

    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}





// =================================================


int pow(int x,int n){
  if(n==0) return 1;

  int ans = 1;
  for (int i = 0; i < n; i++)
    ans = x * ans;
  return ans;
}

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



int main()
{
  cout << "\n\n=======================\n\n";

  // vector<int> a = {3,4,5,6,7,1,2};
  vector<int> a = {3, 6, 2, 8};
  int ans = minimumRateToEatBananas(a,7);
  cout<<"ans: "<<ans;

  // cout<<"index: "<<upper_bound(a.begin(),a.end(),3)-a.begin();

  // cout << singleNonDuplicate(a) << endl;
  
  // cout << floorSqrt(7) << endl;

  // cout<<pow(4,4)<<endl;



  cout << "\n\n=======================";
  return 0;
}







// =============== All above Function explained ===============
/*
  FINDING PEAK ELE - 
    finding the index of peak ele. Peak ele is arr[mid-1] < Peak ele > arr[mid+1]
    asuming arr[-1] and arr[n] = -infinity
*/


/*
sort(arr.begin(), arr.end());
reverse(arr.begin(), arr.end());

char ch = '1';   int n = ch - '0';   // cout<<n;  n = 1

vector<int> ans (6,0);      // ans = {0,0,0,0,0,0}

vector<int> arr = {1,2,3};   cout<<"first ele "<<*arr.begin();
*/

// string str;
// cout<<"enter a string"<<endl;
// getline(cin,str);
// cout<<"String = "<<str;
















