#include<iostream>
using namespace std;
int main(){
    long long x,y;
    cin>>x>>y;
    long long a=2*x-y,b=2*y-x;
    if(a%3==0&&b%3==0&&a>=0&&b>=0)cout<<"YES";
    else cout<<"NO";
}