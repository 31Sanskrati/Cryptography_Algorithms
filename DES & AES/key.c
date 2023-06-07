#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main()
{
    int i;
    long long int key_size = 16; //key size
    unsigned char buffer[8];
    int fd = open("/dev/urandom", O_RDONLY);
    read(fd, buffer, key_size);
    // buffer now contains the random data
    close(fd);

    //write file
    FILE *fptr;
    fptr = fopen("key.txt", "w");
    for (i = 0; i < key_size; ++i)
    {
        printf("%02X", buffer[i]);
        fprintf(fptr, "%02X", buffer[i]);
    }
    printf("\n");
    fclose(fptr);
    return 0;
}