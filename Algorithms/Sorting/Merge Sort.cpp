#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
void merge(ll x[], ll low, ll mid, ll high){
    ll i=0, j=0, k=0;
    
    // finding the size of 2 divided arrays using the indices
    ll size1 = mid-low+1, size2 = high-mid;
    
    // Creating 2 temporary arrays for accessing the elements from actual array and
    // later modify the array
    ll temp1[size1], temp2[size2];
    
    for(ll i=0; i<size1; i++){
        temp1[i] = x[low + i];
    }
    
    for(ll j=0; j<size2; j++){
        temp2[j] = x[mid + 1 + j];
    }
    
    // Reinitializing i, j and k
    i = 0; j = 0; k = low;
    
    while(i < size1 and j < size2){
        if(temp1[i] <= temp2[j]){
            x[k] = temp1[i];
            i += 1;
            k += 1;
        }
        
        if(temp1[i] > temp2[j]){
            x[k] = temp2[j];
            j += 1;
            k += 1;
        }
    }
    
    // One of the array will be completly accessed before another
    // Checking temp1 is remaining to be accessed
    while(i < size1){
        x[k] = temp1[i];
        i += 1;
        k += 1;
    }
    
    // Checking temp1 is remaining to be accessed
    while(j < size2){
        x[k] = temp2[j];
        j += 1;
        k += 1;
    }
}

// Merge Sort using divide and conquer
// Approach - 1
void merge_sort(ll x[], ll low, ll high){
    if(low < high){
        // ll mid = (low + high)/2;
        // To avoid integer overflow for large values of low and high
        
        ll mid = low + (high - low)/2; 
        merge_sort(x, low, mid);
        merge_sort(x, mid+1, high);
        
        merge(x, low, mid, high);
    }
}

void inplace_merge(ll x[], ll low, ll mid, ll high){
    ll i = mid + 1;
    
    // If the last element of first array is less than or equal to the first element of the second array
    // then we will simply merge the arrays as the resultant array will also be sorted.
    // eg - [1, 3, 6] and [7, 8, 9]. Here, we can directly merge the 2 arrays
    if(x[mid] <= x[i]){
        return ;
    }
    
    while(low <= mid and i <= high){
        if(x[low] <= x[i]){
            low += 1;
        }
        
        else{
            ll temp = x[i], j = i;
            
            // We will shift the elements between low and index j
            while(j != low){
                x[j] = x[j-1];
                j -= 1;
            }
            // Put the value of temp at low
            x[low] = temp;
            i += 1;
            low += 1;
            mid += 1;
        }
    }
}

// Function for inplace Merge Sort
// Approach - 2
void inplace_merge_sort(ll x[], ll low, ll high){
    if(low < high){
        // ll mid = (low + high)/2;
        // To avoid integer overflow for large values of low and high
        
        ll mid = low + (high - low)/2; 
        merge_sort(x, low, mid);
        merge_sort(x, mid+1, high);
        
        inplace_merge(x, low, mid, high);
    }
}

// Approach - 3
void inplace_merge1(ll x[], ll start, ll mid, ll end, ll e){
	ll i = start;
    ll j = mid + 1;
    ll k = start;
    
    while (i <= mid && j <= end){
        if (x[i] % e <= x[j] % e){
            x[k] = x[k] + (x[i] % e) * e;
            k++;
            i++;
        }
        else{
        	x[k] = x[k] + (x[j] % e) * e;
            k++;
            j++;
        }
    }
    
    while (i <= mid){
        x[k] = x[k] + (x[i] % e) * e;
        k++;
        i++;
    }
    
    while (j <= end){
        x[k] = x[k] + (x[j] % e) * e;
        k++;
        j++;
    }
  
    // Obtaining actual values 
    for (ll i = start; i <= end; i++){
        x[i] = x[i] / e;
    }
}

void inplace_merge_sort1(ll x[], ll start, ll end, ll e){
	if(start < end){
		ll mid = start + (end - start)/2;
		inplace_merge_sort1(x, start, mid, e);
		inplace_merge_sort1(x, mid+1, end, e);
		inplace_merge1(x, start, mid, end, e);
	}
}

void mergeSort(ll x[], ll n) 
{ 
   ll e = *max_element(x, x+n) + 1; 
   inplace_merge_sort1(x, 0, n-1, e); 
}

void iterative_merge_sort(ll x[], ll n){
	ll c_size, left;
	for(c_size = 1; c_size <= n-1; c_size = 2*c_size){
		for(left = 0; left < n-1; left += 2*c_size){
			ll mid = min(left + c_size - 1, n-1);
			ll right = min(left + 2*c_size - 1, n-1);
			merge(x, left, mid, right);
		}
	}
}

int main(){
	ll n;
	cin >> n;
 
	ll x[n];
	for(ll i=0; i<n; i++){
		cin >> x[i];
	}
 
	iterative_merge_sort(x, n);
	for(ll i=0; i<n; i++){
		cout << x[i] << " ";
	}
	cout << endl;
}