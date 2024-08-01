#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveDuplicates(string input)
{
    string s="";
    int i;
    for(i=0;i<input.length()-1;i++){
        if(input[i]==input[i+1])
            continue;
        s.push_back(input[i]);

    }
    if(s[s.length()-1] != input[i])
        s.push_back(input[i]);
    return s;
}


int main(){
  cout<<"===============\n\n";

  cout<<"String: "<<removeConsecutiveDuplicates("aabbbcc")<<endl;

  cout<<"\n\n===============";
}
