# reason-react-playground

Playing with [Reason](https://facebook.github.io/reason/) and the [Reason bindings for React](https://github.com/reasonml/reason-react) to get a better understanding of the benefits and to mess around. 

### Usage

To get the app running in a development workflow

1. Install OCaml if you have already not (recommend `brew install ocaml`)
2. `git clone git@github.com:bbohen/reason-react-playground.git`
3. `cd reason-react-playground`
4. `npm install`
5. `npm start` - Starts the [bucklescript](http://bloomberg.github.io/bucklescript/Manual.html) platform in watch mode. This will take your OCaml/Reason code and build dependencies and a lib that will also be compiled to javascript.
6. In a seperate tab/instance `npm run dev` - Starts and opens a webpack dev server that will watch for the compiled javascript and then bundle it for the web. HMR is enabled for live reloading.

Other commands

- `npm run bundle` - Uses webpack to bundle the compiled javascript, this would be the script to run for a production bundle.
- `npm run clean` -  The [bucklescript](http://bloomberg.github.io/bucklescript/Manual.html) platform will clean the binary artifact of the build and it's dependency. 
