//
//  gameboard.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <list>
#include "Tile.h"
#include "AllTiles.h"
#include <vector>

/*
 GameBoard est une class parametriser qui represente une grille de jeu
 */

template<typename T, typename J>

// Les tuiles associees a cette grille sont de type T
// Les joueurs qui se retrouve sur les tuiles sont de type J

class GameBoard {

private:
    int col; // Nombre de colonne dans la grille
    int ligne; // Nombre de ligne dans la grille
    int n; // Nombre de joueurs dans la partie
    T** grille; // Matrice qui va representer la grille de jeu
    std:: list<J> listPlayer;

public:

    GameBoard(int col, int ligne) {        
        // col et/ou ligne non valide
        if (col <= 0 || ligne <= 0) {
            this->col = 10;
            this->ligne = 10;
        }
        else {
            this->col = col;
            this->ligne = ligne;
        }

        grille = new T *[this->ligne];

        for (int i = 0; i < this->ligne; i++) {
            grille[i] = new T[this->col];
        }
    }



    void add(const T& tile, int row, int col) {
        // row et/ou col non valide
        if (row < 0 || col < 0 || col > this->col-1 || row > this->ligne-1) {
            throw std::out_of_range("col et/ou row invalide");
        }
        else {
            grill[row][col] = tile;
        }
    }

    const T& getTile(int row, int col) const {

        // row et/ou col non valide
        if (row < 0 || col < 0 || col > this->col-1 || row > this->ligne-1) {
            throw std::out_of_range("col et/ou row invalide");
        }
        else {
            return grille[row][col];
        }
    }

    void getCoordinate(const  T &tile, int *row, int *col) {
        // On veut les coordonnee de la tuile
        int _ligne = tile.getLigne();
        int _col = tile.getCol();

        *row = _ligne;
        *col = _col;
    }

    void setPlayer(J player) {
        // On incremente n
        n++;
        // On ajoute le player J dans la liste de joueur listPlayer
        listPlayer.push_back(player);
    }

    /*
     *  Methode pour trouver le joueur J par sont nom
     */
    J getPlayer(const std::string& playerName) {
        // On commence avec la creation d'un iterator qui est
        // initialiser au debut de la list de joueur listPlayer
        std::list<J>::iterator iterator;
        iterator = listPlayer.begin();

        // On boucle jusqua ce que l'iterator se rend a la fin
        // de la liste, ou que le nom du Player que pointe l'iterator
        // est egale au nom passer en parametre
        while (iterator != listPlayer.end() || (iterator.getName() == playerName)) {
            iterator++;
        }
        if (iterator = listPlayer.end())
            return 0; // ou null je c pas ???
        else
            return iterator;
    }

    // Aller chercher la tile qui correspond a la location de Player
    // que sont nom est passer en parametre
    const T& getTile(const std::string& playerName) const {
        int x;
        int y;
        bool trouver = false;
        for (int i = 0; i < this->ligne; i++) {
            for (int j = 0; j < this->col; j++) {
                if (trouver == false) {
                    // Une list contenant toutes les joueurs sur la tuiles grille[ligne][col]
                    std::list<J> list = grille[ligne][col].getPlayerListTile();
                    for (std::list<J>::iterator it = list.begin(); it != list.end(); ++it) {

                        if (*it.getName() == playerName) {
                            // On a trouver le joueur qui porte le nom playerName
                            x = i;
                            y = j;
                            trouver = true;
                        }
                    }
                }
                else {
                    // On a deja trouver le joueur qui porte le nom playerName
                    break;
                }
            }
        }
        return grille[x][y];
    }

    std::vector<J> getPlayers(const T& tile) const {
        // Vector qui va contenir tout les joueurs sur la tile passer en parametre
        std::vector<J> vec;
        std::list<J> list = tile.getListPlayerTile();
        for (std::list<J>::iterator it = list.begin(); it != list.end(); ++it) {
            vec.push_back(*it);
        }
        return vec;
    }

    /*
     * ???? AUCUNE IDEE ????
     *
     */
    //const T& move(Enum Move move, const std::string& playerName) {

    //}

    /*
     *  Destructeur de la class GameBoard
     */
    ~GameBoard() {
        delete [] grille;
    }

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


#endif // GAMEBOARD_H
