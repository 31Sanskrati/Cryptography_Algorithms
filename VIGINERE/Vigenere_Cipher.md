### Overview of the Vigenère Cipher:

The Vigenère Cipher, also known as the Polyalphabetic Cipher, is a type of encryption where each letter of the plaintext is replaced by another letter from the same alphabet, depending on a key. The key is a word or phrase that determines how the letters are shifted in the alphabet. The Vigenère Cipher is a generalization of the Caesar Cipher, which uses a single letter as the key. The Vigenère Cipher is more secure than the Caesar Cipher because it uses multiple keys and avoids frequency analysis.

### How the Vigenère Cipher Works:

- **Encryption**: To encrypt a message, the sender chooses a key, which is a word or a phrase. Then, for each letter in the message, the sender finds the corresponding letter in the ciphertext alphabet, which is the plaintext alphabet shifted by the key letter's position. For example, if the key is LEMON, then the first letter A of the message is shifted by 11 positions in the alphabet (because the first letter L of the key is the 11th letter of the alphabet, counting from 0), yielding L; the second letter T is shifted by 4 (because the second letter E of the key means 4) yielding X; the third letter T is shifted by 12 ( M) yielding F, with wrap-around; and so on; yielding the message LXFOPVEFRNHR.

- **Decryption**: To decrypt a message, the receiver uses the same key as the sender, but finds the corresponding letter in the plaintext alphabet, which is the ciphertext alphabet shifted by the negative key letter's position. For example, if the key is LEMON, then the first letter L of the message is shifted by -11 positions in the alphabet, yielding A; the second letter X is shifted by -4, yielding T; the third letter F is shifted by -12, yielding T, with wrap-around; and so on; yielding the message ATTACKATDAWN.

### How the Code Works:

- **Helper Function**: The code defines a helper function called `generateKey` that takes the message and the key as input and returns a key of the same length as the message. It does this by repeating the key letters until they match the message length. For example, if the message is ATTACKATDAWN and the key is LEMON, the function returns LEMONLEMONLE.

- **Encryption Function**: The code defines an encryption function that takes the message and the key as input and returns the ciphertext. It does this by looping through each letter in the message and the key, converting them to ASCII values, adding them modulo 26, and converting them back to letters. For example, if the message letter is A and the key letter is L, the function adds 65 (the ASCII value of A) and 76 (the ASCII value of L) modulo 26, which is 11, and converts it to the letter L (the 11th letter of the alphabet).

- **Decryption Function**: The code defines a decryption function that takes the ciphertext and the key as input and returns the plaintext. It does this by looping through each letter in the ciphertext and the key, converting them to ASCII values, subtracting them modulo 26, and converting them back to letters. For example, if the ciphertext letter is L and the key letter is L, the function subtracts 76 (the ASCII value of L) and 76 (the ASCII value of L) modulo 26, which is 0, and converts it to the letter A (the 0th letter of the alphabet).

- **Main Program**: The code asks the user to enter the message and the key, and then calls the `generateKey` function to get the key of the same length as the message. It then calls the `encryption` function to get the ciphertext and prints it. It then calls the `decryption` function to get the plaintext and prints it.
