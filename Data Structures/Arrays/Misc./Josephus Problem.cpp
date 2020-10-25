#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

void solve(vll &v, ll k, ll index, ll &ans){
    if(v.size() == 1){
        ans = v[0];
        return ;
    }
    
    index = (index+k)%v.size();
    v.erase(v.begin() + index);
    solve(v, k, index, ans);
}

int main(){
    ll n, k, a;
    cin >> n >> k;
    vll x;
    
    for(ll i=1; i<=n; i++){
        x.push_back(i);
    }
    ll index = 0, ans = 0;
    k-=1;
    solve(x, k, index, ans);
    cout << ans << endl;
    return 0;
}