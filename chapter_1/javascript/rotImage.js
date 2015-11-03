function rotateImage(matrix){

  var n = matrix[0].length;
  var offset = 0;
  
  for(var l = 0; l < Math.floor(n/2); ++l){

    for(var c = offset; c < n - offset - 1; ++c){

      var coords = getNewCoords(l, c, n);
      var oldValue = matrix[coords.l][coords.c];
      matrix[coords.l][coords.c] = matrix[l][c];

      coords = getNewCoords(coords.l, coords.c, n);
      var currentVal = matrix[coords.l][coords.c];
      matrix[coords.l][coords.c] = oldValue;
      oldValue = currentVal;

      coords = getNewCoords(coords.l, coords.c, n);
      currentVal = matrix[coords.l][coords.c];
      matrix[coords.l][coords.c] = oldValue;
      oldValue = currentVal;

      coords = getNewCoords(coords.l, coords.c, n);
      currentVal = matrix[coords.l][coords.c];
      matrix[coords.l][coords.c] = oldValue;
            
    }
    offset++;

  }

}


function getNewCoords(x, y, n){

  return {l: y, c: n - x - 1};

}

function printMatrix(matrix){

  var k = matrix[0].length;
  var string = '';
  
  for(var i = 0; i < k; i++){
    for(var j = 0; j < k; j++){
      string = string + matrix[i][j] + ' ';
    }
    string = string + '\n';
  }
  console.log(string);
}


var matrix = [[1,2,3,4], [5,6,7,8], [9,10,11,12], [13,14,15,16]];
matrix = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25,26]];

printMatrix(matrix);
rotateImage(matrix);
printMatrix(matrix);

