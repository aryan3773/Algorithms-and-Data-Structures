#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Method - 1 -> Using index based calculation (linear time and linear space)

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        ll a[n], b[n];
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        for(ll i=0; i<n; i++){
            b[i] = a[(i+d)%n];
        }
        for(ll i=0; i<n; i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
	return 0;
}


// Method - 2 -> Using temporary array of size to store first d integers (linear time and space = O(d))

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        ll a[n], b[d];
        for(ll i=0; i<d; i++){
                cin >> b[i];
        }
        for(ll i=0; i<n-d; i++){
                cin >> a[i];
        }
        for(ll i=n-d; i<n; i++){
            a[i] = b[i-(n-d)];
        }
        for(ll i=0; i<n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Method - 3 -> Rotating array left by one and calling thsi function d times (Time - O(n*d) and constant space)


void print(ll x[], ll n){
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void left_rotate_by_one(ll x[], ll n){
    ll temp = x[0], i;
    for(i=0; i<n-1; i++){
        x[i] = x[i+1];
    }
    x[i] = temp; // x[n-1] = temp;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        ll a[n];
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        for(ll i=0; i<d; i++){
            left_rotate_by_one(a, n);
        }
        print(a, n);
    }
    return 0;
}

// Method - 4 -> Extension of previous method, instead of moving one by one divide the array in different sets
// where number of sets is equal to GCD of n and d and move the elements within sets. If gcd=1, then it is equivalent to above method
// Time Complexity - O(n) because loop runs gcd times for every array size, n/gcd and in linear space


ll gcd(ll x, ll y){
    if(y==0){
        return x;
    }
    else{
    return gcd(y, x%y);
    }
}

void print(ll x[], ll n){
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void left_rotate(ll x[], ll n, ll d){
    d %= n;
    ll k=gcd(n, d);
    for(ll i=0; i<k; i++){
        ll j = i;
        ll temp = x[i];
        while(1){
            ll t = j+d;
            if (t >= n){
                t -= n;
            }
            if (t == i){
                break;
            }
            x[j] = x[t];
            j = t;
        }
        x[j] = temp;
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n >> d;
        ll a[n];
        for(ll i=0; i<n; i++){
            cin >> a[i];
        }
        left_rotate(a, n, d);
        print(a, n);
    }
    return 0;
}


// Method - 5 -> Reversal Algorithm: Divide the array into 2 parts, x[:d] and x[d+1:] then reverse both segments separately and then reverse whole array


void reverseArray(int arr[], int start, int end) 
{ 
    while (start < end) { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
}

void reverse(ll x[], ll n, ll d){
    // Use library or above defined function
    reverse(x, x+d);
    reverse(x+d, x+n);
    reverse(x, x+n);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n;
        ll x[n];
        for(ll i=0; i<n; i++){
            cin >> x[i];
        }
        cin >> d;
        reverse(x, n, d);
        for(ll i=0; i<n; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Method - 6 -> Block Swap Algorithm: Divide array into A=x[:d] and B=x[d:].
// Case - 1 : If length of A is greater than B. Divide B into size d(Br), len(B) - d (Bl). Swap A with Br. Then recur on the array leaving last d elements.
// Case - 2 : If length of B is greater than A. Divide A into size d(Al), len(B) - d (Ar). Swap B with Al. Then recur on the array leaving last d elements
// Case - 3 : If length of A and B are equal, then block swap them.

// Swapping d elements starting from fi with d elements starting from si.

void swap(ll x[], ll fi, ll si, ll d){
    ll temp;
    for(ll i=0; i<d; i++){
        temp = x[fi+i];
        x[fi+i] = x[si+i];
        x[si+i] = temp;
    }
}

void left_rotate(ll x[], ll d, ll n){
    if( d==0 or d==n){
        return;
    }
    if(n-d == d){
        swap(x, 0, n-d, d);
        return ;
    }
    if(d < n-d){
        swap(x, 0, n-d, d);
        left_rotate(x, d, n-d);
    }
    else{
        swap(x, 0, d, n-d);
        left_rotate(x+n-d, 2*d-n, d);
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n;
        ll x[n];
        for(ll i=0; i<n; i++){
            cin >> x[i];
        }
        cin >> d;
        d = d%n;
        left_rotate(x, d, n);
        for(ll i=0; i<n; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// Iterative approach of same method

void swap(ll x[], ll fi, ll si, ll d){
    ll temp;
    for(ll i=0; i<d; i++){
        temp = x[fi+i];
        x[fi+i] = x[si+i];
        x[si+i] = temp;
    }
}

void left_rotate(ll x[], ll d, ll n){
    if(d == 0 or d == n){
        return;
    }
    ll i=d, j=n-d;
    while(i != j){
        if(i < j){
            swap(x, d-i, d+j-i, i);
            j -= i;
        }
        else{
            swap(x, d-i, d, j);
            i -= j;
        }
    }
    swap(x, d-i, d, i);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d;
        cin >> n;
        ll x[n];
        for(ll i=0; i<n; i++){
            cin >> x[i];
        }
        cin >> d;
        d = d%n;
        left_rotate(x, d, n);
        for(ll i=0; i<n; i++){
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}