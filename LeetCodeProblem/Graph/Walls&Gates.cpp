#include <iostream>
#include <vector>

using namespace std;


void printMatrix(vector<vector<int>> v1){
    
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v1[i].size(); j++)
        {
            cout << v1[i][j] << " ";
        }
    }

}

void dfs(vector<vector<int>> &grid, int i, int j, int count)
{
    if(i < 0 || i>= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] <count)
    {
        return;
    }
    grid[i][j] = count;
   // cout << count << " ";
    dfs(grid,i+1,j,count+1);
    dfs(grid,i-1,j,count+1);
    dfs(grid,i,j+1,count+1);
    dfs(grid,i,j-1,count+1);


}

vector<vector<int>> walls_Gates(vector<vector<int>> &grid)
{
    for(int i =0; i< grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++)
        {
            if(grid[i][j] == 0)
            {
                dfs(grid, i ,j, 0);
            }
        }
    }
    return grid;
}


int main(){
    vector<vector<int>> v1 = {{8,-1,0,8},{8,8,8,-1},{8,-1,8,-1},{0,-1,8,8}};
    printMatrix(walls_Gates(v1));
}

