#include <stdio.h>
#include "utilitaire.h"

void afficher_entete_decodeur (void) {
  printf("/**************************************************************\n");
  printf(" * DECODEUR ARINC-429\n");
  printf(" *\n");
  printf(" * Auteur: Sivdan Sarkissian\n");
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
  printf(" * Auteur: Sivdan Sarkissian\n");
  printf(" * Session: Hiver 2024\n");
  printf(" *\n");
  printf("/**************************************************************\n\n");
}

void afficher_mot_a429 (unsigned int valeur) {

}

//void decoder_mot_a429 (unsigned int valeur, int* est_corrompu,
//                       double* numero_mot, double* donnee_bnr,
//                       int* donnee_bcd1, int* donnee_bcd2,
//                       int* donnee_bcd3, int* donnee_bcd4) {

    void decoder_mot_a429 (double valeur) {

    #define MASQUE_NUMERO_MOT       0x000000FF // 00000000000000000000000011111111 (255)
    #define MASQUE_DONNEE_BNR       0x1FFFFF00 // 00011111111111111111111100000000
    #define MASQUE_DONNEE_BCD_1     0x00001F00 // 00000000000000000001111100000000
    #define MASQUE_DONNEE_BCD_2     0x0003E000 // 00000000000000111110000000000000
    #define MASQUE_DONNEE_BCD_3     0x007C0000 // 00000000011111000000000000000000
    #define MASQUE_DONNEE_BCD_4     0x1F800000 // 00011111100000000000000000000000
    #define MASQUE_DONNEE_P         0x1F800000 // 10000000000000000000000000000000

    #define DECALAGE_NUMERO_MOT     0
    #define DECALAGE_DONNEE_BNR     8
    #define DECALAGE_DONNEE_BCD_1   8
    #define DECALAGE_DONNEE_BCD_2   13
    #define DECALAGE_DONNEE_BCD_3   18
    #define DECALAGE_DONNEE_BCD_4   23
    #define DECALAGE_DONNEE_P       31

//    printf("numero_mot: %u", ((unsigned int) valeur & MASQUE_NUMERO_MOT) >> DECALAGE_NUMERO_MOT);
//    printf("donnee_bnr: %u", ((unsigned int) valeur & MASQUE_DONNEE_BNR) >> DECALAGE_DONNEE_BNR);
//    printf("donnee_bcd_1: %u", ((unsigned int) valeur & MASQUE_DONNEE_BCD_1) >> DECALAGE_DONNEE_BCD_1);
//    printf("donnee_bcd_2: %u", ((unsigned int) valeur & MASQUE_DONNEE_BCD_2) >> DECALAGE_DONNEE_BCD_2);
//    printf("donnee_bcd_3: %u", ((unsigned int) valeur & MASQUE_DONNEE_BCD_3) >> DECALAGE_DONNEE_BCD_3);
//    printf("donnee_bcd_4: %u", ((unsigned int) valeur & MASQUE_DONNEE_BCD_4) >> DECALAGE_DONNEE_BCD_4);
    printf("p: %u", ((unsigned int) valeur & MASQUE_DONNEE_P) >> DECALAGE_DONNEE_P);

//
//    int no = 1;
//    int donnee = 2;
//    int ss = 3;
//    int p = 4 ;
//
//
//  *numero_mot = decimale_a_octale(*numero_mot);
//
//  if(*numero_mot == 232 || *numero_mot == 255 || *numero_mot == 260) {
//
//  } else if(*numero_mot == 150 || *numero_mot == 252 || *numero_mot == 310 || *numero_mot == 311) {
//
//  }
//
//  printf("%u", valeur);
}