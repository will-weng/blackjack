/*
	header file for blackjack
	William Weng
	20/08/2016
*/

#define CARDS_IN_A_DECK 52
#define SUIT 13
#define ASCII_ZERO 48
#define ASCII_J 74
#define ASCII_Q 81
#define ASCII_K 75


#define BUST 1
#define NOT_BUST 0
#define ACTIVE 1
#define NOT_ACTIVE 0


// a link list structure used for cards
typedef struct _node *link;
typedef struct _game *Game;

struct _node {
    int value;
    link next;
} node;

typedef struct _list {
    link head;
//  link last;
} *List;

// the struct of the game
typedef struct _game{
    List deck;
    int round;
    player playerA;
    player playerB;
    player playerC;
    player playerD;
    player playerE;
    player dealer;
    int cardCount;
} Game;

// a struct for a basic player
typedef struct _playerInfo {
    int active = 1;
    int bust = NOT_BUST;
    List hand;
    int pot;
} player;


// TODO:

void shuffle();
int playerMove(char move);

// DOING:

// creates a new game including the dealers deck and number of players
Game newGame(int numOfPlayers);

// FINISHED:

// creates a list that is a new deck that has been shuffled
// TODO: shuffle the deck
list newDeck();
// create a node that is a card to be placed into the deck
node newCard(int cardNum);
// a function to place a card to the front of a list
void prependCard(list deck, node card);
// a function that puts a card into a given hand at the start of the hand
void dealCards(List deck, List hand);
// given the index of the the card
char readCard(int number);
// shows the first card given the hand
void showCard(List hand);
// throws a hand away and frees up the space
void discardHand(List hand);
// start of a new round including taking away cards from last round and dealing cards
void newRound(int turn);
// updates the number of cards in the deck
void countCard(Game g);