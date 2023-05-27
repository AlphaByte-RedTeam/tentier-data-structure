#include <iostream>

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

// Function to initialize an empty queue
void initializeQueue(Queue &queue)
{
    queue.front = nullptr;
    queue.rear = nullptr;
}

// Function to check if the queue is empty
bool isEmpty(const Queue &queue)
{
    return queue.front == nullptr;
}

// Function to add an element to the rear of the queue
void enqueue(Queue &queue, int element)
{
    Node *newNode = new Node;
    newNode->data = element;
    newNode->next = nullptr;

    if (isEmpty(queue))
    {
        queue.front = newNode;
        queue.rear = newNode;
    }
    else
    {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

// Function to remove an element from the front of the queue
void dequeue(Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Error: Queue is empty. Unable to dequeue element.\n";
        return;
    }

    Node *temp = queue.front;
    queue.front = queue.front->next;

    if (queue.front == nullptr)
    {
        queue.rear = nullptr;
    }

    delete temp;
}

// Function to get the front element of the queue
int front(const Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Error: Queue is empty. No front element.\n";
        return -1; // Return a default value or handle the error differently
    }

    return queue.front->data;
}

// Function to clear the queue
void clear(Queue &queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
}

// Function to display the elements of the queue
void displayQueue(const Queue &queue)
{
    if (isEmpty(queue))
    {
        std::cout << "Queue is empty.\n";
        return;
    }

    Node *current = queue.front;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
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
    displayQueue(queue); // Output: Queue: 10 20 30 40

    std::cout << "Front element: " << front(queue) << "\n"; // Output: Front element: 10

    dequeue(queue);
    std::cout << "Queue after dequeue: ";
    displayQueue(queue); // Output: Queue: 20 30 40

    clear(queue);
    std::cout << "Queue after clear: ";
    displayQueue(queue); // Output: Queue is empty.

    return 0;
}
