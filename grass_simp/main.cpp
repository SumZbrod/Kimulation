#include <SFML/Graphics.hpp>
#include <iostream>
#include "Karta.h"


void test_karta() {
	int w = 12;
	int h = 8;
	Karta forest(h, w);
	forest.show();
	//forest.getRouteWithoutWall(1, 1, 3, 3);
}

int main() {
	//test_ptr_array();
	//test_break();
	//test_exeption();
	test_karta();
	return 0;
}