import * as React from 'react';

const apikey = "10c0ab432b40d8e915f57ab49691bf04"
let id = 0
const render = (movie) => {
return ({
  poster:`https://image.tmdb.org/t/p/w200/${movie.poster_path}`,
  year:movie.release_date.substring(0,4),
  key:id++,
}
)
}
async function year(){
    let jim = []
    for(let i = 1883; i <= 2020;i++){
    const movie = await fetch(`https://api.themoviedb.org/3/discover/movie?api_key=10c0ab432b40d8e915f57ab49691bf04"&primary_release_year${i}&sort_by=popularity.desc`)
    const list = await movie.json()
    jim.push(list.results.map(render)[0])
  }
  console.log(JSON.stringify(jim))
}


year()
