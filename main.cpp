#include <iostream>
using namespace std;

#include "Queue.h"

void test1(){

	cout<<"Test 1: "<<endl;
	Queue q;

	q.enqueue(1);
	int val = q.front();
	cout<<val<<endl;


}


void test2(){

	cout<<"Test 2: "<<endl;
	Queue q;
	//make queue full
	for(int i = 0; i<QUEUE_CAPACITY; i++){
	q.enqueue(i);
	}
	q.display(cout);


}


void test3(){
	
	cout<<"Test 3: "<<endl;
	Queue q;
	
	for(int i = 0; i<QUEUE_CAPACITY; i++){
	q.enqueue(i);
	}
	//q.display(cout);
	
	for(int i = 0; i<QUEUE_CAPACITY; i++){
	q.dequeue();
	}
	q.display(cout);
	
}


int main(){
	test1();
	test2();
	test3();
	return 0;

}
