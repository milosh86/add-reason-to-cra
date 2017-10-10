import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import {format2} from './main.js';

class App extends Component {
  
  render() {
  var d = new Date();
  var numberOfDaysToAdd = 0;
  d.setDate(d.getDate() + numberOfDaysToAdd);
  console.log(d.toString(), d.getDay(), d.getMonth(), 'dadad')
  
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <h1 className="App-title">Welcome to React</h1>
        </header>
        <p className="App-intro">
          To get started, edit <code>src/App.js</code> and save to reload.
        </p>
        <strong>{format2(d, 'm/d/y')}</strong>
      </div>
    );
  }
}

export default App;
