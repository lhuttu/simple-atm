#include <stdio.h>
#include <string.h>

//Funktioiden esittely
void lueMerkkijono(char merkkijono[], int pituus);
void lueRoskat(void);
int kirjautuminen(void);
double otto(int saldo);
void rahanjakoalgoritmi(int maara, int *viiskymppiset, int *kakskymppiset);
void saldokysely(int saldo);
void lopetus();

//Pääfunktio
int main(int argc, char const *argv[])
{
    int saldo;
    int valinta = 0;

    //Kirjautuminen ja saldon alustus
    saldo = kirjautuminen();

    //Päävalikko tulostuu aina uudelleen, kunnes käyttäjä syöttää numeron kolme.
    while (valinta != 3)
    {
        //Tulostetaan päävalikko
        printf("\n           PÄÄVALIKKO\n");
        printf("\nPaina numeroa valitaksesi toiminto: \n");
        printf("1. Otto \n");
        printf("2. Saldo \n");
        printf("3. Lopeta \n");

        //Luetaan käyttäjän valinta
        scanf("%d", &valinta);
        lueRoskat();


        //Käyttäjän valinta 1. valitsee otto funktion, valinta 2. saldokyselyn ja valinta 3. lopettaa ohjelman. 
        switch (valinta)
        {
        case 1:
            saldo = otto(saldo);
            break;
        case 2:
            saldokysely(saldo);
            break;
        case 3:
            lopetus();
        default:
            break;
        }
    }
    return 0;
}

//Funktio kirjautumistoiminnosta
int kirjautuminen(void){

    char tilinro[256];
    FILE *pFile;
    int saldo;
    int tulos;
    int lopetus=1;
    char pin[256];
    char oikeaPin[256];

    do {
        printf("\nAnna tilinumero > ");

        lueMerkkijono(tilinro, 256);

        strcat(tilinro, ".acc");

        if ((pFile = fopen(tilinro, "r")) != NULL){
            printf("Anna PIN-koodisi > ");

            lueMerkkijono(pin, 256);

            fgets(oikeaPin, 256, pFile);

         do {
            if (oikeaPin[strlen(oikeaPin) - 1] == '\n')
               oikeaPin[strlen(oikeaPin) - 1] = '\0';

            if (oikeaPin[strlen(oikeaPin) - 1] == '\r')
               oikeaPin[strlen(oikeaPin) - 1] = '\0';

            if ((tulos = strcmp(pin, oikeaPin)) == 0){
               fscanf(pFile, "%d", &saldo);
               printf("Saldosi on: %d\n", saldo);
               lopetus=0;
            } else{
               printf("Virheellinen PIN-koodi, koeta uudestaan!");
               lueMerkkijono(pin, 256);
            }

         } while (tulos);

         fclose(pFile);

      } else {
         printf("\nTilia ei loydy.\n");
         lopetus=1;
      }

   } while (lopetus);

   return saldo;
}

//Funktio otto-toiminnosta
double otto(int saldo) {
    int maara;
    int viiskymppiset = 0;
    int kakskymppiset = 0;

    printf("\nSyötä nostosumma: ");
    scanf("%d", &maara);
    lueRoskat();

    if (maara < 0 || maara == 10 || maara == 30 || maara > 1000 || maara % 10 != 0)
    {
        printf("Virhe\n");
    } else if (saldo >= maara)
    {
        rahanjakoalgoritmi(maara, &viiskymppiset, &kakskymppiset);
        saldo -= maara;
        printf("\nNostetaan %d kappaletta 50€ seteleitä ja %d kappaletta 20€ seteleitä. \nUusi saldosi on %d€.\n", viiskymppiset, kakskymppiset, saldo);
    } else
    {
        printf("\nTililläsi ei ole tarpeeksi katetta. \nSaldosi on %d€.\n", saldo); 
    }
    
    
    return saldo;
}

//Funktio rahanjakoalgoritmille
void rahanjakoalgoritmi(int maara, int *viiskymppiset, int *kakskymppiset){
    int setelisumma = 0;

    setelisumma = maara;

    *viiskymppiset = setelisumma / 50;
    setelisumma -= *viiskymppiset * 50;

    if (setelisumma != 0 && setelisumma % 20 != 0)
    {
        if (*viiskymppiset > 0)
        {
            *viiskymppiset -= 1;
            setelisumma += 50;
        }
        
    }
    *kakskymppiset = setelisumma / 20;

}

//Funktio saldon kysymiselle
void saldokysely(int saldo) {
    printf("\nTilin saldo: %d€\n", saldo);
}

//Funktio lopetusilmoitukselle
void lopetus(){

    printf("\nKirjaudutaan ulos... \n");
    printf("\nTervetuloa uudelleen! \n");

}

//Merkkijonon lukemisen funktio
void lueMerkkijono(char merkkijono[], int pituus){

   fgets( merkkijono, pituus, stdin );

   // Jos merkkijonon lopussa, ennen lopetusmerkki� on ylim��r�inen
   // rivinvaihto korvataan se lopetusmerkill�
   if( merkkijono[ strlen(merkkijono)-1 ] == '\n')
      merkkijono[ strlen(merkkijono)-1 ] = '\0';
   else
      lueRoskat();

}

//Roskien poisto funktio
void lueRoskat(void){

   // Tyhjennet��n puskuri
   while( fgetc(stdin) != '\n');
}