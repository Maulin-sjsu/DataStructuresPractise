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

Node* LowestCommonAncestor(Node* node, Node* p, Node* q)
{
    if(p->data < node->data && q->data < node->data){
        LowestCommonAncestor(node->left,p,q);
    }else if(p->data > node->data && q->data > node->data){
        LowestCommonAncestor(node->right,p,q);
    }else{
        cout << node->data;
        return node;
    }
}

int main(){

    Node* root  = new Node(15);
    root->left  = new Node(10);
    root->right  = new Node(20);
    root->left->left  = new Node(8);
    root->left->right  = new Node(12);

    LowestCommonAncestor(root, root->left->left, root->left->right);

}