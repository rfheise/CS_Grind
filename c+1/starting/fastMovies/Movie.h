#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <iostream>
#include <string>

using std::string;

class Movie{
  private:
    string title;
    string rating;
    int watched;
  public:
    void set_title(string title){this -> title = title;};
    void set_rating(string rating){this -> rating = rating;};
    void set_watched(int watched){this-> watched = watched;};
    int get_watched(){return watched;};
    string get_rating(){return rating;};
    string get_title(){return title;};
    Movie(string title,string rating,int watched);
    void increment_watched() {watched++;};
    Movie(Movie &source);
    //move constructor for r values passed into vector;
    Movie(Movie && source);
    // ~Movie();
};

#endif
