# Socket.io Whiteboard Example

Socket.io across multiple nodes, backed by redis, on Heroku.

[![Deploy](https://www.herokucdn.com/deploy/button.svg)](https://heroku.com/deploy)

## Deploying to Heroku via CLI

```
$ heroku create
$ git push heroku master
$ heroku open
```

## Scaling

Socket.io requires sticky sessions in order to be scaled up.
On Heroku, you can enable that with:

```
$ heroku features:enable http-session-affinity
$ herouk scale web=4:standard-1x
```

## Developing locally

```
$ yarn
$ heroku local -f Procfile.dev
```
