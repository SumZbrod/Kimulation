#include "Karta.h"


void test_karta() {
	int w = 12;
	int h = 8;
	Karta forest(h, w);
	forest.show();
	//int* A = forest.getRouteWithoutWall(1, 1, 3, 3);
	//delete[] A;
	std::vector<int> A = forest.getRouteWithoutWall(1, 1, 3, 3);
	std::vector<int>().swap(A);

}

int main() {
	//test_ptr_array();
	//test_break();
	//test_exeption();
	test_karta();
	std::cout << "ok";
	return 0;
}