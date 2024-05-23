// Find the length of the sub array with max sum

#include <iostream>
#include <unordered_map>
using namespace std;

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

/*
int maxLengthSubarray(int arr[], int n, int targetSum){
  unordered_map<int,int> mp;


  int currentSum = 0, maxLen = 0;
  currentSum =+ arr[i];

  for (int i = 0; i < n; i++)
  {
    if(currentSum == targetSum)
      maxLen = i+1;
    else if()

    if(mp.find(currentSum) == mp.end())
      mp[currentSum] = i;
  }

}
*/

int main()
{
  cout<<"===========================\n\n";

  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }

  int targetSum;
  cout << "Enter the target sum: ";
  cin >> targetSum;

  int maxLength = maxLengthSubarray(arr, n, targetSum);
  cout << "Maximum length of subarray with target sum: " << maxLength << endl;

  cout<<"\n\n===========================";
  return 0;
}
