//
// Created by Kaib Cropley on 3/4/2019.
// Updated by Kaib Cropley on 3/18/2019.
//
// Base file for all media within store
//

#ifndef CROPLEY_ASSIGNMENT_4_MEDIA_H
#define CROPLEY_ASSIGNMENT_4_MEDIA_H


class Media {
public:
    // Constructor
    Media(char mediaType, int stock);

    // Destructor
    ~Media();

    // Returns type of media
    char getMediaType() const;

    // Returns current stock
    int getStock() const;

    // Removes one unit from the stock of this media
    // Returns false if stock is <= 0, true if stock > 0
    bool borrowStock();

    // Adds one unit from the stock of this media
    void returnStock();

    // Comparison operators - Compares based on their media type
    // If same media type will always be equal
    bool operator>(const Media &other) const;
    bool operator<(const Media &other) const;
    bool operator>=(const Media &other) const;
    bool operator<=(const Media &other) const;
    bool operator==(const Media &other) const;
    bool operator!=(const Media &other) const;
private:
    // Data shared by all media
    char mediaType;
    int stock;
};


#endif //CROPLEY_ASSIGNMENT_4_MEDIA_H
