#include <iostream>
#include <vector>
#include <string>

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

void PrintStrings(vector<string> v1){
    for(auto itr = v1.begin();itr != v1.end(); itr++){
        cout <<  *itr << endl;
    }
}

void dfs(Node* node, string path, vector<string> &v1){
    
    path += char(node->data);
    //cout << path << endl;
    if(node->left == NULL && node->right == NULL){
        v1.push_back(path);
        return;
    }
    if(node->left != NULL){
        dfs(node->left, path + "->", v1);
    }
    if(node->right != NULL){
        dfs(node->right, path + "->", v1);
    }
}


vector <string> BinaryTreePaths(Node* node){
    vector <string> v1;
    if(node == NULL){
        return v1;
    }
    dfs(node, "", v1);
    //PrintStrings(v1);
    return v1;
}


int main(){
    Node* root = new Node('1');
    root->left = new Node('2');
    root->right = new Node('3');
    root->left->left = new Node('4');
    root->left->right = new Node('5');
    root->right->left = new Node('6');
    root->right->right = new Node('7');

    vector<string> v1 = {"Maulin", "Bodiwala"};

    PrintStrings(BinaryTreePaths(root));
    //PrintStrings(v1);
}