#include <iostream>
#include <string>
#include "Movie.h"

using std::string;
using std::cout;
using std::endl;

Movie::Movie(string title,string rating,int watched)
  :watched(watched),title(title),rating(rating){

}

Movie::Movie(Movie && source)
  :Movie(source.title,source.rating,source.watched){
    // cout << source.title <<endl;
}

Movie::Movie(Movie &source)
  :Movie(source.title,source.rating,source.watched){
    // cout << "Copy Constructor Called" << endl;
}

// Movie::~Movie(){
//   // cout << "Descrutor Called for " <<  get_title()  << endl;
//
// }
