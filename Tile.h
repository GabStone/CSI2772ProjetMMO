//
//  tile.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef TILE_H
#define TILE_H

#include "Player.h"
#include "string"
#include <list>
#include "sstream"

// Sur chaque tuile, peut se trouver un ou plusieurs joueurs de type J
template <typename J>

// NOTE: Cette class Tile correspond a une tile de type Desert

class Tile {

protected:

    // List de joueur J qui se retrouve sur la tuile
    std::list<J> listPlayerTile;
    // int col et ligne pour la position de la tuile specific
    int col;
    int ligne;


public:

    // Constructeur de la class Tile
    Tile(int col, int ligne) {
        if (col < 0 || ligne < 0) {
            this->col = 0;
            this->ligne = 0;
        }
        else {
        // Initialisation des attributs ligne et col
        this->col = col;
        this->ligne = ligne;
        }
    }
    // Constructeur par Default
    Tile() {
        col = 0;
        ligne = 0;
    }

    bool operator==(const Tile &t) {
        if (this->col == t.col && this->ligne == t.ligne)
            return true;
        else
            return false;
    }

    virtual bool action(J& player) {
        // Aucune action est possible sur une Tile desert
        return this->action(player);
    }

    virtual Tile* clone() {
        return this->clone();
    }

    /*
     * Methode toString() pour la methode operator<<
     * Returne un std::string
     */
    virtual std::string toString() const {
        std::stringstream ss;
        ss << "Tile Type : " <<"Desert" << "\n";
        ss << "Position : (" << ligne <<"," << col << ")";
        return ss.str();
    }

    // Methode GETTER

    int getCol() const {
        return col;
    }

    int getLigne() const {
        return ligne;
    }

    std::list<J> getListPlayerTile() const {
        return this->listPlayerTile;
    }

    // Methode SETTER

    void setCol(int col) {
        this->col = col;
    }

    void setLigne(int ligne) {
        this->ligne = ligne;
    }


    /*
     * Operator<< pour la class Tile (utilise toString())
     */
    friend std::ostream& operator<<(std::ostream &out, const Tile& tile) {
        out << tile.toString();
        return out;
    }




};



#endif // TILE_H
