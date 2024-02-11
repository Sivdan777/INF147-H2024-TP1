#include <stdio.h>
#include "utilitaire.h"
#include "icd.h"

#define POSITION_A 65

#define MASQUE_NUMERO_MOT       0x000000FF // 00000000000000000000000011111111
#define MASQUE_DONNEE_BNR       0x1FFFFF00 // 00011111111111111111111100000000
#define MASQUE_DONNEE_BCD_1     0x00001F00 // 00000000000000000001111100000000
#define MASQUE_DONNEE_BCD_2     0x0003E000 // 00000000000000111110000000000000
#define MASQUE_DONNEE_BCD_3     0x007C0000 // 00000000011111000000000000000000
#define MASQUE_DONNEE_BCD_4     0x1F800000 // 00011111100000000000000000000000
#define MASQUE_DONNEE_SS        0x60000000 // 01100000000000000000000000000000
#define MASQUE_DONNEE_P         0x1F800000 // 10000000000000000000000000000000

#define DECALAGE_NUMERO_MOT     0
#define DECALAGE_DONNEE_BNR     8
#define DECALAGE_DONNEE_BCD_1   8
#define DECALAGE_DONNEE_BCD_2   13
#define DECALAGE_DONNEE_BCD_3   18
#define DECALAGE_DONNEE_BCD_4   23
#define DECALAGE_DONNEE_SS      29
#define DECALAGE_DONNEE_P       31

int est_corrompu;
int numero_mot_octal;
double donnee_bnr;
int donnee_bcd1;
int donnee_bcd2;
int donnee_bcd3;
int donnee_bcd4;

void afficher_entete_decodeur (void) {
  printf("/**************************************************************\n");
  printf(" * DECODEUR ARINC-429\n");
  printf(" *\n");
  printf(" * Auteur:  Sivdan Sarkissian\n");
  printf(" * Session: Hiver 2024\n");
  printf(" *\n");
  printf("/**************************************************************\n\n");
  printf("Mot ARINC-429  |  Est Corrompu  |  Donnee\n");
  printf("---------------|----------------|------------------------------\n");
}

void afficher_entete_test (void) {
  printf("/**************************************************************\n");
  printf(" * DECODEUR ARINC-429 :: Mode Test\n");
  printf(" *\n");
  printf(" * Auteur:  Sivdan Sarkissian\n");
  printf(" * Session: Hiver 2024\n");
  printf(" *\n");
  printf("/**************************************************************\n\n");
}

