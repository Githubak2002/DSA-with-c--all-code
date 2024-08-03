#include <bits/stdc++.h>    
#include <algorithm>    // tolower
#include <cctype>   // For std::tolower
#include <string>   
using namespace std;

// is string palindrom - [abC gHG cBA] ?

// Beautiful String - problem
// min no of oprations needed to make string beautiful 
int makeBeautiful(string str) {
	int count = 0,len = str.length()-1;

    char startChar = str[0];
    char nxtChar;
    if(startChar == '0')
        nxtChar = '1';
    else
        nxtChar = '0';

	for(int i=1;i<len;i++){
        if(str[i] != nxtChar)
            count++;

        if(nxtChar == '0')
            nxtChar = '1';
        else
            nxtChar = '0';
        
    }
    return count;
		
}


// converting a string to lower case
string strToLowerCase(string s){
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    return s;
}

// capitalize the string [first letter of each word to uppercase]
string convertString(string str) 
{
	string ans = "";
    if(str[0] != ' '){
        char ch = char(str[0]-32);
        ans.push_back(ch);
    }
    int i = 1;
    while(i<str.length()){
        if(str[i] == ' '){
            ans.push_back(' ');
            i++;
            char c = char(str[i++]-32);
            ans.push_back(c);
        }
        else    ans.push_back(str[i++]);
    }
    return ans;
}



// Reverse Words in a String - this is → is this
string reverseWords(string s)
{
    int n = s.length();
    string ans = "";
    string word = "";
    int i = 0;
    reverse(s.begin(),s.end());
    while(i<n)
    {
        if(s[i] == ' ')
            i++;
        else{
            while(i<n && s[i] != ' ')
            {
                word.push_back(s[i++]);
            }
            reverse(word.begin(),word.end());
            ans = ans + word + " ";
            word = "";
        }
    }
    ans.pop_back();
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
    cout<<rev(" this is a string  ");




    cout << "\n\n===============";
}
