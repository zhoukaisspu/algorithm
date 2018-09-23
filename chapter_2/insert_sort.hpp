#pragma once
#include <cstddef>

void insert_sort(int* a, std::size_t length)
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
