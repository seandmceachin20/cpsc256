#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const unsigned int BUFFER_SIZE=80;
const unsigned int FIELDS = 5;

struct Song {
    char Field[FIELDS][BUFFER_SIZE] = {0};
    int FieldLength[FIELDS] = {0};
};

void displayMenu() {
    cout << "A) Load Existing Music File" << endl;
    cout << "B) Save Current List to File" << endl;
    cout << "C) Display Current List" << endl;
    cout << "D) Update Current List" << endl;
    cout << "E) Choose a Play List" << endl;
    cout << "F) Quit" << endl;
}

void displayList(Song *songList, int songPointer) {
    cout << "Displaying Current List:" << endl;
    cout << "Number of Songs = " << songPointer << endl;
    for (int j=0;j<songPointer;j++){
        for (int k=0;k<FIELDS;k++){
            if (k<(FIELDS-1)) {
                cout << songList[j].Field[k] << "|";
            }else{
                cout << songList[j].Field[k];
            }
        }
        cout << endl;
    }
    cout << endl;
}

int readSongFile(Song *songList, int songPointer) {

    char songInListFileName[] = "/Users/brash/CLionProjects/MusicMenu/songInList.txt";
    ifstream in(songInListFileName);
    cout << "Input File Status: " << in.is_open() << endl;

    char buffer;
    int field;
    int ipos;

    char delimiter[] = "|";
    char endOfLine[] = "\0";

    cout << "Loading Existing Song List from File" << endl;
    if (in.is_open()) {
        field = 0;
        ipos = 0;
        while (in.get(buffer)) {
            if (strcmp(&buffer, delimiter) == 0) {
                songList[songPointer].FieldLength[field] = ipos;
                songList[songPointer].Field[field][ipos] = '\0';
                field++;
                ipos = 0;
                //cout << "Delimiter match!!!!" << endl;
                //cout << songPointer << " " << field << " " << ipos << endl;
            } else {
                if (strcmp(&buffer, endOfLine) == 10) {
                    songList[songPointer].FieldLength[field] = ipos;
                    songList[songPointer].Field[field][ipos] = '\0';
                    field = 0;
                    ipos = 0;
                    songPointer++;
                    //cout << "End of entry" << endl;
                } else {
                    //cout << ipos << " " << buffer << " " << strcmp(&buffer, delimiter) << " "
                    //     << strcmp(&buffer, endOfLine) << endl;
                    songList[songPointer].Field[field][ipos] = buffer;
                    ipos++;
                }
            }
        }
        cout << "File read in ... Number of Songs = " << songPointer << endl;
        cout << endl;
    }

    in.close();
    return songPointer;
}

void writeSongFile(Song *songList, int songPointer) {

    char songOutListFileName[] = "/Users/brash/CLionProjects/MusicMenu/songOutList.txt";
    ofstream out(songOutListFileName);
    cout << "Output File Status: " << out.is_open() << endl;

    char buffer;
    int field;
    int ipos;

    char delimiter[] = "|";
    char endOfLine[] = "\0";

    cout << "Saving Existing Song List to File" << endl;
    if (out.is_open()) {
        field = 0;
        ipos = 0;
        for (int j=0;j<songPointer;j++){
            for (int k=0;k<FIELDS;k++){
                if (k<(FIELDS-1)) {
                    out << songList[j].Field[k] << "|";
                }else{
                    out << songList[j].Field[k];
                }
            }
            out << endl;
        }
        cout << endl;
        cout << "File  written ... Number of Songs = " << songPointer << endl;
        cout << endl;
    }

    out.close();
}

int updateList(Song *songList, int songPointer) {

    char buffer[BUFFER_SIZE];

    const char *message[5] = { "Enter the Artist Name: ", "Enter the Song Title: ",
                              "Enter the Song Type: ", "Enter the Task Type: ", "Enter the Song Link URL: " };

    cin.ignore();
    for (int k=0; k<FIELDS;k++) {
        cout << message[k];
        cin.getline(buffer, BUFFER_SIZE - 1, '\n');
        //cout << buffer << endl;
        strcat(songList[songPointer].Field[k], buffer);
        //cout << songList[songPointer].Field[k] << endl;
        songList[songPointer].FieldLength[k] = strlen(songList[songPointer].Field[k]);
        //cout << songList[songPointer].FieldLength[k] << endl;
    }

    songPointer++;

    return songPointer;
}

int createPlayList(Song *songList, int songPointer, Song *playList, int playPointer) {

    char buffer[BUFFER_SIZE];
    cout << "Enter the Task Key Word for Play List Creation: " << endl;
    cin.ignore();
    cin.getline(buffer,BUFFER_SIZE-1,'\n');
    cout << buffer << endl;

    for (int i=0; i<songPointer;i++) {
        if (strcmp(buffer, songList[i].Field[3])==0) {
            playList[playPointer] = songList[i];
            playPointer++;
        }
    }

    return playPointer;
}

int main() {

    int loopStatus = 0;
    char menuChoice[BUFFER_SIZE];

    Song songList[10];
    Song playList[10];

    int songPointer = 0;
    int playPointer = 0;

    int readStatus = 0;

    while (!loopStatus) {
        displayMenu();
        cin >> menuChoice;

        switch (menuChoice[0]) {
            case 'A':
            case 'a':
                if (readStatus == 0) {
                    songPointer = readSongFile(songList,songPointer);
                    readStatus = 1;
                } else {
                    cout << "File has aleady been read in!" << endl;
                }
                displayList(songList,songPointer);
                break;
            case 'B':
            case 'b':
                writeSongFile(songList,songPointer);
                break;
            case 'C':
            case 'c':
                displayList(songList,songPointer);
                break;
            case 'D':
            case 'd':
                cout << "Updating Song List" << endl;
                songPointer = updateList(songList,songPointer);
                displayList(songList,songPointer);
                break;
            case 'E':
            case 'e':
                cout << "Choose a Play List" << endl;
                playPointer = 0;
                playPointer = createPlayList(songList,songPointer,playList,playPointer);
                displayList(playList,playPointer);
                cout << endl;
                break;
            case 'F':
            case 'f':
                cout << "Quitting ... bye!" << endl;
                loopStatus = 1;
                break;
            default:
                cout << "Invalid input ... try again!" << endl;
                break;
        }
    }

    return 0;
}
