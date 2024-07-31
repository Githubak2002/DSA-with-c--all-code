

#include<bits/stdc++.h>
using namespace std;

// rotating an array about n ele  
void rotate(vector<int> &arr,int rotateEle){
  reverse(arr.begin(),arr.begin()+rotateEle);
  reverse(arr.begin()+rotateEle,arr.end());
  reverse(arr.begin(),arr.end());
 
}

// removing duplicates from the array
void removingDuplicates(vector<int> &arr){
  sort(arr.begin(),arr.end());

  int last = arr[1],j=1;
  for (int i = 2; i < arr.size(); i++)
  {
    if(arr[i]!=last){
      arr[j++] = arr[i];
      last = arr[i];
    }
  }
}

// sorting 0,1,2
void sortArray(vector<int>& arr, int n)
{
    int mid=0,low=0,high=n-1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high--]);
        }
    }
}

// finding majority ele of array appared more than n/2 times
int majorityElement(vector<int> v) {
	sort(v.begin(),v.end());
	int index = v.size()/2;
	int majorityEle = v[index];
	return majorityEle;
}
int majorityElementUsingMap(vector<int> v) {
	map<int,int> mp;
	for(int i =0;i<v.size();i++){
		mp[v[i]]++;
	}
	for(auto it:mp){
		if(it.second > v.size()/2)
			return it.first;
	}
	return -1;	
}

// rearrange arr ele as +ve,-ve,+ve... 
vector<int> alternateNumbers(vector<int>&a) {
    int pos = 0,neg = 1;
    vector<int> ans (a.size(),0);
    for(int i=0;i<a.size();i++){
        if(a[i]>0){
            ans[pos]=a[i];
            pos +=2;
        }
        else{
            ans[neg]=a[i];
            neg +=2;
        }
    }
    return ans;
}

// Kadane's algo to find the maxsum of sub array
long long maxSubarraySum(vector<int> arr, int n)
{
    // Kadane's algo
    int startIndex = -1,endIndex = -1,start = 0;
    long long maxSum = LONG_MIN, sum = 0;
    for(int i = 0;i<n;i++){
      if(sum == 0)
        start = i;
      sum += arr[i];
      if(sum>maxSum){
        maxSum = sum;
        startIndex = start;
        endIndex = i;
      }
      if(sum<0){
            sum = 0;
      }
    }
    return maxSum;
}


// max length of sub array with a target
int maxLengthSubarray(int arr[], int n, int targetSum){
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




int main (){

  return 0;
}