#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct PlayerData {
    string Name = {0};
    int Year = {0};
    int Month = {0};
    int Day = {0};
    int Points = {0};
};

int readData(PlayerData *myPlayers, int playerPointer){

    char playerDataFileName[] = "/Users/brash/CLionProjects/BasketBallScores/test.csv";
    ifstream in(playerDataFileName);
    cout << "Input File Status: " << in.is_open() << endl;

    // Read the data into the myPlayers data structure

    string line, field, field2;

    while (getline(in,line)) {

        stringstream ss(line);
        int field_id = 0;

        while (getline(ss, field, ',')) {
            if (field_id==0) {
                //cout << field_id << " " << field << endl;
                myPlayers[playerPointer].Name=field;
            }
            if (field_id==1) {
                stringstream ss2(field);
                int date_id = 0;
                while (getline(ss2,field2,'/')) {
                    //cout << date_id << " " << field2 << endl;
                    if (date_id==0) myPlayers[playerPointer].Month=stoi(field2);
                    if (date_id==1) myPlayers[playerPointer].Day=stoi(field2);
                    if (date_id==2) myPlayers[playerPointer].Year=stoi(field2);
                    date_id++;
                }
            }
            if (field_id==2) {
                //cout << field_id << " " << field << endl;
                myPlayers[playerPointer].Points=stoi(field);
            }
            field_id++;
        }

        playerPointer++;

    }

    return playerPointer;
}

void displayData(PlayerData *myPlayers, int playerPointer) {
    cout << setw(20) << "Name" << setw(10) << "Month" <<  setw(10) << "Day" << setw(10) <<
        "Year" << setw(10) << "Points" << endl;
    for (int i=0;i<playerPointer;i++) {
        cout << setw(20) << myPlayers[i].Name << setw(10) << myPlayers[i].Month <<  setw(10) << myPlayers[i].Day << setw(10) <<
                    myPlayers[i].Year << setw(10) << myPlayers[i].Points << endl;
    }
}

void calculateAveragePoints(PlayerData *myPlayers, int playerPointer) {

    string playerName, startDate, endDate;

    cout << endl;

    cout << "Enter the player name: " << endl;
    getline(cin, playerName);
    cout << "Enter the start date (D/M/Y): " << endl;
    getline(cin, startDate);
    cout << "Enter the end date (D/M/Y): " << endl;
    getline(cin, endDate);

    stringstream ss2(startDate);
    string field2;
    int sd,sm,sy;
    int date_id = 0;
    while (getline(ss2,field2,'/')) {
        //cout << date_id << " " << field2 << endl;
        if (date_id==0) sm=stoi(field2);
        if (date_id==1) sd=stoi(field2);
        if (date_id==2) sy=stoi(field2);
        date_id++;
    }

    stringstream ss3(endDate);
    int ed,em,ey;
    date_id = 0;
    while (getline(ss3,field2,'/')) {
        //cout << date_id << " " << field2 << endl;
        if (date_id==0) em=stoi(field2);
        if (date_id==1) ed=stoi(field2);
        if (date_id==2) ey=stoi(field2);
        date_id++;
    }

    //cout << sm << " " << sd << " " << sy << endl;
    //cout << em << " " << ed << " " << ey << endl;

    cout << "Searching for " << playerName << " starting at " << startDate << " and ending at " << endDate << endl;
    cout << endl;

    int totalPoints = 0;
    int totalGames = 0;
    float averagePoints;

    for (int i=0; i<playerPointer;i++) {

        if (myPlayers[i].Name == playerName) {
            if (myPlayers[i].Year >= sy && myPlayers[i].Month >= sm && myPlayers[i].Day >= sd) {
                if (myPlayers[i].Year <= ey && myPlayers[i].Month <= em && myPlayers[i].Day <= ed) {
                    cout << "Name: " << myPlayers[i].Name << " Date: " << myPlayers[i].Month << "/"
                        << myPlayers[i].Day << "/" << myPlayers[i].Year << " Points: " << myPlayers[i].Points << endl;
                    totalPoints = totalPoints + myPlayers[i].Points;
                    totalGames = totalGames + 1;
                 }
            }
        }

    }

    cout << endl;

    if (totalGames > 0) {
        averagePoints = 1.0*totalPoints/totalGames;
        cout << "From " << startDate << " to " << endDate << ", " << playerName << " averaged " << averagePoints << " points per game." << endl;
    } else {
        cout << "No games in this date range! " << endl;
    }
}

int main() {

    PlayerData myPlayers[100];
    int playerPointer = 0;

    playerPointer = readData(myPlayers,playerPointer);
    cout << "Number of lines read in = " << playerPointer << endl;

    displayData(myPlayers,playerPointer);

    calculateAveragePoints(myPlayers,playerPointer);

    return 0;
}
