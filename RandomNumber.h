#ifndef RANDOMNUMBER_H
#define RANDOMNUMBER_H

#include <stdlib.h>
#include <time.h>

class RandomNumber {
    public:

        /*
            Methode pour initialiser la fonction rand()
            APPELLER SEULEMENT UNE FOIX DANS LA MAIN
        */
        static void initaliseRand() {
            srand(time(NULL));
        }

        /*
            Methode qui genere un nombre aleatoire entre 0 et x
        */
        static int randomNumber(int x) {
            return rand() % x;
        }
    };
#endif // RANDOMNUMBER_H
