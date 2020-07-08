/*-- Queue.cpp-----------------------------------------------------------
 
   This file implements Queue member functions.

-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include <cstdlib>

#include "Queue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(-1), myBack(0)//back doesnt really matter
{}

//--- Definition of empty()
bool Queue::empty() const
{ 
   return (myFront == -1); 
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{

   if(empty()){
	myFront= myBack = 0;//same as myFront= (myBack = 0);
	myArray[0]= value;

	return;
    }


   int newBack = (myBack + 1) % QUEUE_CAPACITY;
   if (newBack != myFront)     // queue isn't full
   { 
      myArray[newBack] = value;
      myBack = newBack;
   }
   else
   {
      cerr << "*** Queue full -- can't add new value ***\n"
              "Must increase value of QUEUE_CAPACITY in Queue.h\n";
      exit(1);
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{ 
	if(empty()){
	return;
	}

//need to add an if statement like the corner case of myFront we added in the beginning
  for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
	 out << myArray[i] << "  ";

   cout << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if ( !empty() ) 
      return (myArray[myFront]);
   else
   {
      cerr << "*** Queue is empty "
              " -- returning garbage value ***\n";
      return myArray[QUEUE_CAPACITY-1]; // "Garbage" value
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{

if(!empty()){

	if(myFront==myBack){
		cout<<"one element left"<<endl;;
		myFront=-1;
	}
	else{

	//check if only one element in the queue
	myFront = (myFront+1)%QUEUE_CAPACITY;
	
	}

}
   else
   {
      cerr << "*** Queue is empty -- "
              "can't remove a value ***\n";
      exit(1);
   }
} 
