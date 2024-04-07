// ========== MAP ==========

/*
MAP - container that stores elements as key-value pairs in an order sorted by the key.

Implementation: It is implemented using a self-balancing Binary Search Tree (BST), like a Red-Black Tree.
Search Time: The search time complexity is O(log n), making it efficient for searching elements.

Use Cases:
When ordered data is needed.
For scenarios where printing/accessing data in sorted order is required.
When predecessor/successor of elements need to be accessed.

unordered_map - container that stores elements as key-value pairs without any specific order of keys by default.

Implementation: It is implemented using a Hash Table, providing O(1) average search time complexity.
Search Time: The average search time complexity is O(1), making it faster than map for large datasets.

*/

#include <bits/stdc++.h>
#include <map>
using namespace std;

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
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

int main()
{
  cout << "\n\n=======================\n\n";

  map<int, int> m1;

  vector<int> arr = {5, 4, 5, 2, 1, 2, 2, 3};
  for (int l = 0; l < arr.size(); l++)
  {
    if (m1[arr[l]] >= 1)
      ++m1[arr[l]];
    else
      m1[arr[l]] = 1;
  }

  for (auto i = m1.begin(); i != m1.end(); i++)
    cout << i->first << " -> " << i->second << '\n';

  cout<<"\n\n";

  unordered_map<string, int> um1;
  vector<string> sarr = {"anupam", "jack", "nuska", "khush", "khush"};

  for (int i = 0; i < sarr.size(); i++)
  {
    if (um1[sarr[i]] >= 1)
      um1[sarr[i]]++;
    else
      um1[sarr[i]] = 1;
  }
  
  for (auto j = um1.begin(); j != um1.end(); j++)
  {
    cout << j->first << " -> " << j->second << "\n";
  }

  cout << "\n\n=======================";
  return 0;
}
