#include "Data.h"

Data::Data(int newcustomerNumber,int newserviceTime,int newTotalTime)
{
	this->customerNumber = newcustomerNumber;
	this->serviceTime = newserviceTime;
	this->totalTime = newTotalTime;

}
int Data:: getCustomerNumber()
{
	return customerNumber;
}

int Data::getServiceTime()
{
	return serviceTime;
}

int Data::gettotalTime()
{
	return totalTime;
}

