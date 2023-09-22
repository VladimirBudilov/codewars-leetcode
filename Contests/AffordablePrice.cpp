#include <iostream>

int main() {
    int amoutOfMoney = 0;
    int amountOfGuns = 0;
    int affordablePrice = 0;

    std::cin >> amountOfGuns;
    std::cin >> amoutOfMoney;

    for (int i = 0; i < amountOfGuns; i++) {
        int price;
        std::cin >> price;
        if (price <= amoutOfMoney && price > affordablePrice) {
            affordablePrice = price;
        }
    }
    std::cout << affordablePrice << std::endl;
    return 0;
}