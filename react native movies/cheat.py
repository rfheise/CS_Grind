import requests
import json
url ='https://api.themoviedb.org/3/discover/movie?api_key=10c0ab432b40d8e915f57ab49691bf04&sort_by=popularity.desc&primary_release_year='

r = requests.get(url)
l = []
id = 0
with open("helpers/years.js","w") as f:
    f.write("export const movieyears =")
    for i in range(2020,1882,-1):
        k = url + str(i)
        y = requests.get(k).json()["results"][0]
        id += 1
        print(i)
        l.append({"poster":f"https://image.tmdb.org/t/p/w200{y['poster_path']}","key":id,"year":i})
    f.write(str(l))
