#include <stdlib.h>
#include <stdio.h>
#include "decodeur/utilitaire.h"
#include "decodeur/a429.h"
#include "configuration.h"
#include "udp/port_udp.h"

#if MODE_APPLICATION
int main(void) {
//  unsigned int valeur_recue;
unsigned int valeur_recue[] = {0x85D3029A, 0x003c90b0, 0x811C6268, 0x840834C8,
                               0xE68B4BC9, 0x8001ABAA};
//  int est_corrompu;
//  double numero_mot_octal;
//  double donnee_bnr;
//  int donnee_bcd1;
//  int donnee_bcd2;
//  int donnee_bcd3;
//  int donnee_bcd4;

  afficher_entete_decodeur();
//  int id_port_udp = initialiser_port_udp(PORT_UDP);
//
//  do {
//    recevoir_port_udp(id_port_udp, &valeur_recue, sizeof(unsigned int));
//    afficher_mot_a429(valeur_recue);
//  }
//  while (recevoir_port_udp(id_port_udp, &valeur_recue, sizeof(unsigned int)));
//
//  detruire_port_udp(id_port_udp);

  for(int i = 0; i <= 5; i++) {
    afficher_mot_a429(valeur_recue[i]);
  }

  return EXIT_SUCCESS;
}

#endif