#include <iostream>

void draw_table(int width);

int main(int argc, char* argv[])
{
	int width{};

	if (argc < 2)
	{
		std::cout << "Not enough arguments";
		return 1;
	}

	width = std::stoi(argv[1]);

	draw_table(width);

	return 0;
}