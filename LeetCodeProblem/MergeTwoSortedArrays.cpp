#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> v1){
    for(int i = 0; i< v1.size(); i++)
    {
        cout << v1[i];
    }
}

void MergeTwoSortedArrays(vector<int> v1, vector<int> v2)
{
    vector <int> fv;
    int i =0;
    int j =0; 
    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] < v2[j])
        {
            //v2.pop_back();
            //cout << v1[j] << endl;
            fv.push_back(v1[i]);
            i++;
        }
        else
        {
            //cout << v2[j] << endl;
            fv.push_back(v2[j]);
            j++;
        }
    }
    if(i < v1.size())
    {
        fv.push_back(v1[i]);
        i++;
    }
    if(j < v2.size())
    {
        fv.push_back(v2[j]);
        j++;
    }
    printVector(fv);
}

int main(){

    vector <int> v1 = {1,3,5,7};
    vector <int> v2 = {2,4,6,8};

    MergeTwoSortedArrays(v1,v2);
}