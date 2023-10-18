#include<iostream>
using namespace std;

class Tree{
    public:
        int value;
        Tree* left;
        Tree* right;

        Tree(int value) : value(value), left(nullptr), right(nullptr){}
};

int diameterOfTreeHelper(Tree* root, int& height){

    if(!root){
        height = 0;
        return 0;
    }

    int leftHeight = 0;
    int rightHeight = 0;
    int leftDiameter = diameterOfTreeHelper(root->left, leftHeight);
    int rightDiamter = diameterOfTreeHelper(root->right, rightHeight);

    int currentDiameter = max(max(leftDiameter, rightDiamter), leftHeight + rightHeight + 1);
    height = max(leftHeight, rightHeight) + 1;

    return currentDiameter;

}

int diameterOfTree(Tree* root){

    int height = 0;
    return diameterOfTreeHelper(root, height);

}
