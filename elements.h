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
	/**
	 * @brief Constructs a new user account.
	 * @param id User's ID
	 * @param password User's password
	 * @param phone User's phone number
	 */
	Accounts(string id,string password,string phone);
	
	/// @return The user's ID
	string getID();
	
	/// @return The user's password
	string getPassword();
	
	/// @return The user's phone number
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
	/**
	 * @brief Constructs a new empty account list.
	 */
	IDList();
	
	/**
	 * @brief Adds a new account to the list.
	 * @param id User's ID
	 * @param password User's password
	 * @param phone User's phone number
	 */
	void addNewAccount(string id,string password,string phone);
	
	/**
	 * @brief Checks if the given credentials belong to an admin.
	 * @param id User's ID
	 * @param password User's password
	 * @return true if credentials match an admin account
	 */
	bool isAdmin(string id,string password);
	
	/**
	 * @brief Validates user credentials.
	 * @param id User's ID
	 * @param password User's password
	 * @return true if credentials are valid
	 */
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
	/**
	 * @brief Constructs a new bicycle.
	 * @param ID Bicycle's ID
	 * @param productName Bicycle's product name
	 */
	Bicycle(string ID,string productName);
	
	/// @return The bicycle's ID
	string getID();
	
	/// @return The bicycle's product name
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
	/**
	 * @brief Constructs a new empty bicycle list.
	 */
	BicycleList();
	
	/**
	 * @brief Adds a new bicycle to the list.
	 * @param id Bicycle's ID
	 * @param productName Bicycle's product name
	 */
	void addNewBicycle(string id,string productName);
	
	/**
	 * @brief Retrieves a bicycle by its ID.
	 * @param id Bicycle's ID to search for
	 * @return Pointer to the found bicycle, or nullptr if not found
	 */
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
	/**
	 * @brief Constructs a new rental status.
	 * @param userID ID of the renting user
	 * @param bicycle Pointer to the rented bicycle
	 */
	RentalStatus(string userID,Bicycle* bicycle);
	
	/// @return The ID of the renting user
	string getUserID();
	
	/// @return Pointer to the rented bicycle
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
	/**
	 * @brief Constructs a new empty rental status list.
	 */
	RentalStatusList();
	
	/**
	 * @brief Adds a new rental status to the list.
	 * @param userID ID of the renting user
	 * @param bicycle Pointer to the rented bicycle
	 */
	void addNewRentalStatus(string userID,Bicycle *bicycle);
	
	/**
	 * @brief Gets the current number of rentals.
	 * @return Number of active rentals
	 */
	int getSize() const { return idx; }
	
	/**
	 * @brief Gets a rental status by index.
	 * @param index Position in the list
	 * @return Pointer to the rental status at the given index
	 */
	RentalStatus* getRentalStatus(int index) const { return list[index]; }
	
	/**
	 * @brief Retrieves all rentals for a specific user.
	 * @param userID ID of the user whose rentals to find
	 * @param result Array to store the found bicycles
	 * @return Number of bicycles found
	 */
	int fetchRentalStatusByID(string userID, Bicycle* result[]) const;
};