// Seojin(Chris) Park
// Chapter 6 & 7 REVIEW Programming Assignment - Integers
// 2/20/2024
#include <stdio.h>
#include <iostream>
using namespace std;


void Option1(int * arr, int length);
void Option2(int * arr , int length);
void Option3(int * arr , int length);
void Exit();


int main()
{
    //initializing Array
    int ARRAY[16] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};
    int *point;
    point = ARRAY;

    // for(int i = 0; i < 16; i++)
    // {
    //     cout << *(point + i) << " ";
    //     if(i % 4 == 0)
    //     {
    //         cout << endl;
    //     }
    // }


    //input is for users input for the options
    int input = 0;
    int length = sizeof ARRAY / sizeof *point;

    //run loop until user chooses option 4 (exit)
    do
    {
        // prompt user for input
        cout << "Choose an option \n";
        cout << "1. Display the matrix (rows x columns) \n";
        cout << "2. Find my integer \n";
        cout << "3. Swap column 1 with column 3 \n";
        cout << "4. Exit \n";
        cout << "Option: ";
        cin >> input;
        switch(input)
        {
            case 1:
                Option1(point, length);
                break;
            case 2:
                Option2(point, length);
                break;
            case 3:
                Option3(point, length);
                break;
            case 4:
                Exit();
                break;
            default:
                cout << "Wrong Menu Choice! \n";
        }
    }while(input != 4); 
    return 0;
}
// Option 1, runs when user chooses option 1, prints the 2d Array
void Option1(int * arr, int length){
    // iterate through array and print the elements in the 2d Array
    
    for(int i = 0; i < length; i++)
    {
        
        if(i % 4 == 0 && i != 0)
        {
            cout << endl;
        }
        cout << *(arr + i) << " ";
    }
    cout << "\n";
    
}

// Option 2, runs when user chooses option 2, prompts user for integer and
// provides the coordinates for the value
void Option2(int * arr , int length)
{
    // findInt is a variable that is used to store what the user inputs(the integer
    // that they want to find)
    int findInt;

    // prompt user for integer
    cout << "Enter integer: ";
    cin >> findInt;

    // iterate through arrary until we find the integer and return the coordinates
    for(int i = 0; i < length; i++)
    {
        
        if(*(arr + i) == findInt)
        {
            cout << "Row: " << i / 4 << " Column: "<<i % 4 << "\n";
        }
        
    }
}

// Option3, runs when user chooses option 3, swaps the first and 3rd columns
// and tells the user that the columns are swapped
void Option3(int * arr , int length)
{
    //swapping the columns
    for(int i = 0; i < length; i = i + 4)
    {
        swap(*(arr + i), *(arr + i + 2));
    }
    
    cout << "Swapped! \n";
}

// Option 4, runs when user chooses option 4, Lets user know that they exited the
// program
void Exit()
{
    cout << "Exiting Program...";
}