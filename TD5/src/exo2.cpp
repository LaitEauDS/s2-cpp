// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <string>


// std::string random_name(size_t size) {
//     std::string name {""};
//     // Optimisation pour que la chaîne de caractère ne réalloue pas de la mémoire à chaque caractère ajouté
//     //https://cplusplus.com/reference/string/string/reserve/
//     name.reserve(size);
//     for(size_t i {0}; i < size; ++i) {
//         name.push_back('A' + std::rand() % 26);
//     }
//     return name;
// }

// std::vector<std::pair<std::string, float>> get_robots_fix(size_t size) {
//     std::vector<std::pair<std::string, float>> robots_fix {};
//     // Meme optimisation que dans random_name()
//     // https://cplusplus.com/reference/vector/vector/reserve/
//     robots_fix.reserve(size);
//     for (size_t i {0}; i < size; ++i) {
//         // random name 
//         std::string robotName { random_name(2) };
//         // random cost
//         float cost {static_cast<float>(std::rand()) / RAND_MAX * 1000.0f};
//         robots_fix.push_back(std::make_pair(robotName, cost));
//     }
//     return robots_fix;
// }

// std::unordered_map<std::string, std::vector<float>> robots_fixes_map(const std::vector<std::pair<std::string, float>>& robots_fixes) {
//     std::unordered_map<std::string, std::vector<float>> map;
//     for (const auto& repair : robots_fixes) {
//         map[repair.first].push_back(repair.second);
//     }
//     return map;
// }

// float sommeElements(const std::vector<float>& elements) {
//     float sum = 0.0f;
//     for (float value : elements) {
//         sum += value;
//     }
//     return sum;
// }

// int main() {
//     std::srand(static_cast<unsigned>(std::time(nullptr)));

//     std::vector<std::pair<std::string, float>> repairs = get_robots_fix(100);

//     auto repair_map = robots_fixes_map(repairs);

//     for (const auto& robot_repairs : repair_map) {
//         std::cout << "Total des coûts de réparations du robot " << robot_repairs.first << " est $"
//                   << sommeElements(robot_repairs.second) << std::endl;
//     }

//     return 0;
// }
