#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>
#include <regex>

using namespace std;

int main()
{
    // 1. Basic String Operations
    string s1 = "Hello";
    string s2 = "World";

    // Concatenation
    string s3 = s1 + " " + s2; // "Hello World"

    // Length and Empty Check
    size_t len = s3.size(); // or s3.length()
    bool isEmpty = s3.empty();

    cout << "String: " << s3 << ", Length: " << len << ", Is Empty: " << boolalpha << isEmpty << endl;

    // 2. Accessing Characters
    char firstChar = s3[0];     // Access first character
    char secondChar = s3.at(1); // Access second character, with bounds checking

    cout << "First character: " << firstChar << ", Second character: " << secondChar << endl;

    // 3. SUBSTRING and Finding
    string substr = s3.substr(6, 5); // Extract "World" - (pos and size)
    size_t pos = s3.find("World");   // Find position of "World"

    cout << "Substring: " << substr << ", Position of 'World': " << pos << endl;

    // 4. Modifying Strings
    s3.append("!");               // Append "!"
    s3.insert(5, ",");            // Insert "," at position 5
    s3.replace(6, 5, "Universe"); // Replace "World" with "Universe"
    s3.erase(5, 1);               // Erase "," at position 5

    cout << "Modified String: " << s3 << endl;

    // 5. Case Conversion
    transform(s3.begin(), s3.end(), s3.begin(), ::tolower); // Convert to lowercase
    cout << "Lowercase: " << s3 << endl;
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper); // Convert to uppercase
    cout << "Uppercase: " << s3 << endl;

    // 6. Trimming (Custom Implementation Required)
    // Implement custom trimming function or use a library

    // 7. Searching and Matching
    size_t foundPos = s3.find("UNIVERSE");
    if (foundPos != string::npos)
    {
        cout << "'UNIVERSE' found at position: " << foundPos << endl;
    }

    // Regular Expressions (Pattern Matching)
    regex re("WORLD");
    smatch match;
    if (regex_search(s3, match, re))
    {
        cout << "Pattern 'WORLD' found" << endl;
    }

    // 8. Comparing Strings
    string s4 = "HELLO WORLD";
    bool isEqual = (s3 == s4);
    int compareResult = s3.compare(s4); // Returns <0 if s3 < s4, 0 if equal, >0 if s3 > s4

    cout << "Are strings equal? " << boolalpha << isEqual << endl;
    cout << "Comparison result: " << compareResult << endl;

    // 9. Sorting and Reversing
    string s5 = "dcba";
    sort(s5.begin(), s5.end());    // Sort characters in ascending order
    reverse(s5.begin(), s5.end()); // Reverse the sorted string

    cout << "Sorted and Reversed String: " << s5 << endl;

    // 10. Iterating Over Strings
    cout << "Iterating over string: ";
    for (char ch : s4)
    {
        cout << ch << " ";
    }
    cout << endl;

    // 11. Advanced Operations

    // Splitting Strings
    auto split = [](const string &s, char delimiter)
    {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter))
        {
            tokens.push_back(token);
        }
        return tokens;
    };

    vector<string> tokens = split("Hello,World,How,Are,You", ',');
    cout << "Split Tokens: ";
    for (const auto &token : tokens)
    {
        cout << token << " ";
    }
    cout << endl;

    // Joining Strings
    auto join = [](const vector<string> &v, char delimiter)
    {
        ostringstream joined;
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            if (it != v.begin())
            {
                joined << delimiter;
            }
            joined << *it;
        }
        return joined.str();
    };

    string joinedString = join(tokens, '-');
    cout << "Joined String: " << joinedString << endl;

    // whiteSpace
    string s6 = "   Hello   ";
    if (isspace(s6[0]))
        cout << "WhiteSpace";

    return 0;
}


