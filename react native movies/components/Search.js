import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,TextInput} from 'react-native';
import Constants from 'expo-constants';
import {movies,renderItem,pages,Item,search} from "../helpers/movies.js";
import {Movie} from "./Movie.js"
import {primary,secondary,hype,tertiary} from "../helpers/styles.js"
import MovieList from "./MovieList.js"

let styles = StyleSheet.create({
  input:{...hype.input,
    width:390,
    borderWidth:3,
  }
})


export default class Search extends React.Component{
  static navigationOptions = {
    headerShown:  false,
  }
  state = {
    movielist:null,
    search:""
  }

  nav = (id,title) => {
    this.props.navigation.navigate("Movie",{id:id,title:title})
  }
  getMovies = async() => {
    let movie = await pages(2020)
    this.setState({movielist: movie.movies})
  }
  componentDidMount(){
    this.getMovies()
  }
  searchupdate = async(value) => {
    if(value != ""){
    this.setState({search:value})
    this.setState({movielist:await search(value)})
  }
  else {
    this.setState({search:value})
    this.getMovies()
  }
  }
  render(){
  return(
  <View style = {hype.allmovies}>
  <View style = {hype.view}>
  <TextInput
  style = {styles.input}
  value ={this.state.search}
  placeholder = "Search"
  onChangeText={this.searchupdate}
  />
  </View>
  <MovieList movie={this.state.movielist} nav = {this.nav} />
  </View>
)
}
}
