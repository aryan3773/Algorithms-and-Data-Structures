#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
void swap(ll &x, ll &y){
	ll temp = x;
	x = y;
	y = temp;
}
 
void insertion_sort(ll x[], ll n){
	for(ll i=1; i<n; i++){
		ll temp = x[i];
		ll j = i-1;
		while(j >=0 and x[j] > temp){
			x[j+1] = x[j];
			j -= 1;
		}
 
		x[j+1] = temp;
	}
}
 
void rec_insertion_sort(ll x[], ll n){
	if(n <= 1){
		return ;
	}
 
	rec_insertion_sort(x, n-1);
 
	ll temp = x[n-1];
	ll j = n-2;
	while(j >= 0 and x[j] > temp){
		x[j+1] = x[j];
		j -= 1;
	}
	x[j+1] = temp;
}
 
ll binary_search(ll x[], ll e, ll start, ll end){
	if(end <= start){
		if(x[start] < e){
			return start+1;
		}
		else{
			return start;
		}
	}
	
	ll mid = (start + end)/2;
	if(x[mid] == e){
		return mid + 1;
	}
	
	if(x[mid] < e){
		return binary_search(x, e, mid+1, end);
	}
	else{
		return binary_search(x, e, start, end-1);
	}
}
 
void binary_insertion_sort(ll x[], ll n){
	for(ll i=1; i<n; i++){
		ll temp = x[i];
		ll j = i-1;
		ll pos = binary_search(x, temp, 0, j);
 
		while(j >= pos){
			x[j+1] = x[j];
			j -= 1;
		}
		x[j+1] = temp;
	}
}
 
int main(){
	ll n;
	cin >> n;
 
	ll x[n];
	for(ll i=0; i<n; i++){
		cin >> x[i];
	}
 
	binary_insertion_sort(x, n);
	for(ll i=0; i<n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}