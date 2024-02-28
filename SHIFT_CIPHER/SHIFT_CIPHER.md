### Overview of the Shift Cipher:

The Shift Cipher, also known as the Caesar Cipher, is one of the simplest and oldest encryption techniques. It is a type of substitution cipher, where each letter in the plaintext is replaced by another letter that is a fixed number of positions away in the alphabet. The number of positions is the key of the cipher.

### How the Shift Cipher Works:

- **Encryption**: To encrypt a message, the sender chooses a key, which is a number between 0 and 25. Then, for each letter in the message, the sender shifts it by the key value in the alphabet, wrapping around from Z to A if necessary. For example, if the key is 3, then A becomes D, B becomes E, and so on. The encrypted message is the ciphertext.

- **Decryption**: To decrypt a message, the receiver uses the same key as the sender, but shifts the letters in the opposite direction. For example, if the key is 3, then D becomes A, E becomes B, and so on. The decrypted message is the plaintext.

### How the Code Works:

- **Helper Function**: The code defines a helper function called `encrypt` that takes two parameters: `text` and `s`. `text` is the plaintext to be encrypted, and `s` is the key of the cipher.

- **Encryption Function**: The `encrypt` function creates an empty string called `result`, and then loops through each character in `text`. If the character is an uppercase letter, it adds the ASCII value of the character and the key, subtracts 65, and takes the modulo 26. This ensures that the result is between 0 and 25, corresponding to the letters A to Z. Then, it adds 65 to the result and converts it back to a character, and appends it to `result`. If the character is a lowercase letter, it does the same thing, but subtracts and adds 97 instead of 65. If the character is not a letter, it simply appends it to `result` without any change. The function returns `result` as the ciphertext.

- **Encryption Process**: The code assigns the plaintext to a variable called `text`, and the key to a variable called `s`. It then calls the `encrypt` function with these parameters, and prints the plaintext, the key, and the ciphertext.
