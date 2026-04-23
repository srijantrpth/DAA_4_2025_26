#include <iostream>
#include <vector>

using namespace std;

int minDifference(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    vector<bool> dp(sum / 2 + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = sum / 2; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    for (int j = sum / 2; j >= 0; j--) {
        if (dp[j]) {
            return sum - 2 * j;
        }
    }
    return 0;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << minDifference(arr, n) << "\n";
    return 0;
}