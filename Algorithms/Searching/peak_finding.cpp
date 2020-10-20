#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

ll linear_peak_element(vll x, ll n){
	if(n == 1){
		return 0;
	}
	
	if(x[0] >= x[1]){
		return 0;
	}
		
	if(x[n-1] >= x[n-2]){
		return n-1;
	}
	
	for(ll i=1; i<n-1; i++){
		if(x[i-1] <= x[i] and x[i] >= x[i+1]){
			return i;
		}
	}
}

ll binary_peak_element(vll x, ll start, ll end, ll n){
	while(start <= end){
		ll mid = (start + end)/2;
		if((mid == 0 or x[mid] >= x[mid-1]) and (mid == n-1 or x[mid] >= x[mid+1])){
			return mid;
		}
		
		else if(x[mid] <= x[mid-1] and mid > 0){
			end = mid-1;
		}
		
		else if(x[mid] <= x[mid+1] and mid < n-1){
			start = mid+1;
		}
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
	
	cout << linear_peak_element(x, n) << endl;
	cout << binary_peak_element(x, 0, n-1, n) << endl;
	
	return 0;
}