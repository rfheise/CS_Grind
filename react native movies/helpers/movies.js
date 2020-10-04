import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList } from 'react-native';
import Constants from 'expo-constants';

const apikey = "10c0ab432b40d8e915f57ab49691bf04"
let id = 0
const render = (movie) => {
return ({
  title:movie.title,
  poster:`https://image.tmdb.org/t/p/w200/${movie.poster_path}`,
  description:movie.overview,
  id:movie.id,
  date:movie.release_date,
  key:id++,
}
)
}

function rend(movie){
return {movie:{
  title:movie.title,
  poster:`https://image.tmdb.org/t/p/w200/${movie.poster_path}`,
  description:movie.overview,
  id:movie.id,
  date:movie.release_date,
  tag:movie.tagline,
  runtime:`${movie.runtime} minutes`
},genres:movie.genres.map(x => x.name + ' ')}

}


export async function year(){
  try{
    let jim = []
    for(let i = 1883; i <= 2020;i++){
    const movie = await fetch(`https://api.themoviedb.org/3/discover/movie?api_key=${apikey}&primary_release_year${year}&sort_by=popularity.desc&page=${page}`)
    const list = await movie.json()
    return list.results.map(render)
  }
}
catch{
  throw new Error("Ooof")
}
}
export async function movies(year,page){
  try{
    const movie = await fetch(`https://api.themoviedb.org/3/discover/movie?api_key=${apikey}&primary_release_year=${year}&sort_by=popularity.desc&page=${page}`)
    const list = await movie.json()
    return list.results.map(render)


}
  catch{
    throw new Error("Ooof")
  }
}

export async function fullthrottle(id){
  // try{
  console.log(id)
    const movie = await fetch(`https://api.themoviedb.org/3/movie/${id}?api_key=${apikey}&language=en-US`)
    const list = await movie.json()
    return rend(list)

//
// }
  // catch{
  //   throw new Error("Ooof")
  // }
}


export async function pages(year){
  const movie = await fetch(`https://api.themoviedb.org/3/discover/movie?api_key=${apikey}&primary_release_year=${year}&sort_by=popularity.desc`)
  const list = await movie.json()
  return {pages:list.total_pages,movies:list.results.map(render)}

}
export async function search(search){
  const movie = await fetch(`https://api.themoviedb.org/3/search/movie?api_key=${apikey}&language=en-US&query=${search}`)
  const list = await movie.json()
  return list.results.map(render)

}

const Movie = (props) => (
<View>
<Text>klasjdfkljsdf</Text>
</View>
)
// const list = ({item}) => <Movie {...item} /



export class Item extends React.Component{

  state = {
    movieList:null,
    page:this.props.page,
    year:this.props.year,
  }
  list = ({item}) => <Movie {...item} />

  componentDidMount(){
    this.getMovies()
  }
  componentWillUnmount(){
    console.log("id")
  }
  getMovies = async () =>{
    this.setState({movieList:await movies(this.state.page,this.state.year)})
  }
  render(){
    return(
      <FlatList
        data={this.state.movieList}
        renderItem={this.list}
        />
    )
  }


}
