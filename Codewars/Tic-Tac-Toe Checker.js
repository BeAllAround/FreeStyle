function isSolved(board) {
  let horizontal = []
  let vertical = []
  let diagonal = []
  let unfinished = false
  
  for(let i = 0; i < board.length; i++) {
    let match = undefined
    let arr = []
    horizontal.push(arr)
    for(let j = 0; j < board.length; j++) {
      arr.push(board[i][j])
      if(board[i][j] === 0){
        unfinished = true
      }
        
      if(match === undefined) {
        match = board[i][j]
      }else {
        if(match == board[i][j] && board[i][j] !== 0) {
          match = board[i][j]
        }else {
          match = undefined
          break
        }
      }

    }
    
    
    if(match !== undefined) {
      return match
    }
    
  }
  
  
  for(let i = 0; i < board.length; i++) {
    let match = undefined
    let arr = []
    vertical.push(arr)
    
    for(let j = 0; j < board.length; j++) {
      arr.push(board[j][i])
      
      if(board[j][i] === 0) {
        unfinished = true
      }
      
      if(match === undefined) {
        match = board[j][i]
      }else {
        if(match == board[j][i] && board[j][i] !== 0) {
          match = board[j][i]
        }else {
          match = undefined
          break
        }
      }
      
    }
    if(match !== undefined) {
      return match
    }
    
  }
  
  let match = undefined
  for(let i = 0; i < board.length; i++) {
      diagonal.push(board[i][i])
      
      if(board[i][i] === 0) {
        unfinished = true
      }
      
      if(match === undefined) {
        match = board[i][i]
      }else {
        if(match == board[i][i] && board[i][i] !== 0) {
          match = board[i][i]
        }else {
          match = undefined
          break
        }
      }
  }
  if(match !== undefined) {
    return match
  }
  
  match = undefined
  let j = board.length-1
  for(let i = 0; i < board.length; i++) {
      diagonal.push(board[i][j])
      
      if(board[i][j] === 0) {
        unfinished = true
      }
      
      if(match === undefined) {
        match = board[i][j]
      }else {
        if(match == board[i][j] && board[i][j] !== 0) {
          match = board[i][j]
        }else {
          match = undefined
          break
        }
      }
    j--;
    
  }
  if(match !== undefined) {
    return match
  }
  
  for (let arr of board) {
    for(let b of arr) {
      if(b == 0) { // TODO: refactor
        return -1
      }
    }
  }
  
  // console.log(horizontal)
  // console.log(vertical)
  if(!unfinished) { // draw basically
    return 0
  }
  return -1
  
}
