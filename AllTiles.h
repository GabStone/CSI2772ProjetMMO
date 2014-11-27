#ifndef ALLTILES_H
#define ALLTILES_H

#include "Tile.h"
#include "RandomNumber.h"

 /*
 *  AllTiles.h contient la definition de toutes les
 *  type de tile possible.
 *  Il existe 14 types de tile
 */

// Tile qui correspond a une restaurant
// Fonctionnalite: le nombre de nourriture du joueur retourne a 10
// Cette tuile est le point initial de tout les joueurs

template <typename J>
class TileRestaurant : public Tile<J>{

private:

public:

    // Constructeur de la class TileRestaurant
    TileRestaurant(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player& player) {
        // Le nombre de nourriture du joueur retourne a 10
        player.setFood(10);
        return true;
    }

    TileRestaurant* clone() {
        return new TileRestaurant(col, ligne);
    }
};




// Tile qui correspond a un marchand d'epice
// Fonctionnalite: Pour 2 pieces d'or, le joueur obtient 3 sacs d'epices
// (moins si la capacite du joueur ne le permet pas)

template <typename J>
class TileMarchandEpice : public Tile<J> {

private:

public:

    // Constructeur de la class TileMarchandEpice
    TileMarchandEpice(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player& player) {
        bool result;
        if (player.getGold() > 2 && player.getCapacityAvailable() > 0) {
            player.decrementeGold(2);
            if (player.getCapacityAvailable() >= 3) {
                // Incremente le spice de 3
                player.setSpice(player.getSpice() + 3);
            }
            else {
                player.setSpice(player.getSpice() + player.getCapacityAvailable());
               }
            result = true;
        }
        result = false;
        return result;
    }

    TileMarchandEpice* clone() {
        return new TileMarchandEpice(col, ligne);
    }
};




// Tile qui correspond a un marchand de tissus
// Fonctionnalite: Pour 2 pieces d'or, le joueur obtient 3 rouleaux de tissus
// (moins si la capacite du joueur ne le permet pas)

template <typename J>
class TileMarchandTissus : public Tile<J>{

private:

public:

    // Constructeur de la class TileMarchandTissus
    TileMarchandTissus(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player& player) {
        bool result;
        if (player.getGold() > 2 && player.getCapacityAvailable() > 0) {
            player.decrementeGold(2);
            if (player.getCapacityAvailable() >= 3) {
                // Incremente le fabric de 3
                player.setFabric(player.getFabric() + 3);
            }
            else {
                // Increment le fabric le plus qu'on peut
                player.setFabric(player.getFabric() + player.getCapacityAvailable());
               }
            result = true;
        }
        result = false;
        return result;
    }

    TileMarchandTissus* clone() {
        return new TileMarchandTissus(col, ligne);
    }


};


// Tile qui correspond a un bijoutier
// Fonctionnalite: Pour 2 piece d'or, le joueur obtient 3 bijoux
// (moins si la capacite du joueur ne le permet pas)

template <typename J>
class TileBijoutier : public Tile<J> {

private:

public:

    // Constructeur de la class TileBijoutier
    TileBijoutier(int col, int ligne) : Tile<J>(col, ligne){
        // On appelle le constructeur de la class Tile
    }

    bool action(Player& player) {
        bool result;
        if (player.getGold() > 2 && player.getCapacityAvailable() > 0) {
            player.decrementeGold(2);
            if (player.getCapacityAvailable() >= 3) {
                // Incremente le jewel de 3
                player.setJewel(player.getJewel() + 3);
            }
            else {
                // Increment le fabric le plus qu'on peut
                player.setJewel(player.getJewel() + player.getCapacityAvailable());
               }
            result = true;
        }
        result = false;
        return result;
    }

    TileBijoutier* clone() {
        return new TileBijoutier(col, ligne);
    }
};



// Tile qui correspond a un fabriquant de charrette
// Fonctinnalite: Pour 7 pieces d'or le joueur peut augmenter sa capaciter
// maximale de 3

template <typename J>
class TileFabriquantCharrette : public Tile<J> {

private:

public:

    // Constructeur de la class TileFabriquantCharrette
    TileFabriquantCharrette(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;

        if (player.getGold() >= 7) {
            player.setCart(player.getCart() + 3);
            player.setGold(player.getGold() - 7);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }


    TileFabriquantCharrette* clone() {
        return new TileFabriquantCharrette(col, ligne);
    }
};




// Tile qui correspond a un petit marche
// Fonctionnalite: Le joueur peut vendre un rouleau de tissus,
// un sac d'epice, et 1 bijoux pour 8 pieces d'or

template <typename J>
class TilePetitMarche : public Tile<J> {

private:


public:

    // Constructeur de la class TilePetitMarche
    TilePetitMarche(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getFabric() > 0 && player.getSpice() > 0 && player.getJewel() > 0) {
            // On decremente fabric, spice et jewel
            player.setFabric(player.getFabric() - 1);
            player.setSpice(player.getSpice() - 1);
            player.setJewel(player.getJewel() - 1);
            // On donne 8 pieces d'or au joueur
            player.setGold(player.getGold() + 8);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }


    TilePetitMarche* clone() {
        return new TilePetitMarche(col, ligne);
    }
};




// Tile qui correspond a un marche d'epices
// Fonctionnalite: Le joueur peut vendre 3 sac d'epices pour 6 pieces d'or

template <typename J>
class TileMarcheEpice : public Tile<J> {

private:

public:

