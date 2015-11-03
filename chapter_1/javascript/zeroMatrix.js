
function zeroMatrix(matrix){

  var lines = matrix.length;
  var columns = matrix[0].length;  

  var zeroCoords = [];

  for(var i = 0; i < lines; i++){
    for(var j = 0; j < columns; j++){
  
      if(matrix[i][j] === 0){
        zeroCoords.push({l:i, c:j});
      }
    } 
  }

  console.log(zeroCoords);

  zeroCoords.forEach(function(coords){
  
    //Fill line
    for(var c = 0; c < columns; c++){
      matrix[coords.l][c] = 0;
    }

    //Fill columns
    for(var l = 0; l < lines; l++){
      matrix[l][coords.c] = 0;
    }

    return matrix;

  });

}

function printMatrix(matrix){

  var lines = matrix.length;
  var columns = matrix[0].length;
  var string = '';
  
  for(var i = 0; i < lines; i++){
    for(var j = 0; j < columns; j++){
      string = string + matrix[i][j] + ' ';
    }
    string = string + '\n';
  }
  console.log(string);
}


matrix = [[1,2,3],[4,0,6],[7,8,9],[10,11,12]];

printMatrix(matrix);
var res = zeroMatrix(matrix);
printMatrix(matrix);

