function isSubstring(s1, s2){

  var s1Letters = s1.split('');
  var s2Letters = s2.split('');

  if(s1Letters.length != s2Letters.length){
    return false;
  }

  for(var i = 0; i < s2Letters.length; i++){

    if(s2Letters[i] === s1Letters[0]){

      var nChecked = 1;
      var offset = i;

      for(var j = 1; j < s2Letters.length; j++){
        if(s1Letters[j] === s2Letters[(j + offset) % s2Letters.length]){
          nChecked++;
          if(nChecked === s1Letters.length){
            return true;
          }
        }
      } 
    }
  }
  return false;
}


var s1 = 'wooww';
var s2 = 'owwo';

var res = isSubstring(s1, s2);

console.log(res);
