#pragma once
#ifndef GUARD_median_h
#define GUARD_median_h
#include <stdexcept> 
#include <vector>   
using std::domain_error;
template <typename T>
/*typename T::value_type median(T begin, T end)
{
	typename T::value_type val = *begin;
	int size = end - begin;
	if (size == 0)
		throw domain_error("median of an empty vector");
	typename T::value_type a[1001];
	T cur = begin;
	for (int i = 0; i < size; i++)
	{
		a[i] = *cur;
		cur++;
	}
	int n = size;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (*(a + i) > *(a + j))
			{
				typename T::value_type temp;
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
	int mid = size / 2;
	val = size % 2 == 0 ? (*(a + mid) + *(a + mid - 1)) / 2 : *(a + mid);
	return val;
}*/
typename T::value_type median(T begin, T end)
{
	typename T::value_type val = *begin;
	int size = end - begin;
	if (size == 0)
		throw domain_error("median of an empty vector");
	std::vector<typename T::value_type> temp;
	std::copy(begin, end, std::back_inserter(temp));
	sort(temp.begin(), temp.end());
	int mid = size / 2;
	val = size % 2 == 0 ? (temp[mid] + temp[mid - 1]) / 2 : temp[mid];
	return val;
}
/*template <typename T>
T median(T* begin, T* end)
{
	T middle = median(begin, end);
	int size = end - begin;
	if (size == 0)
		throw domain_error("median of an empty vector");
	T a[1001];
	T* cur = begin;
	for (int i = 0; i < size; i++)
	{
		a[i] = *cur;
		cur++;
	}
	int n = size;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (*(a + i) > *(a + j))
			{
				T temp;
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
			}
		}
	}
	int mid = size / 2;
	middle = size % 2 == 0 ? (*(a + mid) + *(a + mid - 1)) / 2 : *(a + mid);
	return middle;
}*/
#endif


