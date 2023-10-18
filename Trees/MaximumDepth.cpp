#include<iostream>
using namespace std;

class Tree{
    public:
        int value;
        Tree* left;
        Tree* right;

        Tree(int value) : value(value), left(nullptr), right(nullptr){}
};

int maxDepth(Tree* root){

    if(!root){
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    int maxDepth = max(leftDepth, rightDepth) + 1;

    return maxDepth;

}