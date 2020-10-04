import * as React from 'react';
import { Text, View, StyleSheet,Image,TouchableOpacity} from 'react-native';
import {primary,secondary} from "../helpers/styles.js"

let styles = StyleSheet.create({
  text:{
    color:secondary,
    textAlign:"center",
  },
  view:{
    flexDirection:"row",
    textAlign:"center",
    borderTopWidth: 2,
    borderRadius:0,
    borderColor: secondary,
    alignItems:"center",
    textAlign:"center",
    paddingTop:10,
    paddingBottom:10,
    flex:1,
  }

})
export const Movie = (props) => (
  <TouchableOpacity onPress = {() => props.nav(props.id,props.title)} >
<View style = {styles.view}>
<Image
         style={{width: 75, height: 112.5}}
         source={{uri:props.poster}}
/>
<View style = {{justifyContent:"center"}}>
<Text style = {styles.text}> {props.title}</Text>
</View>
</View>
</ TouchableOpacity>
)
