#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include "priorityQueueAsHeap.h"
#include "orderType.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

int main() {

    int x;
    int orderNum, processTime, priority;

    //declare a customized priority queue
    priorityQueueAsHeap<orderType> priorityQ;

    //declare an array of orders
    orderType orders[10];
    orderType order;

    /* initialize random seed: */
    srand(time(NULL));

    //populate priority queue with 
    //multiple random orders

    //use a loop to generate orders
    //ask user for priority level for each 
    //order
    for (int i = 0; i < 10; i++)
    {
        //generate a random order number
        orderNum = rand() % 10000 + 1;
        //generate processing time 1-10 seconds
        processTime = rand() % 7 + 1;

        //set order to appropriate values
        orders[i].setOrderName(orderNum);
        orders[i].setProcessTime(processTime);

        //ask user for priority level on 
        //each generated order
        cout<<"Order number: "<<orderNum<<endl;
        cout<<"Please enter your priority:\n1. Personal favor for a friend.\n2. Bulk order.\n3. Pay extra.\n4. No priority\n "<<endl; 
        cin>>x;
        cout<<endl;
        orders[i].setPriority(x);
        
        //put the order into priority queue
        priorityQ.addQueue(orders[i]);

    }

    //print the state of queue
    priorityQ.printList();
    cout<<endl;
    cout<<endl;

    //while priority queue is not empty 
    //process each order, delete it from 
    //queue and output the queue to the screen
    while (!priorityQ.isEmptyQueue())
    {
        //get the front element of the queue
        order = priorityQ.front();

        //get the processing time of that order
        x = order.getProcessTime();

        //this function will simulate
        //processing time for each order
        sleep_for(seconds(x));

        //delete the front element
        //as it was already processed   
        priorityQ.deleteQueue(); 

        //print the state of queue
        priorityQ.printList(); 
        
        cout<<endl;
        cout<<endl;
    }
    
    return 0;
}