#include <iostream>
#include <cmath>

int main() {
    long long int m, n;
    std::cin >> n >> m;
    long long int res = 0;
    long long int c1, c2;
    long long int needPorts = 0;
    std::cin >> c1 >> c2;

    if (m <= n) {
        std::cout << 0 << std::endl;
        return 0;
    }
    needPorts = m - n;
    if (c1 >= c2) {
        long long int num = std::ceil(static_cast<double>(needPorts) / 4.0);
        res = num * c2;
    } else {
        long long int num = needPorts / 4;
        res = num * c2;
        long long int remainingPorts = needPorts % 4;
        res += std::min(remainingPorts * c1, c2);
    }
    std::cout << res << std::endl;
    return 0;
}