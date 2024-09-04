#include <iostream>
using namespace std;

class Movie {
public:
    string name;
    double rating;
    string director;

    // Default constructor
    Movie() {
        name = "";
        rating = 0;
        director = "";
    }

    // Parameterized constructor
    Movie(string name, double rating, string director) {
        this->name = name;
        this->rating = rating;
        this->director = director;
    }

    // Copy constructor, used when new object creation and initialization is required.
    Movie(const Movie& movie) {
        name = movie.name;
        rating = movie.rating;
        director = movie.director;
    }

    // Assignment operator using operator overloading
    Movie& operator=(const Movie& movie) {
        name = movie.name;
        rating = movie.rating;
        director = movie.director;

        return *this;
    }
};

int main()
{
    cout << "Hello World!\n";

    Movie movie1;
    Movie movie2("Avengers: Endgame", 9.5, "Russo Brothers");

    Movie movie3(movie2); // Copy constructor called here.
    //Movie movie3 = movie2; Doesn't matter if we use the assignment operator symbol in the initialization, new object creation will result in the call of copy constructor.

    Movie movie4;
    movie4 = movie2; // Here the assignment operator function is called since the object already exists.
    // movie4.operator=(movie2); Another way of calling overloaded operator= function.

    cout << movie1.name << "\t" << movie1.rating << "\t" << movie1.director << endl;
    cout << movie2.name << "\t" << movie2.rating << "\t" << movie2.director << endl;
    cout << movie3.name << "\t" << movie3.rating << "\t" << movie3.director << endl;
    cout << movie4.name << "\t" << movie4.rating << "\t" << movie4.director << endl;
}
