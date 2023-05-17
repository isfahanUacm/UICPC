#include <iostream>
#include <vector>

using namespace std;

#define MODULO 1000000007

struct node {
    vector<unsigned long long> items;
    bool multiply = false;
    vector<node *> children;
    node *parent = nullptr;

    unsigned long long answer() {
        unsigned long long s = multiply ? 1 : 0;
        for (auto item : items) {
            if (multiply) {
                s = (s * item) % MODULO;
            } else {
                s = (s + item) % MODULO;
            }
        }
        for (auto child : children) {
            if (multiply) {
                s = (s * child->answer()) % MODULO;
            } else {
                s = (s + child->answer()) % MODULO;
            }
        }

        return s;
    }
};

int main() {
    auto root = new node();
    auto current = root;

    int n;
    cin >> n;

    for (auto i = 0; i < n; i++) {
        string item;
        cin >> item;
        if (item == "(") {
            auto child = new node();
            child->multiply = !current->multiply;
            child->parent = current;
            current->children.push_back(child);
            current = child;
        } else if (item == ")") {
            auto subAnswer = current->answer();
            auto old = current;
            current = current->parent;
            current->children.pop_back();
            delete old;
            current->items.push_back(subAnswer);
        } else {
            current->items.push_back(stoi(item));
        }
    }

    cout << root->answer() << endl;

    return 0;
}
