#pragma once
#include<iostream>
#include"car.h"

#include<string>

using namespace std;

class Stack {
private:
	int top;
	int capacity;
	Car *storage;

public:
	Stack() {}
	Stack(int c) {
		if (c <= 0)
			throw string("Stack's capacity must be positive");
		storage = new Car[c];
		capacity = c;
		top = -1;
	}
	void push(Car value) {
		if (top == capacity - 1)
			throw string("Stack's underlying storage is overflow");
		top++;
		storage[top] = value;
	}

	Car pop() {
		if (top == -1)
			throw string("Stack is empty");
		return storage[top--];
	}

	Car peek() {

		return storage[top];
	}

	bool isEmpty() {
		return (top == -1);
	}

	void clear() {
		top = -1;
	}

	int getSize() {
		return top + 1;
	}

	void print() {
		Car c;
		if (top == -1) {
			throw string("Stack is empty");
		}
		else {
			for (int i = 0; i <= top; i++)
				c = storage[i];
			cout << c.getCarNumber() << endl;

			cout << endl;
		}
	}
	int search(string x) {
		Car a;

		for (int y = 0; y < (top + 1); y++) {
			a = storage[y];
			if (x == a.getCarNumber())
				return y;

		}
		return -1;
	}

	~Stack() {
		delete[] storage;
	}

};
