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

vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++){
        int num = nums[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main(){
      cout << "\n\n=======================\n\n";

    // vector<int> arr= {2,7,11,15};
    vector<int> arr= {-1,-2,-3,-4,-5};
    unordered_map<int,int> um1;
    vector<int> ar1 = {4,5,3,2,5,2,4};
    for (int i = 0; i < ar1.size(); i++)
    {
        if(um1[ar1[i]] >= 1) um1[ar1[i]]++;
        else um1[ar1[i]] = 1;
    }

    for (auto mele = um1.begin(); mele != um1.end(); mele++)
    {
        cout<<mele->first<<" -> "<<mele->second<<"\n";
    }   


    cout<<"\nArray elements are ----\n";
    printArray(arr);

    int target = -8;
    vector<int> res;
    res = twoSum(5,arr,target);
    
    cout<<"\nThe res indices are: ";
    printArray(res); cout<<"that give the sum to be -> "<<target<<endl;
    return 0;

  cout << "\n\n=======================";
}