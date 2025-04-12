#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool coinChange(int N, vector<int>& seg) {
    vector<int> dp(N+1, -1);
    dp[0] = 0;
    for(int i = 0; i <= N; i++){
        if(dp[i] != -1){
            for(int coin : {3,4}){
                if(i+coin <= N && dp[i+coin]==-1){
                    dp[i+coin] = coin;
                }
            }
        }
    }
    if(dp[N]==-1) return false;
    int cur = N;
    while(cur>0){
        seg.push_back(dp[cur]);
        cur -= dp[cur];
    }
    reverse(seg.begin(), seg.end());
    return true;
}
void fillBlock(vector<string>& grid, int sr, int sc, int r, int c) {
    if(r==3 && c==3) {
        string hor = "<=>";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                grid[sr+i][sc+j] = hor[j];
    } else if(r==3 && c==4) {
        grid[sr+0][sc+0] = '^';
        {string hor = "<=>"; for(int j = 0; j < 3; j++) grid[sr+0][sc+1+j] = hor[j]; }
        grid[sr+1][sc+0] = '#';
        {string hor = "<=>"; for(int j = 0; j < 3; j++) grid[sr+1][sc+1+j] = hor[j]; }
        grid[sr+2][sc+0] = 'v';
        {string hor = "<=>"; for(int j = 0; j < 3; j++) grid[sr+2][sc+1+j] = hor[j]; }
    } else if(r==4 && c==3) {
        string hor = "<=>";
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 3; j++)
                grid[sr+i][sc+j] = hor[j];
    } else if(r==4 && c==4) {
        { string hor4 = "<==>"; for (int j = 0; j < 4; j++) grid[sr+0][sc+j] = hor4[j]; }
        grid[sr+1][sc+0] = '^';
        { string hor3 = "<=>"; for (int j = 0; j < 3; j++) grid[sr+1][sc+1+j] = hor3[j]; }
        grid[sr+2][sc+0] = '#';
        { string hor3 = "<=>"; for (int j = 0; j < 3; j++) grid[sr+2][sc+1+j] = hor3[j]; }
        grid[sr+3][sc+0] = 'v';
        { string hor3 = "<=>"; for (int j = 0; j < 3; j++) grid[sr+3][sc+1+j] = hor3[j]; }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    if(N==2 || N==5){ cout << "Impossible"; return 0; }
    vector<int> rows, cols;
    if(!coinChange(N, rows) || !coinChange(N, cols)){
        cout << "Impossible";
        return 0;
    }

    vector<string> grid(N, string(N, ' '));
    int sr = 0;
    for (int r_seg : rows) {
        int sc = 0;
        for (int c_seg : cols) {
            fillBlock(grid, sr, sc, r_seg, c_seg);
            sc += c_seg;
        }
        sr += r_seg;
    }
    for (auto &s : grid) cout << s <<"\n";
    return 0;
}