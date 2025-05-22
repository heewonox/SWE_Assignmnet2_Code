#include"elements.h"
using namespace std;

/**
 * @brief User interface for the sign-up process.
 * 
 * Handles input/output operations for user registration.
 */
class SignUpUI{
public:
	/**
	 * @brief Reads user ID from input file.
	 * @param in_fp Input file stream
	 * @return The entered user ID
	 */
	string getID(ifstream& in_fp);
	
	/**
	 * @brief Reads password from input file.
	 * @param in_fp Input file stream
	 * @return The entered password
	 */
	string getPassword(ifstream& in_fp);
	
	/**
	 * @brief Reads phone number from input file.
	 * @param in_fp Input file stream
	 * @return The entered phone number
	 */
	string getPhone(ifstream& in_fp);
	
	/**
	 * @brief Displays sign-up information to output file.
	 * @param out_fp Output file stream
	 * @param id User's ID
	 * @param password User's password
	 * @param phone User's phone number
	 */
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
	/**
	 * @brief Constructs a new SignUp controller.
	 */
	SignUp();
	
	/**
	 * @brief Executes the sign-up process.
	 * @param idlist Pointer to the account list
	 * @param in_fp Input file stream
	 * @param out_fp Output file stream
	 */
	void job(IDList* idlist, ifstream& in_fp, ofstream& out_fp);
};

/**
 * @brief User interface for the login process.
 * 
 * Handles input/output operations for user authentication.
 */
class LogInUI{
public:
	/**
	 * @brief Reads user ID from input file.
	 * @param in_fp Input file stream
	 * @return The entered user ID
	 */
	string getID(ifstream& in_fp);
	
	/**
	 * @brief Reads password from input file.
	 * @param in_fp Input file stream
	 * @return The entered password
	 */
	string getPassword(ifstream& in_fp);
	
	/**
	 * @brief Displays login information to output file.
	 * @param out_fp Output file stream
	 * @param id User's ID
	 * @param password User's password
	 */
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
	/**
	 * @brief Constructs a new LogIn controller.
	 */
	LogIn();
	
	/**
	 * @brief Sets the current session ID based on login credentials.
	 * @param idlist Pointer to the account list
	 * @param in_fp Input file stream
	 * @param out_fp Output file stream
	 * @return The session ID if login successful, "guest" otherwise
	 */
	string setCurrentSessionID(IDList* idlist, ifstream& in_fp, ofstream& out_fp);
	
	/// @return true if current user is admin
	bool isAdmin();
	
	/// @return true if current user has valid account
	bool isValidAccount();
};

/**
 * @brief User interface for the logout process.
 * 
 * Handles input/output operations for user logout.
 */
class LogOutUI{
public:
	/// Reads any necessary input for logout
	void getInput();
	
	/**
	 * @brief Displays logout information to output file.
	 * @param out_fp Output file stream
	 * @param id User's ID
	 */
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
	/**
	 * @brief Constructs a new LogOut controller.
	 */
	LogOut();
	
	/**
	 * @brief Executes the logout process.
	 * @param id Current user's ID
	 * @param out_fp Output file stream
	 * @return true if logout successful
	 */
	bool isLogOutSuccessful(string id, ofstream& out_fp);
};

/**
 * @brief User interface for the bicycle rental process.
 * 
 * Handles input/output operations for bicycle rental.
 */
class RentBicycleUI{
public:
	/**
	 * @brief Reads bicycle ID from input file.
	 * @param in_fp Input file stream
	 * @return The entered bicycle ID
	 */
	string getBikeID(ifstream& in_fp);
	
	/**
	 * @brief Displays rental information to output file.
	 * @param out_fp Output file stream
	 * @param bikeID Bicycle's ID
	 * @param productName Bicycle's product name
	 */
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
	/**
	 * @brief Constructs a new RentBicycle controller.
	 */
	RentBicycle();
	
	/**
	 * @brief Executes the bicycle rental process.
	 * @param userID ID of the user renting the bicycle
	 * @param rentalList Pointer to the rental status list
	 * @param bikeList Pointer to the bicycle list
	 * @param in_fp Input file stream
	 * @param out_fp Output file stream
	 */
	void job(string userID, RentalStatusList* rentalList, BicycleList* bikeList, ifstream& in_fp, ofstream& out_fp);
};

/**
 * @brief User interface for displaying rental information.
 * 
 * Handles output operations for rental information display.
 */
class ShowRentalInfoUI{
public:
	/// Reads any necessary input for showing rental info
	void getInput();
	
	/**
	 * @brief Displays rental information to output file.
	 * @param out_fp Output file stream
	 * @param bicycles Array of rented bicycles
	 * @param count Number of bicycles in the array
	 */
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
	/**
	 * @brief Constructs a new ShowRentalInfo controller.
	 */
	ShowRentalInfo();
	
	/**
	 * @brief Executes the rental information display process.
	 * @param userID ID of the user whose rentals to display
	 * @param list Pointer to the rental status list
	 * @param out_fp Output file stream
	 */
	void job(string userID, RentalStatusList* list, ofstream& out_fp);
};

/**
 * @brief User interface for adding new bicycles.
 * 
 * Handles input/output operations for bicycle registration.
 */
class AddBicycleUI{
public:
	/**
	 * @brief Reads bicycle ID from input file.
	 * @param in_fp Input file stream
	 * @return The entered bicycle ID
	 */
	string getID(ifstream& in_fp);
	
	/**
	 * @brief Reads product name from input file.
	 * @param in_fp Input file stream
	 * @return The entered product name
	 */
	string getProductName(ifstream& in_fp);
	
	/**
	 * @brief Displays bicycle registration information to output file.
	 * @param out_fp Output file stream
	 * @param id Bicycle's ID
	 * @param productName Bicycle's product name
	 */
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
	/**
	 * @brief Constructs a new AddBicycle controller.
	 */
	AddBicycle();
	
	/**
	 * @brief Executes the bicycle addition process.
	 * @param list Pointer to the bicycle list
	 * @param in_fp Input file stream
	 * @param out_fp Output file stream
	 */
	void job(BicycleList* list, ifstream& in_fp, ofstream& out_fp);
};

