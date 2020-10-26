#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BLOCK 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verify that only one file is passed as a command-line argument by the user
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL)
    {
        printf("File not found\n");
        return 2;
    }

    fseek(fptr, 0, SEEK_END);
    int fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    int blocks = fileSize / BLOCK;
    BYTE buffer[BLOCK];

    int inJPEG = 0;
    int blockCount = 0;

    char filenames[50][13];

    FILE *jpegptr;

    for (int i = 0; i < blocks; i++)
    {
        fread(buffer, BLOCK, 1, fptr);

        if (((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) &&
            ((int) buffer[3] <= 239 && (int) buffer[3] >= 224) && (inJPEG == 0)))
        {
            sprintf(filenames[blockCount], "%03d.jpg", blockCount);

            jpegptr = fopen(filenames[blockCount], "w");
            fwrite(buffer, BLOCK, 1, jpegptr);

            blockCount++;
            inJPEG = 1;

            continue;
        }
        else if (inJPEG == 0)
        {
            continue;
        }
        else if ((((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff) &&
                  ((int) buffer[3] <= 239 && (int) buffer[3] >= 224)) && (inJPEG == 1)))
        {
            inJPEG = 0;
            fseek (fptr, -BLOCK, SEEK_CUR);
            i--;
            fclose(jpegptr);
            continue;
        }
        else
        {
            fwrite(buffer, BLOCK, 1, jpegptr);
        }
    }
    fclose(jpegptr);
    fclose(fptr);
    exit(0);
}
