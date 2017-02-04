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
#include "blackjack.h"


Game newGame(int numOfPlayers) {

    Game G = malloc(sizeof(struct _game));

    G->deck = newDeck();

    for (int i = 0; i < numOfPlayers; i++)
    {
        /* code */
    }


    // if (numOfPlayers < 5) {
    //     newGame->playerE.active = NOT_ACTIVE;
    //     newGame->playerE.hand->head = NULL;
    // }
    // if (numOfPlayers < 4) {
    //     newGame->playerD.active = NOT_ACTIVE;
    //     newGame->playerD.hand->head = NULL;
    // }
    // if (numOfPlayers < 3) {
    //     newGame->playerC.active = NOT_ACTIVE;
    //     newGame->playerC.hand->head = NULL;
    // }
    // if (numOfPlayers < 2) {
    //     newGame->playerB.active = NOT_ACTIVE;
    //     newGame->playerB.hand->head = NULL;
    // }

    G->dealer.hand->head = NULL;
    G->playerA.hand->head = NULL;
    
    G->round = 1;
    G->cardCount = CARDS_IN_A_DECK;
    return G;
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
        char = '0' + number;
    } else if(number == 11) {
        char = 'j';
    } else if(number == 12) {
        char = 'q';
    } else {
        char = 'k'
    }
    return card;
}

void countCard(Game g) {

    for(node curr = g->deck->head; curr->next != NULL; curr = curr->next) {
        g->cardCount++;
    }

}