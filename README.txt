Jarod Guerrero, Ajeet Dhaliwal, Kaib Cropley


How to run:
Running driver.cpp will read in movie and customer data through the given files (data4movies.txt and data4customers.txt). It will then continue to read from the given command file (data4commands.txt) and execute all given commands. It will print all outgoing messages to the console including error messages and results from commands.


Implementation choices:
- A hash table contains our list of customers.
- A BST contains our list of movies.
- Comedies are sorted by their title (A to B) then their release year (newest to oldest).
- Dramas are sorted by their director (A to B) then their title (A to B)
- Classics are sorted by their release date(newest to oldest) and then by their major actor, specifically by their first name then their last name (A to B).


Contributions:
Driver & Store: Jarod Guerrero
CustomerTable(Hash table) & Customer: Ajeet Dhaliwal
Media, Movies & Submovies: Kaib Cropley
