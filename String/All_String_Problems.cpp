#include <bits/stdc++.h>
#include <algorithm> // tolower
#include <cctype>    // For std::tolower
#include <string>
using namespace std;

// is string palindrom - [abC gHG cBA] ?

// Beautiful String - problem - min no of oprations needed to make string beautiful
int makeBeautiful(string str)
{
    int n = str.size();
    int cnt1 = 0;
    int cnt2 = 0;
    char ch1 = '0';
    char ch2 = '1';
    for (int i = 0; i < n; i++)
    {
        if (ch1 != str[i])
            cnt1++;
        if (ch2 != str[i])
            cnt2++;
        char ch = ch1;
        ch1 = ch2;
        ch2 = ch;
    }
    int ans = min(cnt1, cnt2);
    return ans;
}

// converting a string to lower case
string strToLowerCase(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// capitalize the string [first letter of each word to uppercase]
string convertString(string str)
{
    string ans = "";
    if (str[0] != ' ')
    {
        char ch = char(str[0] - 32);
        ans.push_back(ch);
    }
    int i = 1;
    while (i < str.length())
    {
        if (str[i] == ' ')
        {
            ans.push_back(' ');
            i++;
            char c = char(str[i++] - 32);
            ans.push_back(c);
        }
        else
            ans.push_back(str[i++]);
    }
    return ans;
}

// Does each leter of s appares in t?
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

// Reverse Words in a String - this is → is this
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    string word = "";
    int i = 0;
    reverse(s.begin(), s.end());
    while (i < n)
    {
        if (s[i] == ' ')
            i++;
        else
        {
            while (i < n && s[i] != ' ')
            {
                word.push_back(s[i++]);
            }
            reverse(word.begin(), word.end());
            ans = ans + word + " ";
            word = "";
        }
    }
    ans.pop_back();
    return ans;
}

// check Palindrome ignoring case sensitive and special char


string replaceSpaces(string str){
	string ans = "";
	for(int i=0;i<str.size();i++)
	{
		if(str[i] == ' ')
		{
			ans = ans + "@40";
		}
		else
		ans.push_back(str[i]);
	}
	return ans;
}

// removing repating char
string removeConsecutiveDuplicates(string input)
{
    string s = "";
    int i;
    for (i = 0; i < input.length() - 1; i++)
    {
        if (input[i] == input[i + 1])
            continue;
        s.push_back(input[i]);
    }
    if (s[s.length() - 1] != input[i])
        s.push_back(input[i]);
    return s;
}

int main()
{
    cout << "===============\n\n";

    // cout << "String: " << removeConsecutiveDuplicates("aabbbcc") << endl;

    /* //  convert a lower/upper case
    // A = 65,a = 97
    char c = 'c';
    cout << "c: "<< char(c - 32) << endl;
    cout << "B to lowerCase: "<< char('B' + 32) << endl;
    cout << "c to upperCase: "<< char('c' - 32) << endl;
    */

    //    cout<<convertString("this is a string");

    // int ans = checkPalindrome("N2 i&nJA?a& jnI2n");
    // cout << "ans: " << ans;

    string s;
    s = replaceSpaces("ab c d e");
    cout<<s;

    // string s =" $^";
    // int j = 0;
    // if(s[j] >= 'A' && s[j] <= 'Z' && s[j] >= 'a' && s[j] <= 'z' )
    //     cout<<"Special";

    cout << "\n\n===============";
}
