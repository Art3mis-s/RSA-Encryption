//
//  RSA.cpp
//
#include"RSA.h"
#include<cmath>
#include<string>
#include <random>

bool isPrime(unsigned long long n)
{
    if (n <= 1)
    {
        return false;
    }
    
    for (unsigned long long i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
unsigned long long getPrime(unsigned long long min, unsigned long long max)
{
    // rand return an integer in the range [0, RAND_MAX]
    unsigned long long randomNumber;
    do
    {
        randomNumber = min + (rand() % (max - min + 1));
    }
    while (!isPrime(randomNumber));
    return randomNumber;
}



unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long r;
    while (y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
unsigned long long lcm(unsigned long long x, unsigned long long y)
{
    return (x * y) / gcd(x, y);
}

unsigned long long modInverse(unsigned long long e, unsigned long long lam)
{
    for (unsigned long long d = 1; d <= lam; d++)
    {
        if ((d * e) % lam == 1)
        {
            return d;
        }
    }
    return 0;
}

unsigned long long modExp(unsigned long long base, unsigned long long exp, unsigned long long n)
{
    unsigned long long ans = 1;
    for(unsigned long long i = 0; i < exp; i++)
    {
        ans = (ans * base) % n;
    }
    return ans;
}
// EC
unsigned long long bruteFactor(unsigned long long n)
{
    for (unsigned long long i = 2ULL; i <= n / i; ++i) {
        if (n % i == 0ULL) return i;
    }
    return 0ULL;
}

bool crackRSA(unsigned long long n, unsigned long long e,
              unsigned long long& p, unsigned long long& q,
              unsigned long long& lambda, unsigned long long& d)
{
    p = bruteFactor(n);
    if (p == 0ULL) return false;

    q = n / p;
    lambda = lcm(p - 1ULL, q - 1ULL);
    d = modInverse(e, lambda);

    return (d != 0ULL);
}
