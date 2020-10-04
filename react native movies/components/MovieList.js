import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,TextInput} from 'react-native';
import Constants from 'expo-constants';
import {movies,renderItem,pages,Item} from "../helpers/movies.js";
import {Movie} from "./Movie.js"
import {primary,secondary} from "../helpers/styles.js"

let styles = StyleSheet.create({
  input:{
    width:50,
    height:50,
    textAlign:"center",
  },
  movielist:{
    backgroundColor:primary,
    flex:1
  },
  text:{
    color:"white",
    flexDirection:"row"
  }
})
export default class MovieList extends React.Component{
  list = ({item}) => <Movie {...item} nav = {this.props.nav}/>

  render(){
    return (
      <View style = {styles.movielist}>
      <FlatList
        data={this.props.movie}
        renderItem = {this.list}
      />
      </View>
    )
  }
}
