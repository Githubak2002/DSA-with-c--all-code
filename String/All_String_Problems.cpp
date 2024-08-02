#include <bits/stdc++.h>    
#include <algorithm>    // tolower
#include <cctype>   // For std::tolower
#include <string>   
using namespace std;



// converting a string to lower case
string strToLowerCase(string s){
    transform(s.begin(),s.end(),s.begin(), ::tolower);
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

int main()
{
    cout << "===============\n\n";

    cout << "String: " << removeConsecutiveDuplicates("aabbbcc") << endl;

    string s = "ThIS is A STRING";
    cout << "String: " << strToLowerCase(s) << endl;



    /* //  convert a upper case to lowe case 
    int v1 = 65;
    int v2 = 97;
    cout << "v1: "<< v1 << " = "<< char(v1) << endl;    // 65 = A
    cout << "v2: "<< v2 << " = "<< char(v2) << endl;    // 97 = a
    */








    cout << "\n\n===============";
}
