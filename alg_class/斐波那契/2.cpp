#include <iostream>

using namespace std;

int N = 10;

int main() {
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; i ++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << N << ": " << dp[N] << endl;

    return 0;
}
