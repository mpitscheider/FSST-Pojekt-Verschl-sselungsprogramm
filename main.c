#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "ghost.h"

int b;
int a;
int go;
int h=1;
int vcode;
int cont=0;
char in[260];
char name[256];
char name1[256];


void infos()
{
        printf("\n");
        printf("Information:\n");
        printf("With Ghostcypher you can decrypt/encrypt any type of files!\n");
        printf("To decrypt the files, the encryption code is required which was previously entered during \n");
        printf("the encryption process. If these codes are not the same, the file remains encrypted.\n");
        printf("The files encrypted/decrypted with Ghostcypher are saved under a name of your choice, \n");
        printf("in the same folder as the program.\n");
        printf("-> It's important that you save the decrypted File with the same Ending as the encrypted one!!");
        printf("\n");
        printf("\n");
        printf("To start type [1]");
        scanf("%d", &go);

        if(go==1)
        {
            start();
        }
        else
        {
            return 0;
        }

}

void start()
{
    system("COLOR E");
    printf("Which action should be carried out?\n");
    printf("Encrypt [1], Decrypt [2]: ");
    scanf("%d", &a);
    if (a!=2 && a!=1 )
    {
        printf("ERROR: wrong Input!");
        return 0;
    }

    else
    {
        printf("\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("  IMPORTANT: \n");
        printf("   -The file to be encrypted/decrypted must be in the same folder as the code\n");
        printf("   -Full file name must be entered\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf("\n");
        printf("Filename: ");
        scanf("%s", &in);
        printf("IMPORTANT: The encryption-code must be the same for both encryption and decryption!\n");
        printf("Encryption-Code: ");
        scanf("%d", &vcode);
        if (a == 1)
        {
            char c;
            FILE *fin;
            FILE *fout;
            fin = fopen(in, "rb");
            printf("Filename of the encrypted file: ");
            scanf("%s", &name);
            strcpy(in, name);
            printf("\n");
            printf("Successfully encrypted!");
            fout = fopen(in, "wb");
            while (!feof(fin))
            {
                c = fgetc(fin);
                int temp = (c + vcode);
                fputc((char)temp, fout);
            }
            fclose(fin);
            fclose(fout);
        }
        else if (a == 2)
        {
            char c;
            FILE *fin;
            FILE *fout;
            fin = fopen(in, "rb");
            printf("Filename of the decrypted file: ");
            scanf("%s", &name1);
            strcpy(in, name1);
            printf("\n");
            printf("Successfully decrypted!");
            fout = fopen(in, "wb");
            while (!feof(fin))
            {
                c = fgetc(fin);
                int temp = (c - vcode);
                fputc((char)temp, fout);
            }

        fclose(fin);
        fclose(fout);
    }
    }
    getch();
}
void con()
{
        printf("\n\nClose Ghostcypher[1]\n");
        printf("Run again?[2]\n");
        scanf("%d", &cont);
        if (cont==2)
        {
            start();
        }
        else if (cont!=2)
        {
            h=0;
            return 0;
        }
}


int main ()
{
    system("COLOR E");
    ghost();
    printf("\n");
    printf("          Welcome to Ghostcypher!\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("To start type [1]\n");
    printf("For information type [2]\n");
    scanf("%d", &b);
    if(b==2)
    {
        infos();
    }
    if(b==1)
    {
        start();
        con();
        while (h==1)
        {
        con();
        }
    }
    else
    {
        printf("ERROR: wrong Input!");
        return 0;
    }

}
