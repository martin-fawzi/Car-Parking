#pragma once
#include"Stack.h"
#include"car.h"
#include<deque>
#include"choices.h"
#include<iostream>
#include<string>
int Search(string carnum, int size);
void printDeque(int size);
deque<Car>* myDeque;
Stack *MyStack;
void System2() {
	int y, countCar = 0, c, fail = 0;
	char x, z,go;
	bool exit = false;
	cout << "please enter Number of cars in DequeGarage :";
	cin >> y;
	int size = 0;
	string name, pass;
	myDeque = new deque<Car>(y);
	MyStack = new Stack(y);
	Car c1, c2;
	string NumCar, color;
	do {
		choice();
		cin >> z;
		switch (z) {
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
						cout << "Numbers of cars in garage now :" << size << endl;
						break;
					case '3':

						cout << "enter number of that  you want search about it:";
						cin >> NumCar;
						if (Search(NumCar, size) >= 0) {
							cout << "this car in :" << Search(NumCar, size)+1 << endl;
						}
						else {
							cout << "car not found!!\n";
						}
						break;
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
			cin >> x;
			switch (x)
			{
			case '1':
				if (size != y) {
					cout << "Enter your Number Car\n";
					cin >> NumCar;
					cout << "Enter your Car Color\n";
					cin >> color;
					c1 = Car(NumCar, color);
					myDeque->push_front(c1);
					countCar++;
					size++;
				}
				else {
					cout << "The garage in full:\n";
				}
				break;
			case '2':
				cout << "Enter your Number Car\n";
				cin >> NumCar;
				cout << "1-gate one " << endl;
				cout << "2-gate two" << endl;
				cin >> go;
				switch (go)
				{
				case '1':
					if (Search(NumCar, size) > 0) {
						cout << "car number is ::" << NumCar << endl;
						c2 = myDeque->back();
						if (myDeque->back().getCarNumber() == NumCar) {
							myDeque->pop_back();
							size--;
							cout << "pop back done!" << endl;
						}
						else {
							c = Search(NumCar, size);
							for (int a = 0; a < c; a++) {
								MyStack->push(myDeque->back());
								myDeque->pop_back();

							}
							cout << "into Stack :\n";
							MyStack->print();
							size--;
							myDeque->pop_back();
							cout << "pop back done!" << endl;
							for (int a = 1; a < c; a++) {
								myDeque->push_back(MyStack->pop());
							}
						}
					}
					else {
						cout << "not found::\n";
					}
					break;
			case'2':
					if (Search(NumCar, size) > 0) {
	                    cout << "car number is ::" << NumCar << endl;
	                    c2 = myDeque->front();
	                    if (c2.getCarNumber() == NumCar) {
		                    myDeque->pop_front();
	  	                    size--;
							cout << "pop front done!" << endl;
						}
	                    else {
	                	     c = Search(NumCar, size);
		                     for (int a = 1; a < c; a++) {
			                      MyStack->push(myDeque->front());
			                      myDeque->pop_front();
	       	                 }
	                     	 cout << "into Stack :\n";
		                     MyStack->print();
		                     size--;
		                     myDeque->pop_front();
							 cout << "pop front done!" << endl;
	                    	for (int a = 1; a < c; a++) {
			                     myDeque->push_front(MyStack->pop());
		                    }
	                    }
                    }
                    else {
	                     cout << "not found::\n";
                    }
                    break;

				default:
					break;
				}
		//	int sr = Search(NumCar, size);
					//if (sr <= (y / 2)) {
				


				break;
				/*default:
				cout << "please enter vaild choice::\n";
				break;*/
			}
			break;
		default:
			cout << "please enter vaild choice::\n";
			break;
		}

	} while (exit == false);
	cout << "<<<<<<<<<<<<<<<<<<<<<Thank you for Trace>>>>>>>>>>>>>>>>>>>>>\n";

}
int Search(string carnum, int size) {
	Car a;
	int x = 0;
	for (int i = 0; i <= size; i++) {
		a = myDeque->at(x);
		x++;
		if (a.getCarNumber() == carnum) {
			return  i;
		}
	}
	return -1;

}
void printDeque(int size)
{
	for (int i = 0; i < size; i++) {
		cout << "car :" << myDeque->at(i).getCarNumber() << endl;
	}
}
/*if (Search(NumCar, size) > 0) {
	cout << "car number is ::" << NumCar << endl;
	c2 = myDeque->front();
	if (c2.getCarNumber() == NumCar) {
		myDeque->pop_front();
		size--;
	}
	else {
		c = Search(NumCar, size);
		for (int a = 1; a < c; a++) {
			MyStack->push(myDeque->front());
			myDeque->pop_front();
		}
		cout << "into Stack :\n";
		MyStack->print();
		size--;
		myDeque->pop_front();
		for (int a = 1; a < c; a++) {
			myDeque->push_front(MyStack->pop());
		}
	}
}
else {
	cout << "not found::\n";
}
break;*/

