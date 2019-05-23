#pragma once
#include<iostream>
using namespace std;
void choiceMember() {
	cout << "1:-input car \n";
	cout << "2:-output car \n";
	cout << "3:-Back to menu \n";
	cout << "your choice :";

}
void choiceManger() {
	cout << "1:-number of cars in day :\n";
	cout << "2:-number of cars in garage now :\n";
	cout << "3:-search of car :\n";
	cout << "4:-Back to menu:\n";
	cout << "5:-Exit \n";
	cout << "your choice :";
}
void choice() {
	cout << "1:-Manger\n";
	cout << "2:-User\n";
	cout << "your choice :";
}
void mainchoice() {
	cout << "1:-Car Parking With One Gate\n";
	cout << "2:-Car Parking With Two Gates\n";
	cout << "your choice :";
}
bool login(string name, string pass) {
	if (name == "admin"&&pass == "12345") {
		return true;
	}
	else {
		return false;
	}
}