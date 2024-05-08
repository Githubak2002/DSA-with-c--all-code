// RECURSION - string palindrom?
#include <bits/stdc++.h>
using namespace std;

// print arr ele
void printarray(vector<int> arr)
{
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  cout << endl;
}

// REVERSE AN ARRAY
void reverseArr(int arr[], int start, int end)
{
  if (start >= end)
    return;

  swap(arr[start], arr[end]);
  reverseArr(arr, start + 1, end - 1);
}

// CHECK IF STRING IS PALINDROM
bool isPalindrom(string s, int i)
{
  if (i >= s.length() / 2)
    return true;

  if (s[s.length() - i - 1] != s[i])
    return false;
  return isPalindrom(s, ++i);
  // isPalindrom(s, ++i);
}

// Nth FIBONACII NO - 0th index - complexity nearby (2^n)
int fibonacii(int n)
{
  if (n <= 1)
    return n;

  int last = fibonacii(n - 1);        // first called
  int second_last = fibonacii(n - 2); // second called
  return last + second_last;
  // return fibonacii(n-1)*fibonacii(n-2);
}

int main()
{
  cout << "\n\n";

  string s = "abcdcba";
  int len = s.length();
  cout << "is '" << s << "' palindrom = " << isPalindrom(s, 0) << endl;

  int nth = 5;
  cout << nth << " Fibonacci no is = " << fibonacii(nth) << endl;
  cout << "\n\n";
  return 0;
}
