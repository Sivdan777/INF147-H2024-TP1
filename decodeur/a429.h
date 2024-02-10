
void afficher_entete_decodeur (void);

void afficher_entete_test (void);

void decoder_mot_a429 (unsigned int valeur, int* est_corrompu,
                       int* numero_mot_octal, double* donnee_bnr,
                       int* donnee_bcd1, int* donnee_bcd2,
                       int* donnee_bcd3, int* donnee_bcd4);

void afficher_mot_a429 (unsigned int valeur);
