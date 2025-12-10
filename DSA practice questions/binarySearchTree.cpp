#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int data) {
        if (root == nullptr)
            return new Node(data);

        if (data < root->data)
            root->left = insert(root->left, data);

        else if (data > root->data)
            root->right = insert(root->right, data);

        return root;
    }

    void insert(int data) {
        root = insert(root, data);
    }

    Node* search(Node* root, int data) {
        if (root == nullptr)
            return nullptr;

        if (data < root->data)
            return search(root->left, data);

        else if (data > root->data)
            return search(root->right, data);

        return root; 
    }

    Node* findMin(Node* root) {
        if (root == nullptr) return nullptr;

        while (root->left != nullptr)
            root = root->left;

        return root;
    }

    Node* findMax(Node* root) {
        if (root == nullptr) return nullptr;

        while (root->right != nullptr)
            root = root->right;

        return root;
    }

    Node* deleteNode(Node* root, int data) {
        if (root == nullptr)
            return nullptr;

        if (data < root->data)
            root->left = deleteNode(root->left, data);

        else if (data > root->data)
            root->right = deleteNode(root->right, data);

        else {
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
            
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    void deleteKey(int data) {
        root = deleteNode(root, data);
    }

    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (root == nullptr) return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr) return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    int height(Node* root) {
        if (root == nullptr)
            return 0;

        int l = height(root->left);
        int r = height(root->right);

        return 1 + max(l, r);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder(tree.root);

    cout << "\nPreorder: ";
    tree.preorder(tree.root);

    cout << "\nPostorder: ";
    tree.postorder(tree.root);

    cout << "\nHeight: " << tree.height(tree.root) << endl;

    tree.deleteKey(50);

    cout << "Inorder after deletion: ";
    tree.inorder(tree.root);

    return 0;
}
