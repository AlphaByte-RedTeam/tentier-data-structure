#include <iostream>

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot pop from an empty stack." << std::endl;
            return -1; // Return a default value indicating an error
        }

        int poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty. Cannot peek into an empty stack." << std::endl;
            return -1; // Return a default value indicating an error
        }

        return top->data;
    }

    // Create clear() method
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty." << std::endl;
            return;
        }

        std::cout << "Stack elements: ";
        Node *current = top;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display(); // Stack elements: 30 20 10

    std::cout << "Peek: " << stack.peek() << std::endl; // Peek: 30

    std::cout << "Popped: " << stack.pop() << std::endl; // Popped: 30

    stack.display(); // Stack elements: 20 10

    stack.clear(); // Clear the stack and print the stack elements

    stack.display(); // Stack is empty.

    return 0;
}
