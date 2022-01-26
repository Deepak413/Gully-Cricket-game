#include "game.h"
using namespace std;
Game::Game()
{
	playersPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0]= "Virat";
	players[1]= "Dhawan";
	players[2]= "Rohit";
	players[3]= "SIyer";
	players[4]= "Dhoni";
	players[5]= "Rahul";
	players[6]= "Jadeja";
	players[7]= "Hardik";
	players[8]= "Bumrah";
	players[9]= "BKumar";
	players[10]= "Ishant";

	isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

void Game::Welcome()
{
	cout<<"||******************************************||"<<endl;
	cout<<"||-----------------CRIC-IN------------------||"<<endl;
	cout<<"||  Welcome to the Mini Virtul Cricket Game ||"<<endl;
	cout<<"||                                          ||"<<endl;
	cout<<"||******************************************||"<<endl<<endl;
	cout<<"||***************Instructions***************||"<<endl;
	cout<<"||                                          ||"<<endl;
	cout<<"|| 1.Create 2 teams with 4 players in each  ||"<<endl;
	cout<<"||  team from given pool of 11 players.     ||"<<endl;
	cout<<"|| 2.Make a toss system to decide.          ||"<<endl;
	cout<<"|| 3.Each Inning will be of 6 balls.        ||"<<endl;
	cout<<"|| 4.Decide match Winner after comparing    ||"<<endl;
	cout<<"||   scores of each team.                   ||"<<endl;
	cout<<"||                                          ||"<<endl;
	cout<<"||******************************************||"<<endl<<endl;

}

void Game::showAllPlayers()
{
	cout<<endl;
	cout<<"||******************************************||"<<endl;
	cout<<"||***********Pool of 11 Players*************||"<<endl;
	cout<<"||__________________________________________||"<<endl<<endl;
	for(int i=0;i<totalPlayers;i++)
	{
		cout<<"                  ["<<i<<"] "<<players[i]<<"                  "<<endl;
	}
	cout<<endl;
}

int Game::takeIntegerInput()
{

	int n;
	while(!(cin>>n))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout<<"enter valid input: try again with valid input."<<endl;

	}
		return n;

}

bool Game::validateSelectedPlayers(int index)
{
	int n;
	vector<Player> players;
	players = teamA.players;
	n= players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id==index)
			return false;
	}

	players = teamB.players;
	n= players.size();
	for(int i=0;i<n;i++)
	{
		if(players[i].id==index)
			return false;
	}
	return true;
}


void Game::selectPlayers()
{
	cout<<endl;
	cout<<"||******************************************||"<<endl;
	cout<<"||*********Create Team-A and Team-B*********||"<<endl;
	cout<<"||__________________________________________||"<<endl<<endl;

    for(int i=0; i<playersPerTeam; i++)
    {
    	//Add players for Team-A
    	teamASelection:
    	cout<<"Select player "<<i+1<<" of Team A - ";
    	int playerIndexTeamA = takeIntegerInput();
    	if(playerIndexTeamA<0||playerIndexTeamA>10)
    	{
    		cout<<"enter valid input: select from given inputs"<<endl;
    				goto teamASelection;
    	}
    	else if(!validateSelectedPlayers(playerIndexTeamA))
		{
    		cout<<"Player is already selected...enter new input."<<endl;
    		goto teamASelection;
		}
    	else
    	{
    	Player teamAPlayer;
    	teamAPlayer.id = playerIndexTeamA;
    	teamAPlayer.name =  players[playerIndexTeamA];
    	teamA.players.push_back(teamAPlayer);
    	}

    	//Add players for Team-B
    	teamBSelection:
    	cout<<"Select player "<<i+1<<" of Team B - ";
        int playerIndexTeamB = takeIntegerInput();
        if(playerIndexTeamB<0||playerIndexTeamB>10)
        {
        	cout<<"enter valid input: select from given inputs"<<endl;
        	   	goto teamBSelection;
        }
        else if(!validateSelectedPlayers(playerIndexTeamB))
        		{
            		cout<<"Player is already selected...enter new input."<<endl;
            		goto teamBSelection;
        		}
        else
        {
        Player teamBPlayer;
        teamBPlayer.id = playerIndexTeamB;
        teamBPlayer.name =  players[playerIndexTeamB];
        teamB.players.push_back(teamBPlayer);
        }

    }
}

