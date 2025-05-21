#include<iostream>
#include<fstream>
#include"controls.h"
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;
void parsingCode();
ifstream in_fp;
ofstream out_fp;
int main(){
	in_fp.open(INPUT_FILE_NAME);
	out_fp.open(OUTPUT_FILE_NAME);
	
	parsingCode();
	
	in_fp.close();
	out_fp.close();
	return 0;
}
void parsingCode(){
	int menu_level_1=0,menu_level_2=0;
	bool isProgramExit=false;
	
	string CURRENT_SESSION_ID="guest";
	
	//Session-Wide Elements
	IDList idlist;
	BicycleList bicyclelist;
	RentalStatusList rentalstatus;

	//Controller instances
	SignUp signup(&idlist);
	LogIn login(&idlist);
	LogOut logout;
	RentBicycle rentbicycle;
	ShowRentalInfo showrentalinfo(&rentalstatus);
	AddBicycle addbicycle(&bicyclelist);

	while(!isProgramExit){
		in_fp>>menu_level_1>>menu_level_2;
		switch(menu_level_1){
			case 1:
			{
				switch(menu_level_2){
					case 1:
					{
						//Sign up
						signup.job(in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 2:
			{
				switch(menu_level_2){
					case 1:
					{
						//Log in
						CURRENT_SESSION_ID=login.setCurrentSessionID(in_fp, out_fp);
						break;
					}
					case 2:
					{
						//Log out
						if(logout.isLogOutSuccessful(CURRENT_SESSION_ID, out_fp)){
							CURRENT_SESSION_ID="guest";
						}
						break;
					}
				}
				break;
			}
			case 3:
			{
				switch(menu_level_2){
					case 1:
					{
						//Add new Bike
						addbicycle.job(in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 4:
			{
				switch(menu_level_2){
					case 1:
					{
						//Rent bike
						rentbicycle.job(CURRENT_SESSION_ID,&rentalstatus,&bicyclelist, in_fp, out_fp);
						break;
					}
				}
				break;
			}
			case 5:
			{
				switch(menu_level_2){
					case 1:
					{
						//Show Rental info
						showrentalinfo.job(CURRENT_SESSION_ID, out_fp);
						break;
					}
				}
				break;
			}
			case 6:
			{
				switch (menu_level_2){
					case 1:
					{
						//end
						out_fp<<"6.1. 종료"<<endl;
						isProgramExit=true;
						break;
					}
				}
				break;
			}
		}
	}
}