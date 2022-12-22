#include <SFML/Graphics.hpp>
#include <iostream>
#include "Karta.h"


void test_karta() {
	int w = 12;
	int h = 8;
	Karta forest(h, w);
	int* A = forest.getRouteWithoutWall(1, 1, 3, 3);
	//delete[] A;
}

int main() {
	//test_ptr_array();
	//test_break();
	//test_exeption();
	test_karta();
	return 0;
}