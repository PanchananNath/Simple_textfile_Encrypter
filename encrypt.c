/* C Program to Encrypt a text File*/

#include<stdio.h>
int main()
{
    char fname[100], ch;
    FILE *fps, *fpt;                // *fps and *fpt are two file pointer.
    printf("Enter Filename: ");
    gets(fname);                    // gets(); function helps to get the filename entered by the user.
    fps = fopen(fname, "r");        // open the file provided by the use in read mode.
    if(fps == NULL)                 // if file name is missing then the program will be terminated.
        return 0;
    fpt = fopen("cipher.txt", "w");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fps);
    while(ch != EOF)
    {
        ch = ch+8;
        fputc(ch, fpt);
        ch = fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(fname, "w");
    if(fps == NULL)
        return 0;
    fpt = fopen("cipher.txt", "r");
    if(fpt == NULL)
        return 0;
    ch = fgetc(fpt);
    while(ch != EOF)
    {
        ch = fputc(ch, fps);
        ch = fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
    printf("Encryption process on File %s is Successfully!", fname);
        return 0;
}
