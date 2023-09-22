#include <iostream>
#include <vector>
#include <cmath>

int main(){
    int desiredSum;
    int numberOfBills;
    int stolenMoney = 0;
    int counter = 0;
    std::vector<int> stolenBills;
    std::vector <int> bills;

    std::cin >> desiredSum;
    std::cin >> numberOfBills;

    for(int i = 0; i < numberOfBills; i++) {
        int bill;
        std::cin >> bill;
        bills.push_back(bill);
    }
    for(int i = 0; i < std::pow(3, numberOfBills) ;i++)
    {
        stolenMoney = 0;
        int div = 1;
        for(int j = 0;  j < numberOfBills; j++) {
            stolenMoney += bills[j] * ((i / div) % 3);
            div *= 3;
        }
        if (stolenMoney == desiredSum) {
            int div = 1;
            for(int j = 0;  j < numberOfBills; j++) {
                int bill = bills[j];
                for (int g = 0; g < ((i / div) % 3); g++) {
                    stolenBills.push_back(bill);
                    counter++;
                }
                div *= 3;
            }
            break;
        }
    }
    if(desiredSum == stolenMoney) {
        std::cout << counter << std::endl;
        for(int i = 0; i < stolenBills.size(); i++) {
            std::cout << stolenBills[i];
            if (i != stolenBills.size() - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
        return 0;
    }
    std::cout << -1 << std::endl;
    return 0;
}
