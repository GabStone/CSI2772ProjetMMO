#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include <list>
#include "Tile.h"
#include "AllTiles.h"

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

// TileFactory vas creer des Tile<J>
template <typename J>
class TileFactory {

private:
    // Represente le nombre de tuiles a creer
    int xTiles;

    // Represente la list contenant xTiles Tile
    std::list<Tile<J>*> tileList;

    // Constructeur de la class TileFactory
    // Prive car TileFactory doit etre un singleton
    TileFactory(int xTiles) {
        this->xTiles = xTiles;

        // Creation de xTiles Tile<J>
        // On doit creer xTiles/14 de chaque tuile
        int x = xTiles/14;

        while (x > 0) {
            tileList.push_back(new TileRestaurant<J>(0,0));
            tileList.push_back(new TileMarchandEpice<J>(0,0));
            tileList.push_back(new TileMarchandTissus<J>(0,0));
            tileList.push_back(new TileBijoutier<J>(0,0));
            tileList.push_back(new TileFabriquantCharrette<J>(0,0));
            tileList.push_back(new TilePetitMarche<J>(0,0));
            tileList.push_back(new TileMarchandEpice<J>(0,0));
            tileList.push_back(new TileMarcheBijoux<J>(0,0));
            tileList.push_back(new TileMarcheTissus<J>(0,0));
            tileList.push_back(new TileMarcheNoir<J>(0,0));
            tileList.push_back(new TileCasino<J>(0,0));
            tileList.push_back(new TileMarchandGemme<J>(0,0));
            tileList.push_back(new TilePalais<J>(0,0));
            x--;
        }







    }

public:

    // On retourne null (0) si xTiles < 14
    static TileFactory *get(int xTiles) {
        if (xTiles >= 14) {
            static TileFactory<J> instance(xTiles);
            return &instance;
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


