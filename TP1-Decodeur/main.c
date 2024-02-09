#include <stdlib.h>
#include <stdio.h>
#include "decodeur/utilitaire.h"
#include "decodeur/a429.h"
#include "configuration.h"
#include "udp/port_udp.h"

#if MODE_APPLICATION
int main(void) {
  int id_port_udp;
  unsigned int valeur_recue;

  int est_corrompu;
  double numero_mot = 125;
  double donnee_bnr;
  int donnee_bcd1;
  int donnee_bcd2;
  int donnee_bcd3;
  int donnee_bcd4;

//  afficher_heure(86399);
  // decimale_a_octale(209);
  // afficher_bits(0x12345678, 0, 31);
  afficher_entete_decodeur();
  id_port_udp = initialiser_port_udp(55001);

  //Boucle
        recevoir_port_udp(id_port_udp, &valeur_recue, sizeof(unsigned int));

        //afficher_mot_a429

    decoder_mot_a429(0x85D3029A);

  return EXIT_SUCCESS;
}
#endif