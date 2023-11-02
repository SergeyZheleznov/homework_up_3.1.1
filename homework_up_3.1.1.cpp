// homework_3.1.1.cpp : This file contains the 'main' function.Program execution begins and ends there.
// Эта задача номер 1 урока 3, модуль "Продвинутое программирование"

#include <iostream>

class Smart_array
{
public:
	int size;
	int count = 0;
	int* arr;

public:
	Smart_array(const Smart_array&) = delete;
	Smart_array& operator=(const Smart_array&) = delete;

	Smart_array()
	{
		size = 5;
		arr = new int[size];

		// заполняем созданный массив нулями
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}

		std::cout << "Constructor called\n";
	}

	Smart_array(int size)
	{
		this->size = size;
		arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	~Smart_array()
	{
		delete[] arr;
		std::cout << "Destructor called\n";
	}

	int add_element(int x)
	{
		x = x;
		int* arr_temp;

		if ((count + 1) <= size)
		{
			// создаём временный массив arr_temp 
			arr_temp = new int[size];
			// передаём туда все значения из первичного массива
			for (int i = 0; i < size; i++)
			{
				arr_temp[i] = arr[i];
			}

			// если вызываем функцию добавления в массив элемента в первый раз, то кладём 
			// значение элемента в самый первый элемент массива, то есть с индексом 0
			arr_temp[count] = x;
	

			delete[] arr;
			arr = new int[size];

			for (int i = 0; i < size; i++)
			{
				arr[i] = arr_temp[i];
			}
			
			delete[] arr_temp;

			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << std::endl;
			}

			count = count + 1;
		}
		else
		{
			throw std::runtime_error("Количество элементов, которое Вы ходите ввести, больше, чем количество мест в массиве. Вы не можете больше вводить элементы массива");
		}
	}

	int get_element_from_index(int y)
	{
		if (y >= 0 && y < size)
		{
			std::cout << "Вот значение элемента массива соответствующим индексом" << std::endl;
			return arr[y];
		}
		else
		{
			throw std::runtime_error("Вы ввели значение ошибочное значение индекса, набирайте значение индекса правильно");
		}
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Hello World!\n";
	try {
		Smart_array arr(5);

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		//arr.add_element(19);

		std::cout << arr.get_element_from_index(0) << std::endl;
		std::cout << arr.get_element_from_index(2) << std::endl;
		std::cout << "Smart_array printed\n";
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
