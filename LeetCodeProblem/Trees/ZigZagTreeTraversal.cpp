// #include <iostream>
// #include <queue>
// #include <algorithm>

#include<bits/stdc++.h> 

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

vector <vector<int>> zigZagTraversal(Node *node){
    
    vector <vector<int>> v1;
    if(node == NULL){
        return v1;
    }
    
    
    queue <Node*> q;
    q.push(node);
    int level = 0;

    while(!q.empty())
    {
        
        int count = q.size();
        vector <int> tmp;
        while(count != 0)
        {
            Node *node = q.front();
            q.pop();
            tmp.push_back(node->data);

            if(node->left != NULL){
                q.push(node->left);
            }
            if(node->right != NULL){
                q.push(node->right);
            }
            count --;
        }
       
        if(level % 2 == 1)
        {
            reverse(tmp.begin(),tmp.end());
        }
        v1.push_back(tmp);
        level++;
    }
    return v1;
}

void printVector(vector <vector<int>> v1){
    for(unsigned int i = 0; i < v1.size(); i++){
        for(unsigned int j = 0; j <v1[i].size(); j++)
        {
            cout << v1[i][j] << " " ;
        }
    }
}

int main(){
    Node *root = new Node(1);            
    root->left = new Node(2);    
    root->right = new Node(3);

    printVector(zigZagTraversal(root));

}