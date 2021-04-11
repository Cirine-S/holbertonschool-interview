#!/usr/bin/node
const request = require('request');

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async (err, response, body) => {
  if (err) {
    console.log(err);
  }
  let characters = JSON.parse(body).characters
  for (let i in characters) {
	  await new Promise((resolve, reject) => {
		request(characters[i], (err, response, body) => {
			console.log(JSON.parse(body).name);
			resolve();
	  });
	});
  };
});
