#include <iostream>
#include "inventory.h"
#include <vector> 
// Seojin(Chris) Park
// Chapter 6 & 7 REVIEW Programming Assignment - Integers
// 2/20/2024
using namespace std;

int main() {
    int options = 0;
    //vector for storing objects in the program
    vector<inventoryHeader> vect; 
    // do while loop to run while the option is not 3
    do{
        //print the menu for the user
        cout << "You Dirty Dog Menu:" << endl;
        cout << "1. Enter a new job"<< endl;
        cout << "2. List all current jobs"<< endl;
        cout << "3. Exit"<< endl;
        cout << "Enter menu choice: ";
        cin >> options;
        if(options == 1){
            //create a new object
            inventoryHeader object;
            //temporary values to store the inputs
            string DLN;
            string DN;
            string CP;
            int P;
            cout << "Dog License Number: ";
            cin >> DLN;
            cout << "Dog Name: ";
            cin >> DN;
            cout << "Customer Phone: ";
            cin >> CP;
            cout << "Price: ";
            cin >> P;
            //store the values we got into the object using the set functions
            object.setDogLicense(DLN);
            object.setDogName(DN);
            object.setOwnerPhone(CP);
            object.setPriceQuoted(P);
            //store the object in the object vector we created earlier
            vect.push_back(object); 
            cout << "Thank you, we will take good care of Buddy today!" << endl;

        }
        //if user chooses option 2
        else if(options == 2){
            //sum of the price
            int sum = 0;
            cout << "Current Jobs:" << endl;
            //iterate through the object array and print out all the values
            for(int i = 0; i < vect.size(); i++){
                cout << vect[i].getDogLicense() << endl;
                cout << vect[i].getDogName() << endl;
                cout << vect[i].getCustPhone() << endl;
                cout <<"$" <<vect[i].getPriceQuoted() << endl;
                sum += vect[i].getPriceQuoted();
                cout << "******************************"<<endl;
            }
            //get number of jobs by checking the size of the object vector.
            cout << "You currently have "<< vect.size() << " jobs with a total of $" << sum << endl;
        }   
        
    }while (options != 3);
}
