function hasUniqueCharsSync(str){
  
  var seenChars = {};
  var chars = str.split('');

  for(var i = 0; i < chars.length; i++){
    var char = chars[i];
    if(char in seenChars){
      return false;
    }else{
      seenChars[char] = null;
    }
  }
  return true;

};

var hasUniqueChars = function(str, callback){

  var seenChars = {};
  var chars = str.split('');

  for(var i = 0; i < chars.length; i++){
    var char = chars[i];
    if(char in seenChars){
      return(callback(null, false));
    }else{
      seenChars[char] = null;
    }
  }

  return callback(null, true);


};

var str1 = "Hi!";
var str2 = "Hello world!";

console.log(hasUniqueCharsSync(str1))
console.log(hasUniqueCharsSync(str2))

hasUniqueChars(str1, function(err, result){
  if(err) console.error(err);

  console.log(result);  
});

hasUniqueChars(str2, function(err, result){
  if(err) console.error(err);

  console.log(result);  
});

