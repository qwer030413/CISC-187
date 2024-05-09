#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
class IntBinaryTree
{
    private:
        struct TreeNode
        {
            int value;
            TreeNode *left;
            TreeNode *right;
        };
        
        TreeNode *root;

        void insert(TreeNode *&, TreeNode *&);
        void displayHelper(TreeNode *&);
        int countHelper(TreeNode *&, int);
        int leafHelper(TreeNode *&);
        int maxWidthHelper(TreeNode *&);
        int getWidth(TreeNode *&, int);
        // void destroySubTree(TreeNode *);
        // void deleteNode(int ,TreeNode *&);


    public:
        IntBinaryTree() {
            root = nullptr;
        }
        // ~IntBinaryTree()
        // {
        //     destroySubTree(root)
        // }
        void insertNode(int);
        void displayTree();
        void treeDepth();
        void leafCount();
        void maxWidth();
        // bool searchNode(int);
        // void remove(int);
};


int main(){


    IntBinaryTree node;
    node.insertNode(10);
    node.insertNode(87);
    node.insertNode(9);
    node.insertNode(55);
    node.insertNode(13);
    node.insertNode(40);
    node.insertNode(22);
    node.insertNode(1);
    node.insertNode(0);
    node.insertNode(77);
    node.insertNode(0);
    node.insertNode(4);
    node.insertNode(55);
    node.insertNode(33);
    node.insertNode(22);
    node.displayTree();
    node.treeDepth();
    node.leafCount();
    node.maxWidth();
}

void IntBinaryTree::insert(TreeNode *&NodePtr, TreeNode *&newNode)
{
    if (NodePtr == nullptr)
    {
        NodePtr = newNode;
    }
    else if (newNode-> value < NodePtr -> value)
    {
        insert(NodePtr -> left, newNode);
    }
    else{
        insert(NodePtr -> right, newNode);
    }
}
void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr;

    newNode = new TreeNode;
    newNode -> value = num;
    newNode -> left = newNode-> right = nullptr;
    insert(root, newNode);

}

void IntBinaryTree::displayTree(){
    TreeNode *temp = root;
    displayHelper(temp);
}
void IntBinaryTree::displayHelper(TreeNode *&NodePtr){
    if(NodePtr == nullptr)
    {
        return;
    }
    cout <<NodePtr->value << " ";
    if(NodePtr->left)
    {
        displayHelper(NodePtr->left);
    }
    if(NodePtr->right)
    {
        displayHelper(NodePtr->right);
    }
}
void IntBinaryTree::treeDepth(){
    TreeNode *temp = root;
    cout <<"Tree depth: " <<countHelper(temp, 0) - 1<< endl;
}
int IntBinaryTree::countHelper(TreeNode *&NodePtr, int n){
    if(NodePtr == nullptr)
    {
        return n;
    }
    return max(countHelper(NodePtr->left, n + 1), countHelper(NodePtr->right, n + 1));
}

void IntBinaryTree::leafCount(){
    TreeNode *temp = root;
    cout << "Number of leafs: " << leafHelper(temp) << endl;
}

int IntBinaryTree::leafHelper(TreeNode *&NodePtr){
    if(NodePtr == nullptr){
        return 0;
    }
    if(NodePtr->left == nullptr && NodePtr->right == nullptr)
    {
        return 1;
    }
    
    return leafHelper(NodePtr->left) + leafHelper(NodePtr->right);

}

void IntBinaryTree::maxWidth(){
    TreeNode *temp = root;
    cout << "Max Width: " << maxWidthHelper(temp) << endl;
}

int IntBinaryTree::maxWidthHelper(TreeNode *&NodePtr)
{
    int maxWidth = 0;
    int width = 0;
    int height = countHelper(root, 0);
 
    /* Get width of each level and compare
        the width with maximum width so far */
    for (int i = 1; i <= height; i++) {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }
 
    return maxWidth;
}
int IntBinaryTree::getWidth(TreeNode *&root, int level)
{
    if (root == nullptr)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}