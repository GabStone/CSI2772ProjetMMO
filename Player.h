//
//  player.h
//  CSI2772-MMO
//
//  Created by Jeffrey Bettles and Gabriel Stone
//

#ifndef PLAYER_H
#define PLAYER_H
#include "string"
using std::string;

class Player {
private:
    string name; // Nom du Player
    int gold; // Nombre de piece d'or
    int ruby; // Nombre de ruby
    int spice; // Nombre de spice
    int fabric; // Nombre de  fabric
    int jewel; // Nombre de jewel
    int cart; // Capacite du Player
    int food; // Nombre de food

public:

    /*
     Constructeur de la class Player
     On fait simplement initialiser les attributs
     */
    Player(string name) {
        this->name = name;
        gold = 5;
        ruby = 0;
        spice = 1;
        fabric = 1;
        food = 10;
        cart = 9;
        jewel = 1;
    }

    /*
     Retourne vrai si food > 0
     et faux sinon
     */
    bool canAct() const {
        if (this->food > 0)
            return true;
        else
            return false;
    }

    /*
     Donne une piece d'or a un autre joueur
     Retourne true si le piece a ete donner et false sinon
     */
    bool pay(Player& player) {
        if (this->gold > 0) {
            this->gold--;
            player.gold++;
            return true;
        }
        else {
            return false;
        }
    }

    /*
     reduit le nombre de nourritures de 1 si food > 0
     */
    void eat(){
        if (this->food > 0)
            food--;
    }

    /*
     Retourne le nombre d'element que le Player possede
     */
    int size() {
        return (gold + ruby + fabric + jewel + spice);
    }

    /*
        Decrement le montant de gold du joueur par x
     */
    void decrementeGold(int x) {
        this->gold = gold - x;
    }

    /*
     *  Retourne le montant de ressource du joueur
     */
    int getSize() {
       return (spice + fabric + jewel + ruby);
    }

    /*
     * Retourne la capacite disponible
     */
    int getCapacityAvailable() {
        return (this->getCart() - this->getSize());
    }





    /*
     Methode GET et SET pour les attributs de Player
     */

    int getGold() {
        return this->gold;
    }

    int getRuby() {
        return this->ruby;
    }

    int getFabric() {
        return this->fabric;
    }

    int getJewel() {
        return this->jewel;
    }

    int getCart() {
        return this->cart;
    }

    int getFood() {
        return this->food;
    }

    int getSpice() {
        return this->spice;
    }

    string getName() {
        return this->name;
    }

    void setGold(int gold) {
        this->gold = gold;
    }

    void setRuby(int ruby) {
        this->ruby = ruby;
    }

    void setFabric(int fabric) {
        this->fabric = fabric;
    }

    void setJewel(int jewel) {
        this->jewel = jewel;
    }

    void setCart(int cart) {
        this->cart = cart;
    }

    void setFood(int food) {
        this->food = food;
    }

    void setName(string name) {
        this->name = name;
    }

    void setSpice(int spice) {
        this->spice = spice;
    }
};
#endif // PLAYER_H
