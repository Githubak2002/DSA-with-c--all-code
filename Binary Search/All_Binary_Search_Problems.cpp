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
    left = mid+1;
  }
}


// LOWERBOUND - array ele >= x (CEIL in sorted arr)
// cout<<"index: "<<lower_bound(a.begin(),a.end(),3) - a.begin();
int LowerBound(vector<int> &arr, int x, int n)
{
	int ans = n;
	int start = 0,end = n-1;
	int mid;
	while(start<=end){
		mid = start + (end-start)/2;
		if(arr[mid] >= x)
		{
			ans = mid;
			end = mid-1;
		}
		else
			start = mid+1;
	}
	return ans;
}

// upperBound - array ele > x (FLOOR in sorted arr >=)
int upperBound(vector<int> &arr, int x, int n)
{
	int ans = n;
	int start = 0,end = n-1;
	int mid;
	while(start<=end){
		mid = start + (end-start)/2;
		if(arr[mid] > x)
		{
			ans = mid;
			end = mid-1;
		}
		else
			start = mid+1;
	}
	return ans;
}

// first and last index of the array ele
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
  int firstIndex = -1,lastIndex = -1;
  firstIndex = lower_bound(arr.begin(),arr.end(),k)-arr.begin();
  if(arr[firstIndex] != k)  
    return {-1,-1};

  lastIndex = upper_bound(arr.begin(),arr.end(),k)-arr.begin();
  lastIndex -= 1;

  return {firstIndex,lastIndex};
}



// SEARCH in a ROTATED sorted array 
int searchInARotatedSortedArray(vector<int>& arr, int n, int k)
{
  int start=0,end=n-1,mid;
  while(start<=end)
  {
    mid = start + (end-start)/2;
    if(arr[mid] == k)
      return mid;
    else if(arr[start]<=arr[mid])   // left part is sorted
    {
      if(arr[start] <= k && arr[mid] >= k)
        end = mid-1;
      else
        start = mid+1;
    }
    else                            // right part is sorted
      if(arr[mid] <= k && arr[end]>= k)
        start = mid+1;
      else
        end = mid-1;
  }
  return -1;
}

// search In a rotated sorted array II
bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
  int n = A.size();
  int start=0,end=n-1,mid;
  while(start<=end)
  {
    mid = start + (end-start)/2;
    if(A[mid] == key)
      return true;
    if(A[mid] == A[start] && A[end] == A[mid])
    {
      start++;  end--;  continue;
    }
    else if(A[start]<=A[mid])   // left part is sorted
    {
      if(A[start] <= key && A[mid] >= key)
        end = mid-1;
      else
        start = mid+1;
    }
    else                            // right part is sorted
      if(A[mid] <= key && A[end]>= key)
        start = mid+1;
      else
        end = mid-1;
  }
  return false;
}

// search MIN In a rotated sorted array II
int findMinInARotatedSortedArray(vector<int>& arr)
{
	int start = 0,end = arr.size()-1,mid;
  int mini = INT_MAX;
  while(start<=end)
  {
    mid = start + (end-start)/2;
    if(arr[mid] <= arr[end])
    {
      mini = min(arr[mid],mini);
      end = mid-1;
    }
    else 
    {
      mini = min(mini,arr[start]);
      start = mid+1;
    }
  }
  return mini;
}



int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> a = {3,4,5,6,7,1,2};
  // vector<int> a = {7,8,1,2,3,4,5};

  // cout<<"index: "<<upper_bound(a.begin(),a.end(),3)-a.begin();

  cout<<findMinInARotatedSortedArray(a)<<endl;

  
  cout << "\n\n=======================";
  return 0;
}


// print 2D A ele
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