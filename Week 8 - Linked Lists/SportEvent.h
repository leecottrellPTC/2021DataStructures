#ifndef SPORT_EVENT
#define SPORT_EVENT

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class SportEvent {
public:
	//setters and getters
	//constructors
	//to_string
	//any class functionality

	SportEvent();
	SportEvent(string sport, string homeName, string awayName,
		int homePoints, int awayPoints);
	void setHomeTeam(string homeName);
	string getHomeTeam();

	void setHomeScore(int points);
	int getHomeScore();

	string getAwayTeam();
	void setAwayTeam(string name);

	int getAwayScore();
	void setAwayScore(int score);

	string getSportName();
	void setSportName(string name);

	void increaseHomeScore(int addToScore);
	void increaseAwayScore(int addToScore);

	string to_string();
	string winner();//prototype

	/*SportEvent(string sport = "baseBall", string homeName = "Pirates",
		string awayName = "Losers",
		int homePoints = 100, int awayPoints = 0);*/
protected:
	string sportName;
	string homeTeam;
	string awayTeam;
	int homeScore;
	int awayScore;
private:

};

#pragma region constructors

SportEvent::SportEvent() {
	sportName = "soccer";
	homeTeam = "Brookline Panthers";
	awayTeam = "Away team";
	homeScore = 0;
	awayScore = 0;
}

SportEvent::SportEvent(string sport, string homeName, string awayName,
	int homePoints, int awayPoints) {
	sportName = sport;
	//classvar = parameter;
	homeTeam = homeName;
	awayTeam = awayName;
	if (homePoints < 0) {
		homePoints = 0;
	}
	homeScore = homePoints;
	awayScore = awayPoints;
}

#pragma endregion

#pragma region member functions
string SportEvent::to_string() {
	//sprintf example
	char homeScoreOut[20];
	char awayScoreOut[20];
	sprintf_s(homeScoreOut, 20, "%d goals", homeScore);
	sprintf_s(awayScoreOut, 20, "%d goals", awayScore);
	return homeTeam + " " + homeScoreOut
		+ "\n" + awayTeam + " " + awayScoreOut;
 }

//member functions create functionality
void SportEvent::increaseHomeScore(int addToScore = 1) {
	//default parameter - can call as
	//game1.increaseHomeScore();
	//game1.increaseHomeScore(7);
	homeScore += addToScore;
}

void SportEvent::increaseAwayScore(int addToScore = 1) {
	awayScore += addToScore;
}

string SportEvent::winner() {
	if (homeScore > awayScore) {
		return homeTeam;
	}
	else if (homeScore < awayScore) {
		return awayTeam;
	}
	else if (homeScore == awayScore) {
		return "Tie";
	}
	else {
		return "Bad data, no one wins!";
	}
}
#pragma endregion

#pragma region setters and getters
string SportEvent::getHomeTeam() {
	return homeTeam;
}

string SportEvent::getAwayTeam() {
	return awayTeam;
}

int SportEvent::getHomeScore() {
	return homeScore;
}

int SportEvent::getAwayScore() {
	return awayScore;
}

void SportEvent::setHomeTeam(string name) {
	homeTeam = name;
}

void SportEvent::setAwayTeam(string name) {
	awayTeam = name;
}

void SportEvent::setHomeScore(int score) {
	if (score > 0) {
		homeScore = score;
	}
	else {
		homeScore = 0;
	}
}
void SportEvent::setAwayScore(int score) {
	if (score > 0) {
		awayScore = score;
	}
	else {
		awayScore = 0;
	}
}
void SportEvent::setSportName(string sport) {
	sportName = sport;
}

string SportEvent::getSportName() {
	return sportName;
}
#pragma endregion

#endif