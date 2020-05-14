#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
    map <int, int> m;
    m.insert(pair<int, int>(0,10));
    m.insert(pair<int, int>(1,20));
    m.insert(pair<int, int>(2,40));
    for(auto itr = m.begin(); itr != m.end(); itr++)
    {
        cout << "value of key : " << itr->first << " value : " << itr->second << endl;
    }

    for(int i =0; i< m.size(); i++ )
    {
        //cout << "value : " << m[i]  << endl;
        m.erase(i);
        cout << "value : " << m[i]  << endl;
    }
    
    cout << m.size() << endl;


    m.clear();

    cout << m.empty() << endl;

}