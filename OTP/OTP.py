import base64 # for converting into byte

# function for file handling
def FileHandling(filename, operation, message="read operaation"):
    with open(filename, operation) as f:
        # if operation is "write"
        if operation == "w":
            f.write(message)
            f.close()
            return

    # if operation is "read"
        elif operation == "r":
            text = f.read()
            f.close()
            return text

# function for encryption
def Enc(plaintext, key):
    r = '' # encrypted text

    # xor byte by byte
    for i in range(len(plaintext)):
        c = ord(plaintext[i]) ^ key[i]
        r += chr(c)

    # convert string to bytes
    retval = base64.b64encode(r.encode())
    return retval

# function for decryption
def Dec(ciphertext, key):
    r = ''  # decrypted string

    # convert bytes to string
    med1 = base64.b64decode(ciphertext)
    med2 = med1.decode()

    # xor byte by byte
    for i in range(len(ciphertext)):
        c = ord(med2[i]) ^ key[i]  # ascii value e.g 108
        r += chr(c)
    return r

if __name__ == "__main__":
    # plaintext
    plaintext = FileHandling("plaintext.txt", "r")
    length = len(plaintext)

    # key generation
    key = FileHandling("key.txt", "r")
    # key conversion in byte format
    key = base64.b64encode(key.encode())

    # cipher text generation
    cipher_text = Enc(plaintext, key)
    print("\nMessage Decrypted and stored in file\n")
    FileHandling("encrypt.txt", "w", str(cipher_text))

    # decrypt text generation
    decrypted_text = Dec(cipher_text, key)
    print("\nMessage Encrypted and stored in file")
    FileHandling("decrypt.txt", "w", str(decrypted_text))
