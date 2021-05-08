#include <iostream>
#include <string>

//class that represents various orders
using namespace std;
class orderType
{
    //Overload the stream extraction operator
    friend ostream& operator<<(ostream& os, const orderType&);
public:
    //Overload the assignment operator.
    const orderType& operator=(const orderType&);
    
    //set order name
    void setOrderName(int orderName);
    
    //Function to return the order name.
    int getOrderName() const;
    
    //set priority
    void setPriority(int priorityNum);
    
    //Function to return priority.
    int getPriority() const;
    
    //set priority
    void setProcessTime(int processTimeNum);
    
    //Function to return priority.
    int getProcessTime() const;

    //constructor with parameters
    //Set orderName, processTime and priority 
    //priority will be 4 by default, which means
    //lowest priority
    orderType(int order = 0, int processTimeNum = 0, int priority = 0);
    
    
    //Overload the relational operators.
    bool operator==(const orderType& right) const;
    bool operator!=(const orderType& right) const;
    bool operator<=(const orderType& right) const;
    bool operator<(const orderType& right) const;
    bool operator>=(const orderType& right) const;
    bool operator>(const orderType& right) const;

protected:
    int orderName; //variable to store the order name
    int processTime; //variable to store the processing time
    int priority; // variable to store priority 
};

//constructor to fill in the order variables
orderType::orderType(int order, int processTimeNum, int priorityNum){
    orderName = order;
    processTime = processTimeNum;
    priority = priorityNum;
}

//Overload the assignment operator.
const orderType& orderType::operator=(const orderType& otherOrder){
    orderName = otherOrder.getOrderName();// orderName
    processTime = otherOrder.getProcessTime();// processTime
    priority = otherOrder.getPriority();// priority

    return *this;
}
//set order name
void orderType::setOrderName(int orderN){
    orderName = orderN;
}
//Function to return the order name.
int orderType:: getOrderName() const{
    return orderName;
}
//set priority
void orderType::setPriority(int priorityNum){
    
    //if insvalid priority was entered
    //set the priority to 4 which means
    //no priority
    if(priorityNum < 1 || priorityNum > 4)
        priority = 4;
    else
        priority = priorityNum;
}
//Function to return priority.
int orderType::getPriority() const{
    return priority;
}
//set priority
void orderType::setProcessTime(int processTimeNum){
    processTime = processTimeNum;
}
//Function to return priority.
int orderType::getProcessTime() const{
    return processTime;
}


//overload the operator ==
bool orderType::operator==(const orderType& right) const
{
    return (priority == right.priority);
}

//overload the operator !=
bool orderType::operator!=(const orderType& right) const
{
    return (priority != right.priority);
}

//overload the operator <=
//operator will be reversed 
//since lower number means higher priority
bool orderType::operator<=(const orderType& right) const
{
    return (priority >= right.priority);
}

//overload the operator <
//operator will be reversed 
//since lower number means higher priority
bool orderType::operator<(const orderType& right) const
{
    return (priority > right.priority);
}

//overload the operator >=
//operator will be reversed 
//since lower number means higher priority
bool orderType::operator>=(const orderType& right) const
{
    return (priority <= right.priority);
}

//overload the operator >
//operator will be reversed 
//since lower number means higher priority
bool orderType::operator>(const orderType& right) const
{
    return (priority < right.priority);
}

//Overload the stream extraction operator
//so that cout can output the right data 
ostream& operator<<(ostream& os, const orderType& oType)
{
    os <<"Order Name: "<< oType.getOrderName() << ": " << "Processing time: " << oType.getProcessTime() 
    << ": " << "Order priority: " << oType.getPriority() << ";\n ";
    

  //  os << "Order priority: " << oType.priority << "; ";

    return os;
}