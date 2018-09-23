#include <iostream>

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

int main()
{
	int a[10] = { 2,1,3,5,6,3,8,1,23,1 };
	insert_sort(a, 10);
	for (auto& j : a) {
		std::cout << j << " ";
	}
	std::cout << std::endl;
	return 0;
}