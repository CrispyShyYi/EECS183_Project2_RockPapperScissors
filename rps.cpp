/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * Jialiang Wu
 * alfredwu
 *
 * EECS 183: Project 2
 * Fall 2023
 *
 * 
 This project is a rock-paper-scissors game;
 Rock-paper-scissors is a hand game played between two people; 
 Eeach player simultaneously forms one of three shapes; 
 These shapes are ¡°rock¡± (a simple fist), ¡°paper¡± (a flat hand);
 and ¡°scissors¡± ;

 Rock will beat scissors; 
 Scissors will beat paper;
 Paper will beat Rock; 
 If both players choose the same shape, the game is tied.
 
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;


using namespace std;


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();



/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();


/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character:
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. You can assume a user
 *           will enter a single character, and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);


/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);




void rps() {
    
    // Begin with two players;
    string playerOne;
    string playerTwo;
    int menu;
    string finalWinner;

    // Print the header before the game;
    printInitialHeader();

    // Get player 1 and 2's name;
    playerOne = getName(1);
    cout << endl << endl;
    playerTwo = getName(2);
    cout << endl << endl;

    // Print the menu choice;
    // Until player choose a right number;
    menu = getMenuChoice();
    cout << endl << endl;

    // Play the game, till "Quit" is detected;
    while (menu != 3) {
        // Play one round of game;
        finalWinner = doGame(playerOne, playerTwo, menu);
        // Anounce the winner;
        announceWinner(finalWinner);
        // Play another game if "Quit" does not exist;
        menu = getMenuChoice();

    }

    //close the game;
    printCloser();


    return;
}

string getName(int playerNumber) {
    
    // get name(s) of playerNumber player(s); 
    
    string player;
    int errorNum = 1;
    
    cout << "Player "
        << playerNumber
        << ", enter your name: ";
    
    // Get player one's name;
    // If the name is invalid. Use Rocky insteda;
    if (playerNumber == 1) {
        getline(cin, player);
        if (player == "") {
            printErrorMessage(errorNum);
            return "Rocky";
        }
        else{
            return player;
        }
    }

    // Get player 2's name;
    // If the name is invalid. Use Creed instead;
    if (playerNumber == 2) {
        getline(cin, player);
        if (player == "") {
            printErrorMessage(errorNum);
            return "Creed";
        }
        else {
            return player;
        }
    }
 



    // NOTE: return "" to avoid compile error
    return "";
}

int getMenuChoice() {
    
    printMenu();

    int choice;
    cin >> choice;
    
    // If the choice is not 1, 2, or 3, ask the player again;
    while ((choice < 1) || (choice > 3)) {
        cout << "Invalid menu choice";
        printMenu();
        cin >> choice;
    }
    
    // Return the game type;
    if (choice == 1) {
        return 1;
    }
    else if (choice == 2) {
        return 2;
    }
    else if (choice == 3) {
        return 3;
    }

    // NOTE: return 0 to avoid compile error

    return 0;
}

bool isMoveGood(char move) {
   

    // Judge the move is right or wrong;
    // return right when R, P, S, r, p, s are detected;
    if (move == 'R') return true;
    else if (move == 'r') return true;
    else if (move == 'P') return true;
    else if (move == 'p') return true;
    else if (move == 'S') return true;
    else if (move == 's') return true;
    // other letters return false;
    else return false;
    
     // NOTE: return false to avoid compile error

    return false;
}

char getMove(string playerName) {

    char moves;

    //get player's move;
    cout << playerName << ", enter your move: ";
    cin >> moves;

    if ((moves == 'R') || (moves == 'r')) {
        return moves;
    }
    if ((moves == 'S') || (moves == 's')) {
        return moves;
    }
    if ((moves == 'P') || (moves == 'p')) {
        return moves;
    }
    // If the player type in a char different from;
    // P, p , S, s, R, r: printErrorMessage;
    else {
        printErrorMessage(2);
        return 'r';
    }


    // NOTE: return 'r' to avoid compile error

    return 'r';
}

bool isRoundWinner(char move, char opponentMove) {


    //judge the who wins in a round, or this round is draw;
    if ((toupper(move) == 'R') && (toupper(opponentMove) == 'S')){
        return true;
    }
    else if ((toupper(move) == 'S') && (toupper(opponentMove) == 'P')) {
        return true;
    }
    else if ((toupper(move) == 'P') && (toupper(opponentMove) == 'R')) {
        return true;
    }
    else return false;
    // NOTE: return false to avoid compile error

    return false;
}

void announceRoundWinner(string winnerName) {


    // Annoucne the round winner;
    // or announce this round is a draw when winnerName is empty;
    if (winnerName == "") {
        cout << "This round is a draw!" << endl;
    }
    else {
        cout << winnerName << " wins the round!" << endl;
    }
    return;
}

int doRound(string p1Name, string p2Name) {


    //play one round;
    char playerOne;
    char playerTwo;
    bool final;
    string winnerName;
        
    // Get player 1's move;
        playerOne = getMove(p1Name);
        cout << endl;

    // Get player 2's move;
        playerTwo = getMove(p2Name);
        cout << endl;

    // Judege who is the winner;
        final = isRoundWinner(playerOne, playerTwo); 

    // If player 1 wins, return 1;
    // Else if it is a draw, return 0;
    // Else if player 2 wins, return 2;
        if (final == true) {
            return 1;
        }
        else if ((final == false) && (toupper(playerOne) == toupper(playerTwo))) {
            return 0;
        }
        else {
            return 2;
        }
        

    // NOTE: return 0 to avoid compile error

    return 0;
}

void announceWinner(string winnerName) {


    // Announce the final winner;
    // or announce the game is a draw when winnerName is enpty;
    if (winnerName == "") {
        cout << "No winner!" << endl;
    }
    else {
        cout << "Congratulations " << winnerName << " !" << endl;
        cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
    }
    return;
}

string doGame(string p1Name, string p2Name, int gameType) {


    //play one entire game, with totoal 3 rounds;
    int i = 1;
    int winnerPlayer;
    int pointOne = 0;
    int pointTwo = 0;

    //get the game type;
    if (gameType == 1) {
        // Play the number of MAX_ROUNDS;
        for (i; i <= MAX_ROUNDS; i++) {

            // Find the winner in each round;
            //  Or find it is a draw, and return 0;
            // add 1 point to the winner in each round;
            // do not add point to neither when a draw occurs;
            winnerPlayer = doRound(p1Name, p2Name);
            if (winnerPlayer == 1) {
                announceRoundWinner(p1Name);
                pointOne += 1;
                cout << endl;
            }
            else if (winnerPlayer == 2) {
                announceRoundWinner(p2Name);
                pointTwo += 1;
                cout << endl;
            }
            else if (winnerPlayer == 0) {
                announceRoundWinner("");
                cout << endl;
            }
        }


        // Find the final winner after three rounds;
        if (pointOne > pointTwo) {
            return p1Name;
        }
        else if (pointOne < pointTwo) {
            return p2Name;
        }
        else if (pointOne == pointTwo) {
            return "";
        }
    }
    
    // If the player choose the second choice;
    // Print "Under Construction";
    else if (gameType == 2) {
        cout << "Under Construction" << endl;
        return "";

    }
    // If the player does not want to play anymore;
    // Quit the game;
    else if (gameType == 3) {
        return "Quit";
    }
    // NOTE: return "" to avoid compile error

    return "";
}





void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}
