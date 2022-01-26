#include "game.h"
using namespace std;
int main()
{
	Game game;
	game.Welcome();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.showAllPlayers();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.selectPlayers();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.showTeamPlayers();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.Toss();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.startFirstInning();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.playInning();
	cout<<"press enter to continue..."<<endl;
	getchar();

	game.startSecondInning();

	game.initializePlayers();
	cout<<"press enter to continue..."<<endl;
	getchar();
	game.playInning();

	game.matchSummary();







	return 0;
}
