#include <iostream>
using namespace std;


int* queue = nullptr;
int front = -1;
int rear = -1;
int capacity = 0;

bool isEmpty()
{
	return (front == -1 && rear == -1);
}
bool isFull()
{
	return(rear == capacity - 1);
}

void enqueue(int value)
{
	if (isEmpty()) {
		front = rear = 0;
		capacity = 1;
		queue = new int[capacity];
	}
	else if (isFull()) {
		int newCapacity = capacity * 2;
		int* newQueue = new int[newCapacity];
		for (int i = 0; i < capacity; ++i) 
		{
			newQueue[i] = queue[i];
		}
		delete[] queue;
		queue = newQueue;
		capacity = newCapacity;
	}
	queue[rear++] = value;
}

void dequeue()
{
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		return;
	}
	else if (front == rear) {
		front = rear = -1;
	}
	else {
		front++;
	}
}

int frontElement()
{
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		return -1;
	}
	return queue[front];
}

int main()
{
	queue = new int[3];
	capacity = 3;
	
	enqueue(100);
	enqueue(200);
	enqueue(300);
	
	cout << "element in front: " << frontElement() << endl;
	
	enqueue(100);
		
	dequeue();
	cout << "element in front after dequeue: " << frontElement() << endl;
	
/*	dequeue();
	cout << "element in front after dequeue: " << frontElement() << endl;

	dequeue();
	cout << "element in front after dequeue: " << frontElement() << endl;  */

	
	return 0;
}

