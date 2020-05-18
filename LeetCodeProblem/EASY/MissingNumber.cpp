#include<iostream>
#include <vector>
#include <set>

using namespace std;
// with No extra space : -----------------------------------------
int findMissingNum(vector <int> v1){
    int sum = 0;
    for(int i = 0; i< v1.size(); i++){
        sum += v1[i];
    }    
    int n = v1.size()+1;
    return (n*(n-1)/2) - sum;
}

// with extra space using Set : ----------------------------------
int findMissingNumwithSet(vector<int> v1){
    set <int,less <int> > s1;

    for(int i = 0; i < v1.size(); i++)
    {
        s1.insert(v1[i]);
    }

    for(int i = 0; i < s1.size(); i++)
    {
        if(s1.find(i) == s1.end()){
            return i;
        }
    }
    return -1;
}

int main(){

    vector <int> v1  = {0,1,2,3,4,6,7,8,9};
    cout << findMissingNum(v1) << endl;

    cout << "With Extra Space : " <<findMissingNumwithSet(v1);
}