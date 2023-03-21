#include"Team.h"
#include<iomanip>
Team::Team()
{
    NumberOfPlayers = 0;
    NameTeam = "";
    players = NULL;
    TeamPoints = 0;
}
Team::Team(int NumberOfPlayers1, string NameTeam1, Player* players1, double TeamPoints1)
{
    NumberOfPlayers = NumberOfPlayers1;
    NameTeam = NameTeam1;
    players = new Player[NumberOfPlayers1];
    for (int i = 0; i < NumberOfPlayers1; i++)
    {
        players[i] = players1[i];
    }
    TeamPoints = TeamPoints1;
}
Team::Team(const Team& team_new)
{
    NumberOfPlayers = team_new.NumberOfPlayers;
    NameTeam = team_new.NameTeam;
    players = new Player[team_new.NumberOfPlayers];
    for (int i = 0; i < team_new.NumberOfPlayers; i++)
    {
        players[i] = team_new.players[i];
    }
    TeamPoints = team_new.TeamPoints;
}
Team& Team::operator=(const Team& team_new1)
{
    NumberOfPlayers = team_new1.NumberOfPlayers;
    NameTeam = team_new1.NameTeam;
    players = new Player[team_new1.NumberOfPlayers];
    for (int i = 0; i < team_new1.NumberOfPlayers; i++)
    {
        players[i] = team_new1.players[i];
    }
    TeamPoints = team_new1.TeamPoints;
    return *this;
}
void Team::reading(istream& in)
{
    in >> NumberOfPlayers;
    getline(in, NameTeam, '\n');
    while(NameTeam[NameTeam.size() - 1] == ' ')
        NameTeam = NameTeam.substr(0, NameTeam.size() - 1);
    while(NameTeam[0] == ' ')
        NameTeam = NameTeam.substr(1, NameTeam.size());
    players = new Player[NumberOfPlayers];
    for (int i = 0; i < NumberOfPlayers; i++)
    {
        players[i].reading(in);
    }
    this -> TeamPoints = GetTeamPoints();
}
void Team::RemoveWhiteSpaces(){

}
void Team:: UpdateScore(){
    for(int i = 0; i < NumberOfPlayers; i++){
        players[i].SetPointsPlayer((players[i].GetPointsPlayer() + 1));
    }
}
void Team:: showingFile(ofstream& fout) const{
     fout << NameTeam << '\n';

}
void Team:: showingFileSecond(ofstream& fout) const{
    fout.width(34); fout << left << NameTeam;
    fout << '-';
    fout << "  ";
    fout << fixed;
    fout << setprecision(2);
    fout << this->GetTeamPoints();
    fout << '\n';
}
double Team::GetTeamPoints() const
{
    float sum = 0;
    for (int i = 0; i < NumberOfPlayers; i++)
    {
        sum = sum + players[i].GetPointsPlayer();

    }
    return (double)(sum / NumberOfPlayers);
}
double Team::GetTeamScore() const {
    return TeamPoints;
}
void Team::SetTeamScore(double value) {
    TeamPoints = value;
}
string Team::GetNameTeam() const{
    return NameTeam;
}
bool operator<(const Team& team1, const Team& team2){
    if(team1.GetTeamScore() < team2.GetTeamScore()){
        return 1;
    }
    else{
        return 0;
    }
}
bool operator>(const Team& team1, const Team& team2){
    if(team1.GetTeamScore() != team2.GetTeamScore()){
        if(team1.GetTeamScore() > team2.GetTeamScore()){
            return 1;
        }
        else {
            return 0;
        }
    }else{
        if(team1.GetNameTeam() > team2.GetNameTeam()){
            return 1;
        }
        else{
            return 0;
        }
    }
  
}
ofstream& operator<<(ofstream& fout, const Team& team){
     fout << team.NameTeam << '\n';
     return fout;
}
Team::~Team()
{
    if (players != NULL)
    {
        delete[] players;
    }
}
