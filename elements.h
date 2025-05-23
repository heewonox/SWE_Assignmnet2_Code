#include<map>
#include<string>
#include<vector>
#define lenList 300
using namespace std;

/**
 * @brief Represents a user account in the system.
 * 
 * Stores and provides access to user credentials and contact information.
 */
class Accounts{
private:
	string id;        
	string password;  
	string phone;     
public:
	Accounts(string id,string password,string phone);
	string getID();
	string getPassword();
};

/**
 * @brief Manages a collection of user accounts.
 * 
 * Provides functionality for account management and authentication.
 */
class AccountList{
private:
	Accounts* list[lenList];  
	int idx;                  
public:
	AccountList();
	bool isAdmin(string id,string password);
	bool isValidAccount(string id,string password);
	void addNewAccount(string id,string password,string phone);
};

/**
 * @brief Represents a bicycle in the rental system.
 * 
 * Stores and provides access to bicycle identification and product information.
 */
class Bicycle{
private:
	string ID;         
	string productName; 
public:
	Bicycle(string ID,string productName);
	string getID();
	string getProductName();
};

/**
 * @brief Manages a collection of bicycles.
 * 
 * Provides functionality for bicycle inventory management.
 */
class BicycleList{
private:
	Bicycle* list[lenList];  
	int idx;                 
public:
	BicycleList();
	void addNewBicycle(string id,string productName);
	Bicycle* fetchBicycleByID(string id);
};

/**
 * @brief Represents a bicycle rental status.
 * 
 * Links a user with a rented bicycle.
 */
class RentalStatus{
private:
	string userID;     
	Bicycle *bicycle;  
public:
	RentalStatus(string userID,Bicycle* bicycle);
	string getUserID();
	Bicycle* getBicycle();
};

/**
 * @brief Manages a collection of rental statuses.
 * 
 * Provides functionality for tracking bicycle rentals.
 */
class RentalStatusList{
private:
	RentalStatus *list[lenList];  
	int idx;                      
public:
	RentalStatusList();
	void addNewRentalStatus(string userID,Bicycle *bicycle);
	int fetchRentalStatusByID(string userID, Bicycle* result[]);
};