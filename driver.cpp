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
    Store BlockBuster;

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
        getline(ss, token, ',');
        while(getline(ss, token, ','))
        {
            token.erase(0, 1); // erase extra space at start
            tokens.push_back(token);
        }

        if(movieCmd == 'F') // add comedy movie
        {
            int stock = stoi(tokens[0]);
            int year = stoi(tokens[3]);

            BlockBuster.AddMovie('F', stock, tokens[1], tokens[2], year);
        }
        else if(movieCmd == 'D') // add drama movie
        {
            int stock = stoi(tokens[0]);
            int year = stoi(tokens[3]);

            BlockBuster.AddMovie('D', stock, tokens[1], tokens[2], year);
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

            BlockBuster.AddClassicMovie(stock, tokens[1], tokens[2], actorFirst, actorLast, month, year);
        } else {
            cout << "Error: Invalid movie code" << endl;
        }
    }

    cout << "Done reading in movies" << std::endl;

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
        if (info == "") break; // Reached end
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

        BlockBuster.AddCustomer(custID, custLast, custFirst);
    }

    cout << "Done reading in customers" << std::endl;

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

        getline(infile3, info); // Get whole line
        if (info[info.size() - 1] == '\r') // trim \r from string
            info.resize(info.size() - 1);

        if (storeCmd == 'I') // Output inventory
        {
            BlockBuster.getInventory();
        }
            // Borrow movie
        else if (storeCmd == 'B')
        {
            // Parse
            istringstream ss(info);
            string token;

            getline(ss, token, ' '); // Blank

            getline(ss, token, ' '); // CustID
            tokens.push_back(token);
            int custID = stoi(tokens[0]);

            getline(ss, token, ' '); // Media Type
            tokens.push_back(token);
            char mediaType = tokens[1][0];

            getline(ss, token, ' '); // Genre
            tokens.push_back(token);
            char genre = tokens[2][0];

            if (genre == 'F')
            {
                // Parse comedy
                getline(ss, token, ','); // Get movie title
                tokens.push_back(token);

                getline(ss, token, ','); // Get release year
                tokens.push_back(token);
                int releaseYear = stoi(tokens[4]);

                // Make a movie from the info
                NodeData *pMovie = nullptr;
                if (BlockBuster.findComedy(tokens[3], releaseYear, pMovie))
                {
                    BlockBuster.Borrow(custID, pMovie->getData());
                } else
                { // Movie not found
                    cout << "Error: Movie does not exist" << endl;
                }
            } else if (genre == 'D') // Drama
            {
                // Parse drama
                getline(ss, token, ','); // Get director
                tokens.push_back(token);

                getline(ss, token, ' '); // blank
                getline(ss, token, ','); // Get movie title
                tokens.push_back(token);

                NodeData *pMovie = nullptr;
                if(BlockBuster.findDrama(tokens[3], tokens[4], pMovie))
                {
                    BlockBuster.Borrow(custID, pMovie->getData());
                } else // Movie not found
                {
                       cout << "Error: Movie does not exist" << endl;
                }

            } else if (genre == 'C') // Classic
            {
                // Parse classic
            } else
            {
                cout << "Error: Movie genre does not exist" << endl;
                getline(infile3, info);
            }
        }
            // Return movie
        else if (storeCmd == 'R')
        {
            istringstream ss(info);
            string token;

            getline(ss, token, ' '); // Blank

            getline(ss, token, ' '); // CustID
            tokens.push_back(token);
            int custID = stoi(tokens[0]);

            getline(ss, token, ' '); // Media Type
            tokens.push_back(token);
            char mediaType = tokens[1][0];

            getline(ss, token, ' '); // Genre
            tokens.push_back(token);
            char genre = tokens[2][0];

            if (genre == 'F')
            {
                // Parse comedy
                getline(ss, token, ','); // Get movie title
                tokens.push_back(token);

                getline(ss, token, ','); // Get release year
                tokens.push_back(token);
                int releaseYear = stoi(tokens[4]);

                // Make a movie from the info

                NodeData *pMovie = nullptr;
                if (BlockBuster.findComedy(tokens[3], releaseYear, pMovie))
                {
                    BlockBuster.Return(custID, pMovie->getData());
                } else
                { // Movie not found
                    cout << "Error: Movie does not exist" << endl;
                }
            } else if (genre == 'D')
            {
                // Parse drama
                getline(ss, token, ','); // Get director
                tokens.push_back(token);

                getline(ss, token, ' '); // blank
                getline(ss, token, ','); // Get movie title
                tokens.push_back(token);

                NodeData *pMovie = nullptr;
                if(BlockBuster.findDrama(tokens[3], tokens[4], pMovie))
                {
                    BlockBuster.Return(custID, pMovie->getData());
                } else // Movie not found
                {
                    cout << "Error: Movie does not exist" << endl;
                }
            } else if (genre == 'C')
            {
                // Parse classic
            } else
            {
                cout << "Error: Movie genre does not exist" << endl;
                getline(infile3, info);
            }
        } else if (storeCmd == 'H') // Output customer's transaction history
        {
            //int custID = stoi(tokens[0]);
            //BlockBuster.History(custID);
        } else
        {
            cout << "Error: Invalid command code" << endl;
        }
    }
        /*
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


        // For Borrow/Return, parse the first Four values

        if(storeCmd == 'B')
        {
            //Store.Borrow
        }
        else if(storeCmd == 'R')
        {
            //Store.Return
        }

        else if(storeCmd == 'H')
        {
        */
    return 0;
}
