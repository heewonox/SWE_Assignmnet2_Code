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
	string id;        ///< User's unique identifier
	string password;  ///< User's password
	string phone;     ///< User's phone number
public:
	Accounts(string id,string password,string phone);
	string getID();
	string getPassword();
	string getPhone();
};

/**
 * @brief Manages a collection of user accounts.
 * 
 * Provides functionality for account management and authentication.
 */
class IDList{
private:
	Accounts* list[lenList];  ///< Array of account pointers
	int idx;                  ///< Current number of accounts
public:
	IDList();
	void addNewAccount(string id,string password,string phone);
	bool isAdmin(string id,string password);
	bool isValidAccount(string id,string password);
};

/**
 * @brief Represents a bicycle in the rental system.
 * 
 * Stores and provides access to bicycle identification and product information.
 */
class Bicycle{
private:
	string ID;          ///< Bicycle's unique identifier
	string productName; ///< Name/model of the bicycle
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
	Bicycle* list[lenList];  ///< Array of bicycle pointers
	int idx;                 ///< Current number of bicycles
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
	string userID;     ///< ID of the user who rented the bicycle
	Bicycle *bicycle;  ///< Pointer to the rented bicycle
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
	RentalStatus *list[lenList];  ///< Array of rental status pointers
	int idx;                      ///< Current number of rentals
public:
	RentalStatusList();
	void addNewRentalStatus(string userID,Bicycle *bicycle);
	int getSize() const { return idx; }
	RentalStatus* getRentalStatus(int index) const { return list[index]; }
	int fetchRentalStatusByID(string userID, Bicycle* result[]) const;
};