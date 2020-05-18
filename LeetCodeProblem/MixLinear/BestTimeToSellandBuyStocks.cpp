#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>


using namespace std;

int maxProfit(vector <int> v1)
{
    int max = 0;
    int min = INT8_MAX;
    for(auto itr = v1.begin(); itr != v1.end(); itr++)
    {
        if(*itr < min)
        {
            min = *itr;
        }
        else{
            max = fmax(max, *itr - min); 
        }
    }
    return max;
}

int main()
{
    vector <int> v1 = {7,19,1,5,3,6,4};
    cout << "Maximum Profit : " << maxProfit(v1) << endl;
}