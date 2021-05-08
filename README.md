# HW2-Problem-8
HW2 Problem 8
HW 2 PROBLEM 8
YEVGENIY SUMARYEV
 
 	In this problem the objective was to create a queue of different orders that would accept a range of priorities, 
the priorities would then determine the order of job in the queue. Naturally this would be best accomplished with a 
priority queue. When reading about queues I read that priority queues would be most efficiently implemented with the heap, 
so I’ve decided to use a heap as the main data structure for my priority queue. 
	So I basically took a regular queue and reorganized it as a priority queue which uses heapsort to organize it’s elements. 
  This would guarantee that the element or Order with the highest priority (in our case it’s priority 1) would always be the first 
  element to be removed from the queue. With this approach the 2 important functions in the priorityQueue class are addQueue() which 
  adds an element and a deleteQueue() which deletes an element. In the addQueue() the element would be added  to the end of the queue(I 
  implemented an array for the queue as it would make it easy to traverse a heap), and then compare this new element to the parent, and swap
  the elements if the parent was less than the child. This loop would keep going until we reach the root. Similarly in the deleteQueue() 
 whenever the element is removed(this would be the root element, the first element in the array with the highest priority) we would take the 
 last element and put it in the root and then run a similar method to heapify() where the root is the compared to it’s children and placed in the 
 right position, where parent is larger than it’s children. This approach would guarantee that the element in the front would always be an element with the highest priority.
 For orders I built a class called OrderType which contains 3 variables to store the order number, processing time and priority. Since the priorityQueue 
 class was built to sort largest number first I had to overload relational operators in the Order class so  that highest priority was the one with the lowest number and thus I reversed greater than and less than operators so that lowest number would be treated as the highest in the heap. In addition, in order for 
 the elements in the queue to be displayed in the console I had to overload the stream<< operator. 
 Finally I ran a little stimulation in the main program where I would first generate 10 random orders and asking user to give each order a priority.  Then the queue would be sequentially “processed”, using chrono sleep_for function the order in the front would be removed and machine would pause for the amount of processing time as each order is “processed”, and the queue would be displayed to show how each order is being moved according to its priority. 


