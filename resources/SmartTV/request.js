request(options = { uri: 'http://192.168.0.97:1925/5/input/key', method: 'POST', json: { "key": "VolueDown" } }, function (error, response, body) {
  if (!error && response.statusCode == 200) {
    //console.log(body.id) // Print the shortened url.
    console.log(response) // Print the shortened url.
  }
});