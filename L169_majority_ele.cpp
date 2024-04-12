/* L169. Majority Element
 Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}


int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }

// optimal using map
int majorityElement1(vector<int>& nums) {
    // unordered_map <int,int> um1;
    map <int,int> um1;
    for (int i = 0; i < nums.size(); i++)
    {
        um1[nums[i]]++;
        if(um1[nums[i]] > nums.size()/2)
            return nums[i];
    }    
}

// final optimal - Moore's vonting algorithm
int majorityElement2(vector<int>& nums) {
    int s = nums.size();
    int count = 0,ele;
    for (int i = 0; i < s; i++)
    {
        if(count == 0){
            ele = nums[i];
            count++;
        }   
        if(nums[i] != ele)
            count--;
        if(nums[i] == ele)
            count++;     
    }

    // does majority ele exists
    int countt = 0;
    for (int i = 0; i < s; i++)
    {
        if(ele == nums[i])
            countt++;
    }
    if(countt > s/2) return ele;
    else return -1;
     
} 

int main(){
    cout<<"=====================\n\n";

    vector<int> arr = {3,2,3};
    vector<int> arr1 = {2,2,1,1,1,2,2};
    cout<<"Arr is : ";printarray(arr1);
    cout<<"majority ele in arr after sort = "<<majorityElement2(arr1);


    cout<<"\n\n=====================";
    return 0;
}