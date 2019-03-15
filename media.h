//
// Created by Kaib Cropley on 3/4/2019.
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

    //
    bool borrowMedia() const;

    //
    bool returnMedia() const;

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
