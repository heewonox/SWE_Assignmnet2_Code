#include<map>
#include<string>
#define lenList 300
using namespace std;
class Accounts{
private:
	string id;
	string password;
	string phone;
public:
	Accounts(string id,string password,string phone);
	string getID();
	string getPassword();
	string getPhone();
};
class IDList{
private:
	Accounts* list[lenList];
	int idx;
public:
	IDList();
	void addNewAccount(string id,string password,string phone);
	bool isAdmin(string id,string password);
	bool isValidAccount(string id,string password);
};

class Bicycle{
private:
	string ID;
	string productName;
public:
	Bicycle(string ID,string productName);
	string getID();
	string getProductName();
};
class BicycleList{
private:
	Bicycle* list[lenList];
	int idx;
public:
	BicycleList();
	void addNewBicycle(string id,string productName);
	Bicycle* fetchBicycleByID(string id);
};

class RentalStatus{
private:
	string userID;
	Bicycle *bicycle;
public:
	RentalStatus(string userID,Bicycle* bicycle);
	string getUserID();
	Bicycle* getBicycle();
};
class RentalStatusList{
//fuck!!!
public:
	RentalStatus *list[lenList];
	int idx;
	RentalStatusList();
	void addNewRentalStatus(string userID,Bicycle *bicycle);
};