#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

vector <int> twoSum(vector <int> &numbers, int target)
{
    map <int,int> m;
    vector <int> v1;

    for(int i = 0; i < numbers.size(); i++){
        int diff = target - numbers[i];
        if(m.find(numbers[i])!=m.end())
        {
            v1.push_back(m[numbers[i]]);
            v1.push_back(i);
            return v1;
        }
        m[diff] = i;
    }
    return {-1,-1};
}

void printVector(vector <int> v1){
    for(auto itr = v1.begin(); itr != v1.end(); itr++){
        cout << *itr <<"," ;
    }
}


int main(){

    vector <int> v1 = {2,3,5,9};
    printVector(twoSum(v1,7));
    return 0;
}