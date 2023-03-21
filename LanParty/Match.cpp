#include"Match.h"
Match::Match() {
	;
}
Match::Match(Team team1_new, Team team2_new) {
	team1 = team1_new;
	team2 = team2_new;
}
Match::Match(const Match& match_new) {
	team1 = match_new.team1;
	team2 = match_new.team2;
}
Match& Match::operator=(const Match& match_new1) {
	team1 = match_new1.team1;
	team2 = match_new1.team2;
	return *this;
}
void Match::reading(istream& in) {
	team1.reading(in);
	team2.reading(in);
}
Team Match::GetTeam1() {
	return team1;
}
Team Match::GetTeam2() {
	return team2;
}
int Match::PickTheWinner(){
	if (team1.GetTeamPoints() > team2.GetTeamPoints()) {
		team1.UpdateScore();
		return 1;
	}
	else
	{
		team2.UpdateScore();
		return 2;
	}
}
void Match:: showingFileSecond(ofstream& fout) const{
    fout.width(33); fout << left << team1.GetNameTeam();
	fout.width(1); fout << '-';
	fout.width(33); fout << right << team2.GetNameTeam();
	fout << '\n';

}
void Match:: showingFile(ofstream& fout) const{
	fout.width(33); fout << left << team1.GetNameTeam();
	fout.width(1); fout << '-';
	fout.width(33); fout << right << team2.GetNameTeam();
	fout << '\n';
}
void Match::SetTeam1(Team new_team1) {
	team1 = new_team1;
}
void Match::SetTeam2(Team new_team2) {
	team2 = new_team2;
}
Match::~Match() {
	;
}