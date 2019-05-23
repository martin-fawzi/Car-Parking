
#pragma once
#pragma warning( disable : 4290 ) 
#include<iostream>
#include<string>
using namespace std;

class Car
{
private:
	string Color;
	string CarNumber;
public:
	Car() {

	}
	Car(string CarNumber, string Color) {
		this->CarNumber = CarNumber;
		this->Color = Color;
	}
	string getCarNumber() {
		return CarNumber;
	}

};
