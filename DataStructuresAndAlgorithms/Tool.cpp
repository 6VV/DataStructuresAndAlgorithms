#include "stdafx.h"
#include "Tool.h"
#include <chrono>
#include <iostream>



void Tool::display(func f)
{
	auto timeStart = std::chrono::steady_clock::now();
	f();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - timeStart).count() << std::endl;
}
