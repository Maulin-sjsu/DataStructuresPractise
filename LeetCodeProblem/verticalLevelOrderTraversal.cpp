// #include <iostream>
// #include <queue>
// #include <vector>
// #include <map>

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

void printVector(vector<int> v1)
{
    for(int i = 0; i<v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

void printMap(map <int, vector <int> > m)
{
    for(auto itr = m.begin(); itr != m.end(); itr++)
    {
        printVector(itr->second);
    }
}

void printVerticalOrder(Node *node)
{
    if(node == NULL){
        return;
    }
    map <int, vector <int> > m;
    int hd = 0;

    queue <pair<Node*, int>> q;
    q.push(make_pair(node,hd));

    while(!q.empty())
    {
        pair <Node*, int> tmp = q.front();
        q.pop();
        Node* newnode = tmp.first;
        hd = tmp.second;
        m[hd].push_back(newnode->data);
        if(newnode->left != NULL){
            q.push(make_pair(newnode->left,hd-1));
        }
        if(newnode->right != NULL){
            q.push(make_pair(newnode->right,hd+1));
        }
    }
    printMap(m);
}




int main(){
    Node *root  = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

//            1
//        2       3
//    4      5,6      7

    printVerticalOrder(root);
    }