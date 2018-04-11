#!/usr/bin/env node

exports.discover = function(){
	hue.discover(function (err, result) {
	if (err)
		throw err;
	console.log(result);
	});
}