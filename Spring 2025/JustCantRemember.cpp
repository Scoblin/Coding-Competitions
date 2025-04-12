#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;

ll modexp(ll b,ll e){
  ll r=1;
  b%=MOD;
  while(e){
    if(e&1)r=(r*b)%MOD;
    b=(b*b)%MOD;
    e>>=1;
  }
  return r;
}

vector<vector<ll>> stirling(int n){
  vector<vector<ll>> s(n+1,vector<ll>(n+1));
  s[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
      s[i][j]=(s[i-1][j-1]+(i-1)*s[i-1][j]%MOD)%MOD;
  }
  return s;
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);
  int N,K,M;cin>>N>>K>>M;
  int maxn=max(N,M-1);
  auto S=stirling(maxn);
  ll res=0;
  for(int t=max(0,K-(N-M+1));t<=min(M-1,K);t++){
    int r=K-t+M-1;
    if(r<0||r>N)continue;
    res=(res+S[M-1][t]*S[N][r]%MOD)%MOD;
  }
  cout<<res<<'\n';
  return 0;
}