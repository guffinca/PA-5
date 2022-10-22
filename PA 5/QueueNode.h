#pragma once

#include <iostream>
#include <string>
#include "Data.h"


using std::cin;
using std::cout;
using std::endl;

class QueueNode
{
public:
	QueueNode(Data *newData);
	

	void setNextPtr(QueueNode* newpNext);

	void setData(Data* newpData);
	Data* getData();
	

	QueueNode* getNext();

	

private:
	Data* pData;
	QueueNode* pNext;
	
};



