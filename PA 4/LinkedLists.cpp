// Seojin(Chris) Park
// Chapter 18 Programming Assignment
// 4/4/2024


#include <iostream>
using namespace std;


//the linked list
class LinkedList {
    //private, delclaire our Node 
    private:
        struct Node
        {
            string data;
            Node *next;

        };

        //declaire a Node pointer named head
        Node* head;

    public:
        LinkedList()
        {
            //set heads initial value to null
            head = nullptr;
        }
        ~LinkedList()
        {
            Node *temp;
            Node *nextTemp;
            temp = head;
            while(head != nullptr)
            {
                nextTemp = temp->next;
                delete temp;
                temp = nextTemp;
            }
        } 
        //function declarations
        void appendNode(string);
        int insertNode(string, int);
        int deleteNode(int);
        void displayList();
        int searchList(string);


};

int main(){
    //name of Linked list
    LinkedList necklace;
    //value to store all string variables
    string name;
    //value to store the option that the user chooses
    int option = 0;
    //index
    int i;
    //run program until user selects 6(exit)
    while(option != 6){
        cout << "Menu: \n";
        cout << "1. Append" << endl;
        cout << "2. Insert" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Print" << endl;
        cout << "5. Search" << endl;
        cout << "6. Exit" << endl;
        //prompt user for input and store it in the option variable
        cout << "Please choose a menu option: ";
        cin >> option;
        //use switch
        switch (option){
            case 1:{
                cout << "enter bead material: ";
                cin >> name;
                necklace.appendNode(name);
                cout << "The name " << name << " has been added to the necklace \n";
                break;
            }
            case 2:{
                cout << "enter bead name to insert: ";
                cin >> name;
                cout << "enter index to insert: ";
                cin >> i;
                if(necklace.insertNode(name,i) == -1){
                    cout << "index does not exist in necklace \n";
                }
                else{
                    cout << "Inserted bead material " << name << " to the necklace at index " << i<< endl;
                }
                
                break;
            }
            case 3:{
                cout << "Enter index to delete: ";
                cin >> i;
                if(necklace.deleteNode(i) == -1){
                    cout << "index does not exist in necklace \n";
                }
                else{
                    cout << "Successfully deleted node at index" << i << endl;
                }
                
                break;
            }
            case 4:{
                cout << "Current List: \n";
                necklace.displayList();
                cout << "--------------------------------- \n";
                break;
            }
            case 5:{
                cout << "enter bead name to search: ";
                cin >> name;
                if(necklace.searchList(name) == -1){
                    cout << "Name does not exist in necklace \n";
                }
                else{
                    cout << "bead named " << name << " is located at " << necklace.searchList(name) << endl;
                }
                break;
            }
            //when exiting
            case 6:
                cout << "Exiting program... \n";
                break;
            //if user inputs a option that is not valid
            default:
                cout << "Invalid choice \n";
        }
        
    }
}

//appending a node
void LinkedList::appendNode(string bead){
    //new node to append
    Node *temp;
    Node *temp2;
    temp = new Node;
    //set the data(value) of our newNode to the bead variable
    temp->data = bead;
    //set the next equal to null(it makes sense because we are adding the bead to the end of the list, and the next Node will be null since we are at the end)
    temp->next = nullptr;
    //if the linked list is empty, just set the list to the new bead
    if(head == nullptr){
        head = temp;
    }
    //If linked list is not empty, use the second pointer
    else{
        temp2 = head;
        //iterating until we are at the end of the list
        while(temp2->next != nullptr){
            temp2 = temp2->next;

        }
        //after temp2 is at the end of the list, make the next element the temp variable(new bead)
        temp2->next = temp;
    }
}
//inserting a node
int LinkedList::insertNode(string bead, int index){
    
    Node* temp = head;
    Node* newtemp = new Node;
    //store the bead in the newTemp node
    newtemp->data = bead;
    //checking edge cases
    if(index < 0){
        return -1;
    }
    //if the index is 0, add it to the start of the linked list
    if(index == 0) {
        //set the next of our new variable equal to the rest of the linked list
        newtemp->next = head;
        //set head to our new linked list
        head = newtemp;
        return 0;
    }
    //iterate through linked list until we are at the end
    while (temp != nullptr && index != 1) {
        temp = temp->next;
        index--;
    }
    //if temp is null, that means the index exceeded the linked list(invalid index), so we return -1.
    if(temp == nullptr){
        return -1;
    }
    //insert the new node into the linked list
    newtemp->next = temp->next;
    temp->next = newtemp;
    return 0;
}
int LinkedList::deleteNode(int index){

    Node* temp = head;
    //if the index is 0, delete the first node
    if (index == 0){
        head = head->next;
    }
    
    while(temp != nullptr){
        //if the next node is the deleting node, we skip the node
        if (index == 1){
            temp->next = temp->next->next;
        }
        //else, iterate through linked list normally
        else{
            temp = temp->next;
        }
        //subtracting 1 from index(if index == 1, it means next node is deleting node)
        index--;
    }
    //if the index is invalid, return -1
    if(temp == nullptr){
        return -1;
    }
    return 0;
}
//display linked list
void LinkedList::displayList(){
    Node* temp = head;
    int index = 0;
    //iterate through linked list and print the data
    while(temp != nullptr){
        cout << index <<" "<< temp->data << endl;
        temp = temp->next;
        //add 1 to index so that we can print the corresponding index for the linked list
        index +=1;
    };
}

//search linked list
int LinkedList::searchList(string value){
    Node* temp = head;
    int index = 0;
    //iterate through linked list until we find the value we are looking for
    while(temp != nullptr && temp->data != value){
        temp = temp->next;
        index +=1;
    };
    //if we didnt find the value, return -1
    if(temp == nullptr){
        return -1;
    }
    //if we found a value, return the index of the value
    return index;
}