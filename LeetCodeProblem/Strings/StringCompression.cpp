#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compressString(vector<char> v1)
{
    int index = 0;
    int i = 0;
    while(i< v1.size()){
        int j = i;
        while(j <v1.size() && v1[j] == v1[i]){
            j++;
        }
        v1[index++] = v1[i]; 
        //index++;
        
        if(j-i > 1){
            string num = to_string(j-i);
            for(auto ch : num) { v1[index++] = ch; }
        }
        i = j;
    }
    
    return index;
}

int main(){

    vector <char> v1  = {'a','a','b','b','b','b','b','d','d','d','d','e','e','e'};
    cout << compressString(v1) << endl;
}