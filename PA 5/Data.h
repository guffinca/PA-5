#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class Data
{
public:
	Data(int newcustomerNumber, int newserviceTime, int newTotalTime);

	int getCustomerNumber();
	int getServiceTime();
	int gettotalTime();
	

private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};