/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Artist.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
Artist::Artist() {
   artistName = "";
   birthYear = 0;
   deathYear = 0;
}

// TODO: Define second constructor to initialize
//       private fields (artistName, birthYear, deathYear)
Artist::Artist(string artistName, int birthYear, int deathYear) {
   this->artistName = artistName;
   this->birthYear = birthYear;
   this->deathYear = deathYear;
}

// TODO: Define get functions: GetName(), GetBirthYear(), GetDeathYear()
string Artist::GetName() const {
   return artistName;
}

// TODO: Define PrintInfo() function
//      If deathYear is entered as -1, only print birthYear
void Artist::PrintInfo() const {
   cout << "Artist: " << artistName << " (";
   if (birthYear != -1) {
       cout << birthYear << " to ";
       if (deathYear != -1) {
           cout << deathYear;
       } else {
           cout << "present";
       }
   } else {
       cout << "unknown";
   }
   cout << ")" << endl;
}
