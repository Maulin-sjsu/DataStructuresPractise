#include <iostream>
#include <vector>

using namespace std;

// Bottom UP - DP (Dynamic Programming Question:)

int climbstairs(int n){
    vector <int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}

int main(){
    cout << "No of Ways : " << climbstairs(1);
}