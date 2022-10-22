#include "Queue.h"

Queue::Queue(QueueNode* newpHead, QueueNode* newpTail)
{
	this->pHead = newpHead;
	this->pTail = newpTail;

}

bool Queue::enqueue(Data &newpData)
{
	Data* temppData = new Data(newpData);
	QueueNode *pMem = new QueueNode(temppData);
	bool success = false;

	if (pMem != nullptr)
	{
		success = true;

		if (isEmpty())
		{
			this->pHead = this->pTail = pMem;
		}
		else
		{
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem;
		}
	}
	return success;
}

bool Queue::isEmpty()
{
	return this->pHead == nullptr;
}

//Function from class
Data Queue::dequeue()
{
	QueueNode *pTemp = pTail;
	Data *returnData = pTemp->getData();

	if (this->pHead == this->pTail)
	{
		this->pHead = this->pTail = nullptr;
	}
	else
	{
		this->pHead = pTemp->getNext();
	}
	delete pTemp;

	return *returnData;
}


//Prints out the customers number that is currently in line using recursion

void Queue::printQueue(QueueNode *pNext)
{
	if (pNext != nullptr)
	{
	cout << "Customer  " << pNext->getData()->getCustomerNumber() << " ";
	
	printQueue(pNext->getNext());
	}
	else
	{
		cout << endl;
	}
}

int Queue::sumServiceTimes(QueueNode* pNext)
{
	
	int temp = 0;
	if (pNext != nullptr)
	{
		//Walking through the queue and adding all the service times.
		temp = pNext->getData()->getServiceTime();
		return sumServiceTimes(pNext->getNext()) + temp;
	}
}

QueueNode* Queue::getHead()
{
	return pHead;
}
QueueNode* Queue::gettail()
{
	return pTail;
}