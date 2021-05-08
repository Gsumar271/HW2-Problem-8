#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <assert.h>
#include "queueADT.h"
using namespace std; 

//this class inherits from the queue abstract data type
template <class Type>
class priorityQueueAsHeap: public queueADT<Type>
{
public:
    //Overload the assignment operator.
    const priorityQueueAsHeap<Type>& operator=(const priorityQueueAsHeap<Type>&);
    
    //Function to determine whether the queue is empty.
    bool isEmptyQueue() const;

    //Function to determine whether the queue is full.
    bool isFullQueue() const;
    
    //Function to initialize the queue to an empty state.
    void initializeQueue();
    
    //Function to return the first element of the queue.
    Type front() const;
    
    //Function to return the last element of the queue.
    Type back() const;
    
    //Function to add queueElement to the queue.
    void addQueue(const Type& queueElement);
    
    //Function to remove the first element of the queue.
    void deleteQueue();
    
    //a helper function to swap two elements 
    void swap(Type& x, Type& y);
    
    //a function to print the elements of the queue 
    void printList();

    //Constructor
    priorityQueueAsHeap(int queueSize = 100);
    
    //Copy constructor
    priorityQueueAsHeap(const priorityQueueAsHeap<Type>& otherQueue);
    
    //Destructor
    ~priorityQueueAsHeap();

    //return size of the list
    int getSize();
    
private:
    int maxQueueSize; //variable to store the maximum queue size
    int count; //variable to store the number of
    //elements in the queue

    Type *list; //pointer to the array that holds
    //the queue elements
};

//check if queue is empty
template <class Type>
bool priorityQueueAsHeap<Type>::isEmptyQueue() const
{
    return (count == 0);
} //end isEmptyQueue

//check if queue is full
template <class Type>
bool priorityQueueAsHeap<Type>::isFullQueue() const
{
    return (count == maxQueueSize);
} //end isFullQueue

//initialize the queue 
template <class Type>
void priorityQueueAsHeap<Type>::initializeQueue()
{
    count = 0;
} //end initializeQueue

//get the front of the queue
template <class Type>
Type priorityQueueAsHeap<Type>::front() const
{
    assert(!isEmptyQueue());
    return list[0];
} //end front

//get the back of the queue
template <class Type>
Type priorityQueueAsHeap<Type>::back() const
{
    //assert queue is not empty
    assert(!isEmptyQueue());
    return list[count-1];
} //end front


//function that adds elements to priority queue 
template <class Type>
void priorityQueueAsHeap<Type>::addQueue(const Type& newElement)
{
    int index1, index2;
    //if the queue is not full
    if (!isFullQueue())
    {       
        //Insert the new element in the first available position
        //in the list 
        list[count] = newElement; 

        //After inserting the new element in the heap, list 
        //might no longer be a heap, so restore heap
        
        //if we have more than 1 element in the list 
        if (count != 0)
        {
            index1 = count;
            //get parent index
            index2 = (index1 - 1) / 2;
            //while (the parent of the new entry is smaller than the new entry)
            //swap the parent with the new entry.
            while(index1 > 0){
                if(list[index1] > list[index2])
                    swap(list[index1], list[index2]);
                else 
                    break; //otherwise list is already a heap
                //advance child and parent index
                index1 = index2;    
                index2 = (index1 - 1) / 2;
            }
        }
        //increase the element count
        count++; 
    }
    else
        cout << "Cannot add to a full queue." << endl;
} //end addQueue

//function that deletes an element from priority queue 
template <class Type>
void priorityQueueAsHeap<Type>::deleteQueue()
{
    int indexHigh, indexLow = 0;
    Type temp;

    //if queue is not empty 
    if (!isEmptyQueue())
    {
        //Copy the last element of the list into the first array position.
        list[indexLow] = list[count-1];
        //Reduce the length of the list by 1.
        count--;
        //Restore the heap in the list.
        temp = list[indexLow];
        
        //index of left child 
        indexHigh = 2 * indexLow + 1; 
        //while we are still within array boundary
        while (indexHigh <= count)
        {
            if (indexHigh < count)
                //get the larger of two children 
                if (list[indexHigh] < list[indexHigh + 1])
                    indexHigh = indexHigh + 1; //index of the largest child
            //if subtree is already in a heap then exit loop
            if (temp > list[indexHigh]) 
                break;
            else
            {   
                //move the larger child to the root
                list[indexLow] = list[indexHigh]; 
                //go to the subtree to restore the heap
                //keep advancing until element is right position 
                indexLow = indexHigh; 
                indexHigh = 2 * indexLow + 1;
            }
        } // end while

        list[indexLow] = temp;
        
    }
    else
        //display error if queue is empty 
        cout << "Cannot remove from an empty queue" << endl;
} //end deleteQueue

template <class Type>
priorityQueueAsHeap<Type>::priorityQueueAsHeap(int queueSize)
{
    if (queueSize <= 0)
    {
        cout << "Size of the array must be positive." << endl;
        cout << "Array will be of size 100." << endl;
        maxQueueSize = 100;
    }
    else
        maxQueueSize = queueSize; //set maxQueueSize to
    
    //queueSize
    count = 0;
    //create new array 
    list = new Type[maxQueueSize]; 
} //end constructor

//destructor
template <class Type>
priorityQueueAsHeap<Type>::~priorityQueueAsHeap()
{
    delete [] list;
}

//function which swaps 2 pointers
template <class Type>
void priorityQueueAsHeap<Type>::swap(Type &xp, Type &yp){
    
    Type temp = xp;
    xp = yp;
    yp = temp;
}

//prints the elements of the queue 
template <class Type>
void priorityQueueAsHeap<Type>::printList(){
    Type item;

    for (int i = 0; i < count; i++)
    {
        cout<<list[i]<<" ";
    }
    cout << endl;
    
}

//returns the size of the queue 
template <class Type>
int priorityQueueAsHeap<Type>::getSize(){
    return count;
}