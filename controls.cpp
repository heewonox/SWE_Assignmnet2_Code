#include<iostream>
#include<fstream>
#include"controls.h"
using namespace std;
string SignUpUI::getID(ifstream& in_fp){
	string input;
	in_fp>>input;
	return input;
}
string SignUpUI::getPassword(ifstream& in_fp){
	string input;
	in_fp>>input;
	return input;
}
string SignUpUI::getPhone(ifstream& in_fp){
	string input;
	in_fp>>input;
	return input;
}
void SignUpUI::ShowOutput(ofstream& out_fp, string id,string password,string phone){
	out_fp<<"1.1. 회원가입"<<endl;
	out_fp<<"> "<<id<<" "<<password<<" "<<phone<<" "<<endl;
	return;
}
SignUp::SignUp(IDList *idlist){
	this->idlist=idlist;
}
void SignUp::job(ifstream& in_fp, ofstream& out_fp){
	string id=ui.getID(in_fp);
	string password=ui.getPassword(in_fp);
	string phone=ui.getPhone(in_fp);
	idlist->addNewAccount(id,password,phone);
	ui.ShowOutput(out_fp, id,password,phone);
}
string LogInUI::getID(ifstream& in_fp){
	string input;
	in_fp>>input;
	return input;
}
string LogInUI::getPassword(ifstream& in_fp){
	string input;
	in_fp>>input;
	return input;
}
void LogInUI::showOutput(ofstream& out_fp, string id,string password){
	out_fp<<"2.1. 로그인"<<endl;
	out_fp<<"> "<<id<<" "<<password<<endl;
	return;
}
LogIn::LogIn(IDList *idlist){
	this->idlist=idlist;
}
string LogIn::setCurrentSessionID(ifstream& in_fp, ofstream& out_fp){
	string id=ui.getID(in_fp);
	string password=ui.getPassword(in_fp);
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
void LogOutUI::getInput(){}
void LogOutUI::ShowOutput(ofstream& out_fp, string id){
	out_fp<<"2.2 로그아웃"<<endl;
	out_fp<<"> "<<id<<endl;
}
bool LogOut::isLogOutSuccessful(string id, ofstream& out_fp){
	ui.getInput();
	ui.ShowOutput(out_fp, id);
	return true;
}
string AddBicycleUI::getID(ifstream& in_fp){
	string id;
	in_fp>>id;
	return id;
}
string AddBicycleUI::getProductName(ifstream& in_fp){
	string pm;
	in_fp>>pm;
	return pm;
}
void AddBicycleUI::ShowOutput(ofstream& out_fp, string id,string productName){
	out_fp<<"3.1. 자전거 등록"<<endl;
	out_fp<<"> "<<id<<" "<<productName<<endl;
}
AddBicycle::AddBicycle(BicycleList *list){
	this->list=list;
}
void AddBicycle::job(ifstream& in_fp, ofstream& out_fp){
	string id=ui.getID(in_fp);
	string productName=ui.getProductName(in_fp);
	list->addNewBicycle(id,productName);
	ui.ShowOutput(out_fp, id,productName);
}
string RentBicycleUI::getBikeID(ifstream& in_fp){
	string id;
	in_fp>>id;
	return id;
}
void RentBicycleUI::ShowOutput(ofstream& out_fp, string bikeID,string productName){
	out_fp<<"4.1. 자전거 대여"<<endl;
	out_fp<<"> "<<bikeID<<" "<<productName<<endl;
	return;
}
void RentBicycle::job(string userID,RentalStatusList *rL,BicycleList *bL, ifstream& in_fp, ofstream& out_fp){
	string bikeID=ui.getBikeID(in_fp);
	rentalList=rL;
	bikeList=bL;
	//first : get matching bike
	Bicycle* tmp=bikeList->fetchBicycleByID(bikeID);
	//second : make rental instance
	rentalList->addNewRentalStatus(userID,tmp);
	ui.ShowOutput(out_fp, tmp->getID(),tmp->getProductName());
}
void ShowRentalInfoUI::getInput(){}
void ShowRentalInfoUI::ShowOutput(ofstream& out_fp, string id,string productName){
	out_fp<<"> "<<id<<" "<<productName<<endl;
}
ShowRentalInfo::ShowRentalInfo(RentalStatusList *list){
	this->list=list;
}
void ShowRentalInfo::job(string userID, ofstream& out_fp){
	for(int i=0;i<list->idx;i++){
		if(list->list[i]->getUserID()==userID){
			ui.ShowOutput(out_fp, list->list[i]->getBicycle()->getID(),list->list[i]->getBicycle()->getProductName());
		}
	}
}