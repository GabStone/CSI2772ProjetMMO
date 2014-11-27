//
//  gameboard.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include <list>

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
            grille[i] = new T [this->col];
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

    //void getCoordinate(const  T &tile, int *row, int *col) {

    //}

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

    //const T& getTile(const std::string& playerName) const {

    //}

    //std::vector<J> getPlayers(const T& tile) const {

    //}

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
