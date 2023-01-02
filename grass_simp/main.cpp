#include "Karta.h"
#include "Okno.h"
#include "Human.h"

void test_karta() {
	int h = 8;
	int w = 12;

	Karta forest(h, w);

	int window_height = 1440, window_width = 810;
	Okno village_window(window_height, window_width, forest);

	village_window.loop();

	//int* A = forest.getRouteWithoutWall(1, 1, 3, 3);
	//delete[] A;
	//std::vector<int> A = forest.getRouteWithoutWall(0, 0, 7, 7);

	

	//Okno Window(800, 600);
	//Window.loop(forest);


	//std::vector<int> B = forest.getRouteWithoutWall(4, 3, 1, 1);
	//std::vector<int>().swap(A);c
	//int y_start = -4, y_finish = 10;
	//int x_start = -4, x_finish = 15;

	/*for (int x = x_start; x <= x_finish; x++) {
		std::cout << "\t" << x;
	}
	std::cout << std::endl;*/

	/*for (int y = y_start; y <= y_finish; y++) {
		std::cout << y;
		for (int x = x_start; x <= x_finish; x++) {
			std::cout << '\t' << x << ", " << y;
		}
		std::cout << std::endl;
	}*/
	//int v = 0;
	//for (int y = y_start; y <= y_finish; y++) {
	//	std::cout << y;
	//	for (int x = x_start; x <= x_finish; x++) {
	//		v = int(forest.in_area(y, x));
	//		//std::cout << '\t' << v;
	//		std::cout << '\t' << v << ", " << v;
	//	}
	//	std::cout << std::endl;
	//}
}

int main() {

	//test_ptr_array();
	//test_break();
	//test_exeption();
	test_karta();
	std::cout << "ok";
	return 0;
}