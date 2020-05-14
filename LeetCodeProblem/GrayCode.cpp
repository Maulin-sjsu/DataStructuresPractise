#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector<int> grayCode(int n){
    vector <int> v1;
    for(int i =0; i< 1<<n; i++){
        //Formulae for finding the gray code 
        // i EXOR i>>1(right shifting number --> dividing number by 2)
        v1.push_back(i ^ i>>1);    
    }
    return v1;
} 

void printVector(vector <int> v1)
{
    for(auto itr  = v1.begin(); itr != v1.end(); itr++){
        cout << *itr << " ";
    }
}


int main()
{
    int a = 5;
    printVector(grayCode(3));
    
}