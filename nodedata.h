// ------------- nodedata.h --------------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 1/27/19
// Last Modified 3/15/19
// -------------------------------------------------------------------------
// Node Data header file
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
using namespace std;

// simple class containing one string to use for testing

class NodeData {
	friend ostream & operator<<(ostream &, const NodeData &);

public:
	NodeData();          // default constructor, data is set to an empty string
	~NodeData();
	NodeData(Media *mov);      // data is set equal to parameter
	//NodeData(const NodeData &);    // copy constructor (not needed)
	NodeData& operator=(const NodeData &);


	// Used to set the data to a movie. Movie objects are created in the main driver on the stack
	void setData(Media *pMovie);

	// Used to get and set the stock of the movie.
	int getStock() const;
	void setStock(int newStock);


	bool operator==(const NodeData &) const;
	bool operator!=(const NodeData &) const;
	bool operator<(const NodeData &) const;
	bool operator>(const NodeData &) const;
	bool operator<=(const NodeData &) const;
	bool operator>=(const NodeData &) const;
private:
	Media *data;
	int stock;
};

#endif
