function isPermutation(string1, string2){

  var lettersS1 = string1.split('');
  var lettersS2 = string2.split('');

  lettersS1.sort();
  lettersS2.sort();

  for(var i = 0; i < lettersS1.length; i++){

    if(lettersS1[i] == lettersS2[i]){
      continue;
    }else{
      return false;
    }

  }

  return true;

}


var s1 = 'helloo';
var s2 = 'ololeh';

var res = isPermutation(s1, s2);
console.log(res);
