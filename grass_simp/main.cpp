#include <SFML/Graphics.hpp>
#include <iostream>
#include "Karta.h"


void test_karta() {
	int w = 12;
	int h = 8;
	Karta forest(h, w);
	
	forest.getRoute_withoutwall(0, 0, 0, 3);
}

void test_ptr_array() {
	int* ptr = new int[10];
	int* ptr2 = ptr;
	std::cout << ptr << '\t' << ptr2 << '\n';
	for (int i = 0; i < 10; i++) {
		*ptr = i;
		ptr++;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << *ptr2++ << "\t";
	}
	ptr2 -= 3;
	std::cout << '\n' << *ptr2;
}

void test_break() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << j + 10 * i << '\t';
			if (j == 5) break;
		}
		std::cout << '\n';
	}
}

void test_exeption() {
	try {
		throw "problem";
	}
	catch (...) {
		std::cout << "_-_";
	}
}

int main() {
	//test_ptr_array();
	//test_break();
	//test_exeption();
	test_karta();
	return 0;
}