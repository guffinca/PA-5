#include "QueueNode.h"

QueueNode::QueueNode(Data *newData)
{
	this->pData = newData;
	this->pNext = nullptr;
}

void QueueNode::setNextPtr(QueueNode* newpNext)
{
	this->pNext = newpNext;
}

void QueueNode::setData(Data* newpData)
{
	this->pData = newpData;
}

Data *QueueNode::getData()
{
	return this->pData;
}

QueueNode* QueueNode::getNext()
{
	return this->pNext;
}

