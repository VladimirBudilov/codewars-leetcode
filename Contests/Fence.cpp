#include <iostream>
#include <vector>

int main() {
    int n, k;
    int min;
    int max;
    int res = INT32_MAX;

    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];
    int size = (int) arr.size() - k;
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i <= k; ++i) {
        min = INT32_MAX;
        max = 0;
        for (int j = i; j < size + i; ++j) {
            min = arr[j] > min ? min : arr[j];
            max = arr[j] < max ? max : arr[j];
        }
        res = (max - min) < res ? max - min : res;
    }
    std::cout << res << std::endl;
    return 0;
}