void Game::showTeamPlayers()
{
	vector<Player>teamAPlayers = teamA.players;
	vector<Player>teamBPlayers = teamB.players;
	cout<<endl;
	cout<<"|************************|\t\t|************************|"<<endl;
	cout<<"|******* Team-A *********|\t\t|******** Team-B ********|"<<endl;
	cout<<"|________________________|\t\t|________________________|"<<endl<<endl;

	for(int i=0;i<playersPerTeam;i++)
	{
	    cout<<"|\t"<<"["<<i<<"] "<<teamAPlayers[i].name<<"\t |"
	    		<<"\t\t"
				<<"|\t"<<"["<<i<<"] "<<teamBPlayers[i].name<<"\t |"<<endl;
    }
        cout<<"|________________________|\t\t|________________________|"<<endl;
}

void Game::Toss()
{
	cout<<"|****************************|"<<endl;
	cout<<"|******** Lets Toss *********|"<<endl;
	cout<<"|____________________________|"<<endl<<endl;
	cout<<"...Tossing the coin..."<<endl<<endl;

	int x;
	srand(time(NULL));
	x= rand()%2;
	switch(x)
	{
	case 0:{
		cout<<"Team-A won the Toss."<<endl<<endl;
		tossChoice(teamA);
		break;
	       }
	case 1:{
		cout<<"Team-B won the Toss."<<endl<<endl;
		tossChoice(teamB);
	    break;
           }
    }
}

void Game::tossChoice(Team tossWinnerTeam)
{

	cout<<"enter 1 to Bat and 2 to Ball first: ";
	int tossInput = takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	switch(tossInput)
	{
	case 1:{
		cout<<endl<<tossWinnerTeam.name<<" won the Toss and select to Bat first."<<endl;
		if(tossWinnerTeam.name.compare("Team-A")==0)
		{
			battingTeam = &teamA;
			bowlingTeam = &teamB;

		}
		else
		{
			battingTeam = &teamB;
			bowlingTeam = &teamA;
		}
		break;
    	}
	case 2:{
		cout<<endl<<tossWinnerTeam.name<<" won the Toss and select to Ball first."<<endl<<endl;
		if(tossWinnerTeam.name.compare("Team-B")==0)
				{
					battingTeam = &teamA;
					bowlingTeam = &teamB;

				}
				else
				{
					battingTeam = &teamB;
					bowlingTeam = &teamA;
				}

		  break;
	    }
	default:{
		cout<<"invalid input. please try again..."<<endl;
		tossChoice(tossWinnerTeam);
        break;
	}
	}
}

void Game::startFirstInning()
{
	cout<<"      ***START FIRST INNING***      "<<endl<<endl;

	isFirstInnings = true;
	initializePlayers();


}

void Game::initializePlayers()
{
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout<<battingTeam->name<<" - "<<batsman->name<<" is batting"<<endl;
	cout<<bowlingTeam->name<<" - "<<bowler->name<<" is bowling"<<endl<<endl;

}

void Game::playInning()
{
	for(int i=0;i<maxBalls;i++)
	{
	cout<<"press enter to Bowl"<<endl;
    getchar();
	cout<<"Bowling....";

	bat();

	if(!validateInningScore())
	{
		break;
	}
	}

}
void Game::bat()
{
	srand(time(NULL));
	int runsScored = rand()%7;
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled +1;

    if(runsScored!=0)
    {
    	cout<<bowler->name<<" to "<<batsman->name<<"  "<<runsScored<<" runs"<<endl<<endl;
    	showGameScoreCard();

    }else
    {
    	cout<<bowler->name<<" to "<<batsman->name<<"  OUT!"<<endl<<endl;
 	    bowler->wicketsTaken = bowler->wicketsTaken + 1;
  	    battingTeam->wicketsLost = battingTeam->wicketsLost+1;
  	    showGameScoreCard();
  	    int nextPlayerIndex = battingTeam->wicketsLost;
	    batsman = &battingTeam->players[nextPlayerIndex];

    }

}

