#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int firstUniqueChar(string s)
{
    map <char, int> m1;
    int min = INT8_MAX;
    for(int i = 0; i < s.size(); i++)
    {
        char curr  = s.at(i);
        if(m1.find(curr) == m1.end()){
            m1[curr] = i;
        }else{
            m1.erase(curr);    
        }
    }
    for(auto itr = m1.begin(); itr != m1.end(); itr++)
    {
        min = fmin(itr->second,min);
    }
    return min;
}

int main(){
    string s  = "aaulin";
    cout << firstUniqueChar(s) << endl; 
}