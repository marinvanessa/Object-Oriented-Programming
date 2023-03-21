#include"Player.h"
Player::Player() {
	firstName = "0";
	secondName = "0";
	points = 0;
}
Player::Player(string firstNameNew, string secondNameNew, int pointsNew) {
	firstName = firstNameNew;
	secondName = secondNameNew;
	points = pointsNew;
}
Player::Player(const Player& player_new) {
	firstName = player_new.firstName;
	secondName = player_new.secondName;
	points = player_new.points;
}
Player& Player::operator=(const Player& player_new1) {
	firstName = player_new1.firstName;
	secondName = player_new1.secondName;
	points = player_new1.points;
	return *this;
}
void Player::reading(istream& in) {
	getline(in, firstName, ' ');
	getline(in, secondName, ' ');
	string s;
	getline(in, s, '\n');
	stringstream s1(s);
	s1 >> points;
}
ofstream& operator<<(ofstream& fout,const Player& player){
	fout << player.firstName << " ";
	fout << player.secondName << " ";
	fout << player.points << endl;
	return fout;
}
void Player:: showingFile(ofstream& fout) const{
	fout << firstName << ' ';
	fout << secondName << ' ';
	fout << points << '\n';
}
void Player::SetPointsPlayer(int points1){
	points = points1;
}
int Player::GetPointsPlayer()
{
	return points;
}
Player::~Player() {
	;
}

