// Seojin(Chris) Park
// Chapter 19 Programming Assignment
// 4/18/2024

#include <iostream>
#include <algorithm>
using namespace std;

//class for stack
class StoryStack
{
    private:
    //define Stack Nodes(similar to linked lists)
        struct StackNode
        {
           string value;
           StackNode *next;
        };
        StackNode *top;
    
    public:
        //constructor
        StoryStack(){
            top = nullptr;
        }
        //destructor
        ~StoryStack();
        //function declarations
        void push(string);
        void pop(string &);
        void cap();
        void display();
        void story();
        bool isEmpty();

};


//main function
int main(){
    //define stack object
    StoryStack stack;
    //variable to store popped values from stack
    string popped = "";
    //user input
    int input = 0;
    //run program until user enters 6, which means exit
    while(input != 6){
        //menu
        cout << "Select an option: \n";
        cout << "1. Push (a word onto the stack) \n";
        cout << "2. Pop (a word off the stack) \n";
        cout << "3. Capitalize all of the words on the stack \n";
        cout << "4. Display Stack \n";
        cout << "5. Make a Story \n";
        cout << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> input;

        //if input value is invalid and not an int, tell them the input is invalid and prompt them for a new option
        while(cin.fail()){
            cout << "Error, invalid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Select an option: \n";
            cout << "1. Push (a word onto the stack) \n";
            cout << "2. Pop (a word off the stack) \n";
            cout << "3. Capitalize all of the words on the stack \n";
            cout << "4. Display Stack \n";
            cout << "5. Make a Story \n";
            cout << "6. Exit \n";
            cout << "Enter your choice: ";
            cin >> input;
        }
        //switch statement
        switch (input)
        {
            //push word into stack
            case 1:{
                string newWord;
                cout << "Enter word: ";
                cin >> newWord;
                stack.push(newWord);
                break;
            }
            //pop word from stack
            case 2:{
                stack.pop(popped);
                break;
            }
            //make the elements in stack capital
            case 3:{
                stack.cap();
                break;
            }
            //print out stack elements
            case 4:{
                cout << "Stack: \n";
                stack.display();
                break;
            }
            //write a story with the stack elements
            case 5:{
                stack.story();
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
//deconstructor, deleting every node in the list
StoryStack::~StoryStack(){
    StackNode *temp = nullptr;
    StackNode *nxt = nullptr;
    temp = top;
    while(temp){
        nxt = temp->next;
        delete temp;
        temp = nxt;
    }
}
//pushing new node into the list
void StoryStack::push(string word){
    //define new node
    StackNode *newNode = nullptr;
    newNode = new StackNode;
    //store the sting word value in the newNode
    newNode -> value = word;
    //make sure that the word meets the requirements
    if(word.length() > 10 || word.length() < 1){
        cout << "Error, word cant be blank or longer than 10 letters \n";
    }
    
    else{
        //if stack is empty, push the new node by setting the top equal to the newNode
        if(isEmpty()){
            top = newNode;
            newNode ->next = nullptr;
        }
        //if there are elements in stack, push the new node into the stack
        else{
            newNode->next = top;
            top = newNode;
        }
    }
    
}

//popping stacks
void StoryStack::pop(string &word){
    //temporary pointer
    StackNode *temp = nullptr;
    
    //if stack is empty display error message
    if(isEmpty()){
        cout << "Cant pop, stack empty \n";
    }
    //if not, print what element was popped and pop the element. Also set the words value to the popped elements value
    else{
        cout << "popped element: " << top->value << endl;
        word = top->value;
        temp = top->next;
        delete top;
        top = temp;
        
    }
}
//capitalize the stack
void StoryStack::cap(){
    StackNode *temp = top;
    //if stack is empty display error message
    if(isEmpty()){
        cout << "Stack is empty! \n";
    }
    else{
        //if stack is not empty, make the elements into upper case
        while(temp){
            transform(temp->value.begin(), temp->value.end(), temp->value.begin(), ::toupper);
            temp = temp->next;
        }
        cout << "Capitalized words! \n";
    }
    
}

//write story with stack elements
void StoryStack::story(){
    StackNode *temp = top;
    //array of length 5 because we are going to take in 5 values
    string words[5];
    //variable to store values that are popped
    string val = "";
    //to check if we have enough elements
    bool notEnough = false;
    //add elements to our words array while popping them from stack
    for(int i = 0; i < 5; i++)
    {
        //if we dont have any more elements in the stack, it means we dont have enough elements, break out from for loop
        if(isEmpty()){
            notEnough = true;
            break;
        }
        pop(val);
        words[i] = val;
        
    }
    //if we didnt have enough elements in stack, display error message
    if(notEnough){
        cout << "Not enough elements in stack! \n";
        cout << "You need atleast 5 elementsi in the stack \n";
    }
    //else, print story
    else{
        cout << "I was walking around with " << words[0] << " when I saw a " << words[1] 
        << ". I was so surprised that I did a " << words[2]
        << " and landed on a " << words[3] <<". I did not know that I could do that and I was "
        << words[4] << " to discover my new talent! \n";
    }
    
}
//check if stack is empty
bool StoryStack::isEmpty()
{
    //if top is nullptr, return true
    if(!top){
        return true;
    }
    //else return false
    return false;
}
//display all elements in stack
void StoryStack::display(){
    StackNode *temp = top;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}