// TC=O(n*(sqrt(n)))
// Sc=O(1)
class Solution {
public:
  
    void SieveOfEratosthenes(int n, vector<bool>&prime)
    {
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.

 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    }
 
    int countPrimes(int n) {
        vector<bool>prime(n+1,true);
        SieveOfEratosthenes( n , prime);
        int cnt=0;
        
        for(int i=2;i<n;i++)
        {
            if(prime[i]==true) cnt++;
        }
        
        return cnt;
    }
};