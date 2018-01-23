#include <bits/stdc++.h>
using namespace std;

struct treeNode {
    int data;
    shared_ptr<treeNode> left;
    shared_ptr<treeNode> right;
};

shared_ptr<treeNode> newNode(int data) {
    shared_ptr<treeNode> node(new treeNode);

    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

void printInOrder(const shared_ptr<treeNode>& node) {
    if (node == nullptr)
        return;

    printInOrder(node->left);

    cout << node->data << " ";
    cout.flush();

    printInOrder(node->right);
}

bool inserted;

void insertNode(const shared_ptr<treeNode>& current_node, int& v, int& data, char& c) {
    if (!inserted) {
        if (current_node == nullptr) {
            return;
        }
        if (current_node->data == v) {
            if (c == 'L') {
                current_node->left = newNode(data);
            }
            else {
                current_node->right = newNode(data);
            }
            inserted = true;
            return;
        }

        insertNode(current_node->left, v, data, c);
        insertNode(current_node->right, v, data, c);
    }
    else {
        return;
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        shared_ptr<treeNode> root = nullptr;
        for (int j = 0; j < n; j++) {
            int v, data;
            char c;
            cin >> v >> data >> c;

            if (j == 0) {
                root = newNode(v);
            }
            inserted = false;
            insertNode(root, v, data, c);

        }
        cout << endl;
        printInOrder(root);
    }
}