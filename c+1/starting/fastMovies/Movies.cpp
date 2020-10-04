
#include <iostream>
#include <string>
#include "Movies.h"

using std::cout;
using std::endl;
using std::string;

Movies::Movies()
  :movies(vector<Movie *>()){

}
void Movies::add_movie(string title,string rating,int watched){
  for(Movie *movie:movies){
    if(movie -> get_title() == title && movie -> get_rating() == rating){
      // cout << "Error "<< movie -> get_title() << " Already Added " << endl;
      return;
    }
  }

  movies.push_back(new Movie(title,rating,watched));
  // cout << title << " Added Successfully" << endl;
}
void Movies::increase_watched(string title){
  for(Movie *movie:movies){
    if(movie -> get_title() == title){
      movie -> increment_watched();
      // cout << movie -> get_title() << "Watch Counter Increased" << endl;
      break;
    }
  }
}
void Movies::display_all(){
  for(Movie *movie: movies){
    // cout << "Title: " << movie -> get_title() << " Rating: " << movie -> get_rating() << " Times Watched: " << movie -> get_watched() <<endl;
  }
}

Movies::~Movies(){
  for(auto movie:movies){
    // cout << movie << endl;
    // cout << "Deleting: "<<movie -> get_title() << endl;
    delete movie;
  }
  movies.clear();
  // for(Movie *movie:movies){
  //   // cout << movie << endl;
  //   cout << movie -> get_title() << endl;
  // }
  // cout << "Destructor Called" <<endl;
}
