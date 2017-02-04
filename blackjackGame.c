/*
 *
 *
 * Black Jack
 * William Weng
 * 04/02/2017
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "blackjack.h"

int main(int argc, char *argv[]) {

    printf("Welcome to Black Jack\n");
    printf("How many players: \n");
    int playerNumber;
    scanf("%d", &playerNumber);
    Game G = newGame(playerNumber);
    
    //change condition from testing
    while(G->cardCount > 20) {
        newRound(G->cardCount, G);

        countCard(G);
    }

    return EXIT_SUCCESS;
}