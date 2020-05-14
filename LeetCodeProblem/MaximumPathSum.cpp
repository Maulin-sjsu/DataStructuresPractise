#include <iostream>
#include <vector>
//#include <string>
#include <math.h>

using namespace std;


struct Node
{  
    int data;
    struct Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void PrintStrings(vector<vector<int>> v1){
    int maxPatheSum = INT8_MIN;
    for(auto itr = v1.begin();itr != v1.end(); itr++)
    {
        vector<int> tmp = *itr;
        int sum = 0;
        for(auto itr2 = tmp.begin();itr2 != tmp.end(); itr2++)
        {
            sum = sum + *itr2;
            cout << *itr2 << " ";
        }
        cout << endl;
        maxPatheSum = max(maxPatheSum,sum);
    }
    cout << "Maximum Path Sum : " << maxPatheSum; 
}

void dfs(Node* node, vector<int> path ,vector<vector<int>> &v1){
    
    path.push_back(node->data);
    cout << node->data << endl;
    if(node->left == NULL && node->right == NULL){
        v1.push_back(path);
        return;
    }
    if(node->left != NULL){
        dfs(node->left, path, v1);
    }
    if(node->right != NULL){
        dfs(node->right, path, v1);
    }
}


vector <vector<int>> BinaryTreePaths(Node* node){
    vector <vector<int>> v1;
    vector  <int> path;
    if(node == NULL){
        return v1;
    }
    dfs(node,path ,v1);
    //PrintStrings(v1);
    return v1;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

   // vector<string> v1 = {"Maulin", "Bodiwala"};

    PrintStrings(BinaryTreePaths(root));
    //PrintStrings(v1);
}