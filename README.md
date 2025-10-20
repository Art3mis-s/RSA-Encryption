

# 🔐 RSA Encryption Algorithm – C++ Implementation

### Overview

This project is an educational implementation of the **RSA cryptosystem**, one of the most widely used public-key encryption algorithms in modern cryptography.
It demonstrates the **mathematical foundations** of RSA — including prime number generation, modular arithmetic, key generation, encryption, and decryption — all implemented in **pure C++** for clarity and learning purposes.

---

### 📘 About RSA

Developed in 1977 by **Ron Rivest**, **Adi Shamir**, and **Leonard Adleman**, RSA relies on the computational difficulty of **factoring large prime numbers**.
The algorithm works by generating two keys:

* A **public key** used for encryption.
* A **private key** used for decryption.

---

### 🧮 Core Mathematical Concepts

1. **Prime Number Generation:** Used to find large primes `p` and `q`.
2. **Modulus Calculation:** `n = p * q` forms the modulus for both keys.
3. **Totient (λ(n)):** `λ(n) = lcm(p-1, q-1)` ensures proper modular arithmetic.
4. **Public Key (e):** Chosen such that `1 < e < λ(n)` and `gcd(e, λ(n)) = 1`.
5. **Private Key (d):** Computed as the modular inverse of `e` modulo `λ(n)`.
6. **Encryption:** `cipher = (message^e) mod n`
7. **Decryption:** `message = (cipher^d) mod n`


