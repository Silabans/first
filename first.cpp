// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

struct SeverityStats {
    set<long long> unique_timestamps;
    long long total_active_bits = 0;
};

int main() {
    // Write C++ code here
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;


    map<string, SeverityStats> log_database;
    
    for (int i; i < n; ++i) {
        long long timestamp;
        string severity;
        int status_mask;
        
        // Reads the above one by one, separated by SPACES
        cin >> timestamp >> severity >> status_mask;
        
        // Processing logic below
        if ((status_mask & (1 << 2)) == 0) {
            continue;
        }
        
        // .counts() returns 1 as we are checking an element in a set (only 1 of each element in a set)
        bool isDuplicate = log_database[severity].unique_timestamps.count(timestamp);

        if (!isDuplicate) {
            log_database[severity].unique_timestamps.insert(timestamp);

            int active_bits = __builtin_popcount(status_mask);

            log_database[severity].total_active_bits += active_bits;
        }
    }

    for (const auto& [severity_name, stats] : log_database) {
    int unique_counts = stats.unique_timestamps.size();

    cout << severity_name << ": " << unique_counts << " unique counts, "
            << stats.total_active_bits << " active bits\n";

    }


    return 0;
}