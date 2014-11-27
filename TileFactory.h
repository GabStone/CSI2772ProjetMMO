#ifndef TILEFACTORY_H
#define TILEFACTORY_H

// Class TileFactory
// Cette class est une frabrique de tuile
// Il peut seulement y avoir une instance de la class TileFactory (Singleton)
// TileFactory creer et retourne X tuiles dans un ordre aleatoire
// La fabrique cree X/14 copies de chaque tuile, le reste sont des tuiles desert

/* EX: x = 100 (grille 10X10)
 * on creer x/14 = 7 tuiles de chaque typede
 * 7 * 14 = 98
 * Donc il y auras 2 tuiles desert
 */

class TileFactory {

private:
    // Represente le nombre de tuiles a creer
    int xTiles;

    static TileFactory tf = 0;

    // Constructeur de la class TileFactory
    // Prive car TileFactory doit etre un singleton
   TileFactory(int xTiles) {
       this->xTiles = xTiles;
    }

public:

   static TileFactory *get(int xTiles) {
       if (xTiles >= 14) {
            static TileFactory tf(xTiles);
            return &tf;
       }
       else {
           return 0;
       }
   }

   //Tile *next() {

   //}


   int getXTiles() {
       return this->xTiles;
   }
};

#endif // TILEFACTORY_H


