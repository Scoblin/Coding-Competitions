#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> pos(m + 1);
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    int rounds = 1;
    int curPos = -1;

    for (int lvl = 1; lvl <= m; lvl++){
        auto &vec = pos[lvl];
        auto it = upper_bound(vec.begin(), vec.end(), curPos);
        if (it == vec.end()){
            rounds++;
            curPos = vec[0];
        } else {
            curPos = *it;
        }
    }
    cout << rounds;
    return 0;
}