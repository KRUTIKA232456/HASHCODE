#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    std::string filename = "flower.txt";  
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return 1;
    }

    std::unordered_map<std::string, int> wordFrequency;
    std::string word;

    while (inputFile >> word) {
        
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        
        word.erase(std::remove_if(word.begin(), word.end(), [](char c) {
            return !std::isalnum(c);
        }), word.end());

        if (!word.empty()) {
            wordFrequency[word]++;
        }
    }

    inputFile.close();

    std::vector<std::pair<std::string, int>> sortedWords;
    for (const auto& entry : wordFrequency) {
        sortedWords.push_back(entry);
    }

    std::sort(sortedWords.begin(), sortedWords.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });

    
    int count = 0;
    for (const auto& pair : sortedWords) {
        if (count >= 10) {
            break;
        }
        std::cout << pair.first << ": " << pair.second << std::endl;
        count++;
    }

    return 0;
}
