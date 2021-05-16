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

int compare_dates(int m1,int d1,int y1,int m2,int d2,int y2) {

    if (y1 < y2) {
        return -1;
    } else {
        if (y1 > y2) {
            return 1;
        }
    }

    if (y1 == y2) {
        if (m1 < m2) {
            return -1;
        } else {
            if (m1 > m2) {
                return 1;
            } else {
                if (d1 < d2) {
                    return -1;
                } else {
                    if (d1 > d2) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    }

    return -2; /* should never get here! */
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

    cout << endl;

    cout << setw(20) << "Name" << setw(10) << "Month" <<  setw(10) << "Day" << setw(10) <<
         "Year" << setw(10) << "Points" << endl;

    for (int i=0; i<playerPointer;i++) {

        int startDateCompare;
        int endDateCompare;

        if (myPlayers[i].Name == playerName) {
            startDateCompare = compare_dates(myPlayers[i].Month,myPlayers[i].Day,myPlayers[i].Year,sm,sd,sy);
            endDateCompare = compare_dates(myPlayers[i].Month,myPlayers[i].Day,myPlayers[i].Year,em,ed,ey);

            if (startDateCompare >= 0 && endDateCompare <= -0) {
                    cout << setw(20) << myPlayers[i].Name << setw(10) << myPlayers[i].Month <<  setw(10) << myPlayers[i].Day << setw(10) <<
                         myPlayers[i].Year << setw(10) << myPlayers[i].Points << endl;
                    totalPoints = totalPoints + myPlayers[i].Points;
                    totalGames++;
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
