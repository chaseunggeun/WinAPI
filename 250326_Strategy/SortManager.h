#pragma once
#include "Sort.h"
#include "memory"
class SortManager
{
private:
	std::unique_ptr<ISort> sort;

public:
	void DoSort(int* arr)
	{
		if (sort)
		{
			sort->DoSort(arr);
		}
	}

	void ChangeSort(std::unique_ptr<ISort> newSort)
	{
		sort = std::move(newSort);
	}

	SortManager() :sort(nullptr) {};
	~SortManager() {};
};

