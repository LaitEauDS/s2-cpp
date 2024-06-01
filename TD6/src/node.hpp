#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <stack>


struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    std::vector<Node const*> postfixe() const;
    int min() const;
    int max() const;
};

Node* create_node(int value);
void pretty_print_left_right(Node const& node, std::string const& prefix = "", bool is_left = true);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);

#endif