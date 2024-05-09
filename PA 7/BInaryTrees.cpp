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
        int leafHelper(TreeNode *&);
        int maxWidthHelper(TreeNode *&);
        int getWidth(TreeNode *&, int);
        void destroySubTree(TreeNode *);
      


    public:
        IntBinaryTree() {
            root = nullptr;
        }
        ~IntBinaryTree()
        {
            destroySubTree(root);
        }
        void insertNode(int);
        void displayTree();
        void treeDepth();
        void leafCount();
        void maxWidth();
        
};


int main(){


    IntBinaryTree node;
    int input = 0;
    while (input !=6)
    {
        cout << "Select an option: \n";
        cout << "1. Insert one integer into the tree \n";
        cout << "2. display the tree \n";
        cout << "3. Display Leaf Count \n";
        cout << "4. Display Tree Height \n";
        cout << "5. Display Tree Width \n";
        cout << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> input;
        //if input value is invalid and not an int, tell them the input is invalid and prompt them for a new option
        while(cin.fail()){
            cout << "Error, invalid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Select an option: \n";
            cout << "1. Insert one integer into the tree \n";
            cout << "2. display the tree \n";
            cout << "3. Display Leaf Count \n";
            cout << "4. Display Tree Height \n";
            cout << "5. Display Tree Width \n";
            cout << "6. Exit \n";
            cout << "Enter your choice: ";
            cin >> input;
        }
        switch (input)
        {
            //insert number into tree
            case 1:{
                int newNode;
                cout << "Enter number: ";
                cin >> newNode;
                node.insertNode(newNode);
                break;
            }
            //display tree
            case 2:{
                node.displayTree();
                break;
            }
            //print out how many leafs are in the tree
            case 3:{
                node.leafCount();
                break;
            }
            //print out the maximum depth of the tree
            case 4:{
                node.treeDepth();
                break;
            }
            //display the maximum width of the tree
            case 5:{
                node.maxWidth();
                break;
            }
            //exit program
            case 6:{
                cout<< "Exiting program....";
                break;
            }
            //if input is int value but not on menu, tell user their input is invalid
            default:{
                cout << "Invalid input \n";
            }
        }
    }
    
    
}


//insert function helper, insert new node into binary tree
void IntBinaryTree::insert(TreeNode *&NodePtr, TreeNode *&newNode)
{
    //if tree is empty, add the new node 
    if (NodePtr == nullptr)
    {
        NodePtr = newNode;
    }
    //if binary tree is not empty, compare values and insert the value in tree accordingly.
    else if (newNode-> value < NodePtr -> value)
    {
        insert(NodePtr -> left, newNode);
    }
    else{
        insert(NodePtr -> right, newNode);
    }
}

//inserting function 
void IntBinaryTree::insertNode(int num)
{
    TreeNode *newNode = nullptr;
    //set the value of the newNode to the int number that we got in the parameter and call the inserr function
    newNode = new TreeNode;
    newNode -> value = num;
    newNode -> left = newNode-> right = nullptr;
    insert(root, newNode);

}

//displaying tree
void IntBinaryTree::displayTree(){
    TreeNode *temp = root;
    displayHelper(temp);
}
//displaying tree using recurison
void IntBinaryTree::displayHelper(TreeNode *&NodePtr){
    if(NodePtr == nullptr)
    {
        return;
    }
    //check left
    if(NodePtr->left)
    {
        displayHelper(NodePtr->left);
    }
    //print our the value of the node
    cout <<NodePtr->value << " "<< endl;
    //check right
    if(NodePtr->right)
    {
        displayHelper(NodePtr->right);
    }
}

//get the maximum tree depth 
void IntBinaryTree::treeDepth(){
    TreeNode *temp = root;
    cout <<"Tree depth: " <<countHelper(temp, 0) - 1<< endl;
}
//helper function for depth, use recursion to get the max depth.
int IntBinaryTree::countHelper(TreeNode *&NodePtr, int n){
    if(NodePtr == nullptr)
    {
        return n;
    }
    return max(countHelper(NodePtr->left, n + 1), countHelper(NodePtr->right, n + 1));
}
//get how many leaves are in the tree
void IntBinaryTree::leafCount(){
    TreeNode *temp = root;
    cout << "Number of leafs: " << leafHelper(temp) << endl;
}

//use recursion to transverse through tree until we find a node that left and right is null(a leaf)
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

//get the max width of tree
void IntBinaryTree::maxWidth(){
    TreeNode *temp = root;
    cout << "Max Width: " << maxWidthHelper(temp) << endl;
}

//helper function that compares the width of the tree for each level/index and gets the max
int IntBinaryTree::maxWidthHelper(TreeNode *&NodePtr)
{
    int maxWidth = 0;
    int width = 0;
    int height = countHelper(root, 0);
    for (int i = 1; i <= height; i++) {
        width = getWidth(root, i);
        maxWidth = max(width, maxWidth);
    }
 
    return maxWidth;
}
//getting the width of each level/index of tree
int IntBinaryTree::getWidth(TreeNode *&root, int index)
{
    if (root == nullptr)
        return 0;
    if (index == 1)
        return 1;
    else if (index > 1)
        return getWidth(root->left, index - 1) + getWidth(root->right, index - 1);
}

//destructor helper
void IntBinaryTree::destroySubTree(TreeNode* temp)
{
    if (temp)
    {
        if(temp -> left)
        {
            destroySubTree(temp->left);
        }
        if(temp -> right)
        {
            destroySubTree(temp->right);
        }
        delete temp;
    }
}