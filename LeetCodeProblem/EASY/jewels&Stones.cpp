#include <iostream>
#include <string>
#include <set>

using namespace std;

int jewel_Stones(string j, string s)
{
    set<char> s1;
    int jewelsfound = 0;
    for(int i = 0; i< j.size(); i++)
    {
        char curr = j.at(i);
        s1.insert(curr);
    }
    for(int  i = 0; i< s.size(); i++)
    {
        char curr = s.at(i);
        if(s1.find(curr) != s1.end()){
            jewelsfound++;
        }
    }
    return jewelsfound;
}


int main(){
    string a = "abc";
    string b = "abcbcaabcdddddddd";

    cout << jewel_Stones(a,b) << endl;
}