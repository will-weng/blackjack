/*
 *
 *
 * Black Jack
 * William Weng
 * 16/08/2016
 *
 *
 */
/* 
    TODO: ask for player names 
 */



#include <stdlib.h>
#include <stdio.h>
#include "header"


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



Game newGame(int numOfPlayers) {

    Game newGame = malloc(sizeof(struct _game));

    newGame->deck = newDeck();

    if (numOfPlayers < 5) {
        newGame->playerE.active = NOT_ACTIVE;
        newGame->playerE.hand->head = NULL;
    }
    if (numOfPlayers < 4) {
        newGame->playerD.active = NOT_ACTIVE;
        newGame->playerD.hand->head = NULL;
    }
    if (numOfPlayers < 3) {
        newGame->playerC.active = NOT_ACTIVE;
        newGame->playerC.hand->head = NULL;
    }
    if (numOfPlayers < 2) {
        newGame->playerB.active = NOT_ACTIVE;
        newGame->playerB.hand->head = NULL;
    }

    newGame->dealer.hand->head = NULL;
    newGame->playerA.hand->head = NULL;
    
    newGame->round = 1;
    newGame->cardCount = CARDS_IN_A_DECK;
    return newGame;
}


list newDeck() {

    list newDeck = malloc(sizeof(struct _list));

    newDeck->head = NULL;

    for(int cardCount = CARDS_IN_A_DECK; cardCount > 0; cardCount--) {
        node card = newCard(cardCount);
        prependCard(newDeck, newCard);
    }

    return newDeck;
}


node newCard(int cardNum) {
    node newCard = malloc(sizeof(struct _node));
    newCard->next = NULL;
    return newCard;
}


void prependCard(list deck, node card) {
    node curr;
    curr = deck->head;
    deck->head = card;
    card->next = curr;
}


void newRound(int turn, game G) {

    if(turn != CARDS_IN_A_DECK) {
        discardHand(G->playerA.hand);
        discardHand(G->playerB.hand);
        discardHand(G->playerC.hand);
        discardHand(G->playerD.hand);
        discardHand(G->playerE.hand);
        discardHand(G->dealer.hand);
    }

    printf("=====     Beginning round %d     =====\n", G->round++);

    if (G->playerA.active == ACTIVE) {
        printf("=====     player 1's hand     =====\n");
        for(int i = 0; i < 2; i++) {
            dealCards(G->deck, G->playerA);
            showHand(G->playerA);
        }
        printf("\n");
    }
    if (G->playerB.active == ACTIVE) {
        printf("=====     player 2's hand     =====\n");
        for(int i = 0; i < 2; i++) {
            dealCards(G->deck, G->playerB);
            showHand(G->playerB);
        }
        printf("\n");
    }
    if (G->playerC.active == ACTIVE) {
        printf("=====     player 3's hand     =====\n");
        for(int i = 0; i < 2; i++) {
            dealCards(G->deck, G->playerC);
            showHand(G->playerC);
        }
        printf("\n");
    }
    if (G->playerD.active == ACTIVE) {
        printf("=====     player 4's hand     =====\n");
        for(int i = 0; i < 2; i++) {
            dealCards(G->deck, G->playerD);
            showHand(G->playerD);
        }
        printf("\n");
    }
    if (G->playerE.active == ACTIVE) {
        printf("=====     player 5's hand     =====\n");
        for(int i = 0; i < 2; i++) {
            dealCards(G->deck, G->playerE);
            showHand(G->playerE);
        }
        printf("\n");
    }

    dealCards(G->deck, G->dealer)
    dealCards(G->deck, G->dealer)
    printf("=====     Dealers hand     =====\n");
    showHand(G->dealer);
    printf("\n");

}


void dealCards(List deck, List hand) {
    node curr = deck->head;
    deck->head = curr->next;
    hand->head = curr;
    curr->next = NULL;
}


void discardHand(List hand) {
    
    node del;

    while(hand->head != NULL) {
        del = hand->head;
        hand->head = del->next;
        free(del);
    }
}


void showCard(List hand) {
    printf("%c ", readCard(hand->head->value));
}


char readCard(int number) {
    char card;
    number = number % SUIT;
    if(number > 0 && number < 11) {
        char = ASCII_ZERO + number;
    } else if(number == 11) {
        char = ASCII_J;
    } else if(number == 12) {
        char = ASCII_Q;
    } else {
        char = ASCII_K
    }
    return card;
}

void countCard(Game g) {

    for(node curr = g->deck->head; curr->next != NULL; curr = curr->next) {
        g->cardCount++;
    }

}