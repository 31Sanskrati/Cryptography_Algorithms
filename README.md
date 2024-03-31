# Cryptography_Algorithms

Welcome to the Cryptography Algorithms repository! This repository contains implementations of various cryptography algorithms written primarily in Python, with key generation code written in C. The algorithms included in this repository are DES (Data Encryption Standard), AES (Advanced Encryption Standard), HMAC (Hash-based Message Authentication Code), OTP (One-Time Pad), PRF (Pseudorandom Function) & PRG (Pseudorandom Generator), Shift Cipher, Substitution Cipher, and Vigenère Cipher.

## Overview
Cryptography plays a crucial role in securing sensitive information in today's digital world. This repository aims to provide implementations of fundamental cryptography algorithms along with explanations and examples to help users understand their functionality and usage.

## Algorithm Introduction
1. [DES (Data Encryption Standard)](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/DES%20%26%20AES)
DES is a symmetric key block cipher that operates on 64-bit blocks of plaintext and uses a 56-bit key. It performs multiple rounds of encryption and decryption to securely scramble data.

2. [AES (Advanced Encryption Standard)](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/DES%20%26%20AES)
AES is a symmetric key block cipher that supports key lengths of 128, 192, or 256 bits. It operates on 128-bit blocks of plaintext and uses a substitution-permutation network to encrypt and decrypt data.

3. [HMAC (Hash-based Message Authentication Code)](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/HMAC)
HMAC is a mechanism for calculating a message authentication code involving a cryptographic hash function in combination with a secret key. It provides a way to verify both the integrity and authenticity of a message.

4. [OTP (One-Time Pad)](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/OTP)
OTP is an encryption technique where a unique random key is used only once to encrypt a single plaintext message. It provides perfect secrecy when used correctly.

5. [PRF & PRG (Pseudorandom Function & Pseudorandom Generator)](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/PRF%20%26%20PRG)
A PRF is a function that generates seemingly random values from an input, while a PRG is an algorithm for generating a sequence of numbers that approximates the properties of random numbers.

6. [Shift Cipher](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/SHIFT_CIPHER)
Shift Cipher, also known as Caesar Cipher, is a substitution cipher where each letter in the plaintext is shifted a certain number of places down or up the alphabet.

7. [Substitution Cipher](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/SUBSTITUTION_CIPHER)
Substitution Cipher is a method of encryption where each letter in the plaintext is replaced with another letter according to a fixed system.

8. [Vigenère Cipher](https://github.com/31Sanskrati/Cryptography_Algorithms/tree/main/VIGINERE_CIPHER)
Vigenère Cipher is a method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.

## Implementation
The implementations of these algorithms are written primarily in Python. However, the key generation code is written in C for efficiency. Each algorithm has its own directory containing the implementation code.

## Contribution Guide
Contributions to this repository are welcome! If you'd like to contribute, please follow these guidelines:

- Fork the repository to your GitHub account.
- Create a new branch for your feature or bug fix.
- Make your changes and ensure that the code passes all existing tests.
- Write new tests for any new functionality you add.
- Commit your changes and push them to your fork.
- Submit a pull request to the main repository.

## Resources
Here are some additional resources for learning more about cryptography:

- [Cyber Chef](https://gchq.github.io/CyberChef/) is a good cryptography tool.

## Tech Stack
- Python
- C

## License
This repository is licensed under the MIT License. See the [LICENSE file](https://github.com/31Sanskrati/Cryptography_Algorithms/blob/main/LICENSE) for details.
