#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    vector <int> v1 = {4,7,9,7,8,5,4,1,3,2};

    set <int ,greater<int>> s1;
    set <int , less<int>> s2;

    for(int i = 0; i <v1.size(); i++)
    {
        if(s1.find(v1[i]) == s1.end()){
            s1.insert(v1[i]);
        }else{
            cout << "Number " << v1[i] << " is getting dupicated at position: " << i <<endl;
        }
    }
}