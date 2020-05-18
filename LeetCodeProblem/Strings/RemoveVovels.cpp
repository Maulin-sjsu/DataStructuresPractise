#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string removeVowel(string s){
    set<char> Vowels = {'a','A','e','E','i','I','o','O','u','U'};
    string a;
    for(int i = 0; i<s.size(); i++)
    {
        char curr = s.at(i);
        if(Vowels.find(curr) == Vowels.end()){
            a.push_back(curr);
        }
    }
    return a;
//    Vowels.insert
}

int main()
{
    string s = "Maulin";
    cout << removeVowel(s) << endl;
}