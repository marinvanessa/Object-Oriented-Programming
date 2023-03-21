#include<queue>
#include<stack>
#include<set>
#include"Match.h"
#include<bits/stdc++.h>
void showS(stack <Team> s, ofstream &output_file)
{
	while (!s.empty())
	{
		s.top().showingFileSecond(output_file);
		s.pop();
	}
}
void showq(queue<Match> q, ofstream& output_file)
{
	queue<Match> aux = q;
	while (!aux.empty()) {
		aux.front().showingFile(output_file);
		aux.pop();
	}
}
bool cmp(Team team1, Team team2){
	if (team1.GetTeamScore() != team2.GetTeamScore()){
		if(team1.GetTeamScore() > team2.GetTeamScore()){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if(team1.GetNameTeam() > team2.GetNameTeam()){
			return true;
		}
		else{
			return false;
		}
	}
}
int main(int argc, char *argv[]) {
	int NumberOfTeams, NumberOfDeletedTeams, OurNumber;
	Team team, SaveTeam;
	list<Team> my_list;
	int k = 0;
	double min;
	ifstream my_file;
	queue<Match> my_queue;
	Team first, second;
	stack<Team> winners;
	stack<Team> losers;
	Team first1, second1;
	my_file >> NumberOfTeams;
	list<Team> my_list_new;
	set<Team, greater<Team> > myTree;
	ifstream input_file;
	input_file.open(argv[2]);


	ofstream output_file;
	output_file.open(argv[3]);

	ifstream cerinte;
	cerinte.open(argv[1]);

	if(!input_file){
		output_file << "EROARE DE DESCHIDERE" << "\n";
		
	}

	if(!output_file){
		output_file << "EROARE DE DESCHIDERE" <<"\n";
		
	}

	input_file >> NumberOfTeams;
	for (int i = 0; i < 5; i++){
		int task;
		cerinte >> task;
		switch(i){
			case 0: {
	// // ===================================================Task 1==============================================================
				if (task == 1){
					for (int i = 0; i < NumberOfTeams; i++) {
						team.reading(input_file);
						my_list.push_front(team);
					}	
					for (auto it = my_list.begin(); it != my_list.end(); ++it) {
						it->showingFile(output_file);
					}
				}
				output_file.close();
				break;
			}
			case 1:{
	// // ===================================================Task 2==============================================================
				if(task == 1){
					output_file.open(argv[3], ios :: trunc);
					OurNumber = 2;
					while (OurNumber <= NumberOfTeams) {
						OurNumber <<= 1;
					}
					OurNumber >>= 1;
					NumberOfDeletedTeams = NumberOfTeams - OurNumber;
					while (k < NumberOfDeletedTeams) {
							min = 1000;
							for (auto it = my_list.begin(); it != my_list.end(); ++it) {
								if (it->GetTeamPoints() < min) {
									min = it->GetTeamPoints();
								}
							}
							for (auto it = my_list.begin(); it != my_list.end(); ++it) {
								if (it->GetTeamPoints() == min) {
									it = my_list.erase(it);
									--it;
									k++;
								}
								if (k == NumberOfDeletedTeams) {
									break;
								}
							}
					}
					for (auto it = my_list.begin(); it != my_list.end(); ++it) {
						it->showingFile(output_file);
					}
				}
				output_file.close();
				break;
			}
			case 2:{
	// // ===================================================Task 3==============================================================
				if (task == 1){
					output_file.open(argv[3], ios :: trunc);
					for (auto it = my_list.begin(); it != my_list.end(); ++it) {
						it->showingFile(output_file);
					}
					int round = 1;
					for (auto it = my_list.begin(); it != my_list.end(); it++) {
						first = *it;
						second = *(++it);
						Match match(first, second);
						my_queue.push(match);

					}
					output_file << '\n';
					output_file << "--- ROUND NO:" << round << '\n';
					round += 1;
					
					showq(my_queue, output_file);

					while (true) {
						while (!my_queue.empty()) {
							if ((my_queue.front().PickTheWinner() == 1)) {
								winners.push(my_queue.front().GetTeam1());
								losers.push(my_queue.front().GetTeam2());
							}
							else{
								winners.push(my_queue.front().GetTeam2());
								losers.push(my_queue.front().GetTeam1());
							}
							my_queue.pop();
						}
						while (!losers.empty()) {
							losers.pop();
						}
						output_file << '\n';
						
						output_file << "WINNERS OF ROUND NO:" << round - 1 << '\n';
						showS(winners, output_file);
						if (winners.size() == 8) {
							stack<Team> aux = winners;
							while (!aux.empty()) {
								my_list_new.push_back(aux.top());
								aux.pop();
							}
						}
						if (winners.size() == 1) {
							winners.pop();
							break;
						}else{
								output_file << '\n';
								output_file << "--- ROUND NO:" << round << '\n';
						}
						while (!winners.empty()) {
							first1 = winners.top();
							winners.pop();
							second1 = winners.top();
							winners.pop();
							Match match_second(first1, second1);
							match_second.showingFile(output_file);
							my_queue.push(match_second);
						}
					
						round++;
					}

				}
				break;
			} 
			case 3:{
	// // ===================================================Task 4==============================================================
				if (task == 1){
					output_file << '\n';
					output_file << "TOP 8 TEAMS:" <<'\n';
					for (auto itrt = my_list_new.begin(); itrt != my_list_new.end(); itrt++){
						myTree.insert(*itrt);
					}
					for(auto itrt = myTree.begin(); itrt != myTree.end(); ++ itrt){
						itrt->showingFileSecond(output_file);
					}
					
				}
				break;
			}
			case 4:{
	// // ===================================================Task 5==============================================================
				if (task == 1){
					output_file << '\n';
					output_file << "THE LEVEL 2 TEAMS ARE:" << '\n'; 
					vector<Team> vect;
					for(auto itrt = myTree.begin(); itrt != myTree.end(); ++ itrt){
						vect.push_back(*itrt);
					}
					output_file << vect.at(0);
					output_file << vect.at(2);
					output_file << vect.at(4);
					output_file << vect.at(6);

				}
				break;
			}
	} 
	
} 
output_file.close();
input_file.close();
cerinte.close();
} 
	
	
	
	