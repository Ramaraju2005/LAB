
#include <stdio.h>

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

long long power(long long a, long long b, long long n) {
    long long r=1;
    while(b) {
        if(b%2) r=(r*a)%n;
        a=(a*a)%n;
        b/=2;
    }
    return r;
}

int main() {
    long long p,q,n,phi,e,d=0,m,c;

    printf("Enter p and q: ");
    scanf("%lld%lld",&p,&q);

    n=p*q;
    phi=(p-1)*(q-1);

    for(e=2;e<phi;e++)
        if(gcd(e,phi)==1) break;

    for(d=1;(d*e)%phi!=1;d++);

    printf("Public key: %lld %lld\n",e,n);
    printf("Private key: %lld %lld\n",d,n);

    printf("Enter message number: ");
    scanf("%lld",&m);

    c=power(m,e,n);
    printf("Encrypted: %lld\n",c);

    printf("Decrypted: %lld\n",power(c,d,n));

    return 0;
}

// sample output:
// Enter two prime numbers: 3 11

// Public Key: (3, 33)
// Private Key: (7, 33)

// Enter message (number less than n): 4

// Encrypted Message: 31
// Decrypted Message: 4