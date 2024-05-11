#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindrome(const string &str)
{
  int left = 0;
  int right = str.length() - 1;

  while (left < right)
  {
    if (str[left] != str[right])
    {
      return false;
    }
    left++;
    right--;
  }

  return true;
}

void findAllSubPalindromes(const string &str)
{
  vector<string> palindromes;

  for (int i = 0; i < str.length(); i++)
  {
    for (int j = i; j < str.length(); j++)
    {
      string sub = str.substr(i, j - i + 1);
      if (isPalindrome(sub))
      {
        palindromes.push_back(sub);
      }
    }
  }

  cout << "All possible sub-palindrome strings:" << endl;
  for (const string &palindrome : palindromes)
  {
    cout << palindrome << endl;
  }
}

int main()
{
  cout << "\n\n";
  string input;
  cout << "Enter a string: ";
  cin >> input;

  findAllSubPalindromes(input);

  cout << "\n\n";
  return 0;
}