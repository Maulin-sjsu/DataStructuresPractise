#include <iostream>
#include <vector>

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


void printVector(vector<int>v1)
{
    //cout <<v1.size() << endl;
    for(auto itr= v1.begin(); itr!= v1.end(); itr++)
    {
        cout << *itr << " ";
    }
}

vector <int> &allleaves(Node* node,vector <int> &v1){
    
    if(node == NULL)
    {
        return v1;
    }
    
    if(node->left == NULL && node->right == NULL)
    {
        v1.push_back(node->data);
        return v1;    
    }
    
    allleaves(node->left,v1);
    allleaves(node->right,v1);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector <int> v1;
    printVector((allleaves(root,v1)));
    //cout << "V1 size after calling th program is: " << allleaves(root,v1).size() << endl;

}