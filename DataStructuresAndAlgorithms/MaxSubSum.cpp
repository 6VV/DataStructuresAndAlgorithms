#include "stdafx.h"
#include "MaxSubSum.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "Tool.h"



MaxSubSum::MaxSubSum()
{
	std::default_random_engine dre;
	std::uniform_int_distribution<int> dis(-20,50);

	int size = m_randomArray.size();
	for (int i = 0; i < size;++i)
	{
		m_randomArray[i] = dis(dre);
	}
}

void MaxSubSum::display()
{
	auto startTime=std::chrono::system_clock::now();
	std::cout <<"sum1: "<< sum1(m_randomArray)<<std::endl;
	std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::system_clock::now() - startTime)).count() << std::endl;

	startTime = std::chrono::system_clock::now();
	std::cout << "sum2: " << sum2(m_randomArray)<<std::endl;
	std::cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::system_clock::now() - startTime)).count() << std::endl;

}

int MaxSubSum::sum1(const Array& array)
{
	return sum1(array, 0, array.size()-1);
}

int MaxSubSum::sum1(const Array& array, int begin, int end)
{
	if (begin==end)
	{
		if (array[begin] > 0)
		{
			return array[begin];
		}
		else
		{
			return 0;
		}
	}

	int center = (end + begin) / 2;
	int maxLeftSum = sum1(array, begin, center);
	int maxRightSum = sum1(array, center+1, end);

	int maxLeftBorderSum = 0;
	int leftBorderSum = 0;
	for (int i = center; i >=begin; --i)
	{
		leftBorderSum += array[i];
		if (leftBorderSum>maxLeftBorderSum)
		{
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0;
	int rightBorderSum = 0;
	for (int i = center+1; i <=end ; ++i)
	{
		rightBorderSum += array[i];
		if (rightBorderSum>maxRightBorderSum)
		{
			maxRightBorderSum = rightBorderSum;
		}
	}

	std::vector<int> value{maxRightSum,maxLeftSum,maxLeftBorderSum+maxRightBorderSum};
	return *std::max_element(value.begin(), value.end());
}

int MaxSubSum::sum2(const Array& array)
{
	int maxSum = 0;
	int thisSum = 0;

	for (size_t i = 0; i < array.size();++i)
	{
		thisSum += array[i];

		if (thisSum>maxSum)
		{
			maxSum = thisSum;
		}
		else if (thisSum<0)
		{
			thisSum = 0;
		}
	}

	return maxSum;
}
