#include"elements.h"
using namespace std;
class SignUpUI{
public:
	string getID(ifstream& in_fp);
	string getPassword(ifstream& in_fp);
	string getPhone(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string id,string password,string phone);
};
class SignUp{
private:
	SignUpUI ui;
	IDList *idlist;
public:
	SignUp(IDList *idlist);
	void job(ifstream& in_fp, ofstream& out_fp);
};
class LogInUI{
public:
	string getID(ifstream& in_fp);
	string getPassword(ifstream& in_fp);
	void showOutput(ofstream& out_fp, string id,string password);
};
class LogIn{
private:
	LogInUI ui;
	IDList *idlist;
public:
	LogIn(IDList *idlist);
	string setCurrentSessionID(ifstream& in_fp, ofstream& out_fp);
	bool isAdmin();
	bool isValidAccount();
};

class LogOutUI{
public:
	void getInput();
	void ShowOutput(ofstream& out_fp, string id);
};
class LogOut{
private:
	LogOutUI ui;
public:
	bool isLogOutSuccessful(string id, ofstream& out_fp);
};
class RentBicycleUI{
public:
	string getBikeID(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string bikeID,string productName);
};
class RentBicycle{
private:
	RentBicycleUI ui;
	RentalStatusList *rentalList;
	BicycleList *bikeList;
public:
	void job(string userID,RentalStatusList *rL,BicycleList *bL, ifstream& in_fp, ofstream& out_fp);
};
class ShowRentalInfoUI{
public:
	void getInput();
	void ShowOutput(ofstream& out_fp, Bicycle* bicycles[], int count);
};
class ShowRentalInfo{
private:
	ShowRentalInfoUI ui;
	RentalStatusList *list;
public:
	ShowRentalInfo(RentalStatusList *list);
	void job(string userID, ofstream& out_fp);
};
class AddBicycleUI{
public:
	string getID(ifstream& in_fp);
	string getProductName(ifstream& in_fp);
	void ShowOutput(ofstream& out_fp, string id,string productName);
};
class AddBicycle{
private:
	AddBicycleUI ui;
	BicycleList *list;
public:
	AddBicycle(BicycleList *list);
	void job(ifstream& in_fp, ofstream& out_fp);
};

