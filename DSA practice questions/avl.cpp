#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int height(Node* n) {
    if (n == nullptr)
        return 0;
    else
        return n->height;
}

int bFactor(Node* n) {
    if (n == nullptr)
        return 0;
    else
        return height(n->left) - height(n->right);
}

Node* newNode(int data) {
    Node* temp = new Node(data);
    return temp;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* z = y->left;

    y->left = x;
    x->right = z;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* z = x->right;

    x->right = y;
    y->left = z;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* insertNode(Node* top, int data) {
    if (top == nullptr)
        return newNode(data);

    if (data < top->data)
        top->left = insertNode(top->left, data);
    else if (data > top->data)
        top->right = insertNode(top->right, data);
    else
        return top;

    top->height = 1 + max(height(top->left), height(top->right));

    int balance = bFactor(top);

    // LL Case
    if (balance > 1 && data < top->left->data)
        return rightRotate(top);

    // RR Case
    if (balance < -1 && data > top->right->data)
        return leftRotate(top);

    // LR Case
    if (balance > 1 && data > top->left->data) {
        top->left = leftRotate(top->left);
        return rightRotate(top);
    }

    // RL Case
    if (balance < -1 && data < top->right->data) {
        top->right = rightRotate(top->right);
        return leftRotate(top);
    }

    return top;
}

Node* findMin(Node* top) {
    while (top->left != nullptr)
        top = top->left;

    return top;
}

Node* removeNode(Node* top, int data) {
    if (top == nullptr)
        return top;

    if (data < top->data)
        top->left = removeNode(top->left, data);
    else if (data > top->data)
        top->right = removeNode(top->right, data);
    else {
        if (top->left == nullptr) {
            Node* temp = top->right;
            delete top;
            return temp;
        }
        else if (top->right == nullptr) {
            Node* temp = top->left;
            delete top;
            return temp;
        }

        Node* temp = findMin(top->right);
        top->data = temp->data;
        top->right = removeNode(top->right, temp->data);
    }

    top->height = 1 + max(height(top->left), height(top->right));
    int balance = bFactor(top);

    // LL Case
    if (balance > 1 && bFactor(top->left) >= 0)
        return rightRotate(top);

    // LR Case
    if (balance > 1 && bFactor(top->left) < 0) {
        top->left = leftRotate(top->left);
        return rightRotate(top);
    }

    // RR Case
    if (balance < -1 && bFactor(top->right) <= 0)
        return leftRotate(top);

    // RL Case
    if (balance < -1 && bFactor(top->right) > 0) {
        top->right = rightRotate(top->right);
        return leftRotate(top);
    }

    return top;
}

bool search(Node* node, int key) {
    if (node == nullptr)
        return false;

    if (key == node->data)
        return true;

    if (key < node->data)
        return search(node->left, key);
    else
        return search(node->right, key);
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    if (search(root, 20))
        cout << "20 found in the tree\n";
    else
        cout << "20 not found\n";

    if (search(root, 25))
        cout << "25 found in the tree\n";
    else
        cout << "25 not found\n";

    cout << "Preorder traversal of the constructed AVL tree:\n";
    preOrder(root);
    cout << "\n";

    root = removeNode(root, 40);
    cout << "Preorder traversal after deleting 40:\n";
    preOrder(root);
    cout << "\n";

    root = removeNode(root, 10);
    cout << "Preorder traversal after deleting 10:\n";
    preOrder(root);
    cout << "\n";

    if (search(root, 10))
        cout << "10 found in the tree\n";
    else
        cout << "10 not found\n";

    if (search(root, 25))
        cout << "25 found in the tree\n";
    else
        cout << "25 not found\n";

    return 0;
}
