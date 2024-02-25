### Overview of the AES Algorithm (Advanced Encryption Standard):

AES (Advanced Encryption Standard) is a symmetric key encryption algorithm widely used for securing electronic data. It operates on blocks of data, with AES-128 using a block size of 128 bits. AES supports key sizes of 128, 192, or 256 bits. The algorithm consists of multiple rounds of substitution, permutation, and mixing operations.

### How the AES Algorithm Works:

1. **Key Expansion**: The AES algorithm starts with a key expansion routine that derives a series of round keys from the original key. These round keys are used in each round of encryption and decryption.

2. **SubBytes**: In this step, each byte of the input block undergoes a nonlinear substitution using a fixed S-box table.

3. **ShiftRows**: The rows of the 4x4 input block are shifted cyclically to the left. The first row is not shifted, the second row is shifted by one byte to the left, the third row by two bytes, and the fourth row by three bytes.

4. **MixColumns**: Each column of the 4x4 input block is treated as a polynomial over GF(2^8), and multiplied by a fixed polynomial modulo an irreducible polynomial. This step provides diffusion in the cipher.

5. **AddRoundKey**: Each byte of the transformed input block is XORed with the corresponding byte of the round key.

6. **Final Round**: The final round does not include the MixColumns operation.

### How the Code Works:

1. **Initialization**: The code initializes the Rijndael S-box and its reverse, necessary for the substitution steps in AES.

2. **Key Expansion**: The `expand_key` function expands the provided key into round keys for each round of encryption and decryption.

3. **Encryption Function**: The `enc` function takes a plaintext block and a key as input and performs AES encryption. It iterates through multiple rounds of substitution, shifting, mixing, and adding round keys.

4. **Decryption Function**: The `dec` function takes a ciphertext block and a key as input and performs AES decryption. It reverses the encryption steps by applying the inverse operations in the reverse order.

5. **File Handling**: The code reads the ciphertext from a file, decrypts it using the provided key, and prints the decrypted text. Then, it encrypts the decrypted text again and prints the ciphertext.

6. **Main Execution**: The main block of the code reads the ciphertext from a file, decrypts it, prints the decrypted text, encrypts it again, and prints the ciphertext.