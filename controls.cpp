#include<iostream>
#include<fstream>
#include"controls.h"
using namespace std;

// SignUpUI implementation
string SignUpUI::getID(ifstream& in_fp){
	// Read user ID from input file
	string input;
	in_fp>>input;
	return input;
}

string SignUpUI::getPassword(ifstream& in_fp){
	// Read password from input file
	string input;
	in_fp>>input;
	return input;
}

string SignUpUI::getPhone(ifstream& in_fp){
	// Read phone number from input file
	string input;
	in_fp>>input;
	return input;
}

void SignUpUI::ShowOutput(ofstream& out_fp, string id,string password,string phone){
	// Display sign-up confirmation with user details
	out_fp<<"1.1. 회원가입"<<endl;
	out_fp<<"> "<<id<<" "<<password<<" "<<phone<<" "<<endl;
	out_fp<<endl;
	return;
}

// SignUp controller implementation
SignUp::SignUp() {}

void SignUp::job(IDList* idlist, ifstream& in_fp, ofstream& out_fp){
	// Get user registration details
	string id=ui.getID(in_fp);
	string password=ui.getPassword(in_fp);
	string phone=ui.getPhone(in_fp);
	
	// Create new account and display confirmation
	idlist->addNewAccount(id,password,phone);
	ui.ShowOutput(out_fp, id,password,phone);
}

// LogInUI implementation
string LogInUI::getID(ifstream& in_fp){
	// Read login ID from input file
	string input;
	in_fp>>input;
	return input;
}

string LogInUI::getPassword(ifstream& in_fp){
	// Read login password from input file
	string input;
	in_fp>>input;
	return input;
}

void LogInUI::showOutput(ofstream& out_fp, string id,string password){
	// Display login confirmation
	out_fp<<"2.1. 로그인"<<endl;
	out_fp<<"> "<<id<<" "<<password<<endl;
	out_fp<<endl;
	return;
}

// LogIn controller implementation
LogIn::LogIn() {}

string LogIn::setCurrentSessionID(IDList* idlist, ifstream& in_fp, ofstream& out_fp){
	// Get login credentials
	string id=ui.getID(in_fp);
	string password=ui.getPassword(in_fp);
	
	// Check if user is admin or regular user
	bool isAdmin=idlist->isAdmin(id,password);
	bool isValidAccount=idlist->isValidAccount(id,password);
	
	if(isAdmin){
		ui.showOutput(out_fp, id,password);
		return id;
	}
	else if(isValidAccount){
		ui.showOutput(out_fp, id,password);
		return id;
	}
	else{return "guest";}
}

// LogOutUI implementation
void LogOutUI::getInput(){}

void LogOutUI::ShowOutput(ofstream& out_fp, string id){
	// Display logout confirmation
	out_fp<<"2.2. 로그아웃"<<endl;
	out_fp<<"> "<<id<<endl;
	out_fp<<endl;
}

// LogOut controller implementation
LogOut::LogOut() {}

bool LogOut::isLogOutSuccessful(string id, ofstream& out_fp){
	// Process logout and display confirmation
	ui.getInput();
	ui.ShowOutput(out_fp, id);
	return true;
}

// AddBicycleUI implementation
string AddBicycleUI::getID(ifstream& in_fp){
	// Read bicycle ID from input file
	string id;
	in_fp>>id;
	return id;
}

string AddBicycleUI::getProductName(ifstream& in_fp){
	// Read product name from input file
	string pm;
	in_fp>>pm;
	return pm;
}

void AddBicycleUI::ShowOutput(ofstream& out_fp, string id,string productName){
	// Display bicycle registration confirmation
	out_fp<<"3.1. 자전거 등록"<<endl;
	out_fp<<"> "<<id<<" "<<productName<<endl;
	out_fp<<endl;
}

// AddBicycle controller implementation
AddBicycle::AddBicycle() {}

void AddBicycle::job(BicycleList* list, ifstream& in_fp, ofstream& out_fp){
	// Get bicycle details and add to inventory
	string id=ui.getID(in_fp);
	string productName=ui.getProductName(in_fp);
	list->addNewBicycle(id,productName);
	ui.ShowOutput(out_fp, id,productName);
}

// RentBicycleUI implementation
string RentBicycleUI::getBikeID(ifstream& in_fp){
	// Read bicycle ID to rent from input file
	string id;
	in_fp>>id;
	return id;
}

void RentBicycleUI::ShowOutput(ofstream& out_fp, string bikeID,string productName){
	// Display rental confirmation
	out_fp<<"4.1. 자전거 대여"<<endl;
	out_fp<<"> "<<bikeID<<" "<<productName<<endl;
	out_fp<<endl;
	return;
}

// RentBicycle controller implementation
RentBicycle::RentBicycle() {}

void RentBicycle::job(string userID, RentalStatusList* rentalList, BicycleList* bikeList, ifstream& in_fp, ofstream& out_fp){
	// Get bicycle ID from user input
	string bikeID=ui.getBikeID(in_fp);
	
	// First: verify the bicycle exists in the system
	Bicycle* tmp=bikeList->fetchBicycleByID(bikeID);
	
	// Second: create a new rental record
	rentalList->addNewRentalStatus(userID,tmp);
	
	// Finally: display confirmation to user
	ui.ShowOutput(out_fp, tmp->getID(),tmp->getProductName());
}

// ShowRentalInfoUI implementation
void ShowRentalInfoUI::getInput(){}

void ShowRentalInfoUI::ShowOutput(ofstream& out_fp, Bicycle* bicycles[], int count){
	// Display list of rented bicycles
	out_fp<<"5.1. 자전거 대여 리스트"<<endl;
	for(int i = 0; i < count; i++) {
		out_fp<<"> "<<bicycles[i]->getID()<<" "<<bicycles[i]->getProductName()<<endl;
	}
	out_fp<<endl;
}

// ShowRentalInfo controller implementation
ShowRentalInfo::ShowRentalInfo() {}

void ShowRentalInfo::job(string userID, RentalStatusList* list, ofstream& out_fp){
	// Get and display user's rented bicycles
	Bicycle* rentedBicycles[lenList];
	int count = list->fetchRentalStatusByID(userID, rentedBicycles);
	ui.ShowOutput(out_fp, rentedBicycles, count);
}