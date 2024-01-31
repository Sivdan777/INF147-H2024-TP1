#include <stdio.h>
#include <math.h>

unsigned int uint_pow(unsigned int base, unsigned int exp) {
  unsigned int result = 1;
  while (exp) {
    if (exp % 2)
    result *= base;
    exp /= 2;
    base *= base;
    }
  return result;
}

void afficher_heure(unsigned int secondes) { // 5678 s
  unsigned int heures = secondes / 3600; // 1h
  unsigned int minutes = (secondes % 3600) / 60; // 2078s / 60 = 34 min
  unsigned int secondes_restantes = secondes - heures * 3600 - minutes * 60;

  printf("%02i", heures);
  printf("h");
  printf("%02i", minutes);
  printf("m");
  printf("%02i", secondes_restantes);
  printf("s");

}

unsigned int decimale_a_octale(unsigned int nb_base_decimale) {
  unsigned int reste = 0;
  unsigned int nb_base_octale = 0;
  unsigned int puissance = 0;

  while(nb_base_decimale > 0) {
    reste = nb_base_decimale % 8; // 96 % 8 = 0
    nb_base_decimale /= 8; // 96 / 8 = 12
    //nb_base_octale += reste * pow(8, puissance);
    nb_base_octale += (reste * uint_pow(10, puissance));
    puissance++;
  }
  return nb_base_octale;
}

unsigned int calculer_nb_bits_actifs(unsigned int nb_a_analyser) {
  unsigned int nb_bits_actifs = 0;
  unsigned int masque = 1;

  for(int i = 0; i < 32; i++) {
    if((nb_a_analyser & masque) == 1) {
      nb_bits_actifs++;
    }
    nb_a_analyser = nb_a_analyser >> 1;
  }

  return nb_bits_actifs;
}

void afficher_bits(unsigned int valeur, int bit_depart, int bit_fin) {
  unsigned int masque = 2147483648;
  unsigned int resultat = 0;

  printf("valeur: %0x\n", valeur);
  printf("bit_depart: %i\n", bit_depart);
  printf("bit_fin: %i\n", bit_fin);
  printf("Affichage: (0x%0x) ", valeur);

  for(int i = 31, j = 0; i >= 0; i--) {
    resultat = (valeur & masque) >> i;
    if(i <= bit_fin && i >= bit_depart) {
      j++;
      printf("%u", resultat);
      if(j % 4 == 0) {
        printf(" ");
      }
    }
    masque = masque >> 1;
  }

}