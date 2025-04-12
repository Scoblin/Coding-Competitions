#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    const int MAXN = 50005;
    int N, M;
    vector<pair<int, int>> animals;
    vector<int> locationDefenders(MAXN, 0);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N>>M;
    animals.resize(M);
    for(int i=0;i<M;++i){
        int a,b;
        animals[i]={a,b};
        locationDefenders[a]++;
        locationDefenders[b]++;
    }
    //testing
    vector<int> needs(N+1,0);
    for(int i=1; i<=N; ++i){
        if(locationDefenders[i]<2)
            needs[i] = 2 - locationDefenders[i];
    }
    int alliesNeeded = 0;
    vector<int> defenderCount(N+1,0);
    vector<bool> used(M, false);
    for(int i=0;i<M;++i){
        defenderCount[animals[i].first]++;
        defenderCount[animals[i].second]++;
    }
    for ( int i=0; i<M; ++i){
        int a = animals[i].first;
        int b = animals[i].second;

        if(defenderCount[a]>=2 && defenderCount[b]>= 2)
            continue;

        if(!used[i]) {
            used[i] = true;
            alliesNeeded++;
            defenderCount[a]++;
            defenderCount[b]++;
        }
    }
    for(int i=1; i<=N;++i){
        while(defenderCount[i]<2){
            for(int j=0; j<M;++j) {
                if(used[j])
                    continue;
                int a = animals[i].first;
                int b = animals[i].second;
                if(a==i || b==j){
                    used[j]=true;
                    defenderCount[a]++;
                    defenderCount[b]++;
                    break;
                }
            }
        }
    }
    cout<<M+alliesNeeded<<endl;
    return 0;
}