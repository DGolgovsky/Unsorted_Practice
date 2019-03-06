#include <iostream>
#include <vector>

int tabs = 0;

struct Node {
    int p_key;
    Node *p_left = nullptr;
    Node *p_right = nullptr;
};

void insert(Node *&p_tree, int key) {
    if (!p_tree) {
        p_tree = new Node;
        p_tree->p_key = key;
        return;
    }
    if (key > p_tree->p_key) {
        insert(p_tree->p_right, key);
    } else {
        insert(p_tree->p_left, key);
    }
}

void free(Node *p_tree) {
    if (p_tree != nullptr) {
        free(p_tree->p_left);
        free(p_tree->p_right);
        delete p_tree;
    }
}

void print(Node *p_tree) {
    if (!p_tree)
        return;
    tabs++;
    print(p_tree->p_left);

    for (int i = 0; i < tabs; ++i)
        std::cout << " ";
    std::cout << p_tree->p_key << std::endl;

    print(p_tree->p_right);
    tabs--;
    return;
}

int main() {
    Node *test_tree = new Node;
    std::vector<int> vctr = {20, 14, 17, 2, 30, 25, 13, 28, 36, 49};
    for (auto it : vctr) {
        insert(test_tree, it);
    }
    print(test_tree);
    std::cout << std::endl;
    free(test_tree);
    return 0;
}

