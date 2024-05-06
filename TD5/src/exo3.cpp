#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
#include <functional>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(const Card& other) const {
        return kind == other.kind && value == other.value;
    }

    size_t hash() const {
        // There are 4 kinds and 13 values, giving a total of 52 unique cards.
        return static_cast<size_t>(kind) * 13 + static_cast<size_t>(value);
    }
};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(const Card& card) const {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t size) {
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i = 0; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(std::rand() % 4), static_cast<CardValue>(std::rand() % 13)});
    }
    return cards;
}

std::string card_name(const Card& card) {
    std::string name;

    unsigned int card_value = (static_cast<unsigned int>(card.value) + 2) % 14;

    if (card_value < 10) {
        name += '0' + card_value;
    } else if (card_value == 10) {
        name += "10";
    } else if (card_value == 11) {
        name += 'V';
    } else if (card_value == 12) {
        name += 'Q';
    } else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    switch (card.kind) {
        case CardKind::Heart: name += "Heart"; break;
        case CardKind::Diamond: name += "Diamond"; break;
        case CardKind::Club: name += "Club"; break;
        case CardKind::Spade: name += "Spade"; break;
    }

    return name;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<Card> cards = get_cards(100);

    std::unordered_map<Card, int> card_count;
    for (const Card& card : cards) {
        card_count[card]++;
    }

    for (const auto& pair : card_count) {
        std::cout << card_name(pair.first) << ": " << pair.second << std::endl;
    }

    return 0;
}