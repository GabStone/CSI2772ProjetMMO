#ifndef TILEFACTORY_H
#define TILEFACTORY_H
#include <list>
#include "Tile.h"
#include "AllTiles.h"
#include <algorithm>
#include <deque>

// Class TileFactory
// Cette class est une frabrique de tuile
// Il peut seulement y avoir une instance de la class TileFactory (Singleton)
// TileFactory creer et retourne X tuiles dans un ordre aleatoire
// La fabrique cree X/13 copies de chaque tuile, le reste sont des tuiles desert

/* EX: x = 100 (grille 10X10)
 * on creer x/13 = 7 tuiles de chaque type de tuile
 * 7 * 13 = 9
 * Donc il y auras 9 tuiles desert
 */

// TileFactory vas creer des Tile<J>
template <typename J>
class TileFactory {

private:
    // Represente le nombre de tuiles a creer
    int xTiles;

    // Represente la list contenant xTiles Tile
    std::deque<Tile<J>*> dequeTile;

    // Represente un index pour retourner la bonne tuile
    int index;

    // Constructeur de la class TileFactory
    // Prive car TileFactory doit etre un singleton
    TileFactory(int xTiles) {
        this->xTiles = xTiles;

        // Creation de xTiles Tile<J>
        // On doit creer xTiles/13 de chaque tuile
        int x = xTiles/13;

        while (x > 0) {
            dequeTile.push_back(new TileRestaurant<J>(0,0));
            dequeTile.push_back(new TileMarchandEpice<J>(0,0));
            dequeTile.push_back(new TileMarchandTissus<J>(0,0));
            dequeTile.push_back(new TileBijoutier<J>(0,0));
            dequeTile.push_back(new TileFabriquantCharrette<J>(0,0));
            dequeTile.push_back(new TilePetitMarche<J>(0,0));
            dequeTile.push_back(new TileMarchandEpice<J>(0,0));
            dequeTile.push_back(new TileMarcheBijoux<J>(0,0));
            dequeTile.push_back(new TileMarcheTissus<J>(0,0));
            dequeTile.push_back(new TileMarcheNoir<J>(0,0));
            dequeTile.push_back(new TileCasino<J>(0,0));
            dequeTile.push_back(new TileMarchandGemme<J>(0,0));
            dequeTile.push_back(new TilePalais<J>(0,0));
            x--;
        }
        // Il reste dont a creer les tuiles de type Desert avec le nombre qui reste

        int y = xTiles/13;
        int nDesert = xTiles - (y * 13);
        // On creer nDesert tuiles de type Desert si nDesert > 0
        while (nDesert > 0) {
            dequeTile.push_back(new Tile<J>(0,0));
            nDesert--;
        }

        // On veut melanger toutes les tiles dans la list
        // Pour les retourner dans une ordre aleatoire
        std::random_shuffle(dequeTile.begin(), dequeTile.end()-1);

        // Initialise l'index a 0
        this->index = 0;
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

    // On retourne la prochaine tuile a la position index
    Tile *next() {
        if (index < dequeTile.size()) {
            // on retourne la tuile a la position index
            Tile<J> *tile;

            /*
             * PAS CERTAINE DE ---> (*)DEQUEITEM
             * MAIS SA COMPILE PAS SANS
             */

            tile = (dequeTile[index])->clone();
            index++;
            return tile;
        }
        else {
            throw("No more Tiles");
        }
    }

    int getXTiles() {
        return this->xTiles;
    }
};
#endif // TILEFACTORY_H
