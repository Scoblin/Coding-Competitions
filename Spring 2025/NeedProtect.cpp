// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// struct Animal {
//     int a, b;
// };

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int N, M;
//     if (!(cin >> N >> M)) return 1;

//     vector<Animal> animals(M);
//     vector<vector<int>> locAnimals(N+1);
//     for (int i = 0; i < M; i++){
//         int a, b;
//         cin >> a >> b;
//         animals[i] = {a, b};
//         locAnimals[a].push_back(i);
//         locAnimals[b].push_back(i);
//     }

//     vector<int> used(M, 0);
//     vector<int> coverage(N+1, 0);

//     for (int loc = 1; loc <= N; loc++){
//         if (locAnimals[loc].size() == 1) {
//             int idx = locAnimals[loc][0];
//             if(used[idx] < 2) {
//                 used[idx] = 2;
//             }
//         }
//     }
//     for (int i = 0; i < M; i++){
//         if(used[i] > 0) {
//             coverage[animals[i].a] += used[i];
//             coverage[animals[i].b] += used[i];
//         }
//     }
//     queue<int> q;
//     for (int loc = 1; loc <= N; loc++){
//         if (coverage[loc] < 2) {
//             q.push(loc);
//         }
//     }

//     while(!q.empty()){
//         int loc = q.front();
//         q.pop();
//         if(coverage[loc] >= 2) continue;
//         int deficit = 2 - coverage[loc];
//         while(deficit > 0) {
//             int candidate = -1;
//             int bestGain = -1;
//             for (int idx : locAnimals[loc]) {
//                 if(used[idx] < 2) {
//                     int gain = 0;
//                     int end1 = animals[idx].a;
//                     int end2 = animals[idx].b;
//                     if(coverage[end1] < 2) gain++;
//                     if(coverage[end2] < 2) gain++;
//                     if(gain > bestGain) {
//                         bestGain = gain;
//                         candidate = idx;
//                     }
//                 }
//             }
//             if(candidate == -1) {
//                 break;
//             }
//             used[candidate] += 1;
//             int end1 = animals[candidate].a, end2 = animals[candidate].b;
//             coverage[end1] += 1;
//             coverage[end2] += 1;
//             deficit = 2 - coverage[loc];
//             if(coverage[end1] < 2) q.push(end1);
//             if(coverage[end2] < 2) q.push(end2);
//         }
//     }

//     int totalDefenders = 0;
//     for (int i = 0; i < M; i++){
//         totalDefenders += used[i];
//     }
//     cout << totalDefenders << "\n";

//     return 0;
// }
