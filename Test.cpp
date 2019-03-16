#include <iostream>
#include <cassert>
#include <vector>
#include "movie.h"
#include "classic.h"
#include "comedy.h"
#include "drama.h"

// Tests classics class
void testClassic() {
    Classic a(10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1938);
    Classic b(10, "George Cukor", "Holiday", "Aubrey", "Hepburn", 9, 1938);
    Classic c(10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1940);
    Classic d(10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1938);

    assert(a.getMajorActor() == "Katherine Hepburn");
    assert(a.getReleaseMonth() == 9);
    assert(b > a);
    assert(a < b);
    assert(a != b);
    assert(b != c);
    assert(a != c);
    assert(a <= b);
    assert(b >= a);
    assert(b < c);
    assert(c > a);
    assert(a == d);
}

// Tests Comedy class
void testComedy() {
    Comedy a(10, "Nora Ephron", "You've Got Mail", 1998);
    Comedy b(10, "Nora Ephron", "B", 1998);
    Comedy c(10, "Nora Ephron", "C", 2000);
    Comedy d(10, "Nora Ephron", "C", 2000);

    assert(a < b);
    assert(c > a);
    assert(a != b);
    assert(a != c);
    assert(b > c);
    assert(b >= c);
    assert(a <= c);
    assert(c == d);
}

// Tests drama class
void testDrama() {
    Drama a(10, "A", "A", 1998);
    Drama b(10, "B", "B", 1998);
    Drama c(10, "C", "C", 1998);
    Drama d(10, "C", "C", 1998);
    Drama e(10, "A", "B", 1998);

    assert(a == a);
    assert(a > b);
    assert(a > c);
    assert(a >= b);
    assert(c == d);
    assert(c != b);
    assert(c >= d);
    assert(c <= d);
    assert(c < b);
    assert(c < a);
    assert(a > e);
    assert(a >= e);
}

// Test printing all movie types
void testPrint() {
    Classic a(10, "George Cukor", "Holiday", "Katherine", "Hepburn", 9, 1938);
    Comedy b(10, "George Cukor", "Holiday", 1938);
    Drama c(10, "George Cukor", "Holiday", 1938);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}

// Tests sorting movies
void testSorting() {
    Classic c1(10, "Director", "title", "A", "A", 1, 1);
    Classic c2(10, "Director", "title", "A", "A", 2, 1);
    Classic c3(10, "Director", "title", "B", "B", 1, 1);
    assert(c1 < c2);
    assert(c1 > c3);
    assert(c2 > c3);

    Comedy f1(10, "Director", "A", 1);
    Comedy f2(10, "Director", "A", 2);
    Comedy f3(10, "Director", "B", 1);
    assert(f1 < f2);
    assert(f1 > f3);
    assert(f2 > f3);

    Drama d1(10, "A", "A", 1);
    Drama d2(10, "A", "B", 1);
    Drama d3(10, "B", "A", 1);
    assert(d1 > d2);
    assert(d1 > d3);
    assert(d2 > d3);


    std::vector<Movie *> movies(0);
    movies.push_back(&c1);
    movies.push_back(&c2);
    movies.push_back(&c3);
    movies.push_back(&f1);
    movies.push_back(&f2);
    movies.push_back(&f3);
    movies.push_back(&d1);
    movies.push_back(&d2);
    movies.push_back(&d3);

    assert(*movies[0] < *movies[3]);
    assert(*movies[0] < *movies[6]);
    assert(*movies[3] > *movies[6]);

    for (int i{0}; i < movies.size(); i++) {
        std::cout << *movies[i] << std::endl;
    }


    // Tests stock borrow/return
    int index = 0;
    int movieCount = 10;
    assert(movies[index]->getStock() == movieCount);

    for (int i{0}; i < movieCount; i++) {
        assert(movies[index]->borrowStock());
    }
    assert(movies[index]->getStock() == 0);
    assert(!movies[index]->borrowStock());

    movies[index]->returnStock();
    assert(movies[index]->getStock() == 1);

    assert(movies[index]->borrowStock());
    assert(movies[index]->getStock() == 0);

}

// Runs all test functions
void testAll() {
    testClassic();
    testComedy();
    testDrama();
    // Uncomment to see movies be printed
    testPrint();
    testSorting();
    std::cout << "All test complete" << std::endl;
}

int main() {
    testAll();
    return 0;
}