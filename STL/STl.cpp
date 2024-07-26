
#include <bits/stdc++.h>
// #include<cmath>            // pow(x,n);
// #include<algorithm>
using namespace std;

int main()
{
  cout << "\n\n=======================\n\n";

  // === Array and set ===
  int arr[8] = {1,2,3,4,5,3,5,2};
  set<int> set1;

  for (int i = 0; i < 8; i++)
    set1.insert(arr[i]);

  cout<<"Elements of the array:\n";
  for(auto i:arr)
    cout<<arr[i]<<" ";

  cout<<"\n";

  cout<<"Elements of the set:\n";
  for(auto it:set1)
    cout<<it<<" ";
  

  cout << "\n\n=======================";
  return 0;
}
