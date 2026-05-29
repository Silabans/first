#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, m;
    if(!(cin >> N >> m)) return 0;

    // as the largest m could be is 60 000, integers are sufficient (no need for long long)
    vector<int> k(m);


    for (int i = 0; i < m; ++i) {
        cin >> k[i];
    }

    sort(k.begin(), k.end());

    int count = 0;
    for (int i = 0; i < m; ++i) {
        if ((N - k[i]) < 0) {
            break;
        }
        N -= k[i];

        count++;

    }

    cout << count + '\n';

    return 0;
}