import * as React from 'react';
import { Text, View, StyleSheet,Button,FlatList,StatusBar } from 'react-native';
import Constants from 'expo-constants';
import Ionicons from "react-native-vector-icons/Ionicons"
import {createStackNavigator} from "react-navigation-stack";
import {createAppContainer,createSwitchNavigator} from "react-navigation";
import {createBottomTabNavigator} from "react-navigation-tabs"
import MoviesByYear from "./components/MoviesByYear.js"
import MovieYears from "./components/MovieYears.js"
import MovieDescription from "./components/MovieDescription.js"
import {primary,secondary,tertiary} from "./helpers/styles.js"
import Search from "./components/Search.js"


// You can import from local files
const HomeStackNavigator = createStackNavigator({
  Home:MovieYears,
  Year:MoviesByYear,
  Movie:MovieDescription

},
{
  initialRouteName:"Home"
})
const SearchStackNavigator = createStackNavigator({
  Search:Search,
  Movie:MovieDescription

},
{
  initialRouteName:"Search"
})

const Sear = createAppContainer(SearchStackNavigator)
const Years = createAppContainer(HomeStackNavigator)
Years.navigationOptions = {
  tabBarIcon: ({ focused, tintColor }) => (
    <Ionicons
      name={`ios-home`}
      size={25}
      color={tintColor}
    />
  )
}

Sear.navigationOptions = {
  tabBarIcon: ({ focused, tintColor }) => (
    <Ionicons
      name={`ios-search`}
      size={25}
      color={tintColor}
    />
  )
}

const MainNavigator = createBottomTabNavigator({
  Home:Years,
  Search:Sear
},
{
  initialRouteName:"Home",
  safeAreaInset:{
    bottom:"never"
  },
  tabBarOptions:{
    activeTintColor:secondary,
    style:{
    backgroundColor:primary,
    borderColor:secondary,
    shadowOpacity:.2,
  },
  labelStyle:{
    fontSize:15,
  },
  }
})

// import Ionicons from "@expo/vector-icons"
const Main = createAppContainer(MainNavigator)

export default class App extends React.Component {

  render() {
    return (
      <View style={styles.container}>
      <StatusBar barStyle="light-content" />
      <Main />
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    paddingTop: Constants.statusBarHeight,
    backgroundColor: primary,
    padding: 8,
  },
  paragraph: {
    margin: 24,
    fontSize: 18,
    fontWeight: 'bold',
    textAlign: 'center',
  },
});
