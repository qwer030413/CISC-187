// Seojin(Chris) Park
// Chapter 20 Programming Assignment
// 4/28/2024

//functions that use recursion: count, locate

#include <iostream>
#include <algorithm>
using namespace std;
//static variable for raffle
int raffle = 1;
//class for stack
class StoryStack
{
    private:
    //define Stack Nodes(similar to linked lists)
        struct StackNode
        {
           string value;
           int ticket;
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
        //functions that use recursion: count, locate

        void push(string);
        void pop(string &);
        int counter();
        int count(StackNode*);      //recursion, line 195
        void display();
        void DrawWinner();
        void locate(StackNode*, int);       //recursion, line 219
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
        cout << "1. Add a name \n";
        cout << "2. Make an order \n";
        cout << "3. Count Names \n";
        cout << "4. Draw Raffle Winner \n";
        cout << "5. Display Line \n";
        cout << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> input;

        //if input value is invalid and not an int, tell them the input is invalid and prompt them for a new option
        while(cin.fail()){
            cout << "Error, invalid input \n";
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Select an option: \n";
            cout << "1. Add a name \n";
            cout << "2. Make an order \n";
            cout << "3. Count Names \n";
            cout << "4. Draw Raffle Winner \n";
            cout << "5. Display Line \n";
            cout << "6. Exit \n";
            cout << "Enter your choice: ";
            cin >> input;
        }
        //switch statement
        switch (input)
        {
            //push word into queue
            case 1:{
                string newWord;
                cout << "Enter word: ";
                cin >> newWord;
                cout << "Welcome to Point Loma Seafoods - your raffle number is " << raffle << endl;
                stack.push(newWord);
                
                break;
            }
            //pop word from queue
            case 2:{
                stack.pop(popped);
                break;
            }
            //print out how many people are in line
            case 3:{
                cout << "Number of people in line: "<<stack.counter() << endl;
                break;
            }
            //print out queue elements
            case 4:{
                stack.DrawWinner();
                break;
            }
            //display the people in line
            case 5:{
                cout << "Stack: \n";
                stack.display();
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
    newNode -> ticket = raffle;
    newNode -> next = nullptr;
    raffle +=1;
    //make sure that the word meets the requirements
    if(word.length() > 10 || word.length() < 1){
        cout << "Error, word cant be blank or longer than 10 letters \n";
    }
    
    else{
        //if queue is empty, push the new node by setting the top equal to the newNode
        if(isEmpty()){
            top = newNode;
            newNode ->next = nullptr;
        }
        //if there are elements in queue, push the new node into the queue
        else{
            StackNode *temp = top;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
}

//popping queues
void StoryStack::pop(string &word){
    //temporary pointer
    StackNode *temp = nullptr;
    
    //if queue is empty display error message
    if(isEmpty()){
        cout << "Line is empty \n";
    }
    //if not, print what element was popped and pop the element. Also set the words value to the popped elements value
    else{
        cout  << top->value << " you can order now!"<< endl;
        word = top->value;
        temp = top->next;
        delete top;
        top = temp;
        
    }
}

//counting helper method that uses recursion to count the number of people
int StoryStack::count(StackNode *temp){
    //static variable for counter
    static int i = 0;
    i++;
    //if queue is empty, return 0 people
    if(isEmpty()){
        return 0;
    }
    //if we are at the end of queue, return i
    if (temp ->next == nullptr){
        return i;

    }
    return count(temp->next);
}
//returns the count function
int StoryStack::counter(){
    
    return count(top);
} 



//helper function that uses recurison to locate the winner
void StoryStack::locate(StackNode *temp, int winner){
    //if the person does not exist, let the user know
    if(temp == nullptr){
        cout << "Person with raffle " <<winner << " does not exist! " << endl;
        return;
    }
    //if person exists:
    if(temp->ticket == winner)
    {
        int choice = 0;
        cout << "The winning raffle number is " << winner << endl;
        cout << temp->value << ", what do you want:" << endl;
        cout << "1. A free t-shirt" << endl;
        cout << "2. A free side dish" << endl;
        cin >> choice;
        if(choice == 1){
            cout << "Nice shirt!" << endl;
        }
        else if(choice == 2){
            cout << "Have a good meal!" << endl;
        }
        else{
            cout << "Invalid option!";
        }
        return;
    }
    //input the next node so that we could iterate through the queue with recursion
    locate(temp->next, winner);
    
    
}
//picks a random number from the previously assigned raffles 
void StoryStack::DrawWinner(){
    srand(time(0));
    int winner = rand()%raffle + 1;
    locate(top,winner);
    
}
//check if queue is empty
bool StoryStack::isEmpty()
{
    //if top is nullptr, return true
    if(!top){
        return true;
    }
    //else return false
    return false;
}
//display all elements in queue
void StoryStack::display(){
    StackNode *temp = top;
    int index = 0;
    while(temp){
        cout <<"("<< index << ") " << temp->value << " " << temp->ticket<< endl;
        temp = temp->next;
        index++;
    }
}