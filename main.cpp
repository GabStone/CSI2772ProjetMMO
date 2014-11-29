//
//  main.cpp
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone.
//

#include <iostream>

#include "Player.h"
#include "GameBoard.h"
#include <string>
#include "Tile.h"
#include "AllTiles.h"
#include "RandomNumber.h"
#include "TileFactory.h"
#include <vector>
#include <deque>

/**
 * main function for the project
 * @return The program has finished execution
 */
int main() {
    // Doit appeller initialiseRand() une fois pour utiliser notre fonction random
    RandomNumber::initaliseRand();

    // Welcome statement
    std:: cout << " TILE GAME " << "\n" << "\n";
    std:: cout << " Inspire du jeu Istanbul par Rudiger Dorn " << "\n" << "\n";
    std:: cout << " Par: Gabriel Stone et Jeffrey Bettles " << "\n" << "\n";
    std:: cout << "Nous avons besoin unpeu d'information avant de commencer le jeu" << "\n" << "\n" << "\n";

    // Nombre de joueur (venant de l'utilisateur)
    int nombreJoueur;

    int reponse;

    // BOUCLE POUR NOMBRE DE JOUEUR
    while (true) {
        std:: cout << "Combien de joueur (au moins 2) ?" << "\n";
        std:: cin >> nombreJoueur;
        if (nombreJoueur < 2) {
            std:: cout << "Pas asser de joueur, essayer encore" << "\n" <<"\n";
            continue;
        }

        std:: cout << "Etes vous certaine vous voulez " << nombreJoueur << " joueur dans la joute?" <<"\n";
        std:: cout << "1 pour oui et 0 pour non" "\n";
        std:: cin >> reponse;
        if (reponse == 1) {
            break;
        }
    }
    reponse = 0;

    // Nous avons le nombre de joueurs voulu nombreJoueur
    // On doit creer c'est joueur et donner des noms

    std:: cout << "\n" << "\n" <<"Nous avons maintenant besoin des noms des joueurs!" << "\n";
    Player *tblPlayer;
    tblPlayer = new Player[nombreJoueur];

    // BOUCLE POUR ENTRER NOM DES JOUEURS
    while (true) {
        std:: string nom;
        for (int i = 0; i < nombreJoueur; i++) {
            nom = "";
            std:: cout << "Quel est le nom du Joueur : " << i+1 << " (premier nom seulement PAS D'ESPACE)" << "\n";
            std:: cin >> nom;
            tblPlayer[i] = Player(nom);
        }
        std:: cout << "Donc les noms des joeurs sont comme ceci : " << "\n";
        for (int i = 0; i < nombreJoueur; i++) {
            std:: cout << "Joueur " << i+1 << ": " << tblPlayer[i].getName() << "\n";
        }
        std:: cout << "Entrez 1 si oui et 0 si non" << "\n";
        std:: cin >> reponse;
        if(reponse == 1) {
            break;
        }
        else {
            delete [] tblPlayer;
        }
    }

    // Maintenant nous avons toutes nos joueur dans un tableau
    // On doit creer la gameboard
    int i, j;

    // BOUCLE POUR LA DIMENSION DE LA GRILLE
    while (true) {
        std:: cout << "Quel seras la dimension de la grille de joute ? (entre 4 et 10)" << "\n";
        std:: cout << "Nombre de ligne : ";
        std:: cin >> i;
        std:: cout << "\n";
        std:: cout << "Nombre de colonne : ";
        std:: cin >> j;
        std:: cout << "\n";

        // Dimension non valide
        if (i > 10 || j > 10 || j < 4 || i < 4) {
            std:: cout << "Dimension non valide! Entre 4 et 10" << "\n";
            continue;
        }
        std:: cout << "Donc vous voulez une grille de joutes de " << i << "X" << j << "\n";
        std:: cout << "Entrez 1 si oui, et 0 pour non" << "\n";
        std:: cin >> reponse;
        if (reponse == 1) {
            break;
        }
        else {
            i = 0;
            j = 0;
        }
    }

    GameBoard<Tile<Player>, Player> gameboard(j, i);
    // La GameBoard contiendras des Tile qui contient des Player et une list de Player

    // On doit maintenant ajouter tout les Player creer dans la gameboard

    // BOUCLE POUR AJOUTER LES JOEURS A LA GAMEBOARD
    for (int i = 0; i < nombreJoueur; i++) {
        gameboard.setPlayer(tblPlayer[i]);
    }

    // Il reste a creer le bon nombre de tile (i*j)
    // On utilise la class TileFactory

    // Retourne un tf singleton
    //TileFactory<Tile<Player>> *tf = TileFactory<Tile<Player>>::get(i*j);











    return 0;
}
