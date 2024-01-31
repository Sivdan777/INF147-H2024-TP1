#include <stdlib.h>
#include <stdio.h>
#include "decodeur/utilitaire.h"
#include "decodeur/a429.h"
#include "configuration.h"

#if MODE_APPLICATION
int main(void) {
//  afficher_heure(86399);
  decimale_a_octale(209);
  // afficher_bits(0x12345678, 0, 31);
//  afficher_entete_decodeur();


  return EXIT_SUCCESS;
}
#endif