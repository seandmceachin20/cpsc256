#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const unsigned int BUFFER_SIZE=80;

struct Song {
    char Field[5][BUFFER_SIZE];
    int FieldLength[5];
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
        for (int k=0;k<5;k++){
            if (k<4) {
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
                cout << "Delimiter match!!!!" << endl;
                cout << songPointer << " " << field << " " << ipos << endl;
            } else {
                if (strcmp(&buffer, endOfLine) == 10) {
                    songList[songPointer].FieldLength[field] = ipos;
                    songList[songPointer].Field[field][ipos] = '\0';
                    field = 0;
                    ipos = 0;
                    songPointer++;
                    cout << "End of entry" << endl;
                } else {
                    cout << ipos << " " << buffer << " " << strcmp(&buffer, delimiter) << " "
                         << strcmp(&buffer, endOfLine) << endl;
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
            for (int k=0;k<5;k++){
                if (k<4) {
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

    char buffer[80];

    cout << "Enter the Artist Name: ";
    cin.ignore();
    cin.getline(buffer,79,'\n');
    strcat(songList[songPointer].Field[0],buffer);
    cout << songList[songPointer].Field[0] << endl;
    songList[songPointer].FieldLength[0]=strlen(songList[songPointer].Field[0]);

    cout << "Enter the Song Title: ";
    cin.getline(buffer,79,'\n');
    strcat(songList[songPointer].Field[1],buffer);
    cout << songList[songPointer].Field[1] << endl;
    songList[songPointer].FieldLength[1]=strlen(songList[songPointer].Field[1]);

    cout << "Enter the Song Type: ";
    cin.getline(buffer,79,'\n');
    strcat(songList[songPointer].Field[2],buffer);
    cout << songList[songPointer].Field[2] << endl;
    songList[songPointer].FieldLength[2]=strlen(songList[songPointer].Field[2]);

    cout << "Enter the Task Type ";
    cin.getline(buffer,79,'\n');
    strcat(songList[songPointer].Field[3],buffer);
    cout << songList[songPointer].Field[3] << endl;
    songList[songPointer].FieldLength[3]=strlen(songList[songPointer].Field[3]);

    cout << "Enter the Song Link URL: ";
    cin.getline(buffer,79,'\n');
    strcat(songList[songPointer].Field[4],buffer);
    cout << songList[songPointer].Field[4] << endl;
    songList[songPointer].FieldLength[4]=strlen(songList[songPointer].Field[4]);

    songPointer++;

    return songPointer;
}

int main() {

    int loopStatus = 0;
    char menuChoice[BUFFER_SIZE];

    char songOutListFileName[] = "/Users/brash/CLionProjects/MusicMenu/songOutList.txt";

    ofstream out(songOutListFileName);
    cout << "Output File Status: " << out.is_open() << endl;
    cout << endl;

    Song songList[10];

    int songPointer = 0;
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
                cout << "Function not implemented yet!" << endl;
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
