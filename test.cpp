/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Jialiang Wu
 * alfredwu
 *
 * EECS 183: Project 2
 * Fall 2023
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;



string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);


void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

// Test functions;
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();

    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    //test the isMoveGood function;
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;

    // test the isMoveGood() function;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'R': Expected: 1, Actual: " << isMoveGood('R') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    cout << "'p': Expected: 1, Actual: " << isMoveGood('p') << endl;
    cout << "'S': Expected: 1, Actual: " << isMoveGood('S') << endl;
    cout << "'s': Expected: 1, Actual: " << isMoveGood('s') << endl;
    cout << "'Q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'A': Expected: 0, Actual: " << isMoveGood('A') << endl;
    

    return;
}

void test_isRoundWinner() {
    
    //check the isRoundWinner function;
    cout << "Now testing function isRoundWinner()\n";
    cout << "'R' 'S': Expected: 1, Actual: " << isRoundWinner('R', 'S') << endl;
    cout << "'R' 'R': Expected: 0, Actual: " << isRoundWinner('R', 'R') << endl;
    cout << "'R' 'P': Expected: 0, Actual: " << isRoundWinner('R', 'P') << endl;
    cout << "'S' 'S': Expected: 0, Actual: " << isRoundWinner('S', 'S') << endl;
    cout << "'S' 'P': Expected: 1, Actual: " << isRoundWinner('S', 'P') << endl;
    cout << "'P' 'P': Expected: 0, Actual: " << isRoundWinner('P', 'P') << endl;
    cout << "'S' 'P': Expected: 1, Actual: " << isRoundWinner('S', 'P') << endl;
    return;
}

void test_announceRoundWinner() {
	
    // check the annoucneRoundWinner function;
    cout << "Now testing function announceRoundWinner()\n";
    cout << "Expected: This round is a draw!, Actual: ";
    announceRoundWinner("");
    cout << endl;

    cout << "Expected: Alfred wins this round!, Actual: ";
    announceRoundWinner("Alfred");
    cout << endl;

    cout << "Expected: Fiona wins this round!, Actual: ";
    announceWinner("Fiona");
    cout << endl;
    return;
}

void test_announceWinner() {
	
    // check the announceWinner function;
    cout << "Now testing function announceWinner()\n";
    cout << "Expected: No winner!, Actual: ";
    announceRoundWinner("");
    cout << endl;

    cout << "Expected: ";
    cout << "Congratulations Alfred" << endl;
    cout << "You won EECS 183 Rock - Paper - Scissors!" << endl;
    cout << "Actual: ";
    announceWinner("Alfred");
    cout << endl;
    

    cout << "Expected: ";
    cout << "Congratulations Finoa" << endl;
    cout << "You won EECS 183 Rock - Paper - Scissors!" << endl;
    cout << "Actual: ";
    announceWinner("Fiona");
    cout << endl;
    return;
}
