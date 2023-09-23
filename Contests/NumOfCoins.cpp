#include <iostream>
#include <vector>
#include <climits>

int minCoins(std::vector<int> &coins, int desired_amount) {
    std::vector<int> dp(desired_amount + 1, INT_MAX);
    dp[0] = 0;

    for (int coin: coins) {
        std::cout << coin << std::endl;
        for (int i = coin; i <= desired_amount; ++i) {
            std::cout << "dp before " << dp[i] << std::endl;
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
            std::cout << i << " " << "dp after : " << dp[i] << ", dp[i - coin] + 1 : " << dp[i - coin] + 1 << std::endl;
        }
    }
    for (int i = 0; i < desired_amount + 1; ++i) {
        std::cout << i << " " << dp[i] << " ";
    }
    std::cout << std::endl;
    return dp[desired_amount];
}

int main() {
    std::vector<int> coins = {1, 2};
    int desired_amount = 5;
    int result = minCoins(coins, desired_amount);
    std::cout << "Minimum number of coins needed: " << result << std::endl;
    return 0;
}