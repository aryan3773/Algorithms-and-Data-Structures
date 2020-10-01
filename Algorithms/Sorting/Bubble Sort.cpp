#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void swap(ll &x, ll &y){
	ll temp = x;
	x = y;
	y = temp;
}

void bubble_sort(ll x[], ll n){
	for(ll i=0; i<n-1; i++){
		for(ll j=0; j<n-i-1; j++){
			if(x[j] > x[j+1]){
				swap(x[j], x[j+1]);
			}
		}
	}
}

// Optimized bubble sort - Stops when the remainging array is already sorted
void opt_bubble_sort(ll x[], ll n){
	for(ll i=0; i<n-1; i++){
		bool flag = true;
		for(ll j=0; j<n-1-i; j++){
			if(x[j] > x[j+1]){
				flag = false;
				swap(x[j], x[j+1]);
			}
		}
		
		if(flag){
			break;
		}
	}
}

// Recursive Version
void rec_bubble_sort(ll x[], ll n){
	if(n == 1){
		return ;
	}
	
	for(ll i=0; i<n-1; i++){
		if(x[i] > x[i+1]){
			swap(x[i], x[i+1]);
		}
	}
	
	return rec_bubble_sort(x, n-1);
}

int main(){
	ll n;
	cin >> n;
	
	ll x[n];
	for(ll i=0; i<n; i++){
		cin >> x[i];
	}
	
	rec_bubble_sort(x, n);
	for(ll i=0; i<n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}