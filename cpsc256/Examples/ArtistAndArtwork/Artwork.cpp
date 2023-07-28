/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Artwork.h"
#include <iostream>

// Define default constructor
Artwork::Artwork() {
   title = "";
   yearCreated = 0;
}

// TODO: Define second constructor to initialize
//       private fields (title, yearCreated, artist)
Artwork::Artwork(string title, int yearCreated, Artist artist) {
   this->title = title;
   this->yearCreated = yearCreated;
   this->artist = artist;
}

// TODO: Define get functions: GetTitle(), GetYearCreated()
string Artwork::GetTitle() {
   return title;
}

int Artwork::GetYearCreated() {
   return yearCreated;
}

// TODO: Define PrintInfo() function
//       Call the PrintInfo() function in the Artist class to print an artist's information
void Artwork::PrintInfo() {
    artist.PrintInfo();
    cout << "Title: " << title << ", ";
    cout << yearCreated << endl;
}