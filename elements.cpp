#include<iostream>
#include"elements.h"
using namespace std;
Accounts::Accounts(string id,string password,string phone){
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
IDList::IDList(){
	idx=0;
	this->addNewAccount("admin","admin","PLACEHOLDER_ADMIN_PHONE");
}
void IDList::addNewAccount(string id,string password,string phone){
	Accounts *newAccount=new Accounts(id,password,phone);
	list[idx++]=newAccount;
}
bool IDList::isAdmin(string id,string password){
	if(id=="admin"&&password=="admin"){
		return true;
	}
	else{return false;}
}
bool IDList::isValidAccount(string id,string password){
	for(int i=0;i<this->idx;i++){
		if(list[i]->getID()==id&&list[i]->getPassword()==password){
			return true;
		}
	}
	return false;
}
Bicycle::Bicycle(string ID,string productName){
	this->ID=ID;
	this->productName=productName;
}
string Bicycle::getID(){
	return ID;
}
string Bicycle::getProductName(){
	return productName;
}
BicycleList::BicycleList(){
	idx=0;
}
void BicycleList::addNewBicycle(string id,string productName){
	Bicycle *newBicycle=new Bicycle(id,productName);
	this->list[idx++]=newBicycle;
}
Bicycle* BicycleList::fetchBicycleByID(string id){
	for(int i=0;i<idx;i++){
		if(list[i]->getID()==id){
			return list[i];
		}
	}
	cout<<"Error Fetching Bicycle!!!"<<endl;
}
RentalStatus::RentalStatus(string userID,Bicycle* bicycle){
	this->userID=userID;
	this->bicycle=bicycle;
}
string RentalStatus::getUserID(){
	return userID;
}
Bicycle* RentalStatus::getBicycle(){
	return bicycle;
}
RentalStatusList::RentalStatusList(){
	idx=0;
}
void RentalStatusList::addNewRentalStatus(string userID,Bicycle *bicycle){
	RentalStatus *newRentalStatus=new RentalStatus(userID,bicycle);
	list[idx++]=newRentalStatus;
}
int RentalStatusList::fetchRentalStatusByID(string userID, Bicycle* result[]) const {
	int count = 0;
	for(int i = 0; i < idx; i++) {
		if(list[i]->getUserID() == userID) {
			result[count++] = list[i]->getBicycle();
		}
	}
	return count-1;
}