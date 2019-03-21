// ------------- nodedata.cpp ----------------------------------------------
// Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley CSS 343 C
// Created 1/27/19
// Last Modified 3/20/19
// -------------------------------------------------------------------------
// Node Data implementation file modified for the movie store
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
NodeData::NodeData(Movie *mov)
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
 * Decrements the stock of a movie by 1.
 * Returns false if the movie has no stock left.
 */
bool NodeData::borrowStock()
{
	return data->borrowStock();
}

/*
 * Increments the stock of a movie by 1
 */
void NodeData::returnStock()
{
	data->returnStock();
}

/*
 * Returns the title of the movie in NodeData
 */
string NodeData::getTitle()
{
	return data->getTitle();
}

int NodeData::getReleaseYear()
{
    return data->getReleaseYear();
}

/*
 * How would you get release month
 */
int NodeData::getReleaseMonth()
{
    return 0;
}

char NodeData::getGenre()
{
    return data->getMovieType();
}

string NodeData::getDirector()
{
    return data->getDirector();
}

Movie& NodeData::getData()
{
    return *data;
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

void NodeData::setData(Movie *pMovie) {
	data = pMovie;
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
	output << *(nd.data);
	return output;
}
