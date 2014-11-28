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

/**
 * main function for the project
 * @return The program has finished execution
 */
int main() {
//    RandomNumber::initaliseRand();
//    int t = 100;
//    while (t > 0) {
//        std:: cout << (RandomNumber::randomNumber(10) + 1) << "\n";
//        t--;
//    }


//    GameBoard<int, int> gb(5, 5);
//    Player gaby("gabriel Stone");
//    gaby.eat();
//    gaby.decrementeGold(1);
//    std:: cout << gaby.getName() << "\n";
//    std:: cout << "Hello bro world" << "\n";
//    int x(10);
//    int y(10);
//    int sum = x + y;
//    std:: cout << "La somme de x et y = " << sum << "\n";
//    // adding random code for a test
//    int **m;
//    m = new int *[10];

//    for (int i = 0; i < 10; i++) {
//        m[i] = new int[10];
//    }
//    // creation d'une matrice 10x10

//    m[1][1] = 100;
//    m[1][1]++;
//    std:: cout << m[1][1] << "\n";

//    std::string s1;
//    std::string s2;

//    s1 = "gabriel";
//    s2 = "gAbriel";

//    if (s1 == s2) {
//        std:: cout << "Egale" << "\n";
//    }
//    else {
//        std:: cout << "pas egale" << "\n";
//    }
    Player player("Gabriel Stone");

    Tile<Player> tile(10,10);
    std:: cout << tile.getCol() << "\n";
    std:: cout << tile.getLigne() << "\n";
    std:: cout << tile << "\n";

    std:: cout << "\n" << "\n";

    TilePalais<Player> tilePalais(5,5);
    std:: cout << tilePalais.getCol() << "\n";
    std:: cout << tilePalais.getLigne() << "\n";
    std:: cout << tilePalais << "\n";




    return 0;
}
