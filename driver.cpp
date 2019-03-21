// ------------- driver.cpp ------------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 3/9/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Driver file for the Movie inventory system
// -------------------------------------------------------------------------
// Creates a Store class and performs commands based on file input.
// Takes three input files containing information about the store.
// data4movies.txt contains movies to be added to the store
// data4customers.txt contains a list of customers to be added
//          to our hash table implemented with an array
// data4commands.txt contains a list of commands to be executed
//          on the created store
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
    cout    << "  _____                _ _               __  __            _           " << endl;
    cout    << " |  __ \\              | (_)             |  \\/  |          (_)          " << endl;
    cout    << " | |__) |___  __ _  __| |_ _ __   __ _  | \\  / | _____   ___  ___  ___ " << endl;
    cout    << " |  _  // _ \\/ _` |/ _` | | '_ \\ / _` | | |\\/| |/ _ \\ \\ / / |/ _ \\/ __|" << endl;
    cout    << " | | \\ \\  __/ (_| | (_| | | | | | (_| | | |  | | (_) \\ V /| |  __/\\__ \\" << endl;
    cout    << " |_|  \\_\\___|\\__,_|\\__,_|_|_| |_|\\__, | |_|  |_|\\___/ \\_/ |_|\\___||___/" << endl;
    cout    << "                                  __/ |                                " << endl;
    cout    << "                                 |___/                                 " << endl;

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



    // Part 2: Populate customer hash table from data4customers.txt
    ifstream infile2("data4customers.txt");
    if (!infile2)
    {
        cout << "data4customers.txt not found." << endl;
        return 1;
    }
    cout    << "______               _ _               _____           _                                " << endl;
    cout    << "| ___ \\             | (_)             /  __ \\         | |                               " << endl;
    cout    << "| |_/ /___  __ _  __| |_ _ __   __ _  | /  \\/_   _ ___| |_ ___  _ __ ___   ___ _ __ ___ " << endl;
    cout    << "|    // _ \\/ _` |/ _` | | '_ \\ / _` | | |   | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__/ __|" << endl;
    cout    << "| |\\ \\  __/ (_| | (_| | | | | | (_| | | \\__/\\ |_| \\__ \\ || (_) | | | | | |  __/ |  \\__ \\" << endl;
    cout    << "\\_| \\_\\___|\\__,_|\\__,_|_|_| |_|\\__, |  \\____/\\__,_|___/\\__\\___/|_| |_| |_|\\___|_|  |___/" << endl;
    cout    << "                                __/ |                                                   " << endl;
    cout    << "                               |___/                                                    " << endl;
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
    cout << "  _____                _ _                _____ __  __ _____  _     " << endl;
    cout << " |  __ \\              | (_)              / ____|  \\/  |  __ \\( )    " << endl;
    cout << " | |__) |___  __ _  __| |_ _ __   __ _  | |    | \\  / | |  | |/ ___ " << endl;
    cout << " |  _  // _ \\/ _` |/ _` | | '_ \\ / _` | | |    | |\\/| | |  | | / __|" << endl;
    cout << " | | \\ \\  __/ (_| | (_| | | | | | (_| | | |____| |  | | |__| | \\__ \\" << endl;
    cout << " |_|  \\_\\___|\\__,_|\\__,_|_|_| |_|\\__, |  \\_____|_|  |_|_____/  |___/" << endl;
    cout << "                                  __/ |                             " << endl;
    cout << "                                 |___/                              " << endl;

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
            cout << "------ Current Movie Inventory -------" << endl;
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
                getline(ss, token, ' '); // Get release month
                int releaseMonth = stoi(token);

                getline(ss, token, ' '); // Get release year
                int releaseYear = stoi(token);

                getline(ss, token, ' '); // Get actor first name
                tokens.push_back(token); //[3]

                getline(ss, token, ' '); // Get actor last name
                tokens.push_back(token); //[4]

                NodeData *pMovie = nullptr;
                if(BlockBuster.findClassic(releaseMonth, releaseYear, tokens[3], tokens[4], pMovie))
                {
                    BlockBuster.Borrow(custID, pMovie->getData());
                } else // Movie not found
                {
                    cout << "Error: Movie does not exist" << endl;
                }

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
                getline(ss, token, ' '); // Get release month
                int releaseMonth = stoi(token);

                getline(ss, token, ' '); // Get release year
                int releaseYear = stoi(token);

                getline(ss, token, ' '); // Get actor first name
                tokens.push_back(token); //[3]

                getline(ss, token, ' '); // Get actor last name
                tokens.push_back(token); //[4]

                NodeData *pMovie = nullptr;
                if(BlockBuster.findClassic(releaseMonth, releaseYear, tokens[3], tokens[4], pMovie))
                {
                    BlockBuster.Return(custID, pMovie->getData());
                } else // Movie not found
                {
                    cout << "Error: Movie does not exist" << endl;
                }
            } else
            {
                cout << "Error: Movie genre does not exist" << endl;
                getline(infile3, info);
            }
            // Output customer's transaction history
        } else if (storeCmd == 'H')
        {
            istringstream ss(info);
            string token;

            getline(ss, token, ' '); // Blank

            getline(ss, token, ' '); // CustID
            int custID = stoi(token);
            if(!BlockBuster.History(custID))
            {
                cout << "Error: Customer does not exist" << endl;
            }
            cout << endl;
        } else
        {
            cout << "Error: Invalid command code" << endl;
        }
    }
    cout << "\nDone reading in store commands.\nGood bye!" << endl;
    return 0;
}
