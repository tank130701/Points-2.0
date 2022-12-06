// Points 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include "Base.h"
#include "Point3Dh.h"


class Points 
{
	std::vector<Base*> Points;
public:
	void print_points();
	void remove_point();
	void create_point_int();
	void create_point_float();
	void create_point_double();
};

template<typename T>
T set_value()
{
	T value;
	while (!(std::cin >> value))
	{
		if (std::cin.eof())
		{
			throw "eof";
		}
		std::cin.clear(); //Сбрасываем флаг ошибки, если таковая была
		std::cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
		std::cout << "Try again: ";
	}
	return value;
}

template<typename T>
Point3Dh <T> create_point_3Dh()
{
	T x, y, z, h;
	
	//char letter;
	//std::cout << "Enter Letter: ";
	//std::cin >> letter;
	std::cout << "Enter X: ";
	x = set_value<T>();
	std::cout << "Enter Y: ";
	y = set_value<T>();
	std::cout << "Enter Z: ";
	z = set_value<T>();
	std::cout << "Enter H: ";
	h = set_value<T>();
	Point3Dh<T> newpoint = Point3Dh<T>(x, y, z, h);
	return newpoint;
}




void Points::print_points()
{
	if (Points.size() == 0)
	{
		system("cls");
		std::cout << "List is empty!\n\nPress Enter to Continue\n";
		_getch();
		return;
	}
	else
	{
		for (size_t i = 0; i < Points.size(); i++)
		{
			std::cout << i << ") ";
			Points[i]->show();
		}
		_getch();
	}
}

void Points::remove_point()
{
	std::cout << "Choose point which you want to remove: \n";
	for (size_t i = 0; i < Points.size(); i++)
	{
		std::cout << i << ") ";
		Points[i]->show();
	}
	if (Points.size() == 0)
		return;
	int n = set_value<int>();
	//system("cls");
	auto iter = Points.cbegin();
	Points.erase(iter + n);
}

void Points::create_point_int()
{
	Point3Dh <int> newPoint = create_point_3Dh<int>();
	Points.push_back(&newPoint);
}

void Points::create_point_float()
{
	Point3Dh <float> newPoint = create_point_3Dh<float>();
	Points.push_back(&newPoint);
}

void Points::create_point_double()
{
	Point3Dh <double> newPoint = create_point_3Dh<double>();
	Points.push_back(&newPoint);
}

int menu() {
	system("cls");
	std::cout <<
		"\n=====Points========\n\n"
		"1. Append point(int)\n"
		"2. Append point (double)\n"
		"3. Append point (float)\n"
		"4. Print points list\n"
		"5. Remove point\n"
		"0. Exit " << std::endl;
	int cmd;
	std::cout << "~$ ";
	std::cin >> cmd;
	return cmd;
};

int main()
{
	Points Points;
	while (true)
	{
		int cmd = menu();
		bool exit = false;
		switch (cmd) {
		case 0:
			exit = true;
			break;
		case 1:
			system("cls");
			Points.create_point_int();
			break;
		case 2:
			system("cls");
			Points.create_point_double();
			break;
		case 3:
			system("cls");
			Points.create_point_float();
			break;
		case 4:
			system("cls");
			Points.print_points();
			break;
		case 5:
			system("cls");
			Points.remove_point();
			break;
		};
		if (exit == true) break;
	}
}
