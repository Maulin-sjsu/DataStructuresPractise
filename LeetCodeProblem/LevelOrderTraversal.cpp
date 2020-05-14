#include <iostream>
#include <queue>

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

void LevelOrderTraversal(Node *node)
{
    if(node == NULL){
        return;
    }
    queue <Node*> q;
    q.push(node);
    while(!q.empty())
    {
        Node *node = q.front();
        cout << node ->data << " " ;
        q.pop();

        if(node->left != NULL){
            q.push(node->left);
        }
        
        if(node->right != NULL){
            q.push(node->right);
        }

    }

}

int main(){

    Node *root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);

    LevelOrderTraversal(root);
    
}
