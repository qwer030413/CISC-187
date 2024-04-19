#include <iostream>
#include <algorithm>

using namespace std;

class StoryStack
{
    private:
        struct StackNode
        {
           string value;
           StackNode *next;
        };
        StackNode *top;
        
    public:
        StoryStack(){
            top = nullptr;
        }
        ~StoryStack();
        void push(string);
        void pop(string &);
        void cap();
        void display();
        void story();
        bool isEmpty();

};

int main(){
    StoryStack stack;
    string popped = "";
    int input = 0;
    while(input != 6){
        cout << "Select an option: \n";
        cout << "1. Push (a word onto the stack) \n";
        cout << "2. Pop (a word off the stack) \n";
        cout << "3. Capitalize all of the words on the stack \n";
        cout << "4. Display Stack \n";
        cout << "5. Make a Story \n";
        cout << "6. Exit \n";
        cout << "Enter your choice: ";
        cin >> input;
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
        switch (input)
        {
            case 1:{
                string newWord;
                cout << "Enter word: ";
                cin >> newWord;
                stack.push(newWord);
                break;
            }
            case 2:{
                stack.pop(popped);
                break;
            }
            case 3:{
                stack.cap();
                break;
            }
            case 4:{
                cout << "Stack: \n";
                stack.display();
                break;
            }
            case 5:{
                stack.story();
                break;
            }
            case 6:{
                cout<< "Exiting program....";
                break;
            }
            default:{
                cout << "Invalid input \n";
            }
        }
        
    }
}
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
void StoryStack::push(string word){
    StackNode *newNode = nullptr;
    newNode = new StackNode;
    newNode -> value = word;
    if(word.length() > 10 || word.length() < 1){
        cout << "Error, word cant be blank or longer than 10 letters \n";
    }
    else{
        if(isEmpty()){
            top = newNode;
            newNode ->next = nullptr;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }
    
}
void StoryStack::pop(string &word){
    StackNode *temp = nullptr;
    

    if(isEmpty()){
        cout << "Cant pop, stack empty \n";
    }
    else{
        cout << "popped element: " << top->value << endl;
        word = top->value;
        temp = top->next;
        delete top;
        top = temp;
        
    }
}
void StoryStack::cap(){
    StackNode *temp = top;
    if(isEmpty()){
        cout << "Stack is empty! \n";
    }
    else{
        while(temp){
            transform(temp->value.begin(), temp->value.end(), temp->value.begin(), ::toupper);
            temp = temp->next;
        }
        cout << "Capitalized words! \n";
    }
    
}
void StoryStack::story(){
    StackNode *temp = top;
    string words[5];
    string val = "";
    bool notEnough = false;
    for(int i = 0; i < 5; i++)
    {
        if(isEmpty()){
            notEnough = true;
            break;
        }
        pop(val);
        words[i] = val;
        
    }
    if(notEnough){
        cout << "Not enough elements in stack! \n";
        cout << "You need atleast 5 elementsi in the stack \n";
    }
    else{
        cout << "I was walking around with " << words[0] << " when I saw a " << words[1] 
        << ". I was so surprised that I did a " << words[2]
        << " and landed on a " << words[3] <<". I did not know that I could do that and I was "
        << words[4] << " to discover my new talent! \n";
    }
    
}
bool StoryStack::isEmpty()
{
    bool status;
    if(!top){
        return true;
    }
    return false;
}
void StoryStack::display(){
    StackNode *temp = top;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}