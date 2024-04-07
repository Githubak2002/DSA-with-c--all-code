/*  1. Two Sum

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<string>
// #include<unordered_map>
using namespace std;

void printArray(vector<int>a){
    for (int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<"\n";    
}

int find(vector<int>& nums, int b,int prevIndex){
    for (int i = prevIndex+1; i < nums.size(); i++){
        if(nums[i]==b)
            return i;
    }
    return -1;
}

// vector<int> twoSum(vector<int>& nums, int target) {
//     int a,b,j;

//     for (int i = 0; i < nums.size(); i++){
//         if(nums[i]>target)
//             continue;
    
//         for(int x = i+1; x < nums.size(); x++){
//         if(nums[x]==target-nums[i])
//             return {i,x};
//         }        
//     }
// }

vector<int> twoSum(int n, vector<int> &arr, int target){
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main(){
    
    // vector<int> arr= {2,7,11,15};
    vector<int> arr= {-1,-2,-3,-4,-5};
    cout<<"\nArray elements are ----\n";
    printArray(arr);

    int target = -8;
    vector<int> res;
    res = twoSum(5,arr,target);
    
    cout<<"\nThe res array is\n";
    printArray(res); 
    return 0;
}