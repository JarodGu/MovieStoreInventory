// ------------- driver.cpp ------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 3/9/19
// Last Modified 3/9/19
// -------------------------------------------------------------------------
// Driver file for the Movie inventory system
// -------------------------------------------------------------------------
// Creates a Store class and performs commands based on file input
// -------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

#include "store.h"

using namespace std;

int main()
{
    // Variables
    char delim = ',';

    // Part 1: Populate movie inventory from data4movies.txt
    ifstream infile1("data4movies.txt");
    if (!infile1)
    {
        cout << "data4movies.txt not found." << endl;
        return 1;
    }

    char movieCmd;
    string info;

    while(!infile1.eof())
    {
        vector<string> tokens; // Create vector to hold info about a movie to be added
        movieCmd = infile1.get();
        getline(infile1,info);

        if (info[info.size() - 1] == '\r') // trim \r from string
            info.resize(info.size() - 1);

        istringstream ss(info);
        string token;

        // Tokenize input
        getline(ss, token, delim);
        while(getline(ss, token, delim))
        {
            token.erase(0, 1); // erase extra space at start
            tokens.push_back(token);
        }

        if(movieCmd == 'F') // add comedy movie
        {
            int stock = stoi(tokens[0]);
            int year = stoi(tokens[3]);

            //Store.addMovie('F', stock, tokens[1], tokens[2], year);
        }
        else if(movieCmd == 'D') // add drama movie
        {
            int stock = stoi(tokens[0]);
            int year = stoi(tokens[3]);

            //Store.addMovie('D', stock, tokens[1], tokens[2], year);
        }
        else if(movieCmd == 'C') // add classical movie
        {
            // split tokens[3] into actorFirst, actorLast, month, and year
            string actorFirst = "";
            string actorLast = "";
            string sMonth = "";
            string sYear = "";

            istringstream sss(tokens[3]);

            getline(sss, actorFirst, ' ');
            getline(sss, actorLast, ' ');
            getline(sss, sMonth, ' ');
            getline(sss, sYear, ' ');

            int stock = stoi(tokens[0]);
            int month = stoi(sMonth);
            int year = stoi(sYear);

            //Store.addMovie('C', stock, tokens[1], tokens[2], actorFirst, actorLast, month, year);
        } else {
            cout << "Error: Invalid movie code" << endl;
        }
    }

    // Part 2: Populate customer hash table from data4customers.txt





    // Part 3: Perform commands on the store from data4commands.txt
    //          'B' = Borrow movie
    //          'R' = Return movie
    //          'I' = Output inventory
    //          'H' = Output customer's transaction history




    return 0;
}