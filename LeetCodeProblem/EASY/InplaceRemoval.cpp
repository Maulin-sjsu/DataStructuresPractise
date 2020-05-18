#include <iostream>
#include <vector>

using namespace std;

int InplaceRemoval(vector <int> a, int val){
    for(auto itr = a.begin(); itr != a.end(); itr++)
    {
        if(*itr == val)
        {
                    a.erase(itr);
        }
    }
    return a.size();
}

int main(){

    vector <int> v1 = {0,1,2,3,4,5,6,0,7,0,8,0,9};

    cout <<"Size : " <<InplaceRemoval(v1, 0) << endl;
}