import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,TextInput} from 'react-native';
import Constants from 'expo-constants';
import {movies,renderItem,pages,Item} from "../helpers/movies.js";
import {Movie} from "./Movie.js"
import {primary,secondary,hype} from "../helpers/styles.js"
import MovieList from "./MovieList.js"

export default class MoviesByYear extends React.Component{
  static navigationOptions = (ironman) => {
    return {
    title:ironman.navigation.getParam("year"),
    headerStyle:{
      backgroundColor: primary,
    },
    headerTintColor: secondary,
  }
}
  state = {
    page:"1",
    year:this.props.navigation.getParam("year"),
    allmovies:null,
    max_page:null,
  }
  getMovies = async () => {
    const movie = await pages(this.state.year)
    this.setState({allmovies:movie.movies,max_page:movie.pages})
  }
  pageupdate = async(value) => {
    if((+value > 0 && +value <= this.state.max_page) || value == ""){
      if(value != this.state.page && value != ""){
      this.setState({page:value})
      this.setState({allmovies:await movies(this.state.year,value)})
    }
      else {
        this.setState({page:value})
      }
    }

  }

  componentDidMount(){
    this.getMovies()
  }
  nav = (id,title) => {
    this.props.navigation.navigate("Movie",{id:id,title:title})
  }

  render(){
    return (
      <View style = {hype.allmovies}>
      <View style = {hype.view}>
      <Text style = {hype.text}>Page: </Text>
      <TextInput
      style = {hype.input}
      keyboardType="numeric"
      value ={this.state.page}
      onChangeText={this.pageupdate}
      />
      <Text style = {hype.text}> of {this.state.max_page}</Text>
      </View>
      <MovieList movie={this.state.allmovies} nav = {this.nav} />
      </View>
    )
  }
}
