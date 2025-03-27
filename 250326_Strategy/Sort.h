#pragma once
class ISort
{
public:
	virtual void DoSort(int* arr) = 0;

	virtual ~ISort() {};
};

class QuickSort : public ISort
{
public:
	virtual void DoSort(int* arr) override;

	virtual ~QuickSort() {};
};

class BubbleSort : public ISort
{
public:
	virtual void DoSort(int* arr) override;

	virtual ~BubbleSort() {};
};

class MergeSort : public ISort
{
public:
	virtual void DoSort(int* arr) override;

	virtual ~MergeSort() {};
};

