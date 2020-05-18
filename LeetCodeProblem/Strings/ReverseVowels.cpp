#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

string removeVowel(string s){
    set<char> Vowels = {'a','A','e','E','i','I','o','O','u','U'};

    char cstr[s.size() + 1];
	strcpy(cstr, s.c_str());
    //string a;
    int  i = 0;
    int j = s.size()-1;
    while(i<j)
    {
        while(i<j && Vowels.find(i) != Vowels.end()){
            i++;
        }
        while(i<j && Vowels.find(j) != Vowels.end()){
            j--;
        }
        char temp = cstr[i];
        cstr[i++] = cstr[j];
        cstr[j--] = temp;
    }
    return cstr;
//    Vowels.insert
}

int main()
{
    string s = "Maulin";
    cout << removeVowel(s) << endl;
    
}