//
//  tile.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef TILE_H
#define TILE_H

#include "Player.h"
#include <string>
#include <list>

// Sur chaque tuile, peut se trouver un ou plusieurs joueurs de type J
template <typename J>

class Tile {

private:

    // List de joueur J qui se retrouve sur la tuile
    std::list<J> listPlayerTile;
    // int col et ligne pour la position de la tuile specific
    int col;
    int ligne;


public:

    // Constructeur de la class Tile
    Tile(int col, int ligne) {
        // Initialisation des attributs ligne et col
        this->col = col;
        this->ligne = ligne;
    }

    bool operator==(const Tile &t) {
        if (this->col == t.col && this->ligne == t.ligne)
            return true;
        else
            return false;
    }

//    virtual bool action(Player& player) {

//    }

//    virtual Tile* clone() {

//    }

//    ostream& operator<<(ostream &out, const Tile& tile) {

//    }


    // Methode GETTER

    int getCol() const {
        return col;
    }

    int getLigne() const {
        return ligne;
    }

    // Methode SETTER

    void setCol(int col) {
        this->col = col;
    }

    void setLigne(int ligne) {
        this->ligne = ligne;
    }


};

#endif // TILE_H
