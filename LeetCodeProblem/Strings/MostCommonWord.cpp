#include<bits/stdc++.h> 
#include <sstream>

using namespace std;

string mostCommonWord(string para, vector<string> banned)
{
    set<string> s1;
    for(int i = 0; i<banned.size(); i++)
    {
        s1.insert(banned[i]);
        //cout << "banned Word : " << banned[i] << endl; 
    }
    map <string, int> m1;

// To convert string to the lowercase / Uppercase we use transform
    transform(para.begin(), para.end(), para.begin(), ::tolower);

    stringstream str_strm(para);
    string tmp;
     while (str_strm >> tmp) {
         
         if( s1.find(tmp) == s1.end()){
             if(m1.find(tmp) == m1.end()){
                //cout <<" Entered Word : "<< tmp << endl;
                 m1[tmp] = 1;
                 }
                 else{
                    //cout << "Increasing count for : " << tmp << endl;
                     m1[tmp] += 1;
                     }
            }
            //cout << "Not Entered Word : " << tmp << endl;
        }
        int c = INT8_MIN;
        string s ;
    for(auto itr = m1.begin(); itr != m1.end(); itr++){
        cout << itr->first << " => " << itr->second << endl;
        if(itr->second > c)
        {
            c = itr->second;
            s = itr->first;
        }
    }
    cout << c <<endl;
    return s;
}


int main(){

    string a = "Maulin Bodiwala Maulin Bodiwala Maulin bhai bhai bhai oooo bhai";
    vector<string> b = {"maulin","bodiwala"};

    cout << mostCommonWord(a,b) << endl;

    
}