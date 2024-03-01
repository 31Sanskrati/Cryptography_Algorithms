### Overview of the Substitution Cipher:

The Substitution Cipher, also known as the Monoalphabetic Cipher, is a type of encryption where each letter of the plaintext is replaced by another letter from the same alphabet, depending on a key. The key is a number that determines how the letters are shifted in the alphabet. The Substitution Cipher is one of the simplest and oldest encryption techniques.

### How the Substitution Cipher Works:

- **Encryption**: To encrypt a message, the sender chooses a key, which is a number between 0 and 25. Then, for each letter in the message, the sender finds the corresponding letter in the ciphertext alphabet, which is the plaintext alphabet shifted by the key value. For example, if the key is 4, then A becomes E, B becomes F, and so on. The encrypted message is the ciphertext.

- **Decryption**: To decrypt a message, the receiver uses the same key as the sender, but finds the corresponding letter in the plaintext alphabet, which is the ciphertext alphabet shifted by the negative key value. For example, if the key is 4, then E becomes A, F becomes B, and so on. The decrypted message is the plaintext.

### How the Code Works:

- **Helper Variables**: The code imports the `string` module and creates a variable called `all_letters` that contains all the uppercase and lowercase letters of the English alphabet. It also creates two empty dictionaries called `dict1` and `dict2` that will store the substitution mappings for encryption and decryption, respectively.

- **Key Generation**: The code assigns the key to a variable called `s`, which is 4 in this example. It then loops through each letter in `all_letters` and assigns the value of the letter shifted by the key to the key of the letter in `dict1`. For example, `dict1['A'] = 'E'`, `dict1['B'] = 'F'`, and so on. It also does the opposite for `dict2`, which is used for decryption. For example, `dict2['E'] = 'A'`, `dict2['F'] = 'B'`, and so on.

- **Encryption Function**: The code assigns the plaintext to a variable called `plain_txt`, which is "Hello, How are you?" in this example. It then creates an empty list called `cipher_txt` that will store the ciphertext. It then loops through each character in `plain_txt` and checks if it is a letter. If it is, it appends the value of the character in `dict1` to `cipher_txt`. If it is not, it appends the character itself to `cipher_txt`. For example, `cipher_txt` will contain ['L', 'i', 'p', 'p', 's', ',', 'L', 's', 'c', 'e', 'C', 'm', 'r', 'k', '?']. It then joins the list into a string and prints the ciphertext, which is "Lipps, LsceCmrk?".

- **Decryption Function**: The code creates an empty list called `decrypt_txt` that will store the plaintext. It then loops through each character in `cipher_txt` and checks if it is a letter. If it is, it appends the value of the character in `dict2` to `decrypt_txt`. If it is not, it appends the character itself to `decrypt_txt`. For example, `decrypt_txt` will contain ['H', 'e', 'l', 'l', 'o', ',', 'H', 'o', 'w', 'a', 'r', 'e', 'y', 'o', 'u', '?']. It then joins the list into a string and prints the plaintext, which is "Hello, How are you?".
