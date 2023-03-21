#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string.h>
using namespace std;
class Player {
	string firstName;
	string secondName;
	int points;

public: 
	Player();
	Player(string, string, int);
	Player& operator=(const Player&);
	Player(const Player&);
	void reading(istream&);
	void SetPointsPlayer(int);
	int GetPointsPlayer();
	friend ofstream& operator<<(ofstream&,const Player&);
	 void showingFile(ofstream&) const;
	~Player();

};
