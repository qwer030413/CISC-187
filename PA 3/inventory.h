#include <iostream>
using namespace std;

class inventoryHeader{
    //declaire private variables
    private:
        string dogLicense;
        string dogName;
        string ownerPhone;
        double priceQuoted;
    //declaire public functions
    public:
        void setDogLicense(string);
        void setDogName(string);
        void setOwnerPhone(string);
        void setPriceQuoted(int);
        string getDogLicense();
        string getDogName();
        string getCustPhone();
        int getPriceQuoted(); 
    //constructor for setting initial value for variables
    inventoryHeader() {
        dogLicense = "";
        dogName = "";
        ownerPhone = "";
        priceQuoted = 0;

    }

    
    
};