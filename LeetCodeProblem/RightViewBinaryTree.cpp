#include <iostream>
#include <queue>
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
    for(auto itr= v1.begin(); itr!= v1.end(); itr++)
    {
        cout << *itr << " ";
    }
}

vector <int> RightView(Node* node){
    vector<int> v1;
    queue <Node*> q;

    if(node == NULL)
    {
        return v1;
    }
    int level = 0;
    q.push(node);

    while(!q.empty()){
     
        int tmp1 = q.size(); 
        for(int i = 0; i < tmp1; i++)
        {
            Node* tmp = new Node(-1);
            tmp = q.front();
            
             if(i == tmp1-1)
             {
                 v1.push_back(tmp->data);
             } 
            q.pop();
            if(tmp->left != NULL)
            {
                q.push(tmp->left);
            }
            if(tmp->right != NULL)
            {
                q.push(tmp->right);
            }
        }
        level++;

    }
    return v1;

}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    printVector(RightView(root));
}