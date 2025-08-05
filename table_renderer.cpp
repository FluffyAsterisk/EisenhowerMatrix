#include <iostream>
#include <cstdlib>
#include <string>

// Returns text with padding for specified width
std::string get_text_with_pad(std::string text, unsigned int pad_width)
{
	if (pad_width < text.length())
	{
		std::cout << "Not enough space :(";
		exit(1);
	}

	long unsigned int tl = text.length();
	int l = (pad_width - tl)/2;

	std::string pl{};
	for (int i = 0; i < l; i++)
	{
		pl += ' ';
	}

	std::string pr{};
	for (int i=0; i < pad_width - (l+tl); i++)
	{
		pr += ' ';
	}

	return pl + text + pr;
}

void draw_y_border(int width)
{
	for (int i = 0; i < width; i++)
	{
		std::cout << '-';
	}

	std::cout << '\n';
}

void draw_sector(int width, std::string text="", bool right_border=true)
{
	std::cout << '|';

	if (text == "")
	{
		for (int i = 0; i < width-1; i++) std::cout << ' ';
	}
	else 
	{
		std::cout << get_text_with_pad(text, width-1);
	}

	if (right_border) std::cout << '|';
}

void draw_line(int width, std::string text[] = {})
{
	int sector_width = width / 2;

	draw_sector(sector_width, text[0], false);
	draw_sector(sector_width, text[1]);

	std::cout << '\n';
}

void draw_tasks(int width, std::string arr1[], std::string arr2[], int arr1_sz, int arr2_sz)
{
	unsigned int max_length = std::max(arr1_sz, arr2_sz);

	for (int i = 0; i < max_length; i++)
	{
		// If one array is bigger than other
		if (i >= arr1_sz && i < arr2_sz )
		{
			std::string text[] = {"", arr2[i]};
			draw_line(width, text);
		}
		else if (i < arr1_sz && i >= arr2_sz ) 
		{
			std::string text[] = {arr1[i], ""};
			draw_line(width, text);
		}
		else
		{
			std::string text[] = {arr1[i], arr2[i]};
			draw_line(width, text);
		}
	}
}

void draw_table(int width)
{
	std::string ui[] = {"ur, imp", "Do tasks", "Do some more", "Another one", "aksdfj","knocks"};
	std::string ni[] = {"not ur, imp", "asd", "12345"};
	std::string un[] = {"ur, not imp", "asd", "12345"};
	std::string nn[] = {"not ur, not imp", "asd", "12345", "knockckckc"};

	draw_y_border(width);

	draw_tasks(width, ui, ni, size(ui), size(ni));

	draw_y_border(width);

	draw_tasks(width, un, nn, size(un), size(nn));

	draw_y_border(width);

	std::cout << std::endl;
}
