#include <bits/stdc++.h>
using namespace std;
 
struct Edge {
    int u, v;
    int mode;
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<Edge> edges(M);
    vector<vector<int>> inc(N + 1);
    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v, 0};
        inc[u].push_back(i);
        inc[v].push_back(i);
    }
    vector<int> req(N + 1, 2);
    long long cost = 0;
    bool progress = true;
    while(progress){
        progress = false;
        for (int i = 0; i < M; i++){
            if(edges[i].mode == 0){
                int a = edges[i].u, b = edges[i].v;
                if(req[a] >= 2 && req[b] >= 2){
                    edges[i].mode = 2;
                    req[a] = max(0, req[a] - 2);
                    req[b] = max(0, req[b] - 2);
                    cost += 2;
                    progress = true;
                }
            }
        }
        for (int i = 0; i < M; i++){
            if(edges[i].mode == 0){
                int a = edges[i].u, b = edges[i].v;
                if(req[a] >= 1 && req[b] >= 1){
                    edges[i].mode = 1;
                    req[a] = max(0, req[a] - 1);
                    req[b] = max(0, req[b] - 1);
                    cost += 1;
                    progress = true;
                }
            }
        }
        for (int v = 1; v <= N; v++){
            if(req[v] > 0){
                for (int idx : inc[v]){
                    if(edges[idx].mode == 0){
                        int a = edges[idx].u, b = edges[idx].v;
                        edges[idx].mode = 1;
                        req[v] = max(0, req[v] - 1);
                        if(req[a == v ? b : a] > 0)
                            req[a == v ? b : a] = max(0, req[a == v ? b : a] - 1);
                        cost += 1;
                        progress = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < M; i++){
            if(edges[i].mode == 1){
                int a = edges[i].u, b = edges[i].v;
                if(req[a] > 0 || req[b] > 0){
                    edges[i].mode = 2;
                    if(req[a] > 0)
                        req[a] = max(0, req[a] - 1);
                    if(req[b] > 0)
                        req[b] = max(0, req[b] - 1);
                    cost += 1;
                    progress = true;
                }
            }
        }
    }
    for (int v = 1; v <= N; v++){
        if(req[v] > 0){
            cout << -1;
            return 0;
        }
    }
    cout << cost;
    return 0;
}