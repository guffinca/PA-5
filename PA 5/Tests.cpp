
#include "tests.h"

void Tests::testenqueue()
{
	Queue test;
	Data* pData = new Data(1, 2, 3); //putting new data

	test.enqueue(*pData);
	if (test.getHead()->getData()->getCustomerNumber() == pData->getCustomerNumber())
	{
		cout << "Test 1 works" << endl;
	}
	else
	{
		cout << "Test 1 does not work" << endl;
	}
} 

void Tests::testenqueue2() //Testing enquene when 1 node is already in
{
	Queue test2;

	Data* node1 = new Data(1, 2, 3); //node thats already in queue
	test2.enqueue(*node1);

	Data* node2= new Data(1, 2, 3);
	test2.enqueue(*node2);

	//checking if the second node get enqueued correctly
	if (test2.gettail()->getData()->getCustomerNumber() == node2->getCustomerNumber())
	{
		cout << "Test 2 works correctly" << endl;

	}
	else
	{
		cout << "Test 2 does not work correctly" << endl;
	}



}
void Tests::testdequeue()
{
	Queue test3;
	Data* data = new Data(1, 2, 3);
	test3.enqueue(*data);
	test3.dequeue();

	//Tests if head is nullptr
	if (test3.getHead() != nullptr)
	{
		cout << "Test failed, Head = nullptr" << endl;
	}
	//tests if tail is nullptr
	if (test3.gettail() != nullptr)
	{
		cout << "Test failed, tail = nullptr" << endl;
	}
	else
	{
		cout << "Test 3 works correctly" << endl;
	}

}
void Tests::testdequeue2() //testing if
{
	Queue test4;
	Data* data1 = new Data(1, 2, 3);
	Data* data2 = new Data(1, 2, 3);

	test4.enqueue(*data1);
	test4.enqueue(*data2);
	test4.dequeue();



}

void Tests::testsimulation() //Running simulation for 24 hours
{
	int time = 1440;
	runQueues(time);
}