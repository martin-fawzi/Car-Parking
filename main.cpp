#include"garage1.h"
#include"garage2.h"
#include<iostream>
#include<string>
using namespace std;



int main() {
	char x;
	mainchoice();
	cin >> x;
	switch (x) {
	case '1':
		System1();
		break;
	case '2':
		System2();
		break;
	default:
		cout << "not vaild in choices:\n";

	}
	system("pause");

	return 0;
}

