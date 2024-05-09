#include <iostream>
#include <algorithm>
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
