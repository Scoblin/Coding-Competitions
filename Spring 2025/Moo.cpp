// Mark's Moos
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int main() {
    int M;
    cin >> M;

    vector<string> moos(M);
    for(int i=0;i<M;i++){
        cin>>moos[i];
    }
    unordered_map<string, int> melodyCount;

    for (int i=0;i<=M-8;++i){
        unordered_set<string> uniqueMoos;
        string melodyStr;
        for(int j=i;j<i+8;++j){
            uniqueMoos.insert(moos[j]);
        }
        if(uniqueMoos.size() ==8){
            string key;
            for(int j=i;j<i+8;++j){
                key+=moos[j]+" ";
            }
            melodyCount[key]++;
        }
    }
    if(melodyCount.empty()){
        cout<< 0 << endl;

    }else{
        int maxCount=0;
        string resultMelody;
        for(auto& entry : melodyCount){
            if(entry.second > maxCount){
                maxCount=entry.second;
                resultMelody = entry.first;
            }
        }
        cout << maxCount << endl;
        cout << resultMelody << endl;
    }
    return 0;
}