#include<iostream>
using namespace std;

class Tree{
    public:
        int value;
        Tree* left;
        Tree* right;

        Tree(int value) : value(value), left(nullptr), right(nullptr){}
};


int isBalancedBTHelper(Tree* root){

    if(!root) return 0;

    int leftHeight = isBalancedBTHelper(root->left);
    int rightHeight = isBalancedBTHelper(root->right);

    if(leftHeight == -1 || rightHeight == -1)
        return -1;

    if(abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}


bool isBalancedBT(Tree* root){
    return isBalancedBTHelper(root) != -1;
}

