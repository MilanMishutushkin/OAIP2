#include <iostream>
#include "functions.h"

int main() {
	int size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++) 
	{
		std::cout <<"\n" << i+1 << " element = ";
		std::cin >> array[i];
	}

	std::cout << "Original array: ";
	for (int i = 0; i < size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	bool menuFlag(true);
	while (menuFlag)
	{
		runMenu();
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			bubbleSort(array, size);
			std::cout << "After Bubble Sort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 2:
		{
			minSort(array, size);
			std::cout << "After Min Sort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 3:
		{
			insertSort(array, size);
			std::cout << "After Insertion Sort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 4:
		{
			shellSort(array, size);
			std::cout << "After Shell Sort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 5:
		{
			hoareSort(array, 0, size - 1);
			std::cout << "After Quick Sort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 6:
		{
			bogoSort(array, size);
			std::cout << "After Bogosort: ";
			for (int i = 0; i < size; i++) {
				std::cout << array[i] << " ";
			}
			std::cout << std::endl;
		}
		break;
		case 7:
		{
			std::cout << "\n1.Order search";
			std::cout << "\n2.Binary search";
			std::cout << "\nYour choice: ";
			int choice;
			std::cin >> choice;
			if (choice == 1)
			{
				orderSearch(array, size);
			}
			else
			{
				binarySearch(array, size);
			}
		}
		break;
		default:
		{
			std::cout << "\n===============";
			std::cout << "\n Invalid input";
			std::cout << "\n===============";
		}
		}
	}


	return 0;
}
