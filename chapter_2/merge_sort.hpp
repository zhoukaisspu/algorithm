#pragma once
#include <memory>

void merge(int* array, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	auto Lptr = std::make_unique<int[]>(n1);
	auto Rptr = std::make_unique<int[]>(n2);
	for (int i = 0; i < n1; ++i) {
		Lptr[i] = array[p + i];
	}
	for (int i = 0; i < n2; ++i) {
		Rptr[i] = array[q + 1 + i];
	}
	int Lindex = 0;
	int Rindex = 0;
	for (int i = p; i <= r; ++i) {
		if (Lptr[Lindex] <= Rptr[Rindex]) {
			array[i] = Lptr[Lindex];
			++Lindex;
		}
		else {
			array[i] = Rptr[Rindex];
			++Rindex;
		}
		if (Lindex == n1) {
			for (int j = i + 1; j <= r; ++j) {
				array[j] = Rptr[Rindex];
				++Rindex;
			}
			return;
		}
		else if (Rindex == n2) {
			for (int j = i + 1; j <= r; ++j) {
				array[j] = Lptr[Lindex];
				++Lindex;
			}
			return;
		}
	}
}

void merge_sort(int* A, int start, int end)
{
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(A, start, middle);
		merge_sort(A, middle + 1, end);
		merge(A, start, middle, end);
	}
}