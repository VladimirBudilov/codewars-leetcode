#include <iostream>
#include <vector>
#include <cmath>

int main() {
    std::vector<int> input;
    std::vector<int> desiredWord;
    int inputNumber;
    std::cin >> inputNumber;

    for (int i = 0; i < inputNumber; i++) {
        int number;
        std::cin >> number;
        input.push_back(number);
    }
    for (int i = 0; i < inputNumber; ++i) {
        int number;
        std::cin >> number;
        desiredWord.push_back(number);
    }
    if (input == desiredWord) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    int start = -1;
    int end = -1;
    for (int i = 0; i < inputNumber; i++) {
        if (input[i] == desiredWord[i]) {
            start = i;
        } else {
            break;
        }
    }
    for (int i = inputNumber - 1; i >= 0; i--) {
        if (input[i] == desiredWord[i]) {
            end = i;
        } else {
            break;
        }
    }
    if (start == -1) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    if (end == -1) {
        end = inputNumber - 1;
    }
    auto first = input.begin() + start + 1;
    auto last = input.begin() + end;

    std::sort(first, last);

    if (input == desiredWord) {
        std::cout << "YES" << std::endl;
        return 0;
    }
    std::cout << "NO" << std::endl;
    return 0;
}