// Sieve of Sundaram used to print primes smaller than n 
#include <bits/stdc++.h> 
using namespace std; 

//function
// In general Sieve of Sundaram, produces primes smaller than (2*x + 2) for a number given number x.
int SieveOfSundaram(int n) 
{  
    // Since we want primes smaller than n, we reduce n to half 
    int New = (n-1)/2; 
  
    // This array is used to separate numbers of the form i+j+2ij from others where  1 <= i <= j
    bool marked[New + 1]; 
    // Initialize all elements as not marked 
    memset(marked, false, sizeof(marked)); 
  
    // Main logic of Sundaram.  Mark all numbers of the form i + j + 2ij as true where 1 <= i <= j 
    for (int i=1; i<=New; i++) 
        for (int j=i; (i + j + 2*i*j) <= New; j++) 
            marked[i + j + 2*i*j] = true; 
  
    // Since 2 is a prime number 
    if (n > 2) 
        cout << 2 << " "; 
  
    // Print other primes. Remaining primes are of the form 2*i + 1 such that marked[i] is false. 
    for (int i=1; i<=New; i++) 
        if (marked[i] == false) 
            cout << 2*i + 1 << " "; 
} 
  
// Driver function 
int main() 
{ 
    int n = 56; 
    SieveOfSundaram(n); 
    return 0; 
} 
