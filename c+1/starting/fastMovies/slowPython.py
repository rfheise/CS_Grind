
import time

class Movie:
    def __init__(self,title,rating,watched):
        self.title = title
        self.rating = rating
        self.watched = watched
    def increment_watched(self):
        self.watched += 1


class Movies:
    def __init__(self):
        self.movies = []
    def add_movie(self,title,rating,watched):
        for movie in self.movies:
            if movie.title == title and movie.rating == rating:
                return
        self.movies.append(Movie(title=title,rating=rating,watched=watched))
    def increase_watched(self,title):
        for movie in self.movies:
            if movie.title == title:
                movie.increment_watched()
    def display_all(self):
        # for movie in self.movies:
            # print(movie.title,movie.watched)
        return

def main():
    start = time.process_time_ns()
    for i in range(1000000):
    # print("go")
        movies = Movies()
        movies.add_movie(title ="Spider-Man",rating="PG-13",watched = 3)
        movies.add_movie(title ="Spider-Man",rating="PG-13",watched = 3)
        movies.increase_watched("Spider-Man")
        movies.add_movie(title = "Andy Griffith Show",rating ="G",watched = 40)
        movies.display_all()
    end  = time.process_time_ns()
    print(f"Time spent {(end-start)/10**9}")
    # print(movies.movies)

if __name__ == '__main__':
    main()
