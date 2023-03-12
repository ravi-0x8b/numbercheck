#include <iostream>
#include <ctime>
#include "fill.h"

struct NumberAnalyzer {
	int small_index;
	int small_value;
	int big_index;
	int big_value;
};

int* loadFromDisk(const char*, int);
NumberAnalyzer numberVerify(const int*, int);

int main(int argc, char** argv) {
	std::srand(std::time(nullptr));

	fillFile(100);
	
	int* array = loadFromDisk("numbers.txt", 100);

	NumberAnalyzer analyzer = numberVerify(array, 100);

	std::cout << "Position " << analyzer.big_index << " contains the largest number ( " << analyzer.big_value << " )\n";
	std::cout << "Position " << analyzer.small_index << " contains the smallest number ( " << analyzer.small_value << " )\n";

	delete[] array;
	return 0;
}

int* loadFromDisk(const char* path, int buffer) {
	std::fstream file;
	file.open(path, std::ios_base::in);

	if (!file.is_open())
		return nullptr;

	int* arr = new int[buffer];
	for (int i = 0; i < buffer; i++)
		file >> arr[i];
	return arr;
}

NumberAnalyzer numberVerify(const int* vec, int size) {
	NumberAnalyzer number{ 0, 0, 0, 0 };

	for (int i = 0; i < size; ++i) {
		if (vec[i] > number.big_index) {
			number.big_index = i;
			number.big_value = vec[i];
		}
		else {
			number.small_index = i;
			number.small_value = vec[i];
		}
	}
	return number;
}