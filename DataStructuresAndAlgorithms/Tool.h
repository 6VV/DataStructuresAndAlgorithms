#ifndef _TOOL_H_
#define _TOOL_H_

/*************************************************
//  Copyright (C), 2015-2016, CS&S. Co., Ltd.
//  File name: 	    Tool.h
//  Author:			刘巍      
//  Version: 		1.0     
//  Date: 			2017/06/02
//  Description:    工具类，提供常用功能
//  Others:         
//  Function List:  
//  History:
//    <author>      刘巍 
//    <time>        2017/06/02
//    <version>     1.0 
//    <desc>        build this moudle     
*************************************************/


class Tool
{
private:
	typedef void(*func)();

public:
	static void display(func f);
};

#endif