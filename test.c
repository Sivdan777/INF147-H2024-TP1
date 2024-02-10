#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "decodeur/utilitaire.h"
#include "decodeur/a429.h"
#include "configuration.h"

void test_afficher_heure (void);
void test_decimale_a_octale (void);
void test_calculer_nb_bits_actifs (void);
void test_afficher_bits (void);

#if MODE_TEST
int main(void) {
  afficher_entete_test(); // OK
  test_afficher_heure(); // OK
  test_decimale_a_octale(); // OK
  test_calculer_nb_bits_actifs(); // OK
  test_afficher_bits(); //


  return EXIT_SUCCESS;
}
#endif

void test_afficher_heure (void) {

  unsigned int val_testees[] = {0, 59, 61, 3661, 32949, 86399};
  char* val_attendues[] = {"00h00m00s", "00h00m59s", "00h01m01s", "01h01m01s",
                           "09h09m09s", "23h59m59s"};

  printf("|****************************************|\n");
  printf("|          TEST AFFICHER_HEURE           |\n");
  printf("|****************************************|\n\n");

  for(int i = 0; i <= 4; i++) {
    printf("Valeur testee   : %us\n", val_testees[i]);
    printf("Resultat attendu: %s \n", val_attendues[i]);
    printf("Resultat  obtenu: ");
    afficher_heure(val_testees[i]);
    printf("\n\n");
  }

}

void test_decimale_a_octale (void) {

  unsigned int val_testees[] = {1, 8, 15, 64, 104, 209};
  unsigned int val_attendues[] = {1, 10, 17, 100, 150, 321};

  printf("|****************************************|\n");
  printf("|         TEST DECIMALE_A_OCTALE         |\n");
  printf("|****************************************|\n\n");

  for(int i = 0; i <= 5; i++) {
    printf("Valeur testee   : %u\n", val_testees[i]);
    printf("Resultat attendu: %u \n", val_attendues[i]);
    printf("Resultat  obtenu: %u", decimale_a_octale(val_testees[i]));
    printf("\n\n");
  }

}

void test_calculer_nb_bits_actifs (void) {

  unsigned int val_testees[] = {0x00000000, 0x00000001, 0x80000000, 0x12345678, 0xFFFFFFFF};
  unsigned int val_attendues[] = {0, 1, 1, 13, 32,};

  printf("|****************************************|\n");
  printf("|      TEST CALCULER_NB_BITS_ACTIFS      |\n");
  printf("|****************************************|\n\n");

  for(int i = 0; i <= 4; i++) {
    printf("Valeur testee   : 0x%08x\n", val_testees[i]);
    printf("Resultat attendu: %u \n", val_attendues[i]);
    printf("Resultat  obtenu: %u",calculer_nb_bits_actifs(val_testees[i]));
    printf("\n\n");
  }

}

void test_afficher_bits (void) {

  unsigned int val_testees[] = {0x12345678, 0x9ABCDEF0, 0xA3CF8643, 0xA3CF8643, 0xA3CF8643};
  int bits_depart[] = {0, 0, 4, 31, 0};
  int bits_fin[] = {31, 31, 15, 31, 0};
  char* val_attendues[] = {"0001 0010 0011 0100 0101 0110 0111 1000",
                           "1001 1010 1011 1100 1101 1110 1111 0000",
                           "1000 0110 0100", "1", "1"};

  printf("|****************************************|\n");
  printf("|           TEST AFFICHER_BITS           |\n");
  printf("|****************************************|\n\n");

  for(int i = 0; i <= 4; i++) {
    printf("Valeur testee   : 0x%0x\n", val_testees[i]);
    printf("Resultat attendu: %s \n", val_attendues[i]);
    printf("Resultat  obtenu: ");
    afficher_bits(val_testees[i], bits_depart[i], bits_fin[i]);
    printf("\n\n");
  }

}