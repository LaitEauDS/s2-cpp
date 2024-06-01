#include "node.hpp"

Node* create_node(int value) {
    return new Node { value };
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int value) {
    if (value < this->value) {
        if (left) {
            left->insert(value);
        } else {
            left = create_node(value);
        }
    } else {
        if (right) {
            right->insert(value);
        } else {
            right = create_node(value);
        }
    }
}

int Node::height() const {
    if (is_leaf()) return 1;
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + std::max(left_height, right_height);
}

void Node::delete_childs() {
    if (left) {
        left->delete_childs();
        delete left;
        left = nullptr;
    }
    if (right) {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

void Node::display_infixe() const {
    if (left) left->display_infixe();
    std::cout << value << " ";
    if (right) right->display_infixe();
}

std::vector<Node const*> Node::prefixe() const {
    std::vector<Node const*> nodes { this };
    if (left) {
        auto left_nodes = left->prefixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        auto right_nodes = right->prefixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

std::vector<Node const*> Node::postfixe() const {
    std::vector<Node const*> nodes {};
    std::stack<Node const*> to_process {};
    Node const* previous { nullptr };
    to_process.push(this);

    while (!to_process.empty()) {
        Node const* current { to_process.top() };

        if (previous == nullptr || (previous->left == current || previous->right == current)) {
            if (current->left) {
                to_process.push(current->left);
            } else if (current->right) {
                to_process.push(current->right);
            } else {
                nodes.push_back(current);
                to_process.pop();
            }
        } else if (current->left == previous) {
            if (current->right) {
                to_process.push(current->right);
            } else {
                nodes.push_back(current);
                to_process.pop();
            }
        } else if (current->right == previous) {
            nodes.push_back(current);
            to_process.pop();
        }

        previous = current;
    }

    return nodes;
}

int Node::min() const {
    const Node* current = this;
    while (current->left) {
        current = current->left;
    }
    return current->value;
}

int Node::max() const {
    const Node* current = this;
    while (current->right) {
        current = current->right;
    }
    return current->value;
}

Node*& most_left(Node*& node) {
    if (node->left == nullptr) {
        return node;
    }
    return most_left(node->left);
}

bool remove(Node*& node, int value) {
    if (node == nullptr) return false;

    if (value < node->value) {
        return remove(node->left, value);
    } else if (value > node->value) {
        return remove(node->right, value);
    } else {
        if (node->is_leaf()) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node*& min_node = most_left(node->right);
            node->value = min_node->value;
            return remove(min_node, min_node->value);
        }
        return true;
    }
    return false;
}

void delete_tree(Node* node) {
    if (node == nullptr) return;
    node->delete_childs();
    delete node;
}

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}