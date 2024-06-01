#include "node.hpp"

int main() {
    Node* root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    std::cout << "Arbre binaire:" << std::endl;
    pretty_print_left_right(*root);

    std::cout << "Feuille: " << (root->is_leaf() ? "Yes" : "No") << std::endl;

    std::cout << "Hauteur de l'arbre: " << root->height() << std::endl;

    std::cout << "Parcours infixe: ";
    root->display_infixe();
    std::cout << std::endl;

    std::cout << "Parcours prefixe: ";
    auto prefix_nodes = root->prefixe();
    for (const auto& node : prefix_nodes) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    std::cout << "Parcours postfixe: ";
    auto postfix_nodes = root->postfixe();
    for (const auto& node : postfix_nodes) {
        std::cout << node->value << " ";
    }
    std::cout << std::endl;

    std::cout << "Valeur minimale: " << root->min() << std::endl;
    std::cout << "Valeur maximale: " << root->max() << std::endl;

    int sum = 0;
    for (const auto& node : prefix_nodes) {
        sum += node->value;
    }
    std::cout << "Somme des valeurs des noeuds de l'arbre binaire : " << sum << std::endl;


    delete_tree(root);

    return 0;
}
