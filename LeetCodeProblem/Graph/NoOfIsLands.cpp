#include<iostream>
#include <vector>

using namespace std;


void printMatrix(vector<vector<char>> v1){
    
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
    }

}

int dfs(vector<vector<char>> &grid, int i, int j){
    if(i < 0 || i >= grid.size() || j < 0 || j>=grid[i].size() || grid[i][j] == '0' ){
        return 0;
    }
    grid[i][j] = '0';
    //cout << " + ";
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);
    return 1;
}

int numofIslands(vector<vector<char>> &grid){
    if(grid.size() == 0){
        return 0;
    }
    int numOfIslands =0;
    for(int i =0; i<grid.size(); i++)
    {
        for(int j = 0; j< grid[i].size(); j++)
        {
            //cout << "--";
            if(grid[i][j] == '1'){
                numOfIslands += dfs(grid,i,j);
               // cout << numOfIslands;
            }
        }
    }
    return numOfIslands;
}


int main(){
    vector<vector<char>> v1 = {{'1','1','1'},{'1','1','0'},{'1','0','1'}};
    cout << numofIslands(v1) << endl;
}
