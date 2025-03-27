#include <iostream>
#include "SortManager.h"

int main()
{
	int testArr[10] = { 4,32,56,2,1,0,234,98, -1, -8 };
	SortManager sortMgr;

	sortMgr.ChangeSort(std::make_unique<BubbleSort>()); // new BubbleSort() 대신 std::make_unique<BubbleSort>()
	sortMgr.DoSort(testArr);

	sortMgr.ChangeSort(std::make_unique<QuickSort>());
	sortMgr.DoSort(testArr);

	sortMgr.ChangeSort(std::make_unique<MergeSort>());
	sortMgr.DoSort(testArr);

}