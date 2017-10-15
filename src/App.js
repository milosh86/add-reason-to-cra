import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';
import { format2 } from './main.js';
import { jsComponent as Article } from './Article/Article.js';
// let Article = require('./Article/Article.js').jsComponent;

class App extends Component {

  render() {
    var d = new Date();
    var numberOfDaysToAdd = 0;
    d.setDate(d.getDate() + numberOfDaysToAdd);

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
        <h1>******************************</h1>
        <Article
          title="ReasonML in CRA"
          body={"I am trying to setup Reason and ReasonReact with existing Create React App project." + 
          " This is a ReasonReact component used inside standard React.js component"}
        />
      </div>
    );
  }
}

export default App;
