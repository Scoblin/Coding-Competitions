#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }

    if(C == 2){
        if(N % 2 == 1){
            cout << -1;
            return 0;
        }
        int cost1 = 0, cost2 = 0;
        for(int i = 0; i < N; i++){
            int exp1 = (i % 2 == 0 ? 1 : 2);
            int exp2 = (i % 2 == 0 ? 2 : 1);
            if(A[i] != exp1) cost1++;
            if(A[i] != exp2) cost2++;
        }
        cout << min(cost1, cost2);
        return 0;
    }

    const int INF = 1e9;
    auto solveScenario = [&](bool firstChanged) -> int {
        vector<vector<int>> dp(N, vector<int>(2, INF));
        int firstFixedColor = -1;
        if(firstChanged){
            dp[0][1] = 1;
        } else {
            dp[0][0] = 0;
            firstFixedColor = A[0];
        }
        for(int i = 1; i < N; i++){
            int optNotChanged = INF, optChanged = INF;
            if(dp[i-1][0] != INF && A[i-1] != A[i])
                optNotChanged = min(optNotChanged, dp[i-1][0]);
            if(dp[i-1][1] != INF)
                optNotChanged = min(optNotChanged, dp[i-1][1]);
            dp[i][0] = optNotChanged;
            if(dp[i-1][0] != INF)
                optChanged = min(optChanged, dp[i-1][0] + 1);
            if(dp[i-1][1] != INF)
                optChanged = min(optChanged, dp[i-1][1] + 1);
            dp[i][1] = optChanged;
        }
        int ans = INF;
        if(firstChanged){
            ans = min(dp[N-1][0], dp[N-1][1]);
        } else {
            if(dp[N-1][0] != INF && A[N-1] != firstFixedColor)
                ans = min(ans, dp[N-1][0]);
            ans = min(ans, dp[N-1][1]);
        }
        return ans;
    };
    int ans1 = solveScenario(false);
    int ans2 = solveScenario(true);
    int ans = min(ans1, ans2);
    cout << (ans >= INF ? -1 : ans);
    return 0;
}