#include <iostream>
#include <vector>
#include <queue>
#include <math.h>  

using namespace std; 

int minSum(vector <int> v1, int k)
{
    priority_queue <int, vector<int>, less<int> > pq;
    int sum = 0;
    for(auto itr = v1.begin(); itr != v1.end(); itr++){
        pq.push(*itr);
    }
    for(int i = 0; i< k; i++)
    {
    
        //int a;
        float a = pq.top();
        pq.pop();
        int b  = ceil(a/2);
        
        pq.push(b); 
    }

    while(!pq.empty())
    {
        cout << pq.top();
        sum = sum + pq.top();
        pq.pop();
    } 
    return sum;
}

int main()
{
    vector<int> v1 = {3,5,7,15};
    cout << minSum(v1,2);
}