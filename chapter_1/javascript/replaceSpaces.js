function replaceSpaces(string, length){

  var letters = string.split('');
  
  for(var i = 0; i < length; i++){
    
    if(letters[i] === ' '){
      letters[i] = '\%20';
    }

  }
  
  return letters.join('');

}

var s = 'Mr John Smith';

var res = replaceSpaces(s, s.length);
console.log(res);
