// ------------- nodedata.cpp ----------------------------------------------
// Jarod Guerrero CSS 343 C
// Created 1/27/19
// Last Modified 3/15/19
// -------------------------------------------------------------------------
// Node Data implementation file
// -------------------------------------------------------------------------
// NodeData class modified to hold Movie objects for use in Assignment 4
// movie store inventory. Each NodeData object holds a pointer to the movie
// object created in the driver.
// -------------------------------------------------------------------------
#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() { data = nullptr; }                         // default

/*
 * Main constructor used to set the NodeData to a movie.
 */
NodeData::NodeData(Media *mov)
{
	data = mov;
}

NodeData::~NodeData() { }            // needed so Movies are deleted properly

/*
 * Retrieves the stock of the movie pointed to by data
 * Returns -1 if data is null
 */
int NodeData::getStock() const
{
	if(data == nullptr)
	{
		return -1;
	}
	return data->getStock();
}

/*
 * Sets the stock of the movie pointed to by data
 */
void NodeData::setStock(int newStock)
{
	data->setStock(newStock);
}

//NodeData::NodeData(const NodeData& nd) { data = nd.data; }  // copy

//NodeData::NodeData(const string& s) { data = s; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

//------------------------- operator==,!= ------------------------------------
bool NodeData::operator==(const NodeData& rhs) const {
	return *data == *rhs.data;
}

bool NodeData::operator!=(const NodeData& rhs) const {
	return *data != *rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool NodeData::operator<(const NodeData& rhs) const {
	return *data < *rhs.data;
}

bool NodeData::operator>(const NodeData& rhs) const {
	return *data > *rhs.data;
}

bool NodeData::operator<=(const NodeData& rhs) const {
	return *data <= *rhs.data;
}

bool NodeData::operator>=(const NodeData& rhs) const {
	return *data >= *rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

void NodeData::setData(Media *pMovie) {
	data = pMovie;
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
	output << nd.data;
	return output;
}
