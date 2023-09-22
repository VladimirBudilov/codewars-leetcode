#include <iostream>
#include <map>

int main() {
    std::string input;
    int amountOfWords = 0;
    std::map<std::string, int> words;
    std::cin >> input;
    words = {{"s", 0},
             {"h", 0},
             {"e", 0},
             {"r", 0},
             {"i", 0},
             {"f", 0}};
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 's') {
            words["s"]++;
        }
        if (input[i] == 'h') {
            words["h"]++;
        }
        if (input[i] == 'e') {
            words["e"]++;
        }
        if (input[i] == 'r') {
            words["r"]++;
        }
        if (input[i] == 'i') {
            words["i"]++;
        }
        if (input[i] == 'f') {
            words["f"]++;
        }
    }
    words["f"] = words["f"] / 2;
    for (auto i: words) {
        if (amountOfWords == 0) {
            amountOfWords = i.second;
        }
        if (i.second < amountOfWords) {
            amountOfWords = i.second;
        }
    }
    std::cout << amountOfWords << std::endl;
    return 0;
}