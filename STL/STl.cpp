
#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

// finding the majority ele using map [not optimal]
int majorityElementUsingMap(vector<int> v)
{
  map<int, int> mp;
  for (int i = 0; i < v.size(); i++)
  {
    mp[v[i]]++;
  }
  for (auto it : mp)
  {
    if (it.second > v.size() / 2)
      return it.first;
  }
  return -1;
}

int main()
{
  cout << "\n\n=======================\n\n";

  // ================= Array and SET =================
  vector<int> arr = {1, 2, 3, 4, 5, 3, 5, 2};
  set<int> set1;

  for (int i = 0; i < arr.size(); i++)
    set1.insert(arr[i]);

  cout << "Ele in the array:\n";
  for (int i=0;i<arr.size(); i++)
    cout << arr[i] << " ";
  cout << "\n";
  cout << "Ele in the set:\n";
  for (auto it : set1)
    cout << it << " "; 
  cout<<"\n\n\n";

  // ================= MAP =================

  // MAP (by default assending order, 0 to 1/a to z)  
  // TC - O(logn) for Insertion/Deletion/Search/Access by Key

  map<string, int> ageMap;

  ageMap["Alice"] = 30;
  ageMap["Bob"] = 25;
  ageMap["Charlie"] = 35;

  for (const auto& pair : ageMap) {
      cout << pair.first << ": " << pair.second << endl;
  }
  // cout << "Bob's age: " << ageMap["Bob"] << endl;


  // unordered_map (no specific order)
  // TC - Average case O(1), but worst case O(n)


  cout << "\n\n=======================";
  return 0;
}
