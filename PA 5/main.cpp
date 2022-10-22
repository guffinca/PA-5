

#include "PA5.h"
#include "Queue.h"
#include "tests.h"
/*
Programmer - Caden Guffin

Assignment - Programming Assignment 5

Data - 10/21/2022

*/


int main()
{
	Tests tests;

	tests.testenqueue();
	tests.testenqueue2();
	tests.testdequeue();
	tests.testdequeue2();
	tests.testsimulation();
}

void runQueues(int n)
{
	Queue Queue1; //Express lane
	Queue Queue2; //Normal lane

	int expressArrival = rand() %5 +1; //Chooses number 0 through 5, then adds 3, leaves the possibality to be 3-8
	int normalArrival = rand() %8+3;//choose number 0 through 4, then adds 1, leaves possibality to 1-5
	int express_service = 0;
	int normal_service = 0;
	int customerNumbers = 1;
	int totalTime1 = 0;
	int totaltime2 = 0;
	int programruntime = 0;

	//runs similation until it reaches the set amount of time
	while (programruntime < n)
	{
		if (expressArrival == 0)
		{
			//Giving random service time
			express_service = rand() % 5 + 1;
			
			//runs through queue and gets service times, adds those times together and returns sum.
			
			totalTime1 = express_service + totalTime1;
			Data* newCustomer = new Data(customerNumbers++, express_service, totalTime1);
			cout << "Customer " << newCustomer->getCustomerNumber() << " Entered the Express Lane at " << programruntime << " minutes" << endl;
			Queue1.enqueue(*newCustomer);

			//setting arrivaltime for next person
			expressArrival = rand() % 5 + 1;

		}
		else
		{
			//counts down arrival time, equlavalent to a minute.
			expressArrival--;
			//counts down service time
			express_service--;
		}

		//once service time is finished a person is dequeued
		//prints out which customer has exited the queue
		if (!Queue1.isEmpty() && express_service == 0)
		{
			cout << "Customer " << Queue1.getHead()->getData()->getCustomerNumber() << " checked out the express lane at " << programruntime << " minutes" << endl;
			Queue1.dequeue();
		}
 
		//Will add a person to the queue once a person arrives
		if (normalArrival == 0)
		{
			normal_service = rand() % 8 + 3;
			//create new Data set
			totaltime2 = normal_service + totaltime2;
			Data* newCustomer = new Data(customerNumbers++, normal_service, totaltime2);
			cout << "Customer " << newCustomer->getCustomerNumber() << " Entered the Normal Lane at " << programruntime << " minutes" << endl;
			Queue2.enqueue(*newCustomer);

			normalArrival = rand() % 8 + 3;

		}
		else
		{
			//same thing as express lane
			normalArrival--;
			normal_service--;
		}

		if(!Queue2.isEmpty() && normal_service == 0)
		{

			//deleating customer from line after they are served
			cout << "Customer " << Queue2.getHead()->getData()->getCustomerNumber() << " checked out the Normal lane at " << programruntime << " minutes" << endl;

			Queue2.dequeue();

		}
		
		//every 10 minutes, prints the both queues
		//if queue is empty at that 10 minute interval, noting is printed out.
		if (!Queue1.isEmpty())
		{

			if (programruntime % 10 == 0)
			{
				cout << "" << endl;
				cout << "Express Lane at " << programruntime << " minutes" << endl;

				Queue1.printQueue(Queue1.getHead());
				cout << "Service time: " << express_service << endl;
				cout << "Total Service Time: " << totalTime1 << endl;
				cout << "" << endl;
			}
		}

		if(!Queue2.isEmpty())	
		{
			if (programruntime % 10 == 0)
			{
				
				cout << "Normal Lane at " << programruntime << " minutes " <<endl;
				Queue2.printQueue(Queue2.getHead());
				cout << "Service time: " << normal_service << endl;
				cout << "Total Service Time: " << totaltime2 << endl;
				cout << "" << endl;

			}
		}

		programruntime++; 


	}

	

}