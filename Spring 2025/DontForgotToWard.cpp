#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    long long min_x=1e9,max_x=-1e9,min_y=1e9,max_y=-1e9;
    for(int i=0;i<N;i++){
        long long x,y;
        cin>>x>>y;
        min_x=min(min_x,x);
        max_x=max(max_x,x);
        min_y=min(min_y,y);
        max_y=max(max_y,y);
    }
    cout<<max(max_x-min_x,max_y-min_y)+1;
}