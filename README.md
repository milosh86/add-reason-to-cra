- npm i bs-platform -D
- add scripts:
    "bsb-build": "bsb -make-world"
    "bsb-watch": "bsb -make-world -w"
    "bsb-clean": "bsb -clean-world"
- add bsconfig:
  {
    "name": "bscript",
    "version": "0.1.0",
    "sources":  [{"dir": "src", "subdirs": true}],
    "bs-dependencies" : [
        // add your bs-dependencies here 
    ],
    "package-specs" :  [  { "module" : "es6", "in-source" :  true}  ]
  }
  * "subdirs" option enables compiling of Reason files located in sub-directories inside "src" folder
  * "in-source" option - output JS files next to ML files (in the same directory as vanilla JS)

  - npm i "reason-react"
  - add "reason-react" to bs-dependencies in bsconfig file
  - add "reason": {"react-jsx": 2} to bsconfing in order to enable JSX syntax

  - Eslint breaks with js files generated by bsb: 
      * "Module build failed: TypeError: Cannot read property ‘node’ of undefined" 
      * we have to add Reason output files to .eslintignore
      * .eslintignore is working only when CRA is ejected!