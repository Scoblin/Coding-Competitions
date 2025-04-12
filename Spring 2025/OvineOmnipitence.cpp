#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
 
struct UnionFind {
    vector<int> parent, rank;
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int a) {
        return parent[a] == a ? a : parent[a] = find(parent[a]);
    }
    void unionn(int a, int b) {
        a = find(a), b = find(b);
        if(a == b)return;
        if(rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if(rank[a] == rank[b]) rank[a]++;
    }
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> color(n);
    for (int i = 0; i < n; i++){
        cin >> color[i];
    }
    UnionFind uf(n);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        uf.unionn(u - 1, v - 1);
    }
    vector<vector<int>> comps(n);
    for (int i = 0; i < n; i++){
        comps[uf.find(i)].push_back(i);
    }
    int compCount = 0;
    vector<int> tot(c + 1, 0), uniformCount(c + 1, 0);
    for (int i = 0; i < n; i++){
        if(comps[i].empty()) continue;
        compCount++;
        bool uniform = true;
        int col = color[comps[i][0]];
        unordered_set<int> st;
        for (int idx : comps[i]){
            st.insert(color[idx]);
            if(color[idx] != col) uniform = false;
        }
        for (int colVal : st){
            tot[colVal]++;
        }
        if(uniform) uniformCount[col]++;
    }
    int ans = 1e9;
    for (int i = 1; i <= c; i++){
        if(tot[i] == compCount){
            ans = min(ans, compCount - uniformCount[i]);
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
    return 0;
}