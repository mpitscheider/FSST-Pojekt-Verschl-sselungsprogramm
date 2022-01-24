#include <stdio.h>
#include <stdlib.h>

#define Dateiname_MAX 20

/*
int main()
{
   FILE *fp;
    int i;
    int gel;

    // oeffnen im Lesemodus
    fp = fopen("zahlen.txt", "r");

    if(fp == NULL)
    {
	printf("Datei konnte nicht geoeffnet werden.\n");
    }
    else
    {
        for(i=0; i<11; i++)
        {

            fscanf(fp, "%d\n", &gel);
            printf("gelesen: %d\n", gel);
        }
	fclose(fp);
    }

    return 0;
}
*/

int main()
{
    FILE *fp;                                                           //erstellt Pointer (Name= fp) für Files
    char cdatei[Dateiname_MAX];                                         //Array für von User eingegebenen Dateinamen
    char crd[100];                                                      //"c read_data" Array für Speicherung von eingelesene Zeichen von Datei
    int n= 0;                                                           //für Index in "cd"

    //###Benutzereingabe Datei###

    printf("!!!zu verschluesselnde Datei muss im selben Ordner wie Code sein!!! \n");
    printf("Dateiname: ");
    //Benutzereingabe
    fgets(cdatei, Dateiname_MAX, stdin);                                //In welches Array speichern, max. Anzahl an Zeichen, Eingabetyp: Standardeingabe
    cdatei[strlen(cdatei) -1] = '\0';                                   //automatisches Leerzeichen (am Ende von get-Eingabe) durch 0 ersetzen
    printf("Datei: %s \n", cdatei);
    //Zeiger auf zu öffnende Datei
    fp= fopen(cdatei, "r");

    if (fp== NULL)
    {
        printf("Datei konnte nicht geoeffnet werden!");
    }
    else
    {
        //Zeichen einlesen und in char speichern
        //###Leerzeichen und Zeilenumbrüche -> nichts (Leerzeichen) wird ausgegeben###
        //"(rd[0] = fgetc(fp))!= EOF" =eingelesenes Zeichen in Array "crd"() speichern und abfragen ob EOF (=End Of File) erreicht ist
        while ((crd[n] = fgetc(fp))!= EOF)
        {
            printf("gelesen: %c \n", crd[n]);
            n++;
        }

        //gibt komplett eingelesene Datei aus
        printf("\n%s \n", crd);

    }

    fclose(fp);

    return 0;
}




