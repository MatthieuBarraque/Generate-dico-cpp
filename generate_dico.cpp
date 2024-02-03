// generate_dico.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "generate_dico.h"

std::string capitalize(const std::string& s) {
    if (s.empty()) return s;
    std::string result(s);
    result[0] = std::toupper(result[0]);
    return result;
}

std::vector<std::string> generate_combinations(std::vector<std::string> keywords, char special_char, int max_words) {
    std::set<std::string> unique_combinations;
    std::sort(keywords.begin(), keywords.end(), [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
    for (auto& keyword : keywords) {
        std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
    }

    // TODO: Implement itertools.product equivalent here

    std::vector<std::string> combinations_with_capital;
    for (const auto& word : unique_combinations) {
        combinations_with_capital.push_back(capitalize(word));
    }
    return combinations_with_capital;
}

void ascii_art_header() {
    std::cout << R"(
    8888888b.  8888888888 .d8888b.  888    d8P  
    888   Y88b 888       d88P  Y88b 888   d8P   
    888    888 888       Y88b.      888  d8P    
    888   d88P 8888888    "Y888b.   888d88K     
    8D3SIR3"  888           "Y88b. 8888888b    
    888        888             "888 888  Y88b   
    888        888       Y88b  d88P 888   Y88b  
    888        8888888888 "Y8888P"  888    Y88b 
    )" << '\n';
}

void main() {
    ascii_art_header();
    std::cout << "Générateur de combinaisons - Made by D3sir3\n";
    std::cout << "Combien de mots-clés voulez-vous entrer?\n";
    int nombre_mots;
    std::cin >> nombre_mots;

    std::vector<std::string> mots;
    for (int i = 0; i < nombre_mots; ++i) {
        std::string mot;
        std::cin >> mot;
        mots.push_back(mot);
    }

    auto combinations = generate_combinations(mots, ' ', 1000000);
    std::ofstream file("my_Dico.txt");
    for (const auto& word : combinations) {
        file << word << '\n';
    }

    std::cout << "\n" << combinations.size() << " mélanges ont été générés et sauvegardés dans 'my_Dico.txt'.\n";
}