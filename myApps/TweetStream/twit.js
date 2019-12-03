var tweet = require('twit');
var fs = require('fs');
var file = 'twitter.json';
var T = new tweet({
  consumer_key: 'YjGAeb5oYU8qF1hOGSU64yWyB',
  consumer_secret: 'keBI9lYCFHI0DDBoSueZIS8eSWv3Q8pwJKo2HkSEjmmkewS8d4',
  access_token: '2354787434-1Hj0yqy7JZTIx1Dz4SuhcPrxqoILLfhjiar6xdo',
  access_token_secret: '0KULguU1rOSjDHX2aoHuA3I7w5W2mJKIIJwMhQ40AYUco'
});

// var params = {screen_name: 'sketchbooks99'};
//
// T.get('statuses/user_timeline', params, function(error, tweets, response){
//   if(!error) {
//     console.log(tweets);
//   }
//   console.log(tweets);
// });

var stream = T.stream('statuses/filter', {track: '#NowPlaying'});
stream.on('tweet', function(tw) {
  fs.writeFile(file, JSON.stringify(tw), null, null);
  fs.readFile(file, 'utf8', function (err, tw) {
    console.log(JSON.stringify(tw));
  });
});
