#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

void minimum(vll x, ll n){
	ll m1 = INT_MAX;
	ll m2 = INT_MAX;
	
	for(ll i=0; i<n; i++){
		if(x[i] < m1){
			m2 = m1;
			m1 = x[i];
		}
		
		else if(x[i] < m2){
			m2 = x[i];
		}
	}
	
	if(m2 == INT_MAX){
		cout << "Minimum is " << m1 << endl;
		cout << "No second Minimum " << endl;
	}
	else{
		cout << "Minimum is " << m1 << endl;
		cout << "Second Minimum " << m2 << endl;
	}
}

void maximum(vll x, ll n){
	ll m1 = INT_MIN;
	ll m2 = INT_MIN;
	
	for(ll i=0; i<n; i++){
		if(x[i] > m1){
			m2 = m1;
			m1 = x[i];
		}
		
		else if(x[i] > m2){
			m2 = x[i];
		}
	}
	
	if(m2 == INT_MIN){
		cout << "Maximum is " << m1 << endl;
		cout << "No second Maximum " << endl;
	}
	else{
		cout << "Maximum is " << m1 << endl;
		cout << "Second Maximum " << m2 << endl;
	}
}

int main(){
	ll n, a;
	cin >> n;
	
	vll x;
	for(ll i=0; i<n; i++){
		cin >> a;
		x.push_back(a);
	}
	
	minimum(x, n);
	maximum(x, n);
	
	return 0;
}