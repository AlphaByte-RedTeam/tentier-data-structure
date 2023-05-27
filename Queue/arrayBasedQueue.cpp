#include <iostream>

const int MAX_SIZE = 100;

struct Queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize an empty queue
void initializeQueue(Queue &queue)
{
    queue.front = -1;
    queue.rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(const Queue &queue)
{
    return queue.front == -1;
}

// Function to check if the queue is full
bool isFull(const Queue &queue)
{
    return (queue.rear + 1) % MAX_SIZE == queue.front;
}

// Function to add an element to the rear of the queue
void enqueue(Queue &queue, int element)
{
    if (isFull(queue))
    {
        std::cout << "Error: Queue is full. Unable to enqueue element.\n";
        return;
    }

    if (isEmpty(queue))
    {
        queue.front = 0;
        queue.rear = 0;
    }
    else
    {
        queue.rear = (queue.rear + 1) % MAX_SIZE;
    }

    queue.arr[queue.rear] = element;
}

// Function to remove an element from the front of the queue
void dequeue(Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Error: Queue is empty. Unable to dequeue element.\n";
        return;
    }

    if (queue.front == queue.rear)
    {
        queue.front = -1;
        queue.rear = -1;
    }
    else
    {
        queue.front = (queue.front + 1) % MAX_SIZE;
    }
}

// Function to get the front element of the queue
int front(const Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Error: Queue is empty. No front element.\n";
        return -1; // Return a default value or handle the error differently
    }

    return queue.arr[queue.front];
}

// Function to clear the queue
void clear(Queue &queue)
{
    initializeQueue(queue);
}

// Function to display the elements of the queue
void displayQueue(const Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    int i = queue.front;
    while (i != queue.rear)
    {
        std::cout << queue.arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    std::cout << queue.arr[queue.rear] << "\n";
}

int main()
{
    Queue queue;
    initializeQueue(queue);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    std::cout << "Queue: ";
    displayQueue(queue); // Output: 10 20 30 40

    std::cout << "Front element: " << front(queue) << "\n"; // Output: 10

    dequeue(queue);
    std::cout << "Queue after dequeue: ";
    displayQueue(queue); // Output: 20 30 40

    clear(queue);
    std::cout << "Queue after clear: ";
    displayQueue(queue); // Output: Queue is empty.

    return 0;
}
