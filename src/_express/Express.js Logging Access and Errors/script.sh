If you don't have Forever installed, here is how to do it:

$ npm install forever -g
If that gives a permissin error:

$ sudo npm install forever -g












Error logging is enable by starting your app with Forever with the -e option.

$ forever -e error.log start app.js
If you fancy logging console.log() stuff from your code, you can also add the -o option.

$ forever -o output.log -e error.log start app.js
You may wonder if it is worth installing a module just to enable error logging. Whether you want to enable error logging or not, you most probably would need Forever anyway, find out why.

So there you go, logging enabled for your Express.js app. For the sake of neatness, you might want to keep the logs in a directory called logs instead of the root folder of your app. The choice is yours. Happy logging!
