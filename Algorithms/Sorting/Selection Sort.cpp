#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void swap(ll &x, ll &y){
    ll temp = x;
    x = y;
    y = temp;
}

void selection_sort(ll x[], ll n){
    for(ll i=0; i<n-1; i++){
        ll min_idx = i;
        for(ll j=i+1; j<n; j++){
            if(x[j] < x[min_idx]){
                min_idx = j;
            }
        }
        swap(x[min_idx], x[i]);
    }
}

// Stable Selection Sort
void selection_sort_stable(ll x[], ll n){
    for(ll i=0; i<n-1; i++){
        ll min_idx = i;
        for(ll j=i+1; j<n; j++){
            if(x[j] < x[min_idx]){
                min_idx = j;
            }
        }
        
        ll temp = x[min_idx];
        for(ll j=min_idx; j>i; j--){
            x[j] = x[j-1];
        }
        x[i] = temp;
    }
}

// Recursive Selection Sort
ll min_index(ll x[], ll i, ll j){
    if(i == j){
        return i;
    }
    
    ll k = min_index(x, i+1, j);
    return (x[i] < x[k])? i : k;
}

void rec_selection_sort(ll x[], ll n, ll idx=0){
    if(idx == n){
        return;
    }
    
    ll k = min_index(x, idx, n-1);
    if (k != idx){
       swap(x[k], x[idx]);
    }
    
    rec_selection_sort(x, n, idx+1);
}

int main(){
    ll n;
    cin >> n;
    
    ll x[n];
    for(ll i=0; i<n; i++){
        cin >> x[i];
    }
    
    selection_sort(x, n);
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    
    selection_sort_stable(x, n);
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    
    ll idx;
    rec_selection_sort(x, n, idx = 0);
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}