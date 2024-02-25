### Overview of PRF and PRG:

PRF (Pseudorandom Function) and PRG (Pseudorandom Generator) are two concepts in cryptography that are used to create functions or algorithms that produce outputs that are indistinguishable from true randomness by any efficient adversary. PRF and PRG are useful for various applications, such as encryption, authentication, key generation, and more.

### How PRF and PRG Work:

- **PRF**: A PRF is a family of functions that map an input to an output, using a secret key. The key determines which function from the family is used. A PRF is secure if, given a random function from the family and its outputs on some inputs, no efficient adversary can distinguish it from a truly random function. A PRF can be used to generate pseudorandom outputs from a fixed key and variable inputs.

- **PRG**: A PRG is a function that takes a short random input (called a seed) and produces a long pseudorandom output. A PRG is secure if, given the output of the PRG on a random seed, no efficient adversary can distinguish it from a truly random string of the same length. A PRG can be used to expand a small amount of randomness into a large amount of pseudorandomness.

### How the Code Works:

- **PRF**: The code implements a PRF that takes a 16-bit input and produces a 48-bit output, using a 48-bit key. The key is divided into four 12-bit parts, corresponding to four different values of k (0, 1, 2, 3). The code uses a helper function to convert hexadecimal to binary, and another function to check if the key is already used for a particular k. The code reads the input and the key from two files, and creates a table to store the mapping between the input and the output for each k. The code prints the table and the length of the input.

- **PRG**: The code implements a PRG that takes a 16-bit input and produces a 48-bit output, using a 48-bit key. The key is the same for all values of k (0, 1, 2, 3). The code uses the same helper functions as the PRF code, and also checks if the key is duplicate. The code reads the input and the key from two files, and creates a table to store the mapping between the input and the output for each k. The code prints the table and the length of the input.