bool Game::validateInningScore()
{
	if(isFirstInnings)
	{
		if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			cout<<"\t\t |||FIRST INNING ENDS ||| "<<endl<<endl;
			cout<<battingTeam->name<<" "<<battingTeam->totalRunsScored<<" - "
					<<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled
					<<")"<<endl;
			cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored+1
					<<" runs to win the match."<<endl<<endl;

			return false;
		}
		else
			{
				return true;
			}
	}
	else
	{
		if(battingTeam->totalRunsScored>bowlingTeam->totalRunsScored)
		{
			cout<<endl<<battingTeam->name<<" won the match."<<endl<<endl;
			return false;
		}
		else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored)
			{
				cout<<"Match tied."<<endl<<endl;
				return false;
			}
			else if(battingTeam->totalRunsScored < bowlingTeam->totalRunsScored)
			{
				cout<<bowlingTeam->name<<" won the match."<<endl<<endl;
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return true;
		}
	}

}

void Game::showGameScoreCard()
{
	cout<<" _____________________________________________________________"<<endl;
		cout<<"|    "<<battingTeam->name<<"  "<<battingTeam->totalRunsScored<<" - "
				<<bowler->wicketsTaken<<"("<<batsman->ballsPlayed<<")"
				<<" | "<<batsman->name<<" "<<batsman->runsScored<<" ("
				<<batsman->ballsPlayed<<")"<<"      "<<bowler->name<<" "
				<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "
				<<bowler->wicketsTaken<<"     |"<<endl;
		cout<<" _____________________________________________________________"<<endl<<endl;


}


void Game::startSecondInning()
{
	cout<<"              ||START SECOND INNING||           "<<endl<<endl;
	isFirstInnings = false;
	swap(battingTeam,bowlingTeam);
}

int Game::swap(Team *p,Team *q)
{
	Team temp = *p;
	*p = *q;
	*q = temp;
	 return 0;
}

void Game::matchSummary()
{
	cout<<endl<<"             |||MATCH ENDS|||            "<<endl<<endl;
	cout<<teamA.name<<" "<<teamA.totalRunsScored<<"-"<<teamA.wicketsLost<<"-("
			<<teamB.totalBallsBowled<<")"<<endl;
    cout<<"**********************************************|"<<endl;
    cout<<"| PLAYER \t BATTING \t BOWLING|"<<endl;
    cout<<"|_____________________________________________|"<<endl<<endl;
    for(int i=0;i<playersPerTeam;i++)
    {
    	cout<<"| [ "<<i<<" ] ";
    	cout<<teamA.players[i].name<<" \t ";
    	cout<<teamA.players[i].runsScored<<"(";
    	cout<<teamA.players[i].ballsPlayed<<") \t\t ";
		cout<<teamA.players[i].ballsBowled<<"-";
		cout<<teamA.players[i].runsGiven<<"-";
		cout<<teamA.players[i].wicketsTaken<<" |"<<endl;

    }

    cout<<endl<<endl;

    cout<<teamB.name<<" "<<teamB.totalRunsScored<<"-"<<teamB.wicketsLost<<"-("
    			<<teamA.totalBallsBowled<<")"<<endl;
        cout<<"*******************************************|"<<endl;
        cout<<"| PLAYER \t BATTING \t BOWLING|"<<endl;
        cout<<"|__________________________________________|"<<endl<<endl;
        for(int i=0;i<playersPerTeam;i++)
        {
        	cout<<"| [ "<<i<<" ] ";
        	cout<<teamB.players[i].name<<" \t ";
        	cout<<teamB.players[i].runsScored<<"(";
        	cout<<teamB.players[i].ballsPlayed<<") \t\t ";
    		cout<<teamB.players[i].ballsBowled<<"-";
    		cout<<teamB.players[i].runsGiven<<"-";
    		cout<<teamB.players[i].wicketsTaken<<" |"<<endl;

        }

}

