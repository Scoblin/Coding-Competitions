#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Tarp {
    int x1, y1, x2, y2;
    int cx1, cy1, cx2, cy2;
};
int K;
vector<Tarp> tarps;
vector<int> xs, ys;
struct Key {
    int idx, rx1, ry1, rx2, ry2;
    bool operator==(const Key &o) const {
        return idx == o.idx && rx1 == o.rx1 && ry1 == o.ry1 && rx2 == o.rx2 && ry2 == o.ry2;
    }
};
struct KeyHash {
    size_t operator()(const Key &k) const {
        size_t res = 17;
        res = res * 31 + hash<int>()(k.idx);
        res = res * 31 + hash<int>()(k.rx1);
        res = res * 31 + hash<int>()(k.ry1);
        res = res * 31 + hash<int>()(k.rx2);
        res = res * 31 + hash<int>()(k.ry2);
        return res;
    }
};
unordered_map<Key, ll, KeyHash> memo;
ll rec(int idx, int rx1, int ry1, int rx2, int ry2) {
    if(rx1 >= rx2 || ry1 >= ry2) return 0;
    Key key = {idx, rx1, ry1, rx2, ry2};
    if(memo.count(key)) return memo[key];
    if(idx > K) {
        ll area = (ll)(xs[rx2] - xs[rx1]) * (ys[ry2] - ys[ry1]);
        memo[key] = area;
        return area;
    }
    int ix1 = max(rx1, tarps[idx].cx1);
    int iy1 = max(ry1, tarps[idx].cy1);
    int ix2 = min(rx2, tarps[idx].cx2);
    int iy2 = min(ry2, tarps[idx].cy2);
    ll ans = 0;
    if(ix1 >= ix2 || iy1 >= iy2) {
        ans = rec(idx + 1, rx1, ry1, rx2, ry2);
    } else {
        ans += rec(idx + 1, rx1, ry1, ix1, ry2);
        ans += rec(idx + 1, ix2, ry1, rx2, ry2);
        ans += rec(idx + 1, ix1, ry1, ix2, iy1);
        ans += rec(idx + 1, ix1, iy2, ix2, ry2);
    }
    memo[key] = ans;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M >> K;
    tarps.resize(K + 1);
    for (int i = 1; i <= K; i++){
        cin >> tarps[i].x1 >> tarps[i].y1 >> tarps[i].x2 >> tarps[i].y2;
        xs.push_back(tarps[i].x1);
        xs.push_back(tarps[i].x2);
        ys.push_back(tarps[i].y1);
        ys.push_back(tarps[i].y2);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    for (int i = 1; i <= K; i++){
        tarps[i].cx1 = int(lower_bound(xs.begin(), xs.end(), tarps[i].x1) - xs.begin());
        tarps[i].cx2 = int(lower_bound(xs.begin(), xs.end(), tarps[i].x2) - xs.begin());
        tarps[i].cy1 = int(lower_bound(ys.begin(), ys.end(), tarps[i].y1) - ys.begin());
        tarps[i].cy2 = int(lower_bound(ys.begin(), ys.end(), tarps[i].y2) - ys.begin());
    }
    for (int i = 1; i <= K; i++){
        memo.clear();
        ll vis = rec(i + 1, tarps[i].cx1, tarps[i].cy1, tarps[i].cx2, tarps[i].cy2);
        cout << vis << "\n";
    }
    return 0;
}