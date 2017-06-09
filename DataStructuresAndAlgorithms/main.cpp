#include "stdafx.h"
#include "List.h"
#include <iostream>

int main()
{
	List<int> list;
	list.push_back(2);
	list.push_back(3);
	list.push_front(1);

	std::cout << list.back() << std::endl;

	for (auto iter = list.begin(); iter != list.end(); ++iter)
	{
		if ((*iter)%2==0)
		{
			iter=list.erase(iter);
		}
		std::cout << *iter << std::endl;
	}

	getchar();
	return 0;
}