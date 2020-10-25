#include<bits/stdc++.h>
#define ll long long int
#define vll vector<vll>
using namespace std;

// Without recursion
void all_permutations_with_spaces(string x){
    ll n = pow(2, x.size()-1);
    for(ll i=1; i<=n; i++){
        for(ll j=0; j<x.size(); j++){
            cout << x[j];
            if((i>>j)&1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Using recursion
void all_permutations_with_spaces_rec(string x, string y){
    if(x.size() == 0){
        cout << y << endl;
        return ;
    }
    
    all_permutations_with_spaces_rec(x.substr(1), y+x[0]);
    all_permutations_with_spaces_rec(x.substr(1), y+"_"+x[0]);
}

int main(){
    string x;
    cin >> x;
    
    //all_permutations_with_spaces(x);
    
    string y = "";
    all_permutations_with_spaces_rec(x.substr(1), y+x[0]);
    return 0;
}

/* Python Program
l = []

def subset(x, y):
    if(len(x) == 0):
        l.append(y)
        return ;
        
    subset(x[1:], y+"_"+x[0])
    subset(x[1:], y+x[0])
    
x = input()
subset(x[1:], x[0])

print(l)
*/