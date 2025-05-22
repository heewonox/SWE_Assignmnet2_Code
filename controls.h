#include"elements.h"
using namespace std;

/**
 * @brief User interface for the sign-up process.
 * 
 * Handles input/output operations for user registration.
 */
class SignUpUI{
public:
	string getID(ifstream& in_fp);
	string getPassword(ifstream& in_fp);
	string getPhone(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string id,string password,string phone);
};

/**
 * @brief Controls the sign-up process.
 * 
 * Manages the flow of user registration and coordinates between UI and data layer.
 */
class SignUp{
private:
	SignUpUI ui;
public:
	void job(IDList* idlist, ifstream& in_fp, ofstream& out_fp);
};

/**
 * @brief User interface for the login process.
 * 
 * Handles input/output operations for user authentication.
 */
class LogInUI{
public:
	string getID(ifstream& in_fp);
	string getPassword(ifstream& in_fp);
	void showOutput(ofstream& out_fp, string id,string password);
};

/**
 * @brief Controls the login process.
 * 
 * Manages user authentication and session management.
 */
class LogIn{
private:
	LogInUI ui;
public:
	string setCurrentSessionID(IDList* idlist, ifstream& in_fp, ofstream& out_fp);
};

/**
 * @brief User interface for the logout process.
 * 
 * Handles input/output operations for user logout.
 */
class LogOutUI{
public:
	void getInput();
	void ShowOutput(ofstream& out_fp, string id);
};

/**
 * @brief Controls the logout process.
 * 
 * Manages user session termination.
 */
class LogOut{
private:
	LogOutUI ui;
public:
	bool isLogOutSuccessful(string id, ofstream& out_fp);
};

/**
 * @brief User interface for the bicycle rental process.
 * 
 * Handles input/output operations for bicycle rental.
 */
class RentBicycleUI{
public:
	string getBikeID(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string bikeID,string productName);
};

/**
 * @brief Controls the bicycle rental process.
 * 
 * Manages the rental of bicycles to users.
 */
class RentBicycle{
private:
	RentBicycleUI ui;
public:
	void job(string userID, RentalStatusList* rentalList, BicycleList* bikeList, ifstream& in_fp, ofstream& out_fp);
};

/**
 * @brief User interface for displaying rental information.
 * 
 * Handles output operations for rental information display.
 */
class ShowRentalInfoUI{
public:
	void getInput();
	void ShowOutput(ofstream& out_fp, Bicycle* bicycles[], int count);
};

/**
 * @brief Controls the display of rental information.
 * 
 * Manages the retrieval and display of user's rental information.
 */
class ShowRentalInfo{
private:
	ShowRentalInfoUI ui;
public:
	void job(string userID, RentalStatusList* list, ofstream& out_fp);
};

/**
 * @brief User interface for adding new bicycles.
 * 
 * Handles input/output operations for bicycle registration.
 */
class AddBicycleUI{
public:
	string getID(ifstream& in_fp);
	string getProductName(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string id,string productName);
};

/**
 * @brief Controls the addition of new bicycles.
 * 
 * Manages the registration of new bicycles in the system.
 */
class AddBicycle{
private:
	AddBicycleUI ui;
public:
	void job(BicycleList* list, ifstream& in_fp, ofstream& out_fp);
};

