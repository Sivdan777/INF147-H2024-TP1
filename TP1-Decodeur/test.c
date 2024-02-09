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
  afficher_entete_test();
  test_afficher_heure();
  test_decimale_a_octale();
  test_calculer_nb_bits_actifs();
    test_afficher_bits();


  return EXIT_SUCCESS;
}
#endif

void test_afficher_heure (void) {
  printf("|****************************************|\n");
  printf("|          TEST AFFICHER_HEURE           |\n");
  printf("|****************************************|\n\n");

  printf("Valeur testee: 0 s\n");
  printf("Resultat attendu: 00h00m00s\n");
  printf("Resultat  obtenu: ");
  afficher_heure(0);
  printf("\n\n");
}

void test_decimale_a_octale (void) {
  printf("|****************************************|\n");
  printf("|         TEST DECIMALE_A_OCTALE         |\n");
  printf("|****************************************|\n\n");

  printf("Valeur testee: 209\n");
  printf("Resultat attendu: 321\n");
  printf("Resultat  obtenu: %u", decimale_a_octale(209));
  printf("\n\n");
}

void test_calculer_nb_bits_actifs (void) {
  printf("|****************************************|\n");
  printf("|      TEST CALCULER_NB_BITS_ACTIFS      |\n");
  printf("|****************************************|\n\n");

  printf("Valeur testee: 0x12345678\n");
  printf("Resultat attendu: 13\n");
  printf("Resultat  obtenu: %u", calculer_nb_bits_actifs(0x12345678));
  printf("\n\n");
}

void test_afficher_bits (void) {
  printf("|****************************************|\n");
  printf("|           TEST AFFICHER_BITS           |\n");
  printf("|****************************************|\n\n");

  printf("Valeur testee: 0xA3CF8643\n");
  printf("Resultat attendu:       1000 0110 0100\n");
  afficher_bits(0xA3CF8643, 4, 15);
  printf("\n\n");
}