//
// Created by Edward Brash on 5/15/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const unsigned int BUFFER_SIZE = 80;
const char delimiter1[] = ",";
const char delimiter2[] = "/";

struct PlayerData {
    char Name[80];
    int Year;
    int Month;
    int Day;
    int Points;
};

int readData(struct PlayerData *myPlayers, int playerPointer){

    char playerDataFileName[] = "/Users/brash/CLionProjects/BasketBallScoresInC/test.csv";
    FILE * in;
    in = fopen(playerDataFileName,"r");

    if (in == NULL) {
        printf("Failed to open file!  Quitting read ... \n");
        return -1;
    } else {
        printf("Opened %s for reading ... \n",playerDataFileName);
    }

    /* Read the data into the myPlayers data structure */

    char line[BUFFER_SIZE], field[BUFFER_SIZE], field2[BUFFER_SIZE];

    while (fgets(line,BUFFER_SIZE,in) != NULL) {

        /* printf("%s",line); */

        char *running = strdup(line);
        char *token;
        int field_id = 0;

        token = strsep(&running,delimiter1);
        /* printf("Token1 = %s \n", token); */
        strcpy(myPlayers[playerPointer].Name,token);
        token = strsep(&running,delimiter2);
        /* printf("Token2 = %s \n", token); */
        myPlayers[playerPointer].Month=atoi(token);
        token = strsep(&running,delimiter2);
        /* printf("Token3 = %s \n", token); */
        myPlayers[playerPointer].Day=atoi(token);
        token = strsep(&running,delimiter1);
        /* printf("Token4 = %s \n", token); */
        myPlayers[playerPointer].Year=atoi(token);
        token = strsep(&running,delimiter1);
        /* printf("Token5 = %s \n", token); */
        myPlayers[playerPointer].Points=atoi(token);

        playerPointer++;
    }

    fclose(in);

    return playerPointer;
}

void displayData(struct PlayerData *myPlayers, int playerPointer) {
    int i;
    printf("      Name            Month           Day            Year           Points \n");
    for (i=0;i<playerPointer;i++) {
        printf("      %s            %d            %d            %d            %d \n",myPlayers[i].Name,myPlayers[i].Month,
               myPlayers[i].Day,myPlayers[i].Year,myPlayers[i].Points);
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


void calculateAveragePoints(struct PlayerData *myPlayers, int playerPointer) {

    char playerNameWithReturn[BUFFER_SIZE];
    char startDateWithReturn[BUFFER_SIZE];
    char endDateWithReturn[BUFFER_SIZE];

    char playerName[BUFFER_SIZE];
    char startDate[BUFFER_SIZE];
    char endDate[BUFFER_SIZE];

    printf(" \n");

    printf ("Enter the player name: ");
    fgets(playerNameWithReturn,BUFFER_SIZE,stdin);
    printf("Enter the start date (D/M/Y): ");
    fgets(startDateWithReturn,BUFFER_SIZE,stdin);
    printf("Enter the end date (D/M/Y): ");
    fgets(endDateWithReturn,BUFFER_SIZE,stdin);

    //printf(":%s:\n",strtok(playerNameWithReturn,"\n"));
    strcpy(playerName,strtok(playerNameWithReturn, "\n"));
    strcpy(startDate,strtok(startDateWithReturn, "\n"));
    strcpy(endDate,strtok(endDateWithReturn, "\n"));

    int sy,sm,sd;
    int ey,em,ed;
    char *tokens;
    char *tokene;

    char *runnings = strdup(startDate);
    char *runninge = strdup(endDate);

    tokens = strsep(&runnings,delimiter2);
    sm=atoi(tokens);
    tokens = strsep(&runnings,delimiter2);
    sd=atoi(tokens);
    tokens = strsep(&runnings,delimiter2);
    sy=atoi(tokens);

    printf ("Start Date: %d %d %d \n",sm,sd,sy);

    tokene = strsep(&runninge,delimiter2);
    em=atoi(tokene);
    tokene = strsep(&runninge,delimiter2);
    ed=atoi(tokene);
    tokene = strsep(&runninge,delimiter2);
    ey=atoi(tokene);

    printf ("End Date Date: %d %d %d \n",em,ed,ey);

    int totalPoints = 0;
    int totalGames = 0;
    float averagePoints;
    int i;

    for (i=0; i<playerPointer;i++) {

        int startDateCompare;
        int endDateCompare;

        /* printf(":%s:%s:     %d %d %d    %d %d %d   %d %d %d  \n",myPlayers[i].Name,playerName,
               myPlayers[i].Year,sy,ey,myPlayers[i].Month,sm,em,myPlayers[i].Day,sd,ed); */

        if (strcmp(myPlayers[i].Name,playerName)==0) {

            startDateCompare = compare_dates(myPlayers[i].Month,myPlayers[i].Day,myPlayers[i].Year,sm,sd,sy);
            endDateCompare = compare_dates(myPlayers[i].Month,myPlayers[i].Day,myPlayers[i].Year,em,ed,ey);

            /* printf("%d %d\n",startDateCompare,endDateCompare); */

            if (startDateCompare >= 0 && endDateCompare <= -0) {
                printf("Name: %s  Date:  %d/%d/%d   Points: %d \n",myPlayers[i].Name,myPlayers[i].Month,
                           myPlayers[i].Day,myPlayers[i].Year,myPlayers[i].Points);
                totalPoints = totalPoints + myPlayers[i].Points;
                totalGames = totalGames + 1;
            }
        }
    }

    printf(" \n");

    if (totalGames > 0) {
        averagePoints = 1.0*totalPoints/totalGames;
        printf("From %s to %s, %s averaged %f points per game.\n",startDate,endDate,playerName,averagePoints);
    } else {
        printf("No games in this date range! \n");
    }
}

int main() {

    struct PlayerData myPlayers[100];
    int playerPointer = 0;

    playerPointer = readData(myPlayers,playerPointer);
    printf("Number of lines read in = %d \n",playerPointer);

    displayData(myPlayers,playerPointer);

    calculateAveragePoints(myPlayers,playerPointer);

    return 0;

}


