// homework_3.1.1.cpp : This file contains the 'main' function.Program execution begins and ends there.
// ��� ������ ����� 1 ����� 3, ������ "����������� ����������������"

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

		// ��������� ��������� ������ ������
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

		if ((count + 1) <= size) // ��� ������, ����� ��� �� ����� ����������� ������, ������ ����� �������� � �������� �������
		{
			// ���� �������� ������� ���������� � ������ �������� � ������ ���, �� ����� 
			// �������� �������� � ����� ������ ������� �������, �� ���� � �������� 0
			// ���� �������� ������� ���������� � ������ ������ ���, �� ����� � ������ � �������� 1 � �.�
			arr[count] = x;

			// ���������� ��� ������, ������� ��������� � ���������� ������ ������ add_element
			std::cout << "������ ��������" << std::endl;
			for (int i = 0; i < size; i++)
			{
				std::cout << arr[i] << std::endl;
			}
	
		}
		else // ����� � ��� ���������� ��������� ��� ������, ��� ���������� �������� ������,
			// ������� ����� ��������� ������, ����� �������� ���� ����� �������
		{
			std::cout << "���������� ���������, ������� �� ������ ������, ������, ��� ���������� ���� � �������.������ ��������." << std::endl;
			
			// ������ ��������� ������ arr_temp
			int* arr_temp = new int[size + 1];
			// ������� ���� ��� �������� �� ���������� �������
			for (int i = 0; i < size; i++)
			{
				arr_temp[i] = arr[i];
			}
			// ��������� � ��������� ������� ����� �������� 
			arr_temp[size] = x;

			std::cout << "��������� ������ ��������" << std::endl;
			for (int i = 0; i < (size + 1); i++)
			{
				std::cout << arr_temp[i] << std::endl;
			}
			size++;
			delete[] arr;

			arr = arr_temp;
			std::cout << "������ ��������" << std::endl;
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
			std::cout << "��� �������� �������� ������� ��������������� ��������" << std::endl;
			return arr[y];
		}
		else
		{
			throw std::runtime_error("�� ����� �������� ��������� �������� �������, ��������� �������� ������� ���������");
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
