#include <iostream>
#include <vector>
#include <iterator>
#include <math.h>

using namespace std;

int rainTappingWater(vector <int> v1)
{
    int n = v1.size();
    vector <int> start(n);
    vector <int> end(n);
    
    start[0] = v1[0];
    for(int i = 1; i <n; i++)
    {
        start[i] = fmax(v1[i], start[i-1]);
    }

    end[n-1] = v1[n-1]; 
    for(int j = n-2; j >= 0; j--)
    {
        end[j] = fmax(end[j+1],v1[j] );
    }

    int water = 0;
    for(int i = 0; i<n; i++){
        water += fmin(start[i], end[i])- v1[i];
    }
    return water;
}



int main()
{
    vector <int> v1 = {1,2,3};
    cout << rainTappingWater(v1) << endl;
}
