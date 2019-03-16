//
// Created by Kaib Cropley on 3/4/2019.
//

#include "media.h"

// Constructor
Media::Media(char mediaType, int stock) : mediaType{mediaType}, stock{stock}  {

}

// Destructor
Media::~Media() {

}

// Returns media type
char Media::getMediaType() const {
    return mediaType;
}

// Returns current stock
int Media::getStock() const {
    return stock;
}

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

bool Media::borrowStock() {
    if (stock > 0) {
        stock--;
        return true;
    }
    return false;
}

void Media::returnStock() {
    stock++;
}



