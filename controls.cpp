#include<iostream>
#include<fstream>
#include"controls.h"
using namespace std;

/**
*@brief Reads user ID from input file.
*@param in_fp Input file stream
*@return The entered user ID
*/
string SignUpUI::getID(ifstream& in_fp){
	// Read user ID from input file
	string input;
	in_fp>>input;
	return input;
}

/**
*@brief Reads password from input file.
*@param in_fp Input file stream
*@return The entered password
*/
string SignUpUI::getPassword(ifstream& in_fp){
	// Read password from input file
	string input;
	in_fp>>input;
	return input;
}

/**
*@brief Reads phone number from input file.
*@param in_fp Input file stream
*@return The entered phone number
*/
string SignUpUI::getPhone(ifstream& in_fp){
	// Read phone number from input file
	string input;
	in_fp>>input;
	return input;
}

/**
*@brief Displays sign-up information to output file.
*@param out_fp Output file stream
*@param id User's ID
*@param password User's password
*@param phone User's phone number
*/
void SignUpUI::ShowOutput(ofstream& out_fp, string id,string password,string phone){
	// Display sign-up confirmation with user details
	out_fp<<"1.1. 회원가입"<<endl;
	out_fp<<"> "<<id<<" "<<password<<" "<<phone<<" "<<endl;
	out_fp<<endl;
	return;
}


/**
*@brief Executes the sign-up process.
*@param idlist Pointer to the account list
*@param in_fp Input file stream
*@param out_fp Output file stream
*/
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
/**
 * @brief Reads user ID from input file.
 * @param in_fp Input file stream
 * @return The entered user ID
 */
string LogInUI::getID(ifstream& in_fp){
	// Read login ID from input file
	string input;
	in_fp>>input;
	return input;
}

/**
 * @brief Reads password from input file.
 * @param in_fp Input file stream
 * @return The entered password
 */
string LogInUI::getPassword(ifstream& in_fp){
	// Read login password from input file
	string input;
	in_fp>>input;
	return input;
}

/**
 * @brief Displays login information to output file.
 * @param out_fp Output file stream
 * @param id User's ID
 * @param password User's password
 */
void LogInUI::showOutput(ofstream& out_fp, string id,string password){
	// Display login confirmation
	out_fp<<"2.1. 로그인"<<endl;
	out_fp<<"> "<<id<<" "<<password<<endl;
	out_fp<<endl;
	return;
}


/**
 * @brief Sets the current session ID based on login credentials.
 * @param idlist Pointer to the account list
 * @param in_fp Input file stream
 * @param out_fp Output file stream
 * @return The session ID if login successful, "guest" otherwise
 */
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
/**
 * @brief Reads any necessary input for logout
 */
void LogOutUI::getInput(){}

/**
 * @brief Displays logout information to output file.
 * @param out_fp Output file stream
 * @param id User's ID
 */
void LogOutUI::ShowOutput(ofstream& out_fp, string id){
	// Display logout confirmation
	out_fp<<"2.2. 로그아웃"<<endl;
	out_fp<<"> "<<id<<endl;
	out_fp<<endl;
}


/**
 * @brief Executes the logout process.
 * @param id Current user's ID
 * @param out_fp Output file stream
 * @return true if logout successful
 */
bool LogOut::isLogOutSuccessful(string id, ofstream& out_fp){
	// Process logout and display confirmation
	ui.getInput();
	ui.ShowOutput(out_fp, id);
	return true;
}

// AddBicycleUI implementation
/**
 * @brief Reads bicycle ID from input file.
 * @param in_fp Input file stream
 * @return The entered bicycle ID
 */
string AddBicycleUI::getID(ifstream& in_fp){
	// Read bicycle ID from input file
	string id;
	in_fp>>id;
	return id;
}

/**
 * @brief Reads product name from input file.
 * @param in_fp Input file stream
 * @return The entered product name
 */
string AddBicycleUI::getProductName(ifstream& in_fp){
	// Read product name from input file
	string pm;
	in_fp>>pm;
	return pm;
}

/**
 * @brief Displays bicycle registration information to output file.
 * @param out_fp Output file stream
 * @param id Bicycle's ID
 * @param productName Bicycle's product name
 */
void AddBicycleUI::ShowOutput(ofstream& out_fp, string id,string productName){
	// Display bicycle registration confirmation
	out_fp<<"3.1. 자전거 등록"<<endl;
	out_fp<<"> "<<id<<" "<<productName<<endl;
	out_fp<<endl;
}



/**
 * @brief Executes the bicycle addition process.
 * @param list Pointer to the bicycle list
 * @param in_fp Input file stream
 * @param out_fp Output file stream
 */
void AddBicycle::job(BicycleList* list, ifstream& in_fp, ofstream& out_fp){
	// Get bicycle details and add to inventory
	string id=ui.getID(in_fp);
	string productName=ui.getProductName(in_fp);
	list->addNewBicycle(id,productName);
	ui.ShowOutput(out_fp, id,productName);
}

// RentBicycleUI implementation
/**
 * @brief Reads bicycle ID from input file.
 * @param in_fp Input file stream
 * @return The entered bicycle ID
 */
string RentBicycleUI::getBikeID(ifstream& in_fp){
	// Read bicycle ID to rent from input file
	string id;
	in_fp>>id;
	return id;
}

/**
 * @brief Displays rental information to output file.
 * @param out_fp Output file stream
 * @param bikeID Bicycle's ID
 * @param productName Bicycle's product name
 */
void RentBicycleUI::ShowOutput(ofstream& out_fp, string bikeID,string productName){
	// Display rental confirmation
	out_fp<<"4.1. 자전거 대여"<<endl;
	out_fp<<"> "<<bikeID<<" "<<productName<<endl;
	out_fp<<endl;
	return;
}



/**
 * @brief Executes the bicycle rental process.
 * @param userID ID of the user renting the bicycle
 * @param rentalList Pointer to the rental status list
 * @param bikeList Pointer to the bicycle list
 * @param in_fp Input file stream
 * @param out_fp Output file stream
 */
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
/**
 * @brief Reads any necessary input for showing rental info
 */
void ShowRentalInfoUI::getInput(){}

/**
 * @brief Displays rental information to output file.
 * @param out_fp Output file stream
 * @param bicycles Array of rented bicycles
 * @param count Number of bicycles in the array
 */
void ShowRentalInfoUI::ShowOutput(ofstream& out_fp, Bicycle* bicycles[], int count){
	// Display list of rented bicycles
	out_fp<<"5.1. 자전거 대여 리스트"<<endl;
	for(int i = 0; i < count; i++) {
		out_fp<<"> "<<bicycles[i]->getID()<<" "<<bicycles[i]->getProductName()<<endl;
	}
	out_fp<<endl;
}


/**
 * @brief Executes the rental information display process.
 * @param userID ID of the user whose rentals to display
 * @param list Pointer to the rental status list
 * @param out_fp Output file stream
 */
void ShowRentalInfo::job(string userID, RentalStatusList* list, ofstream& out_fp){
	// Get and display user's rented bicycles
	Bicycle* rentedBicycles[lenList];
	int count = list->fetchRentalStatusByID(userID, rentedBicycles);
	ui.ShowOutput(out_fp, rentedBicycles, count);
}