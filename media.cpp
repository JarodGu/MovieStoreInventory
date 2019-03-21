//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/20/2019.
//
// Parent file for all media sold
//

#include "media.h"

// Constructor
Media::Media(char mediaType, int stock) : mediaType{mediaType}, stock{stock}  {

}

// Returns media type
char Media::getMediaType() const {
    return mediaType;
}

// Returns current stock
int Media::getStock() const {
    return stock;
}

// Removes one unit from the stock of this media
// Returns false if stock is <= 0, true if stock > 0
bool Media::borrowStock() {
    if (stock > 0) {
        stock--;
        return true;
    }
    return false;
}

// Adds one unit from the stock of this media
void Media::returnStock() {
    stock++;
}

// Sets stock to give integer
// Returns false if the integer is below 0
bool Media::setStock(int stockLevel) {
    if (stockLevel < 0) {
        return false;
    }
    stock = stockLevel;
    return true;
}

// Compares media based on their type
bool Media::operator>(const Media &other) const {
    return mediaType > other.getMediaType();
}

bool Media::operator<(const Media &other) const {
    return mediaType < other.getMediaType();
}

bool Media::operator>=(const Media &other) const {
    return mediaType >= other.getMediaType();
}

bool Media::operator<=(const Media &other) const {
    return mediaType <= other.getMediaType();
}

bool Media::operator==(const Media &other) const {
    return mediaType == other.getMediaType();
}

bool Media::operator!=(const Media &other) const {
    return mediaType != other.getMediaType();
}



