#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the binary tree
Node* insertNode(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }
    else {
        std::cout << "Enter 'l' to insert '" << data << "' to the left of " << root->data << " or 'r' to insert it to the right: ";
        char choice;
        std::cin >> choice;

        if (choice == 'l')
            root->left = insertNode(root->left, data);
        else if (choice == 'r')
            root->right = insertNode(root->right, data);
    }
    return root;
}

// Function for pre-order traversal
void preOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Function for in-order traversal
void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Function for post-order traversal
void postOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

// Function to find the depth of the tree
int findDepth(Node* root) {
    if (root == nullptr)
        return 0;
    
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
}

// Function to find a specific value in the tree
bool findValue(Node* root, int value) {
    if (root == nullptr)
        return false;
    
    if (root->data == value)
        return true;
    
    return findValue(root->left, value) || findValue(root->right, value);
}

// Function to count the number of nodes in the tree
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        std::cout << "Binary Tree Menu:\n";
        std::cout << "1. Insert Node\n";
        std::cout << "2. Pre-order Traversal\n";
        std::cout << "3. In-order Traversal\n";
        std::cout << "4. Post-order Traversal\n";
        std::cout << "5. Find Depth of the Tree\n";
        std::cout << "6. Find a Value\n";
        std::cout << "7. Count Nodes\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to be inserted: ";
                std::cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                std::cout << "Pre-order Traversal: ";
                preOrderTraversal(root);
                std::cout << "\n";
                break;
            case 3:
                std::cout << "In-order Traversal: ";
                inOrderTraversal(root);
                std::cout << "\n";
                break;
            case 4:
                std::cout << "Post-order Traversal: ";
                postOrderTraversal(root);
                std::cout << "\n";
                break;
            case 5:
                std::cout << "Depth of the Tree: " << findDepth(root) << "\n";
                break;
            case 6:
                std::cout << "Enter value to be found: ";
                std::cin >> value;
                if (findValue(root, value))
                    std::cout << "Value " << value << " found in the tree.\n";
                else
                    std::cout << "Value " << value << " not found in the tree.\n";
                break;
            case 7:
                std::cout << "Number of Nodes: " << countNodes(root) << "\n";
                break;
            case 8:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}
