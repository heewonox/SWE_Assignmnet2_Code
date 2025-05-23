#include<iostream>
#include<fstream>
#include"controls.h"
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

/**
 * @brief Parses and processes user commands from the input file.
 * 
 * This function handles the main program loop, reading commands and delegating
 * to appropriate controllers based on the menu selection.
 */
void parsingCode();

ifstream in_fp;   ///< Input file stream for reading commands
ofstream out_fp;  ///< Output file stream for writing results

/**
 * @brief Main entry point of the bicycle rental system.
 * 
 * Initializes file streams and starts the command processing loop.
 * @return 0 on successful execution
 */
int main(){
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	
	parsingCode();
	
	in_fp.close();
	out_fp.close();
	return 0;
}

void parsingCode(){
	int menu_level_1=0,menu_level_2=0;  ///< Menu selection variables
	bool isProgramExit=false;           ///< Program termination flag
	
	string CURRENT_SESSION_ID="guest";  ///< Current user's session ID, defaults to guest
	
	// Session-Wide Elements - Shared across all operations
	AccountList accountlist;              ///< Manages user accounts
	BicycleList bicyclelist;    ///< Manages bicycle inventory
	RentalStatusList rentalstatus;  ///< Tracks bicycle rentals

	// Controller instances for different operations
	SignUp signup;              ///< Handles user registration
	LogIn login;                ///< Handles user authentication
	LogOut logout;              ///< Handles user logout
	RentBicycle rentbicycle;    ///< Handles bicycle rental
	ShowRentalInfo showrentalinfo;  ///< Displays rental information
	AddBicycle addbicycle;      ///< Handles bicycle registration

	while(!isProgramExit){
		in_fp>>menu_level_1>>menu_level_2;
		switch(menu_level_1){
			case 1:  // Account Management
			{
				switch(menu_level_2){
					case 1:  // Sign up
					{
						signup.job(&accountlist, in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 2:  // Session Management
			{
				switch(menu_level_2){
					case 1:  // Log in
					{
						CURRENT_SESSION_ID=login.setCurrentSessionID(&accountlist, in_fp, out_fp);
						break;
					}
					case 2:  // Log out
					{
						if(logout.isLogOutSuccessful(CURRENT_SESSION_ID, out_fp)){
							CURRENT_SESSION_ID="guest";
						}
						break;
					}
				}
				break;
			}
			case 3:  // Bicycle Management
			{
				switch(menu_level_2){
					case 1:  // Add new Bike
					{
						addbicycle.job(&bicyclelist, in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 4:  // Rental Operations
			{
				switch(menu_level_2){
					case 1:  // Rent bike
					{
						rentbicycle.job(CURRENT_SESSION_ID, &rentalstatus, &bicyclelist, in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 5:  // Information Display
			{
				switch(menu_level_2){
					case 1:  // Show Rental info
					{
						showrentalinfo.job(CURRENT_SESSION_ID, &rentalstatus, out_fp);
						break;
					}
				}
				break;
			}
			case 6:  // Program Control
			{
				switch (menu_level_2){
					case 1:  // End program
					{
						out_fp<<"6.1. 종료";
						isProgramExit=true;
						break;
					}
				}
				break;
			}
		}
	}
}