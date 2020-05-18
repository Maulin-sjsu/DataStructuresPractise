#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int KthLargestElement(vector <int> v1, int k)
{
    priority_queue <int, vector <int> , greater<int>> pq;

    for(auto itr = v1.begin(); itr!= v1.end(); itr++){
        pq.push(*itr);
    }   
    int a;
    for(int i =0; i < k; i++)
    {
        a = pq.top();
        cout << " No "<< i << "element is getting popoed :" << a << endl; 
        pq.pop();
    }
    return a;
}

int main(){
    vector<int> v1 = {12,7,29,6,89,78,5,65,34,80,99};
    cout << KthLargestElement(v1,7) << endl;

}