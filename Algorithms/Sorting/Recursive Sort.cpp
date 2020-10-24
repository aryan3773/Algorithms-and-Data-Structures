#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

void insert(vll &x, ll val){
    if(x.size() == 0 or x[x.size()-1] <= val){
        x.push_back(val);
        return;
    }
    
    ll temp = x[x.size()-1];
    x.pop_back();
    insert(x, val);
    x.push_back(temp);
}

void rec_sort(vll &x){
    if(x.size() == 1 or x.size() == 0){
        return ;
    }
    
    ll temp = x[x.size()-1];
    x.pop_back();
    rec_sort(x);
    insert(x, temp);
}

int main(){
    ll n, a;
    cin >> n;
    
    vll x;
    for(ll i=0; i<n; i++){
        cin >> a;
        x.push_back(a);
    }
    
    rec_sort(x);
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}
