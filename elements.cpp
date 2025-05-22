#include<iostream>
#include"elements.h"
using namespace std;

/**
 * @brief Constructs a new user account.
 * @param id User's ID
 * @param password User's password
 * @param phone User's phone number
 */
Accounts::Accounts(string id,string password,string phone){
	// Initialize account with provided credentials
	this->id=id;
	this->password=password;
	this->phone=phone;
}

/**
 * @return The user's ID
 */
string Accounts::getID(){
	return id;
}

/**
 * @return The user's password
 */
string Accounts::getPassword(){
	return password;
}

/**
 * @return The user's phone number
 */
string Accounts::getPhone(){
	return phone;
}

// IDList class implementation
/**
 * @brief Constructs a new empty account list.
 */
IDList::IDList(){
	idx=0;
	// Initialize with admin account
	this->addNewAccount("admin","admin","PLACEHOLDER_ADMIN_PHONE");
}

/**
 * @brief Adds a new account to the list.
 * @param id User's ID
 * @param password User's password
 * @param phone User's phone number
 */
void IDList::addNewAccount(string id,string password,string phone){
	// Create new account and add to list
	Accounts *newAccount=new Accounts(id,password,phone);
	list[idx++]=newAccount;
}

/**
 * @brief Checks if the given credentials belong to an admin.
 * @param id User's ID
 * @param password User's password
 * @return true if credentials match an admin account
 */
bool IDList::isAdmin(string id,string password){
	// Check if credentials match admin account
	if(id=="admin"&&password=="admin"){
		return true;
	}
	else{return false;}
}

/**
 * @brief Validates user credentials.
 * @param id User's ID
 * @param password User's password
 * @return true if credentials are valid
 */
bool IDList::isValidAccount(string id,string password){
	// Linear search through accounts to validate credentials
	for(int i=0;i<this->idx;i++){
		if(list[i]->getID()==id&&list[i]->getPassword()==password){
			return true;
		}
	}
	return false;
}

// Bicycle class implementation
/**
 * @brief Constructs a new bicycle.
 * @param ID Bicycle's ID
 * @param productName Bicycle's product name
 */
Bicycle::Bicycle(string ID,string productName){
	// Initialize bicycle with ID and product name
	this->ID=ID;
	this->productName=productName;
}

/**
 * @return The bicycle's ID
 */
string Bicycle::getID(){
	return ID;
}

/**
 * @return The bicycle's product name
 */
string Bicycle::getProductName(){
	return productName;
}

// BicycleList class implementation
/**
 * @brief Constructs a new empty bicycle list.
 */
BicycleList::BicycleList(){
	idx=0;
}

/**
 * @brief Adds a new bicycle to the list.
 * @param id Bicycle's ID
 * @param productName Bicycle's product name
 */
void BicycleList::addNewBicycle(string id,string productName){
	// Create new bicycle and add to inventory
	Bicycle *newBicycle=new Bicycle(id,productName);
	this->list[idx++]=newBicycle;
}

/**
 * @brief Retrieves a bicycle by its ID.
 * @param id Bicycle's ID to search for
 * @return Pointer to the found bicycle, or nullptr if not found
 */
Bicycle* BicycleList::fetchBicycleByID(string id){
	// Linear search through bicycle inventory
	for(int i=0;i<idx;i++){
		if(list[i]->getID()==id){
			return list[i];
		}
	}
	// Error case: bicycle not found
	cout<<"Error Fetching Bicycle!!!"<<endl;
}

// RentalStatus class implementation
/**
 * @brief Constructs a new rental status.
 * @param userID ID of the renting user
 * @param bicycle Pointer to the rented bicycle
 */
RentalStatus::RentalStatus(string userID,Bicycle* bicycle){
	// Create new rental record linking user and bicycle
	this->userID=userID;
	this->bicycle=bicycle;
}

/**
 * @return The ID of the renting user
 */
string RentalStatus::getUserID(){
	return userID;
}

/**
 * @return Pointer to the rented bicycle
 */
Bicycle* RentalStatus::getBicycle(){
	return bicycle;
}

// RentalStatusList class implementation
/**
 * @brief Constructs a new empty rental status list.
 */
RentalStatusList::RentalStatusList(){
	idx=0;
}

/**
 * @brief Adds a new rental status to the list.
 * @param userID ID of the renting user
 * @param bicycle Pointer to the rented bicycle
 */
void RentalStatusList::addNewRentalStatus(string userID,Bicycle *bicycle){
	// Create new rental record and add to list
	RentalStatus *newRentalStatus=new RentalStatus(userID,bicycle);
	list[idx++]=newRentalStatus;
}

/**
 * @brief Retrieves all rentals for a specific user.
 * @param userID ID of the user whose rentals to find
 * @param result Array to store the found bicycles
 * @return Number of bicycles found
 */
int RentalStatusList::fetchRentalStatusByID(string userID, Bicycle* result[]) const {
	int count = 0;
	// First pass: collect all bicycles rented by the user
	for(int i = 0; i < idx; i++) {
		if(list[i]->getUserID() == userID) {
			result[count++] = list[i]->getBicycle();
		}
	}
	
	// Second pass: sort results by bicycle ID using bubble sort
	// This ensures consistent output order regardless of rental order
	for(int i = 0; i < count - 1; i++) {
		for(int j = 0; j < count - i - 1; j++) {
			if(result[j]->getID() > result[j + 1]->getID()) {
				// Swap the pointers
				Bicycle* temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}
	
	return count;
}