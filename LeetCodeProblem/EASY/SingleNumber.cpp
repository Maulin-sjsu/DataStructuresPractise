#include <iostream>
#include <vector>
#include <set>

using namespace std;

int SingleNo(vector <int> v1){
    set <int> s1;
    for(int i =0; i<v1.size(); i++)
    {
        if(s1.find(v1[i]) == s1.end())
        {
            s1.insert(v1[i]);
        }else{
            s1.erase(v1[i]);
        }
    }

    for(auto itr = s1.begin(); itr!= s1.end(); itr++)
    {
        return *itr;
    }
    return -1;
}

int main(){
    vector <int> v1 = {2,4,2,4,8,2,8,5,2,5,4};

    cout << SingleNo(v1);

}
