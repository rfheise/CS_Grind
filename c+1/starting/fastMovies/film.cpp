
#include <iostream>
#include <string>
#include "Movies.h"
#include "Movie.h"

#include <chrono>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

int main(void){
  auto start = std::chrono::system_clock::now();
    // Some computation here
  for(int i =0; i < 1000000; i++){
    {
    Movies movies = Movies();
    movies.add_movie("Spider-Man","PG-13",3);
    movies.add_movie("Spider-Man","PG-13",3);
    movies.increase_watched("Spider-Man");
    movies.add_movie("Andy Griffith Show","G",40);
    movies.display_all();
    }

  }

  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);

  std::cout << "finished computation at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << "s\n";

}
