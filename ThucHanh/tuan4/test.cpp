#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int countWorkingPlans(int N, int K1, int K2) {
    // dp[i] represents the number of valid working plans for the first i days
    vector<int> dp(N + 1, 0);
    dp[0] = 1;  // There is one way to schedule zero days (do nothing)

    // Iterate over each day
    for (int i = 1; i <= N; ++i) {
        for (int l = K1; l <= K2; ++l) {
            if (i - l == 0) {
                dp[i] = (dp[i] + dp[0]) % MOD;
            } else if (i - l - 1 >= 0) {
                dp[i] = (dp[i] + dp[i - l - 1]) % MOD;
            }
        }
    }

    // Total number of valid working plans for N days
    return dp[N]+dp[N-1];
}

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;
    cout << countWorkingPlans(N, K1, K2) << endl;
    return 0;
}
