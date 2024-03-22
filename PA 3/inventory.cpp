
#include "inventory.h"
//defining the functions and what they do.
void inventoryHeader::setDogLicense(string newLicense){
        dogLicense = newLicense;
}
void inventoryHeader::setDogName(string newName){
    dogName = newName;
}
void inventoryHeader::setOwnerPhone(string newPhone){
    ownerPhone = newPhone;
}
void inventoryHeader::setPriceQuoted(int newPrice){
    priceQuoted = newPrice;
}
string inventoryHeader::getDogLicense(){
    return dogLicense;
}
string inventoryHeader::getDogName(){
    return dogName;
}
string inventoryHeader::getCustPhone(){
    return ownerPhone;
}
int inventoryHeader::getPriceQuoted(){
    return priceQuoted;
}
