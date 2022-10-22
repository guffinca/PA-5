#pragma once

#include <iostream>
#include "QueueNode.h"
#include "Data.h"

using std::cin;
using std::cout;
using std::endl;

class Queue
{
public:
	Queue(QueueNode* newpHead = nullptr, QueueNode* newpTail = nullptr);


	bool enqueue(Data &newpData);

	bool isEmpty();

	Data dequeue();

	void printQueue(QueueNode *pNext);

	int sumServiceTimes(QueueNode* pNext);

	QueueNode *getHead();
	QueueNode *gettail();


private:
	QueueNode* pHead;
	QueueNode* pTail;
};