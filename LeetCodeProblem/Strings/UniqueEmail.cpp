#include <iostream>
#include <vector>
#include <set>

using namespace std;

int UniqueAddress(vector<string> v1){
    set <string> s1;
    for(auto itr = v1.begin(); itr != v1.end(); itr++)
    {
        string a;
        string email = *itr;
        for(int i = 0; i <email.size(); i++)
        {
            
            char curr = email.at(i);
            if(curr == '.'){
                continue;
            }else if(curr == '+'){
                while(email.at(i) != '@'){
                    i++;
                }
            }
            a.push_back(curr);
        }
        s1.insert(a);
    }
    return s1.size();
}

int main(){
    vector<string> v1 = {"maulin.bodiwala@gmail","darshil.kapadiya@gmail","maulinbodiwala@gmail","maulinbodiwala+hjdhjdj@gmail"};
    cout << UniqueAddress(v1) << endl;
}
