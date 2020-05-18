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

void fill(vector<vector<int>> &image,int i, int j, int currColor,int newColor){
    if(i < 0 || i >= image.size() || j < 0 || j >= image[i].size() || image[i][j] != currColor)
    {
        return;
    }
    image[i][j] = newColor;
    fill(image, i+1, j, currColor ,newColor);
    fill(image, i-1, j, currColor ,newColor);
    fill(image, i, j+1, currColor ,newColor);
    fill(image, i, j-1, currColor ,newColor);
}

vector<vector<int>> floodfill(vector<vector<int>> &image,int sr, int sc,int newColor){
    if(image[sr][sc] == newColor)
    {
        return image;
    }
    //cout << image[sr][sc] << newColor << endl;
    fill(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main(){
    vector<vector<int>> v1 = {{1,1,1},{1,1,0},{1,0,1}};
    printMatrix(floodfill(v1,1,1,2));
}