import React, {Component} from 'react';
import {NativeModules} from 'react-native';
import RNImmediatePhoneCall from 'react-native-immediate-phone-call';
import {
  Text, Image, StyleSheet, View, StatusBar, TouchableOpacity, Button
} from 'react-native';


export default class Main extends Component{

render(){
    return(


    <View style={styles.container}>
<StatusBar barStyle="light-content" backgroundColor="#7159c1"/>
<TouchableOpacity style={styles.box} onPress={()=> {
                 RNImmediatePhoneCall.immediatePhoneCall('3125340000');
            }}>
<Text style={styles.Text}>Press Me</Text>
</TouchableOpacity>
    </View>

    );
}
}

const styles = StyleSheet.create({
  container: {
    justifyContent: 'center',
    alignItems: 'center',
    flex: 1,
    backgroundColor: '#000',
  },
  box:{
    justifyContent: 'center',
    alignItems: 'center',
    width: 200,
    height:200,
    backgroundColor: '#F00',
    borderColor: '#FFF',
    borderRadius: 100,
  },
  Text:{
    color: '#FFF',
    fontSize: 24,

  },

});
