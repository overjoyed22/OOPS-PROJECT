#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Abstract class for a player
class Player {
protected:
    string name;
    int age;
public:
    Player(string _name, int _age) : name(_name), age(_age) {}
    virtual void display() = 0; // Pure virtual function for abstraction
    virtual string getData() = 0; // Pure virtual function to get player data
    virtual void updateData(int newData) = 0; // Pure virtual function to update player data
};

// Class for a batsman
class Batsman : public Player {
private:
    int runsScored;
public:
    Batsman(string _name, int _age, int _runsScored) : Player(_name, _age), runsScored(_runsScored) {}

    void display() override {
        cout << "Name: " << name << ", Age: " << age << ", Runs Scored: " << runsScored << endl;
    }

    string getData() override {
        return "Batsman," + name + "," + to_string(age) + "," + to_string(runsScored);
    }

    void updateData(int newData) override {
        runsScored += newData;
    }
};

// Class for a bowler
class Bowler : public Player {
private:
    int wicketsTaken;
public:
    Bowler(string _name, int _age, int _wicketsTaken) : Player(_name, _age), wicketsTaken(_wicketsTaken) {}

    void display() override {
        cout << "Name: " << name << ", Age: " << age << ", Wickets Taken: " << wicketsTaken << endl;
    }

    string getData() override {
        return "Bowler," + name + "," + to_string(age) + "," + to_string(wicketsTaken);
    }

    void updateData(int newData) override {
        wicketsTaken += newData;
    }
};

// Class for a cricket team
class CricketTeam {
private:
    string teamName;
    vector<Player*> players;
public:
    CricketTeam(string _teamName) : teamName(_teamName) {}

    void addPlayer(Player* player) {
        players.push_back(player);
    }

    void displayPlayers() {
        cout << "Players in team " << teamName << ":" << endl;
        for (Player* player : players) {
            player->display();
        }
    }

    void updatePlayersData() {
        for (Player* player : players) {
            int newData;
            cout << "Enter last match data for  " << player->getData() << ": ";
            cin >> newData;
            player->updateData(newData);
        }
        cout << "Player data updated successfully." << endl;
    }

    void saveToFile() {
        ofstream outFile(teamName + "_players.txt", ios::app); // Append mode
        if (outFile.is_open()) {
            for (Player* player : players) {
                outFile << player->getData() << endl;
            }
            outFile.close();
            cout << "Player data updated and saved to " << teamName << "_players.txt" << endl;
        } else {
            cout << "Unable to open file to save player data." << endl;
        }
    }
};

int main() {
    cout << "*****************WELCOME TO CRICKET TEAM MANAGEMENT SYSTEM******************" << endl;
   cout << " Data of all the players till last matched is given below" << endl;

    // Creating instances of players
    Batsman batsman1("Virat Kohli", 32, 12000);
    Batsman batsman2("Rohit Sharma", 34, 10000);
    Batsman batsman3("Shikhar Dhawan", 31, 11300);
    Batsman batsman4("Yuvraj Singh", 41, 12308);
    Batsman batsman5("MS Dhoni",42 , 15000);
    Batsman batsman6("Hardik Pandya",30 ,5000);
    Batsman batsman7("Ravindra Jadeja",32 , 9000);
    Bowler bowler1("Jasprit Bumrah", 28, 200);
    Bowler bowler2("Ravichandran Ashwin", 35, 600);
    Bowler bowler3("Bhuvaneshwar Kumar", 35, 500);
    Bowler bowler4("Kuldeep Jadav", 26, 100);
    // Creating a cricket team
    CricketTeam indiaTeam("India");
    indiaTeam.addPlayer(&batsman1);
    indiaTeam.addPlayer(&batsman2);
    indiaTeam.addPlayer(&batsman3);
    indiaTeam.addPlayer(&batsman4);
    indiaTeam.addPlayer(&batsman5);
    indiaTeam.addPlayer(&batsman6);
    indiaTeam.addPlayer(&batsman7);
    indiaTeam.addPlayer(&bowler1);
    indiaTeam.addPlayer(&bowler2);
    indiaTeam.addPlayer(&bowler3);
    indiaTeam.addPlayer(&bowler4);
    // Displaying players of the team
    indiaTeam.displayPlayers();
    cout << endl;
    cout << "Now we can update data of each player after a match" << endl;
    // Updating player data after a match
    cout << "Enter match data for players:" << endl;
    indiaTeam.updatePlayersData();
   
    cout << "The updated data of all players:" << endl;
    indiaTeam.displayPlayers();
    // Saving updated player data to file
    indiaTeam.saveToFile();
}
