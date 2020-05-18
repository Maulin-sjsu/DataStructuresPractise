#include <iostream>

using namespace std;

bool isPowerofTwo(int n)
{
    if(n == 1)
    {
        return true;
    }
    int number = 1;
    for(int i = 0; i <= n/2; i++)
    {
        number = 2*number;
        if(n == number)
        {
            cout << "Power : " << i+1 << endl;
            return true; 
        }
    }
    return false;
}

int main(){

    int number = 60904940;
    cout << isPowerofTwo(number);
}