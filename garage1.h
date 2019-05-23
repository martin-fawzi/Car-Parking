#pragma once
#include"Stack.h"
#include"car.h"
#include"choices.h"
#include<iostream>
#include<string>
using namespace std;
Stack * s1;
Stack* s2;
void System1() {
	int y, countCar = 0, fail = 0;
	string numcar, color, name, pass;
	Car c1;
	char  x, z;
	bool exit = false;
	cout << "please enter number of cars in StackGarage :";
	cin >> y;
	s1 = new Stack(y);
	s2 = new Stack(y);
	do
	{
		choice();
		cin >> x;
		switch (x) {
		case '1':
			do {
				cout << "username :";
				cin >> name;
				cout << "password :";
				cin >> pass;
				if (login(name, pass) == true) {
					choiceManger();
					cin >> x;
					switch (x) {
					case '1':
						cout << "Numbers of cars in this day :" << countCar << endl;
						break;
					case '2':
						cout << "Numbers of cars in garage now :" << s1->getSize() << endl;
						break;
					case '3':

						cout << "enter number of that  you want search about it:";
						cin >> numcar;
						if (s1->search(numcar) < 0) {
							cout << "not found\n";

						}
						else {
							cout << "this car in :" << (s1->search(numcar)) + 1 << endl;

						}break;
					case '4':
						break;

					case '5':
						exit = true;
						break;
					}
					break;
				}
				else {
					cout << "try again!!\n";
					fail++;
				}
			} while (fail != 5);
			if (fail == 5) {
				cout << "try again later:::\n";
			}
			break;
		case '2':
			choiceMember();
			cin >> z;
			switch (z) {
			case '1':
				if (s1->getSize() < y) {
					cout << "enter number car\n";
					cin >> numcar;
					cout << "enter color\n";
					cin >> color;
					countCar++;
					s1->push(Car(numcar, color));
				}
				else {
					cout << "garage is full\n";
				}
				break;
			case '2':

				cout << "enter car number\n";
				cin >> numcar;
				if (s1->search(numcar) >= 0) {
					for (int q = 0; s1->peek().getCarNumber() != numcar && !(s1->isEmpty()); q++) {
						s2->push(s1->peek());
						s1->pop();
						cout << "Push done\n";
					}
					if (s1->peek().getCarNumber() == numcar) {
						s1->pop();
					}

				}
				else {
					cout << "not found !!\n";
				}
				for (int m = 0; m < s2->getSize(); m++) {

					s1->push(s2->peek());
					s2->pop();

				}break;
			case '3':
				break;

			}
		}
	} while (!exit);
}
