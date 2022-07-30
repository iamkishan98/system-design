#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;

    public:
    TreeNode(int data){
        this->data = data;
        left = NULL; right = NULL;
    }
    public:
    int getData();
    TreeNode *getLeft();
    TreeNode *getRight();
};

int TreeNode::getData(){
    return this->data;
}

TreeNode * TreeNode::getLeft(){
    return this->left;
}
TreeNode * TreeNode::getRight(){
    return this->right;
}


int main()
{
    TreeNode *head = new TreeNode(1);
    cout<<head->getData()<<endl;
    return 0;

}