void decoder_mot_a429 (unsigned int valeur, int* est_corrompu,
                       int* numero_mot_octal, double* donnee_bnr,
                       int* donnee_bcd1, int* donnee_bcd2,
                       int* donnee_bcd3, int* donnee_bcd4) {

  unsigned int numero_mot_decimal = ((unsigned int) valeur & MASQUE_NUMERO_MOT) >> DECALAGE_NUMERO_MOT;
  unsigned int p = ((unsigned int) valeur & MASQUE_DONNEE_P) >> DECALAGE_DONNEE_P;
  unsigned int nb_bits_allumes = calculer_nb_bits_actifs(valeur);
//  int ss = 3;

  *numero_mot_octal = (int)decimale_a_octale(numero_mot_decimal);

  if(*numero_mot_octal == NUMERO_MOT_DEPART || *numero_mot_octal == NUMERO_MOT_DESTINATION ||
    *numero_mot_octal == NUMERO_MOT_DATE) { // Decoder en BCD
    *donnee_bcd1 = ((int) valeur & MASQUE_DONNEE_BCD_1) >> DECALAGE_DONNEE_BCD_1;
    *donnee_bcd2 = ((int) valeur & MASQUE_DONNEE_BCD_2) >> DECALAGE_DONNEE_BCD_2;
    *donnee_bcd3 = ((int) valeur & MASQUE_DONNEE_BCD_3) >> DECALAGE_DONNEE_BCD_3;
    *donnee_bcd4 = ((int) valeur & MASQUE_DONNEE_BCD_4) >> DECALAGE_DONNEE_BCD_4;
    *donnee_bnr = 0xFFFFFFFF;
  } else if(*numero_mot_octal == NUMERO_MOT_UTC) { // Decoder en BNR
    *donnee_bnr = (((unsigned int) valeur & MASQUE_DONNEE_BNR) >> DECALAGE_DONNEE_BNR) * RESOLUTION_MOT_UTC;
    *donnee_bcd1 = *donnee_bcd2 = *donnee_bcd3 = *donnee_bcd4 = 0x0000FFFF;
  } else if (*numero_mot_octal == NUMERO_MOT_ALTITUDE) { // Decoder en BNR
    *donnee_bnr = (((unsigned int) valeur & MASQUE_DONNEE_BNR) >> DECALAGE_DONNEE_BNR) * RESOLUTION_MOT_ALTITUDE;
    *donnee_bcd1 = *donnee_bcd2 = *donnee_bcd3 = *donnee_bcd4 = 0x0000FFFF;
  } else if(*numero_mot_octal == NUMERO_MOT_LONGITUDE) { // Decoder en BNR
    *donnee_bnr = (((unsigned int) valeur & MASQUE_DONNEE_BNR) >> DECALAGE_DONNEE_BNR) * RESOLUTION_MOT_LONGITUDE;
    *donnee_bcd1 = *donnee_bcd2 = *donnee_bcd3 = *donnee_bcd4 = 0x0000FFFF;
  } else if(*numero_mot_octal == NUMERO_MOT_LATITUDE) { // Decoder en BNR
    *donnee_bnr = (((unsigned int) valeur & MASQUE_DONNEE_BNR) >> DECALAGE_DONNEE_BNR) * RESOLUTION_MOT_LATITUDE;
    *donnee_bcd1 = *donnee_bcd2 = *donnee_bcd3 = *donnee_bcd4 = 0x0000FFFF;
  }

  if(((valeur & MASQUE_DONNEE_SS) >> DECALAGE_DONNEE_SS) == 3) {
    *donnee_bnr *= -1;
  }


  if(nb_bits_allumes % 2) *est_corrompu = 0;
  else *est_corrompu = 1;

}

void afficher_mot_a429 (unsigned int valeur) {
  decoder_mot_a429(valeur, &est_corrompu, &numero_mot_octal, &donnee_bnr,
                   &donnee_bcd1, &donnee_bcd2, &donnee_bcd3, &donnee_bcd4);

  printf("0x%08x", valeur);
  if(!est_corrompu) printf("            NON");
  else printf("            OUI");

  if(numero_mot_octal == NUMERO_MOT_DEPART) {
    printf("          Depart de l'aeroport: ");
    printf("%c%c%c%c\n", donnee_bcd1 + POSITION_A, donnee_bcd2 + POSITION_A,
           donnee_bcd3 + POSITION_A, donnee_bcd4 + POSITION_A);
  }

  if(numero_mot_octal == NUMERO_MOT_DESTINATION) {
    printf("          Arrivee a l'aeroport: ");
    printf("%i%i%i%i\n", donnee_bcd1, donnee_bcd2, donnee_bcd3, donnee_bcd4);
  }

  if(numero_mot_octal == NUMERO_MOT_DATE) {
    printf("          Date du vol: ");
    printf("%i/%i/%i\n\n", donnee_bcd3, donnee_bcd2, donnee_bcd1);
  }

  if(numero_mot_octal == NUMERO_MOT_UTC) {
    printf("          Heure du vol: ");
    afficher_heure((unsigned int)donnee_bnr);
    printf("\n");
  }

  if(numero_mot_octal == NUMERO_MOT_LATITUDE) {
    printf("          Latitude: ");
    printf("%f\n", donnee_bnr);
  }

  if(numero_mot_octal == NUMERO_MOT_LONGITUDE) {
    printf("          Longitude: ");
    printf("%f\n", donnee_bnr);
  }

  if(numero_mot_octal == NUMERO_MOT_ALTITUDE) {
    printf("          Altitude: ");
    printf("%0.1f\n", donnee_bnr);
  }

}
