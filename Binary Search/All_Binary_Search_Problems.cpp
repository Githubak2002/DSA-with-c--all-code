#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printArray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}



// LOWERBOUND - array ele >= x
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

// upperBound - array ele > x
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


int main()
{
  cout << "\n\n=======================\n\n";

  vector<int> a = {1,2,3,4};

  cout<<"index: "<<upper_bound(a.begin(),a.end(),3)-a.begin();

  
  cout << "\n\n=======================";
  return 0;
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