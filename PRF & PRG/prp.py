# This is the implementation of Pseudo random permutation
# Submitted by - CSB20047

# Function to convert Hexadecimal to binary
def hex2bin(s):
    mp = {'0': "0000",
          '1': "0001",
          '2': "0010",
          '3': "0011",
          '4': "0100",
          '5': "0101",
          '6': "0110",
          '7': "0111",
          '8': "1000",
          '9': "1001",
          'A': "1010",
          'B': "1011",
          'C': "1100",
          'D': "1101",
          'E': "1110",
          'F': "1111"}
    bin = ""
    for i in range(len(s)):
        bin = bin + mp[s[i]]
    return bin

# function to check if the key is duplicate
def check_duplicate(key, table):
    status = False
    for i in table:
        used_key = i[1]
        used_key += str(i[2])
        used_key += str(i[3])
        used_key += str(i[4])
        
        if(key == used_key):
            status = True
            break
    return status

# function to implement prp
def prp(length):

    # table to store mapping
    table = []
    table.append(["x", "k = 0", "k = 1", "k = 2", "k = 3"])
    print(table)

    counter = 0
    #open key and message file
    with open("message.txt") as m, open("key.txt") as k:
        while counter < length:
            # temperory table
            temp_table = []

            # read 16bits of message
            c = m.read(4)
            if not c:
                print("End of file")
                break
            temp_table.append(c)
        
            # read 48 bits of key for k=0, k=1, k=2 and k=3
            key = k.read(16)
            key = hex2bin(str(key))

            #check if the key is duplicate
            # True if key is duplicate else false
            status = check_duplicate(key, table)

            # if key is unique
            if(status == False):
                # append key for all k in a row
                temp_table.append(key[0:16])
                temp_table.append(key[16:32])
                temp_table.append(key[32:48])
                temp_table.append(key[48:64])

                counter += 1
                # print row
                print(temp_table)
                table.insert(0,temp_table)

            # key is duplicate
            else:
                continue

# main function
if __name__ == "__main__":
    print("********* PSEUDO RANDOM PERMUTATION  *********")
    print()
    length = int(input("What should be the length of x\n"))
    prp(length)
