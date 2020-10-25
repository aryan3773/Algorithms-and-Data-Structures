#include<bits/stdc++.h>
#define ll long long int
#define vll vector<vll>
using namespace std;

void subsets(string x, string y){
    if(x.size() == 0){
        cout << y << endl;
        return ;
    }
    
    subsets(x.substr(1), y);
    subsets(x.substr(1), y+x[0]);
}


int main(){
    string x, y="";
    cin >> x;
    
    subsets(x, y); // or directly pass empty string
    
    return 0;
}

/* Python Program

l = []

def subset(x, y):
    if(len(x) == 0):
        l.append(y)
        return ;
        
    subset(x[1:], y)
    subset(x[1:], y+x[0])
    
x = input()
subset(x, "")

// For all subsets
print(l)

// For unique subsets
print(list(set(l)))

*/