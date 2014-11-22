//
//  gameboard.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

/*
 GameBoard est une class parametriser qui represente une grille de jeux
 */

template<typename T, typename J>
class GameBoard {
private:
    int col; // Nombre de colonne dans la grille
    int ligne; // Nombre de ligne dans la grille
    T **grille;

public:

    GameBoard(int col, int ligne) {
        this->col = col;
        this->ligne = ligne;
        grille = new T *[ligne];
        for (int i = 0; i < ligne; i++) {
            grille[ligne] = new T[col];
        }
    }

    //void add(const T& tile, int row, int col) {

    //}

    //const T& getTile(int row, int col) const {

    //}

    //void getCoordinate(const  T &tile, int *row, int *col) {

    //}

    //void setPlayer(J player) {

    //}

    //J getPlayer(const std::string& playerName) {

    //}

    //const T& getTile(const std::string& playerName) const {

    //}

    //std::vector<J> getPlayers(const T& tile) const {

    //}

    //const T& move(Enum Move move, const std::string& playerName) {

    //}
};




#endif // GAMEBOARD_H
