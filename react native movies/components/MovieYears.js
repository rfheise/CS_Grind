import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,TextInput} from 'react-native';
import Constants from 'expo-constants';
import {movieyears} from "../helpers/years.js"
import Year from "./Year.js"
import {primary,secondary} from "../helpers/styles.js"

export default class MovieYears extends React.Component{
  static navigationOptions = {
    headerStyle: {
        backgroundColor: primary,
      },
      headerTintColor: secondary,
    cardStyle:{
    backgroundColor:primary,
    paddingTop:40,
    }
  }
  state = {
    movielist:movieyears
  }
  movetonavigator = year => {
    this.props.navigation.navigate('Year',{year:year})
  }
  list = (obj) => <Year {...obj.item} navigator = {this.movetonavigator} />

  render(){
    return(
  <View>
  <FlatList
    horizontal = {true}
    renderItem = {this.list}
    data = {this.state.movielist}
    />
    </View>
  )
}


}
