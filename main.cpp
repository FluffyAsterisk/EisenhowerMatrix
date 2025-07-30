#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

// Returns text with padding for specified width
string get_text_with_pad(string text, unsigned int pad_width)
{
	if (pad_width < text.length())
	{
		cout << "Not enough space :(";
		exit(1);
	}

	long unsigned int tl = text.length();
	int l = (pad_width - tl)/2;

	string pl{};
	for (int i = 0; i < l; i++)
	{
		pl += ' ';
	}

	string pr{};
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
		cout << '-';
	}

	cout << '\n';
}

void draw_sector(int width, string text="", bool right_border=true)
{
	cout << '|';

	if (text == "")
	{
		for (int i = 0; i < width-1; i++) cout << ' ';
	}
	else 
	{
		cout << get_text_with_pad(text, width-1);
	}

	if (right_border) cout << '|';
}

void draw_line(int width, string text[] = {})
{
	int sector_width = width / 2;

	draw_sector(sector_width, text[0], false);
	draw_sector(sector_width, text[1]);

	cout << '\n';
}

void draw_tasks(int width, string arr1[], string arr2[], int arr1_sz, int arr2_sz)
{
	unsigned int max_length = max(arr1_sz, arr2_sz);

	for (int i = 0; i < max_length; i++)
	{
		// If one array is bigger than other
		if (i >= arr1_sz && i < arr2_sz )
		{
			string text[] = {"", arr2[i]};
			draw_line(width, text);
		}
		else if (i < arr1_sz && i >= arr2_sz ) 
		{
			string text[] = {arr1[i], ""};
			draw_line(width, text);
		}
		else
		{
			string text[] = {arr1[i], arr2[i]};
			draw_line(width, text);
		}
	}
}

void draw_table(int width)
{
	string ui[] = {"ur, imp", "Do tasks", "Do some more", "Another one", "aksdfj","knocks"};
	string ni[] = {"not ur, imp", "asd", "12345"};
	string un[] = {"ur, not imp", "asd", "12345"};
	string nn[] = {"not ur, not imp", "asd", "12345", "knockckckc"};

	draw_y_border(width);

	draw_tasks(width, ui, ni, size(ui), size(ni));

	draw_y_border(width);

	draw_tasks(width, un, nn, size(un), size(nn));

	draw_y_border(width);

	cout << endl;
}

int main(int argc, char* argv[])
{
	int width{};

	if (argc < 2)
	{
		cout << "Not enough arguments";
		return 1;
	}

	width = stoi(argv[1]);

	draw_table(width);

	return 0;
}