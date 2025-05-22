#include<iostream>
#include"elements.h"
using namespace std;

// Accounts class implementation
Accounts::Accounts(string id,string password,string phone){
	// Initialize account with provided credentials
	this->id=id;
	this->password=password;
	this->phone=phone;
}

string Accounts::getID(){
	return id;
}

string Accounts::getPassword(){
	return password;
}

string Accounts::getPhone(){
	return phone;
}

// IDList class implementation
IDList::IDList(){
	idx=0;
	// Initialize with admin account
	this->addNewAccount("admin","admin","PLACEHOLDER_ADMIN_PHONE");
}

void IDList::addNewAccount(string id,string password,string phone){
	// Create new account and add to list
	Accounts *newAccount=new Accounts(id,password,phone);
	list[idx++]=newAccount;
}

bool IDList::isAdmin(string id,string password){
	// Check if credentials match admin account
	if(id=="admin"&&password=="admin"){
		return true;
	}
	else{return false;}
}

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
Bicycle::Bicycle(string ID,string productName){
	// Initialize bicycle with ID and product name
	this->ID=ID;
	this->productName=productName;
}

string Bicycle::getID(){
	return ID;
}

string Bicycle::getProductName(){
	return productName;
}

// BicycleList class implementation
BicycleList::BicycleList(){
	idx=0;
}

void BicycleList::addNewBicycle(string id,string productName){
	// Create new bicycle and add to inventory
	Bicycle *newBicycle=new Bicycle(id,productName);
	this->list[idx++]=newBicycle;
}

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
RentalStatus::RentalStatus(string userID,Bicycle* bicycle){
	// Create new rental record linking user and bicycle
	this->userID=userID;
	this->bicycle=bicycle;
}

string RentalStatus::getUserID(){
	return userID;
}

Bicycle* RentalStatus::getBicycle(){
	return bicycle;
}

// RentalStatusList class implementation
RentalStatusList::RentalStatusList(){
	idx=0;
}

void RentalStatusList::addNewRentalStatus(string userID,Bicycle *bicycle){
	// Create new rental record and add to list
	RentalStatus *newRentalStatus=new RentalStatus(userID,bicycle);
	list[idx++]=newRentalStatus;
}

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