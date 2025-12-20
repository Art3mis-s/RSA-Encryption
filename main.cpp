//
//  main.cpp
//

#include <iostream>
#include <string>
#include <iomanip>
#include "RSA.h"
#include <random>
#include <climits>


using namespace std;

int main()
{
    unsigned long long p, q, n, lambda, d, e, m, c;
    unsigned int seed;
    
    cout << "Enter a seed: ";
    cin >> seed;
    
    srand(seed);
    
    p = getPrime(UCHAR_MAX, USHRT_MAX);
    q = getPrime(UCHAR_MAX, USHRT_MAX);
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    
    n = p * q;
    cout << "n: " << n << endl;
    
    lambda = lcm(p - 1, q - 1);
    cout << "Lambda: " << lambda << endl;
    
    e = getPrime(2, lambda - 1);
    while (lambda % e  == 0)
    {
        e = getPrime(2, lambda - 1);
    }
    cout << "e: " << e << endl;
    
    d = modInverse(e, lambda);
    cout << "\nd: " << d << endl;
    
    cout << "Public key: n = " << n << " e = " << e << endl;
    cout << "Private key: n = " << n << " d = " << d << endl;
    
    cout << "Enter a positive number less than " << n << ": ";
    cin >> m;
    
    c = modExp(m, e, n);
    cout << "Cipher: " << c << endl;
    
    m = modExp(c, d, n);
    cout << "Decrypted cipher: " << m << endl;


    cout << "\n--- Brute-force crack---\n";

        unsigned long long p2, q2, lambda2, d2;

        if (crackRSA(n, e, p2, q2, lambda2, d2)) {
            cout << "Factor p found: " << p2 << "\n";
            cout << "Factor q found: " << q2 << "\n";
            cout << "computed lambda(n): " << lambda2 << "\n";
            cout << "Derived private key d: " << d2 << "\n";

            unsigned long long cracked = modExp(c, d2, n);
            cout << "Decrypted message using derived private key: " << cracked << "\n";
        } else {
            cout << "RSA key recovery unsuccessful.\n";
        }
}
