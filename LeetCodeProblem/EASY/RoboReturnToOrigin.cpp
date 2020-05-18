#include <iostream>
#include <vector>

using namespace std;

bool isRoboatOrigin(vector <char> v1){
    int UD = 0;
    int LR = 0;
    for (int i = 0; i <v1.size(); i++)
    {
        if(v1[i] == 'U')
        {
            UD++;
        }else if(v1[i] == 'D'){
            UD--;
        }else if(v1[i] == 'L'){
            LR++;
        }else if(v1[i] == 'R'){
            LR--;
        }
    }
    return (UD == 0 && LR == 0);
}

int main(){
    vector <char> v1 = {'U','D','D','U'};
    cout << "Is Robot at Origin : " << isRoboatOrigin(v1);
}