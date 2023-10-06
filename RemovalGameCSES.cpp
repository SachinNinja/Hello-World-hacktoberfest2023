#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 5001;
long long  memo[MAX_N][MAX_N][2];
 
long long dp(int i,int j,bool turn,vector<int>& v) {
  if (i==j){
    if(turn) return v[i];
    else return 0;
  }
  if(i>j) return 0;
 
  if(memo[i][j][turn]!=-1) return memo[i][j][turn];
 
  long long ans = 0;
  if(turn == 1){
    ans =  max(v[i]+dp(i+1,j,!turn,v),v[j]+dp(i,j-1,!turn,v));
  }else{
    ans = min(dp(i+1,j,!turn,v),dp(i,j-1,!turn,v));
  }
  return memo[i][j][turn]=ans;
}
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  memset(memo,-1,sizeof(memo));
  for (int i = 0; i < n; i++) cin >> v[i];
  cout<<dp(0,n-1,1,v);
}
