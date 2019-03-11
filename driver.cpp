// ------------- driver.cpp ------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 3/9/19
// Last Modified 3/10/19
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
    ifstream infile2("data4customers.txt");
    if (!infile2)
    {
        cout << "data4customers.txt not found." << endl;
        return 1;
    }

    while(!infile2.eof())
    {
        vector<string> tokens; // Create vector to hold info about customer to be added
        getline(infile2,info);

        if (info[info.size() - 1] == '\r') // trim \r from string
            info.resize(info.size() - 1);

        istringstream ss(info);
        string token;

        // Tokenize input
        while(getline(ss, token, ' '))
        {
            tokens.push_back(token);
        }

        int custID = stoi(tokens[0]);
        string custLast = tokens[1];
        string custFirst = tokens[2];

        //Store.addCustomer(custID, custLast, custFirst);
    }

    // Part 3: Perform commands on the store from data4commands.txt
    //          'B' = Borrow movie
    //          'R' = Return movie
    //          'I' = Output inventory
    //          'H' = Output customer's transaction history
    ifstream infile3("data4commands.txt");
    if (!infile3)
    {
        cout << "data4commands.txt not found." << endl;
        return 1;
    }

    char storeCmd;
    while(!infile3.eof())
    {
        vector<string> tokens; // Create vector to hold info about a movie to be added
        storeCmd = infile3.get();
        getline(infile3,info);

        if (info[info.size() - 1] == '\r') // trim \r from string
            info.resize(info.size() - 1);

        istringstream ss(info);
        string token;

        // Tokenize input
        getline(ss, token, ' ');
        while(getline(ss, token, ' '))
        {
            //token.erase(0, 1); // erase extra space at start
            tokens.push_back(token);
        }

        if(storeCmd == 'B') // Borrow movie
        {
            //Store.Borrow
        }
        else if(storeCmd == 'R') // Return movie
        {
            //Store.Return
        }
        else if(storeCmd == 'I') // Output inventory
        {
            //Store.getInventory();
        }
        else if(storeCmd == 'H') // Output customer's transaction history
        {
            //Store.History
        } else {
            cout << "Error: Invalid command code" << endl;
        }
    }

    return 0;
}