"""
   SUBSTITUTION CIPHER
"""

import string
  
# A list containing all characters
all_letters= string.ascii_letters
   
      
dict1 = {}
key = 4
   
for i in range(len(all_letters)):
    dict1[all_letters[i]] = all_letters[(i+key)%len(all_letters)]
   
   
plain_txt= "Hello, How are you?"
cipher_txt=[]
   
# loop to generate ciphertext
   
for char in plain_txt:
    if char in all_letters:
        temp = dict1[char]
        cipher_txt.append(temp)
    else:
        temp =char
        cipher_txt.append(temp)
          
cipher_txt= "".join(cipher_txt)
print("Cipher Text is: ",cipher_txt)
   
      
""" 
create a dictionary to store the substitution
for the given alphabet in the cipher 
text based on the key
"""
   
      
dict2 = {}     
for i in range(len(all_letters)):
    dict2[all_letters[i]] = all_letters[(i-key)%(len(all_letters))]
       
# loop to recover plain text
decrypt_txt = []
  
for char in cipher_txt:
    if char in all_letters:
        temp = dict2[char]
        decrypt_txt.append(temp)
    else:
        temp = char
        decrypt_txt.append(temp)
          
decrypt_txt = "".join(decrypt_txt)
print("Recovered plain text :", decrypt_txt) 