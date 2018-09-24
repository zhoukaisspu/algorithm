#pragma once
#include <cstddef>

void insert_sort(int* a, int length)
{
	if (length <= 1)
		return;
	for (int i = 1; i < length; ++i) {
		int key = a[i];
		int index = i - 1;
		while ((index >= 0) && (a[index] > key)) {
			a[index + 1] = a[index];
			index = index - 1;
		}
		a[index + 1] = key;
	}
}

void insert_valid(int* A, int index)
{
	int value = A[index];
	while ((index > 0) && (value < A[index -1])) {
		A[index] = A[index -1];
		--index;
	}
	A[index] = value;
}


void insert_sort_recursive(int* A, int length)
{
	if (length > 1) {
		insert_sort_recursive(A, length - 1);
		insert_valid(A, length -1);
	}
}

void insert_sort_test()
{
	std::cout << "<<<<<<<<<<<<start insert sort test>>>>>>>>>>>>>>"
		<< std::endl;
	int a[10] = { 2,1,3,5,6,3,8,1,23,1 };
	int sort_a[10] = { 1,1,1,2,3,3,5,6,8,23 };
	std::cout << "insert sort:       ";
	for (auto& j : a) {
		std::cout << j << " ";
	}
	std::cout << std::endl;
	std::cout << "correctness result:";
	for (auto& j : sort_a) {
		std::cout << j << " ";
	}
	std::cout << std::endl;
	insert_sort(a, 10);
	std::cout << "actual result:     ";
	for (auto& j : a) {
		std::cout << j << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 10; ++i) {
		if (a[i] != sort_a[i]) {
			std::cout << "[ERROR]: insert sort error!"
				<< std::endl;
			return;
		}
	}
	std::cout << "[INFO]: insert sort correct" << std::endl;
	std::cout << "<<<<<<<<<<<<<<<<end insert sort test>>>>>>>>>>>>>>>>"
		<< std::endl;
}
