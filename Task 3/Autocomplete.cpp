#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
    string key;
    Node* left;
    Node* right;
    int height;
    Node(string k) : key(k), left(nullptr), right(nullptr), height(1) {}
};


int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* insert(Node* node, string key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // duplicate word

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

   
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

   
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool startsWith(const string& word, const string& prefix) {
    if (word.size() < prefix.size()) return false;
    for (size_t i = 0; i < prefix.size(); ++i) {
        if (tolower(word[i]) != tolower(prefix[i])) return false;
    }
    return true;
}

void findAllWithPrefix(Node* root, const string& prefix, vector<string>& results) {
    if (!root) return;


    if (startsWith(root->key, prefix))
        results.push_back(root->key);


    if (prefix < root->key)
        findAllWithPrefix(root->left, prefix, results);


    if (prefix > root->key || startsWith(root->key, prefix))
        findAllWithPrefix(root->right, prefix, results);
}

int main() {
    Node* root = nullptr;

    ifstream file("dictionary.txt");
    if (!file) {
        cout << "Error: dictionary.txt not found.\n";
        return 1;
    }

    string word;
    int count = 0;
    while (file >> word) {
        root = insert(root, word);
        count++;
    }
    cout << "Loaded " << count << " words into the AVL tree.\n";

    string prefix;
    while (true) {
        cout << "\nType a prefix (or 'exit'): ";
        cin >> prefix;
        if (prefix == "exit") break;

        vector<string> suggestions;
        findAllWithPrefix(root, prefix, suggestions);

        if (suggestions.empty()) {
            cout << "No suggestions.\n";
        } else {
            cout << "Suggestions:\n";
            for (auto& s : suggestions)
                cout << "- " << s << "\n";
        }
    }

    return 0;
}
