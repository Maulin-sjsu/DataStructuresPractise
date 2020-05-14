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


bool IsSameTree(Node* s, Node* t){

    if(s == NULL && t == NULL ){
        return true;
    }else if(s->data == t->data){
        return IsSameTree(s->left, t->left) && IsSameTree(s->right, t->right);
    }else{
        return false;
    }
}

bool IsSubtreeOfanotherTree(Node* s, Node* t){
    if(s == NULL)
    {
        return false;
    }else if(IsSameTree(s,t)){
        return true;
    }else{
        return IsSubtreeOfanotherTree(s->left,t) || IsSubtreeOfanotherTree(s->right, t);
    }
}




int main(){

    Node* root1  = new Node(15);
    root1->left  = new Node(10);
    root1->right  = new Node(20);
    root1->left->left  = new Node(8);
    root1->left->right  = new Node(12);


    Node* root2  = new Node(10);
    root2->left  = new Node(8);
    root2->right  = new Node(12);
//  root2->left->left  = new Node(8);
//  root2->left->right  = new Node(12);
    
    cout << IsSubtreeOfanotherTree(root1,root2);


}