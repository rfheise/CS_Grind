#include <iostream>
#include <vector>
#include "Movie.h"
using std::vector;


class Movies{
  private:
    static int total;
    vector<Movie> movies;
  public:
    //constructor
    Movies();
    //adds movies
    void add_movie(string title, string rating, int watched);
    //displays all movies in Movies
    void display_all();
    //increase watch count
    void increase_watched(string title);


};
