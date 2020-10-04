import { StyleSheet} from 'react-native';

export const primary = "silver"

export const secondary = "crimson"

export const tertiary = "gray"

export const hype = StyleSheet.create({
  view:{
    flexDirection:"row",
  justifyContent:"center",
  paddingTop:10,
  paddingBottom:10,
  alignItems:"center"
},
text:{
  color:secondary,
  flexDirection:"row",
  fontSize:50,
},
allmovies:{
  backgroundColor:primary,
  flex:1
},
input:{
  fontSize:50,
  textAlign:"center",
  backgroundColor:"white",
  borderColor:secondary,
  borderWidth:2,
  width:50,
  height:50,
  borderRadius:7,
},
})
