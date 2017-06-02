#ifndef _MAX_SUB_SUM_H_
#define _MAX_SUB_SUM_H_

/*************************************************
//  Copyright (C), 2015-2016, CS&S. Co., Ltd.
//  File name: 	    MaxSubSum.h
//  Author:			刘巍      
//  Version: 		1.0     
//  Date: 			2017/06/02
//  Description:    最大序列和
//  Others:         
//  Function List:  
//  History:
//    <author>      刘巍 
//    <time>        2017/06/02
//    <version>     1.0 
//    <desc>        build this moudle     
*************************************************/

#include <array>

class MaxSubSum
{
	typedef std::array<int, 1000> Array;

public:
	MaxSubSum();

	void display();

	int sum1(const Array& array);
	int sum2(const Array& array);
	
private:
	int sum1(const Array& array, int begin, int end);

private:
	Array m_randomArray;
};

#endif