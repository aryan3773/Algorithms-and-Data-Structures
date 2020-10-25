#include<bits/stdc++.h>
#define ll long long int
#define vll vector<vll>
using namespace std;

// Without recursion
void permutations_with_case_change(string x){
    ll n = pow(2, x.size());
    for(ll i=1; i<=n; i++){
        string temp = x;
        for(ll j=0; j<x.size(); j++){
            if((i>>j)&1){
                temp[j] = toupper(temp.at(j));
            }
        }
        cout << temp << endl;
    }
}

// Using recursion
void permutations_with_case_change_rec(string x, string y){
    if(x.size() == 0){
        cout << y << endl;
        return ;
    }
    
    permutations_with_case_change_rec(x.substr(1), y+x[0]);
    //permutations_with_case_change_rec(x.substr(1), y.push_back(toupper(x.at(0))));
}

int main(){
    string x="abc";
    // Convert every letter to lower case
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    
    permutations_with_case_change(x);
    
    
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