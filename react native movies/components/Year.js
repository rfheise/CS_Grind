import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,Image,TouchableOpacity} from 'react-native';
import {createStackNavigator} from "react-navigation"
import Constants from 'expo-constants';
import {primary,secondary} from "../helpers/styles.js"

const size = 300
const styles = StyleSheet.create({
  image:{
    width:size,
    height: size*2,
    borderRadius:size/4,
    overflow:"hidden",
  },
  view:{
    paddingLeft:50,
    paddingRight:0,
    justifyContent:"center",
    alignItems:"center",

  },
  text:{
    color:secondary,
    fontSize:50,
  }

})
export default function Year(props){
return (
  <View style = {styles.view}>
  <TouchableOpacity style = {[styles.view,{paddingLeft:0,paddingRight:0}]} onPress={() => props.navigator(props.year)} >
  <Image
           style={styles.image}
           source={{uri:props.poster}}
  />
  <Text style = {styles.text}>{props.year}</Text>
  </TouchableOpacity>
  </View>
)
}
