// Points 2.0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <conio.h>
#include "Base.h"
#include "Point3Dh.h"


class Points 
{
	std::vector<Base*> v;
public:
	
	void print_points();
	void remove_point();
	void app_end_point(Base *point);
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
	std::cout << "Enter X: ";
	x = set_value<T>();
	std::cout << "Enter Y: ";
	y = set_value<T>();
	std::cout << "Enter Z: ";
	z = set_value<T>();
	std::cout << "Enter H: ";
	h = set_value<T>();
	Point3Dh <T> newpoint(x, y, z, h);
	return newpoint;
}




void Points::print_points()
{
	if (v.size() == 0)
	{
		system("cls");
		std::cout << "List is empty!\n\nPress Enter to Continue\n";
		_getch();
		return;
	}
	else
	{
		//std::cout << v.size() <<"\n";
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << i << ") ";
			v[i]->show();
		}
		_getch();
	}
}

void Points::remove_point()
{
	std::cout << "Choose point which you want to remove: \n";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << i << ") ";
		v[i]->show();
	}
	if (v.size() == 0)
		return;
	int n = set_value<int>();
	//system("cls");
	auto iter = v.cbegin();
	v.erase(iter + n);
}



void Points::app_end_point(Base* point)
{
	v.push_back(point);
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
		if (cmd == 1)
		{
			system("cls");
			Point3Dh <int> newPoint = create_point_3Dh<int>();
			Points.app_end_point(&newPoint);
		}
		else if (cmd == 2)
		{
			system("cls");
			Point3Dh <double> newPoint = create_point_3Dh<double>();
			Points.app_end_point(&newPoint);
		}
		else if (cmd == 3)
		{
			system("cls");
			Point3Dh <float> newPoint = create_point_3Dh<float>();
			Points.app_end_point(&newPoint);
		}
		else if (cmd == 4)
		{
			system("cls");
			Points.print_points();
		}
		else if (cmd == 5)
		{
			system("cls");
			Points.remove_point();
		}
		else if (cmd == 0)
		{
			break;
		}
	}
}
