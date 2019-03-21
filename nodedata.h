// ------------- nodedata.h --------------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 1/27/19
// Last Modified 3/15/19
// -------------------------------------------------------------------------
// Node Data header file modified for the movie store
// -------------------------------------------------------------------------
// NodeData class modified to hold Movie objects for use in Assignment 4
// movie store inventory. Each NodeData object holds a pointer to the movie
// object created in the driver.
// -------------------------------------------------------------------------

#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "classic.h"
using namespace std;

// simple class containing one string to use for testing

class NodeData {
	friend ostream & operator<<(ostream &, const NodeData &);

public:
	NodeData();          // default constructor, data is set to an empty string
	~NodeData();
	NodeData(Movie *mov);      // data is set equal to parameter
	//NodeData(const NodeData &);    // copy constructor (not needed)
	NodeData& operator=(const NodeData &);


	// Used to set the data to a movie. Movie objects are created in the main driver on the stack
	void setData(Movie *pMovie);

	// Used to get and set the stock of the movie.
	int getStock() const;
	void returnStock(); // Increments stock by 1
	bool borrowStock(); // Decrements stock by 1

	// Methods to get movie information
	string getTitle(); // gets movie title
	int getReleaseYear(); // gets movie release year
	int getReleaseMonth(); // gets a CLASSIC MOVIE release month. Returns 0 if not a classic
	string getDirector(); // gets movie director
	char getGenre(); // gets movie genre
	Movie& getData();


	bool operator==(const NodeData &) const;
	bool operator!=(const NodeData &) const;
	bool operator<(const NodeData &) const;
	bool operator>(const NodeData &) const;
	bool operator<=(const NodeData &) const;
	bool operator>=(const NodeData &) const;
private:
	Movie *data;
};

#endif
