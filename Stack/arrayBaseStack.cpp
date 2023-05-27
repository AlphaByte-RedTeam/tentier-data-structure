#include <iostream>

#define MAX_SIZE 100

struct Stack
{
    int arr[MAX_SIZE];
    int top;

    Stack()
    {
        top = -1; // Initializing the top index to -1
    }
};

bool isEmpty(Stack &stack)
{
    return (stack.top == -1);
}

bool isFull(Stack &stack)
{
    return (stack.top == MAX_SIZE - 1);
}

void clear(Stack &stack)
{
    stack.top = -1;
}

void push(Stack &stack, int value)
{
    if (isFull(stack))
    {
        std::cout << "Error: Stack is full. Cannot push element." << std::endl;
        return;
    }

    stack.arr[++stack.top] = value;
    std::cout << "Pushed element: " << value << std::endl;
}

void pop(Stack &stack)
{
    if (isEmpty(stack))
    {
        std::cout << "Error: Stack is empty. Cannot pop element." << std::endl;
        return;
    }

    int poppedElement = stack.arr[stack.top--];
    std::cout << "Popped element: " << poppedElement << std::endl;
}

int peek(Stack &stack)
{
    if (isEmpty(stack))
    {
        std::cout << "Error: Stack is empty. Cannot peek element." << std::endl;
        return -1;
    }

    return stack.arr[stack.top];
}

void display(Stack &stack)
{
    if (isEmpty(stack))
    {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Stack elements: ";
    for (int i = 0; i <= stack.top; i++)
    {
        std::cout << stack.arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Stack stack;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack); // Output: Stack elements: 10 20 30

    std::cout << "Top element: " << peek(stack) << std::endl; // Output: Top element: 30

    pop(stack); // Output: Popped element: 30

    display(stack); // Output: Stack elements: 10 20

    clear(stack); // Clear the stack and print the stack elements

    display(stack); // Output: Stack is empty.

    return 0;
}
