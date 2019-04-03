#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>   

using namespace std;

class stack
{
private:
	int Size;
	string *data;
	int last;
public:
	stack(int N)
	{
		Size = N;
		last = 0;
		data = new string[Size];
	}
	void push(const string value);
	bool pop(string &out);
	bool show_top(string &value);
};

void output(ifstream &new_file, stack &numbers, stack &symbols);

int main()
{
	int count = 0;
	int max_size = 100;
	stack symbols(max_size);
	stack numbers(max_size);
	string line;
	string text;
	ifstream file("text.txt");
	if (!file.is_open())
		cout << "Error";
	else
	{
		while (!file.eof())
		{
			getline(file, line);
			int size = line.size();
			int i = 0;
			while (size > 0)
			{
				if (line[i] == '(')
				{
					i++;
					size--;
					while (line[i] != ')')
					{
						if (isdigit(line[i]))
						{
							string str;
							while (isdigit(line[i]))
							{
								str = str + to_string(line[i]);
								i++;
							}
							numbers.push("!");
							numbers.push(str);
						}
						else
						{
							string elem;
							elem = line[i];
							i++;
							size--;
							while (islower(line[i]))
							{
								elem = elem + line[i];
								i++;
								size--;
							}
							symbols.push(elem);
							count++;
						}
					}
					string str;
					while (count != 0)
					{
						string value;
						numbers.show_top(value);
						if (value[0] = '!')
						{
							numbers.pop(value);
							numbers.pop(value);
							int value_num = atoi(value.c_str());
							int value_num1 = atoi(str.c_str());
							int value0 = value_num * value_num1;
							string value_str = to_string(value0);
							numbers.push(value_str);
						}
						else
						{
							str = line[i];
							numbers.push(str);
						}
						count--;
					}


				}
				if (isdigit(line[i]))
				{
					string str;
					while (isdigit(line[i]))
					{
						str = str + to_string(line[i]);
						i++;
					}
					symbols.push(str);
				}
				else
				{
					string elem;
					elem = line[i];
					i++;
					size--;
					while (islower(line[i]))
					{
						elem = elem + line[i];
						i++;
						size--;
					}
					symbols.push(elem);
				}

			}

		}
	}


	ofstream new_file("text_new.txt");
	output(new_file, numbers, symbols);

}

void stack::push(const string value)
{
	if (last == Size)
	{
		cout << "Stack overload " << endl;
		exit(1);
	}
	data[last++] = value;
}

bool stack::pop(string &out)
{
	if (last < 1)
		return false;
	out = data[--last];
	return true;
}

bool stack::show_top(string &value)
{
	if (last < 1)
		return false;
	value = data[--last];
	last++;
	return true;
}

void output(ifstream &new_file, stack &numbers, stack &symbols)
{
	string value;
	bool flag1 = true;
	bool flag2 = true;
	while (flag1 = true || flag2 == true)
	{
		if (symbols.pop(value))
			//cout << value << ": ";
		{
			new_file >> value;

		}

		if (numbers.pop(value))

		{
			new_file >> value;
		}
	}
}
