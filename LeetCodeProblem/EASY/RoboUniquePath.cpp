#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n)
{
    vector<vector<int>> dq(m , vector<int> (n, 0));
    dq[0][0] = 0;

    for(int i = 0; i< dq.size(); i++)
    {
        dq[i][0] = 1;
    }
    for(int i = 0; i< dq[0].size(); i++)
    {
        dq[0][i] = 1;
    }
    for(int i = 1; i<dq.size(); i++){
        for(int j = 1; j<dq[i].size(); j++)
        {
            dq[i][j] = dq[i-1][j] + dq[i][j-1];
        }
    }
    return dq[m-1][n-1];
}

int main(){
    cout << uniquePaths(3,4) << endl;
}