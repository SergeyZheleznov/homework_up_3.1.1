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

	void add_element(int x)
	{
		x = x;

		if ((count + 1) <= size) // это случай, когда нам не нужно увеличивать массив, просто пишем значения в элементы массива
		{
			// если вызываем функцию добавления в массив элемента в первый раз, то кладём 
			// значение элемента в самый первый элемент массива, то есть с индексом 0
			// если вызываем функцию добавления в массив второй раз, то кладём в ячейку с индексом 1 и т.д
			arr[count] = x;

			// Распечатем тот массив, который получился в результате вызова метода add_element
			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << std::endl;
			}
	
		}
		else // здесь у нас количество элементов уже больше, чем изначально заданный массив,
			// поэтому нужно увеличить массив, чтобы положить туда новый элемент
		{
			std::cout << "Количество элементов, которое Вы ходите ввести, больше, чем количество мест в массиве.Массив увеличен." << std::endl;
			
			// создаём временный массив arr_temp
			int* arr_temp = new int[size + 1];
			// передаём туда все значения из первичного массива
			for (int i = 0; i < size; i++)
			{
				arr_temp[i] = arr[i];
			}
			// добавляем в последний элемент новое значение 
			arr_temp[size] = x;

			std::cout << "Временный массив значений" << std::endl;
			for (int i = 0; i < (size + 1); i++)
			{
				std::cout << arr_temp[i] << std::endl;
			}
			size++;
			delete[] arr;

			arr = arr_temp;
			std::cout << "Массив значений" << std::endl;
			for (int i = 0; i < (size); i++)
			{
				std::cout << arr_temp[i] << std::endl;
			}
		}
		count = count + 1;
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
		arr.add_element(19);
		arr.add_element(21);

		std::cout << arr.get_element_from_index(10) << std::endl;
		std::cout << arr.get_element_from_index(2) << std::endl;
		std::cout << "Smart_array printed\n";
	}
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
