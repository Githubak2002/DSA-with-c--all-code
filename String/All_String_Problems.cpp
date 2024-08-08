#include <bits/stdc++.h>
#include <algorithm> // tolower
#include <cctype>    // For std::tolower
#include <string>
using namespace std;

// is string palindrom - [abC gHG cBA] ?

// converting a string to lower case
string strToLowerCase(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
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

// replacing spaces with xyz
string replaceSpaces(string str){
	string ans = "";
	for(int i=0;i<str.size();i++)
	{
		if(str[i] == ' ')
			ans = ans + "@40";
		else
		ans.push_back(str[i]);
	}
	return ans;
}



// ===================== MEDIUM LEVEL =====================


// check Palindrome ignoring case sensitive and special char

// finding longest Palindrom Substring
string longestPalinSubstring(string s) {
    if(s.length() <= 1) return s;

    int n = s.length(),maxLen = 1,start=0;

    int left,right;
    for (int i = 0; i < n; i++)
    {
        left = i;   right = i;
        while(left>=0 && right<n && s.at(left) == s.at(right))
        {
            right++;
            left--;
        }
        if(maxLen < right-left-1)
        {
            maxLen = right-left-1;
            start = left+1;
        }

        left = i,right = i+1;
        while(left>=0 && right<n && s.at(left) == s.at(right))
        {
            right++;
            left--;
        }
        if(maxLen < right-left-1)
        {
            maxLen = right-left-1;
            start = left+1;

        }
    }
    
    return s.substr(start, maxLen);
}

// str = "Hello Ak" return "AK Hello"
string reverseString(string &str){
    stack<string> words;  // Stack to store words
    string temp;          // To store the current word
    string ans;           // To store the final reversed sentence
    for (char c : str)   
    {
        if (c != ' ')
            temp += c;
        else if (!temp.empty()) 
        {
            words.push(temp);                   
            temp.clear();                       
        }                                       

    }
    if (!temp.empty()) 
		words.push(temp);

    // Construct the reversed str from the stack
    while (!words.empty()) 
    {
        ans += words.top() + ' ';
        words.pop();
    }

    // Remove any leading space in the result
    if (!ans.empty() && ans[0] == ' ') 
        ans.pop_back();

    return ans;
}

// finding the first Non repeating char
char findNonRepeating(string str) {
    unordered_map<char,int> mpp;
    for (int i = 0; i <= n; i++)
    {
        mpp[i]
    }
    
        mpp[c]++;
    
    for(auto ch: str){
        if(mpp[ch] == 1)
            return ch;
    }
    return '#';
}

// finding the index of Non repeating char
int firstUniqueCharacter(string s , int n) {
	map<int,int> mpp;
    for (int i = 1; i <= n; i++)
    {
        mpp[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if(mpp[i]==1)
            return i;
    }
    

}





int main()
{
    cout << "===============\n\n";
    

    // cout << "String: " << removeConsecutiveDuplicates("aabbbcc") << endl;

    char ans;
    ans = findNonRepeating("cbbd");
    // ans = longestPalinSubstring("koabcbal");
    cout<<ans;

    cout << "\n\n===============";
}





/*  // convert a lower/upper case
    // A = 65,a = 97
    char c = 'c';
    cout << "c: "<< char(c - 32) << endl;
    cout << "B to lowerCase: "<< char('B' + 32) << endl;
    cout << "c to upperCase: "<< char('c' - 32) << endl;
*/



