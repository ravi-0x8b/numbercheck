#include "fill.h"

void fillFile(int range) {
	std::fstream file;
	file.open("numbers.txt", std::ios_base::out);

	if (!file.is_open())
		return;

	for (int i = 0; i < range; ++i)
		file << std::rand() % MAX_RAND << ' ';
	file.close();
}
