 #include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

// Utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Get height of a node
int height(Node* n) {
    return (n == nullptr) ? 0 : n->height;
}

// Create a new node
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor of node N
int getBalance(Node* N) {
    return (N == nullptr) ? 0 : height(N->left) - height(N->right);
}

// Insert a key in AVL tree
Node* insert(Node* node, int key) {
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate keys not allowed

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Check balance
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find node with minimum key value
Node* findMin(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// Delete a node in AVL tree
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    // Standard BST deletion
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance the node
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* node, int key) {
    if (node == nullptr)
        return false;          // key not found

    if (key == node->key)
        return true;           // key found

    if (key < node->key)
        return search(node->left, key);   // search left subtree
    else
        return search(node->right, key);  // search right subtree
}

// Preorder traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert nodes
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
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

    // Delete nodes
    root = deleteNode(root, 40);
    cout << "Preorder traversal after deleting 40:\n";
    preOrder(root);
    cout << "\n";

    root = deleteNode(root, 10);
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
