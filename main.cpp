// main.cpp: 定义应用程序的入口点。
//

#include "header.h"

using namespace std;

int main(int argc,char** argv)
{
	string logo = R"(  ____                        _         
 |  _ \    __ _   _ __     __| |   __ _ 
 | |_) |  / _` | | '_ \   / _` |  / _` |
 |  __/  | (_| | | | | | | (_| | | (_| |
 |_|      \__,_| |_| |_|  \__,_|  \__,_|
                                        )";
	string pdcode,codepath=argv[1];
	cout << logo << endl;
	//判断语言
	ifstream code;
	code.open(codepath, ios::in);
	getline(code, pdcode, '\n');
	pdcode.erase(0,6);
	return 0;
}
