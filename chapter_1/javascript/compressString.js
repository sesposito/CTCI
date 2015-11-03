function compressString(string){

  var letters = string.split('');
  var currentLetter = letters[0];
  var counter = 1;
  var compressedString = '';

  for(var i = 1; i < string.length; i++){

    if(letters[i] === currentLetter){
      counter++;
    }else{
      compressedString = compressedString + currentLetter + counter;
      counter = 1;
      currentLetter = letters[i];
    }
  }

  compressedString = compressedString + currentLetter + counter;

  return compressedString;

}


var s = 'aabcccccaaabccccccccccc';
var res = compressString(s);
console.log(res);
