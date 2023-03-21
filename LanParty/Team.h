#include"Player.h"
class Team {
    int NumberOfPlayers;
    string NameTeam;
    Player* players;
    double TeamPoints;

public:
    Team();
    Team(int, string, Player*, double);
    Team& operator=(const Team&);
    Team(const Team&);
    void reading(istream&);
    void RemoveWhiteSpaces();
    double GetTeamPoints() const;
    string GetNameTeam() const;
    double GetTeamScore() const;
    void SetTeamScore(double);
    void UpdateScore();
    void showingFile(ofstream&) const;
    void showingFileSecond(ofstream&) const;
    friend bool operator<(const Team&, const Team&);
    friend bool operator>(const Team&, const Team&);
    friend ofstream& operator<<(ofstream&,const Team&);
    ~Team();

};
