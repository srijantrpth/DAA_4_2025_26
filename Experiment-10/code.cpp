#include <string>
#include <vector>

using namespace std;

class Solution {
    long long solve(const string &s, const string &t, vector<vector<long long>> &dp, int i, int j) {
        if (j == static_cast<int>(t.size())) {
            return 1;
        }
        if (i == static_cast<int>(s.size())) {
            return 0;
        }

        long long &ans = dp[i][j];
        if (ans != -1) {
            return ans;
        }

        ans = solve(s, t, dp, i + 1, j);
        if (s[i] == t[j]) {
            ans += solve(s, t, dp, i + 1, j + 1);
        }
        return ans;
    }

public:
    int numDistinct(string s, string t) {
        if (t.size() > s.size()) {
            return 0;
        }

        vector<vector<long long>> dp(s.size(), vector<long long>(t.size(), -1));
        return static_cast<int>(solve(s, t, dp, 0, 0));
    }
};