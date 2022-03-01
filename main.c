#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define Dateiname_MAX 20



int main()
{
    FILE *fp;                                                           //erstellt Pointer (Name= fp) für Files
    char cdatei[Dateiname_MAX];                                         //Array für von User eingegebenen Dateinamen
    char crd[100];                                                      //"c read_data" Array für Speicherung von eingelesene Zeichen von Datei
    int n= 0;                                                           //für Index in "cd"
    int a= 0;                                                           //Benutzereingabe für Verschlüsseln/Entschlüsseln
    int va=0;                                                           //Bestimmt ob Verschlüsselt oder Entschlüsselt wird
    //###Benutzereingabe Datei###
    printf("                  $\n                  $$\n                  $$$\n                $$$$$\n              $$$$$\n           $$$$$$$\n          $$$$$$$$$\n         $$$$$$$$$$\n        $$$(O)$(O)$$\n        $$$$$$$$$$$$\n   $$$  $$$$$( )$$$$  $$$         $\n    $$$  $$$$$$$$$$  $$$         $$\n     $$$  $$$$$$$$  $$$        $$$\n       $$$$$$$$$$$$$$         $$$$\n       $$$$$$$$$$$$$$          $$$$\n        $$$$$$$$$$$$$$$     $$$$$$\n          $$$$$$$$$$$$$$$$$$$$$$$\n             $$$$$$$$$$$$$$$$$$$\n                $$$$$$$$$$$$$\n");
    printf("\n");
    printf("Welcome to Ghostcypher!\n");
    printf("\n");
    printf("!!!zu verschluesselnde/entschluesselnde Datei muss im selben Ordner wie Code sein!!! \n");
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
        printf("Verschluesseln[1], Entschluesseln[2]: ");
        scanf ("%3d", &a);


        //
    if(a==1) va=12;
    else if(a==2) va=40;
    else    {printf("Falsche Eingabe");
            return 0;}

        printf("Verschluesselter/Entschluesselter Text: ");
        while ((crd[n] = fgetc(fp))!= EOF)
        {

            if (!isspace(crd[n]) || !isblank(crd[n]))
            printf("%c", (((crd[n] - 97) + va) % 26) + 97);
        else
            printf("%c", crd[n]);
        crd[n]+= 1;

        }
}

    fclose(fp);

    return 0;
}
