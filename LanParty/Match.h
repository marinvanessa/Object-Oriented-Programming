#include"Team.h"
class Match {
	Team team1;
	Team team2;
	bool winner;

public:
	Match();
	Match(Team, Team);
	Match(const Match&);
	Match& operator=(const Match&);
	void reading(istream&);
	Team GetTeam1();
	Team GetTeam2();
	void SetTeam1(Team);
	void SetTeam2(Team);
	int PickTheWinner();
	void showingFile(ofstream&) const;
	void showingFileSecond(ofstream&) const;
	~Match();
};