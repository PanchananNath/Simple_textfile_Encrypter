/* C Program to Decrypt the encrypted / cipher  File*/


#include<stdio.h>
int main()
{
    char fname[100], ch;
    FILE *fps, *fpt;                // *fps and *fpt are two file pointer.
    printf("Enter Filename: ");
    gets(fname);                    // gets(); function helps to get the filename entered by the user.
    fps = fopen(fname, "w");        // open the file provided by the use in write mode.
    if(fps == NULL)                 // if file name is missing then the program will be terminated.
        return 0;
    fpt = fopen("cipher.txt", "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt);                // fgetc(); helps to read each character present in the given file.
    while(ch != EOF)                // loop will continue till the End of File (EOF).
    {
        ch = ch-8;                  // change the ASCCI value of each character by subtracting 8 from it.
        fputc(ch, fps);             //update the charter value in the *fps file pointer with the help of swapping.
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("\nFile %s Decrypted Successfully!", fname);
    return 0;
}
