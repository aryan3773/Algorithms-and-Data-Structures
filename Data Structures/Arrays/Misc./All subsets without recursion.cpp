#include<bits/stdc++.h>
#define ll long long int
#define vll vector<vll>
using namespace std;

void subsets(string x){
    ll n = pow(2, x.size());
    vector<string> s;
    for(ll i=1; i<n; i++){
        string temp;
        for(ll j=0; j<x.size(); j++){
            if((i>>j)&1){
                temp += x[j];
            }
        }
        s.push_back(temp);
    }
    
    for(auto i:s){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    string x;
    cin >> x;
    
    subsets(x);
    return 0;
}