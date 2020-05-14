#include <iostream>
#include <iterator>
#include <vector>


using namespace std;

void printVector(vector <int> v1){

    for(auto itr = v1.begin(); itr != v1.end(); ++itr)
    {
        cout << *itr << " " ;
    }
    cout << endl;
}

void printVector2(vector <int> v1){

    for(int i = 0; i <v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}


void printReverseVector(vector <int> v1){

    for(auto itr = v1.rbegin(); itr != v1.rend(); ++itr)
    {
        cout << *itr << " " ;
    }
    cout << endl;
}

int main(){

    vector <int> v1 = {-1,-1};
    printVector2(v1);
    // v1.push_back(5);
    // v1.push_back(10);
    // v1.push_back(15);
    // v1.push_back(20);

    printVector(v1);
    cout << endl;
    printVector2(v1);
    cout << endl;
    printReverseVector(v1);
    cout << endl;
    cout << "Size of the Vector: " << v1.size() << endl;
    cout << "Maximum size of the Vector: " << v1.max_size() << endl;
    cout << "Capacity of the Vector: " << v1.capacity() << endl;
    cout << "Is vector Empty : " << v1.empty() << endl;
}