    // Constructeur de la class TileMarcheEpice
    TileMarcheEpice(int col, int ligne) : Tile<J>(col, ligne){
        // On appelle le constucteur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getSpice() >= 3) {
            player.setSpice(player.getSpice() - 3);
            player.setGold(player.getGold() + 6);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TileMarcheEpice* clone() {
        return new TileMarchandEpice(col, ligne);
    }
};





// Tile qui correspond a un marche de bijoux
// Fonctionnalite: Le joueur peut vendre 3 bijoux pour 6 pieces d'or

template <typename J>
class TileMarcheBijoux : public Tile<J> {

private:

public:

    // Constructeur de la class TileMarcheBijoux
    TileMarcheBijoux(int col, int ligne) : Tile<J>(col, ligne){
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getJewel() >= 3) {
            player.setJewel(player.getJewel() - 3);
            player.setGold(player.getGold() + 6);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TileMarcheBijoux* clone() {
        return new TileMarcheBijoux(col, ligne);
    }
};




// Tile qui correspond a un marche de tissus
// Fonctionnalite: Le joueur peut vendre 3 rouleaux de tissus pour 6 pieces d'or

template <typename J>
class TileMarcheTissus : public Tile<J> {

private:

public:

    // Conctructeur de la class TileMarcheTissus
    TileMarcheTissus(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        int result;
        if (player.getFabric() >= 3) {
            player.setFabric(player.getFabric() - 3);
            player.setGold(player.getGold() + 6);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TileMarcheTissus* clone() {
        return new TileMarcheTissus(col, ligne);
    }
};





// Tile qui correspond a un marche noir
// Fonctinnalite: pour une piece d'or le joueur obtient au hasard
// entre 0 et 5 tissus, epice et/ou bijoux
// (moins si la capacite du joueur ne le permet pas)

template <typename J>
class TileMarcheNoir : public Tile<J>{

private:

public:

    // Constructeur de la class TileMarcheNoir
    TileMarcheNoir(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getGold() >= 1) {
            player.setGold(player.getGold() - 1);
            int x;
            int y;
            // y == 0 : ajoute un tissus
            // y == 1 : ajoute un epice
            // y == 2 : ajoute un bijou
            // Boucle avec 5 chances ou jusqua ce que la capacite du joueur est plein
            // A chaque iteration, on 50% de chance d'avoir 1 tissus ou 1 epice ou 1 bijou
            for (int i = 0; (i < 5 && player.getCapacityAvailable() > 0); i++) {
                // x random entre 0 et 1
                x = RandomNumber::randomNumber(1);
                if (x == 0) {
                    // y random entre 0 et 2
                    y = RandomNumber::randomNumber(2);
                    if (y == 0) {
                        player.setFabric(player.getFabric() + 1);
                    }
                    else if (y == 1) {
                        player.setSpice(player.getSpice() + 1);
                    }
                    else if (y == 2) {
                        player.setJewel(player.getJewel() + 1);
                    }
                }
                else {
                    // le joueur ne recoit rien
                }
            }
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TileMarcheNoir* clone() {
        return new TileMarcheNoir(col, ligne);
    }
};





// Tile qui correspond a un casino
// Fonctionnalite: Pour une piece d'or le joueur a :
// 2 chances sur 5 de rien gagner
// 3 chances sur 10 de gagner 2 pieces d'or
// 2 chances sur 10 de gagner 3 pieces d'or
// 1 chance sur 10 de gagner 10 pieces d'or

template <typename J>
class TileCasino : public Tile<J>{

private:

public:

    // Constructeur de la class TileCasino
    TileCasino(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player& player) {
        bool result;
        if (player.getGold() >= 1) {
            player.setGold(player.getGold() - 1);

            // ???

            result = true;

        }
        else {
            result = false;
        }
        return result;
    }

    TileCasino* clone() {
        return new TileCasino(col, ligne);
    }
};




// Tile qui correspond a un marchand de gemme
// Fonctionnalite: Le joueur peut acheter un rubis
// 1er rubis coutera 12, 2e coutera 13 .... ect

template <typename J>
class TileMarchandGemme : public Tile<J> {

private:
    // Represente le prix courant de rubis
    int prix = 12;

public:

    // Constructeur de la class TileMarchandGemme
    TileMarchandGemme(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getGold() >= prix) {
            player.setGold(player.getGold() - prix);
            prix++;
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TileMarchandGemme* clone() {
        return new TileMarchandGemme(col, ligne);
    }
};





// Tile qui correspond a un palais
// Fonctionnalite: Le joueur obtient un rubis en echange pour
// 5 rouleaux de tissus, 5 sac d'epices et 5 bijoux

template <typename J>
class TilePalais : public Tile<J> {

private:

public:

    // Constructeur de la class TilePalais
    TilePalais(int col, int ligne) : Tile<J>(col, ligne) {
        // On appelle le constructeur de la class Tile
    }

    bool action(Player &player) {
        bool result;
        if (player.getFabric() >= 5 && player.getSpice() >= 5 && player.getJewel() >= 5) {
            player.setFabric(player.getFabric() - 5);
            player.setSpice(player.getSpice() - 5);
            player.setJewel(player.getJewel() - 5);
            player.setRuby(player.getRuby() + 1);
            result = true;
        }
        else {
            result = false;
        }
        return result;
    }

    TilePalais* clone() {
        return new TilePalais(col, ligne);
    }
};
#endif // ALLTILES_H
