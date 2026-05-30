#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> k(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> k[i];
    }

    sort(k.begin(), k.end());

    int counter = 0;
    for (int i = 1; i < n; ++i) {
        if (k[i] != k[i - 1]) {
            counter++;
        }
    }

    std::cout << counter << '\n';
}

