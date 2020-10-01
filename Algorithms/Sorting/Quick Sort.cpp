#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Function for printing array
void print_array(ll x[], ll n){
    for(ll i=0; i<n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

// Function for swapping 2 integers
void swap(ll &x, ll &y){
    ll temp = x;
    x = y;
    y = temp;
}

// Function for partitioning array using first element as a pivot
ll init_partition(ll x[], ll start, ll end){
    ll pivot = x[start];
    ll i = start + 1;
    for(ll j=start+1; j<=end; j++){
        if(x[j] < pivot){
            swap(x[i], x[j]);
            i += 1;
        }
    }
    i -= 1;
    swap(x[i], x[start]);
    return i;
}

// Function for partitioning array using middle element as pivot
ll middle_partition(ll x[], ll start, ll end){
    // Find the middle element of the array
    ll middle = start + (end - start)/2;
    
    // swapping middle element with the last element so now middle element will be pivot
    swap(x[middle], x[end]);
    
    ll pivot = x[end];
    ll i = start - 1;
    
    for(ll j=start; j<end; j++){
        if(x[j] < pivot){
            i += 1;
            swap(x[i], x[j]);
        }
    }
    i += 1;
    swap(x[i], x[end]);
    return i;
}

// Function for partitioning array using last element as pivot (Lomuto Scheme)
ll partition(ll x[], ll start, ll end){
    ll pivot = x[end];
    ll i = start - 1;
    
    for(ll j=start; j<end; j++){
        if(x[j] < pivot){
            i += 1;
            swap(x[i], x[j]);
        }
    }
    i += 1;
    swap(x[i], x[end]);
    return i;
}

// Function for partitioning array using Hoare's Scheme
ll partition_h(ll x[], ll start, ll end){
	ll pivot = x[start];
	ll i = start-1;
	ll j = end+1;
	
	while(true){
		do{
			i++;
		} while(x[i] < pivot);
		
		do{
			j--;
		} while(x[j] > pivot);
		
		if(i >= j)
			return j;
		swap(x[i], x[j]);
	}
}

// Function for Randomized partition
ll randomized_partition(ll x[], ll low, ll high) 
{ 
	srand(time(NULL)); 
    ll random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(x[random], x[high]); 
  
    return partition(x, low, high); 
} 

// Function for Quick sort
void quick_sort(ll x[], ll start, ll end){
    if(start < end){
        ll i = partition_h(x, start, end);
        //cout << i << endl; -> To get which index were chosen
        
        /* For Lomuto scheme,
        quick_sort(x, start, i-1);
        quick_sort(x, i+1, end); */

        // For Hoare's Scheme
        quick_sort(x, start, i);
        quick_sort(x, i+1, end);
    }
}

void iterative_quick_sort(ll x[], ll low, ll high){
	ll temp[high-low+1];
	ll top = -1;
	temp[++top] = low;
	temp[++top] = high;
	
	while(top >= 0){
		high = temp[top--];
		low = temp[top--];
		
		ll p = randomized_partition(x, low, high);
		
		// If there are elements on left side of pivot, then push left side to stack
		if(p-1 > low){
			temp[++top] = low;
			temp[++top] = p-1;
		}
		
		// If there are elements on right side of pivot, then push right side to stack
		if(p+1 < high){
			temp[++top] = p+1;
			temp[++top] = high;
		}
	}
}

int main(){
    // n is the size of array
    ll n;
    cin >> n;
    
    // Taking array as input
    ll x[n];
    for(ll i=0; i<n; i++){
        cin >> x[i];
    }
    
    // Applying quicksort to the array
    quick_sort(x, 0, n-1);
    
    // Printing the array
    print_array(x, n);
    return 0;
}