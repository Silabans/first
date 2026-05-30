#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Write C++ code here
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N, m;
    if (!(std::cin >> N >> m)) return 0;
    
    // there is no need for long long as 30 000 * 60 000 = 1.8 * 10^9, which lower than the limit
    // for integers -> roughly 2.14 * 10^9
    std::vector<int> data(m);
    
    for (int i = 0; i < m; ++i) {
        std::cin >> data[i];
    }
    
    sort(data.begin(), data.end());
    
    int counter = 0;
    for (int i = 0; i < m; ++i) {
        if (N < data[i]) break;
        
        N -= data[i];
        ++counter;
    }
    
    std::cout << counter << '\n';

    return 0;
}