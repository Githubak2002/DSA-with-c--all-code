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

// is Valid Parenthesis
bool isValidParenthesis(string s)
{
    stack<char> st;
    for (char c : s) {
        if (c == '[' || c == '{' || c == '(') 
            st.push(c);

        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false; 
            char top = st.top();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) 
                    return false; 
            st.pop();
        } else {
            return false; 
        }
    }
    
    return st.empty();
}


// ===================== MEDIUM LEVEL =====================

bool isAlphaNumeric(char c)
{
    return (c>='a' && c<='z' ) || (c>='A' && c<='Z') || (c>='0' && c<='9') ;
}
// check Palindrome considering only alphanumeric characters
bool checkPalindrome(char str[]) 
{
    int len = strlen(str);
    int start = 0,end = len-1;
    while(start<end)
    {
        if(!isAlphaNumeric(str[start]))
            start++;
        else if(!isAlphaNumeric(str[end]))
            end--;
        else if(str[start] == str[end])
        {
            start++;    end--;
        }
        else{
            cout<<"start: "<<start<<endl;
            cout<<"end: "<<end<<endl;
            return false;
        } 
    }
    return true;
}


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
    for(auto c: str)
        mpp[c]++;
    
    for(auto ch: str){
        if(mpp[ch] == 1)
            return ch;
    }
    return '#';
}

// finding the index of Non repeating char
int firstUniqueCharacter(string s , int n) {
	map<char,int> mpp;

    for(auto ch: s)
        mpp[ch]++;
    for (int i = 0; i <= n; i++)
    {
        if(mpp[s[i]] == 1)
            return i;
    }
    return -1;  
}

// length of Longest Substring Without Repeating Characters
int uniqueSubstrings(string input)
{   
    map<char,int> mpp;
    int i = 0,count = 0,maxLen = 0;
    while(i < input.size())
    {
        mpp[input[i]]++;
        if(mpp[input[i]] == 1)
        {
            count++;
            i++;
        }
        else
        {
            maxLen = max(count,maxLen);
            mpp.clear();
            count = 0;
        }
    }
    maxLen = max(count,maxLen);
    return maxLen;    
}

// 451 sort charactes by frequency
string frequencySort(string s)
{
    map<char,int> mpp;
    for(auto ch: s)
        mpp[ch]++;
    
    for (auto x : mpp)
    {
        cout<<x.first<<" appares "<<x.second<<endl;
    }
    return "";
}


 
int main()
{
    cout << "===============\n\n";

  
    // cout << "String: " << removeConsecutiveDuplicates("aabbbcc") << endl;

    string s = "ANURAG";
    bool ans,n = s.size();
    // ans = firstUniqueCharacter(s,n);
    // ans = .llongestPalinSubstring("koabcbal");
    // cout<<ans;


    cout << "\n\n===============";
}





/*  // convert a lower/upper case
    // A = 65,a = 97
    char c = 'c';
    cout << "c: "<< char(c - 32) << endl;
    cout << "B to lowerCase: "<< char('B' + 32) << endl;
    cout << "c to upperCase: "<< char('c' - 32) << endl;

    char str[] = {'a','b','c','b','a','\0'};
    int len = strlen(str);

    float f = static_cast<float>(i);
    str = std::to_string(num);
*/



