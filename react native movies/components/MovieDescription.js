import * as React from 'react';
import { Text, View, StyleSheet,Image} from 'react-native';
import Constants from 'expo-constants';
import {fullthrottle} from "../helpers/movies.js";
import {Movie} from "./Movie.js"
import {primary,secondary} from "../helpers/styles.js"


let styles = StyleSheet.create({
  view:{
    justifyContent:"center",
    alignItems:"center",
    color:secondary,
    backgroundColor:primary,
    flex:1
  },
  text:{
    color:secondary,
    flexWrap:"wrap"}
})
let key = 0
export default class MovieDescription extends React.Component{
  static navigationOptions = (suit) => {
    return {
      title:suit.navigation.getParam("title"),
      headerStyle:{
        backgroundColor:primary
      },
      headerTintColor:secondary
    }

  }
  state = {
    id:this.props.navigation.getParam("id"),
    title:null,
    poster:null,
    description:null,
    date:null,
    genres:[],
    tag:null,
    runtime:null
  }

  getMovie = async () => {
    let movie = await fullthrottle(this.state.id)
    this.setState({...movie.movie,genres:movie.genres})
  }
  componentDidMount(){
    this.getMovie()
  }
  render(){
    return (
      <View style = {styles.view}>
      <Image
        source = {this.state.poster && {uri:this.state.poster}}
        style = {{height:400,width:300}}
        />
        <View key = {key ++} style = {{flexDirection:"row",flexWrap:"wrap",justifyContent:"center"}}>
        <Text style = {[styles.text,{fontWeight:"bold"}]}>Genres:</Text>
        <Text style = {styles.text}>{this.state.genres}</Text>
        </View>
      {Object.keys(this.state).filter(x => x != "genre").filter(x => x != "id").filter(x => x != "poster").filter(x => this.state[x] != "").map(x => {return (
        <View style = {{flexDirection:"row",flexWrap:"wrap",justifyContent:"center"}} key = {key++}>
        <Text style = {[styles.text,{fontWeight:"bold"}]}>{x + ":"}</Text>
        <Text style = {styles.text}>{this.state[x]}</Text>
        </View>)})}
      </View>
    )
  }
}
