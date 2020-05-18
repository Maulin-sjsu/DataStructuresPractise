#include <iostream>
#include <vector> 
#include <math.h>


using namespace std;

int maxArea(vector <int> v1)
{
    int max = INT8_MIN;
    for(int i =0; i <v1.size(); i++)
    {
        for(int j = i+1; j < v1.size(); j++)
        {
            int min = fmin(v1[i],v1[j]);
            max = fmax(max,min*(j-i));
        }
       // cout << max <<endl;
    }
    return max;
}

int main(){
    vector <int> v1 = {1,8,6,2,5,4,8,3,7};
    
    cout << maxArea(v1) << endl;
}