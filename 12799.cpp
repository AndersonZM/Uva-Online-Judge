//AC 29/09/2018
//Anderson Zudio
#include <iostream>
#include <cmath>

using namespace std;

long long int PotMod(long long int a, int b, int n){
    long long int m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++){
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
    }
    return (long long int) d;
}

long long modInverse(long long n, long long m) {
    long long la = 1, lb = 0, ra = 0, rb = 1;
    long long i = 0, t, mod = m;
    while(n%m) {
        if(!i) {
            la -= n/m*ra;
            lb -= n/m*rb;
        } else {
            ra -= n/m*la;
            rb -= n/m*lb;
        }
        i = !i;
        t = n, n = m, m = t%m;
    }
    if(i)
        return (la%mod+mod)%mod;
    return (ra%mod+mod)%mod;
}


int main(){
	long long int n, e, c; //pair n and e is the public key, c is the message
	ios_base::sync_with_stdio(false);

	
	while(cin >> n >> e >> c){
		long long int tot, d; //n = (p - 1)(q - 1); tot is the totient function; d is the inverse multiplicative of e in module tot
		long long int m = 0; //the decrypted message
		int sqr = (int) sqrt(n);
		for(int i = 3; i < sqr; ++i){
			if(n % i == 0){
				tot = (i - 1) * (n/i - 1);
				break;
			} 
		}
		
		//decode
		d = modInverse(e, tot);
		m = PotMod(c, d, n);
		cout << m << endl;
	}
	
	return 0;
}