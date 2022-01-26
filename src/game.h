#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include "team.h"      //"player.h <string> <vector>

class Game {
public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];
	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam, *bowlingTeam;
	Player *batsman, *bowler;
    void Welcome();                      //to greet user and give some instructions
    void showAllPlayers();               //print all players of the pool.
    int takeIntegerInput();              //to take interger as an inputfrom user.
    void selectPlayers();                //to create team A and B of 4 players each.
    bool validateSelectedPlayers(int);   //to check if players already selected or not.
    void showTeamPlayers();              //to print name of both team players.
    void Toss();                         //toss functionality.
    void tossChoice(Team);               //to get user input to choose after winning toss.
    void startFirstInning();             //to start 1st inning.
    void initializePlayers();            //to initialize batsman and bowler.
    void playInning();                   //to play the innings.
    void bat();                          //to get score on each ball. and to update scores
    bool validateInningScore();          //used to terminate the game.
    void showGameScoreCard();            //to print the score.
    void startSecondInning();            //to start 2nd inning
    int swap(Team *p,Team *q);           //to swap pointer object of class Team.
    void matchSummary();                 //to put match summary.

};
