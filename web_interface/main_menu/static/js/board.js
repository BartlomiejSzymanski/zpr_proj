function createBoard(boardSize) {
  const board = document.getElementById("board");
  board.style.setProperty("--board-size", boardSize); 
  board.selectedField = null; 
  board.currentPlayer = 1; 
  board.highlightedCell = null; 

  console.log(`Board size: ${boardSize}`);
  for (let i = 0; i < boardSize; i++) {
    for (let j = 0; j < boardSize; j++) {
      const cell = document.createElement("div");
      cell.className = "cell";
      cell.dataset.row = i;
      cell.dataset.col = j;
      cell.dataset.allowed = true;

      for (let m = 0; m < boardSize; m++) {
        for (let n = 0; n < boardSize; n++) {
          const subCell = document.createElement("div");
          subCell.className = "sub-cell";
          subCell.dataset.row = i;
          subCell.dataset.col = j;
          subCell.dataset.subRow = m;
          subCell.dataset.subCol = n;
          subCell.addEventListener("click", function () {
            handleClick(subCell, board);
          });

          cell.appendChild(subCell);
        }
      }
      board.appendChild(cell);
    }
  }
}


function handleClick(subCell, board) {
  if (board.selectedField === subCell) {
    board.selectedField.classList.remove("selected"); 
    board.selectedField = null;
  } else {
    if (board.selectedField) {
      board.selectedField.classList.remove("selected");
    }
    subCell.classList.add("selected");
    board.selectedField = subCell;
  }

}

function makeMove(cell, subRow, subCol, currentPlayer){
  selectedField = getSubcell(cell,subRow, subCol);
  board = document.getElementById("board")
  const hasSignX = selectedField.querySelector(".signX");
  const hasSignO = selectedField.querySelector(".signO");
  
  if (!hasSignX && !hasSignO) {
    if (currentPlayer === 1) {
      const signX = document.createElement("div");
      signX.className = "signX";
      signX.textContent = "X";
      selectedField.appendChild(signX);
    } else {
      const signO = document.createElement("div");
      signO.className = "signO";
      signO.textContent = "O";
      selectedField.appendChild(signO);
    }
    
    board.currentPlayer = currentPlayer === 1 ? 2 : 1;
  
  } else {
    console.log("The selected field already has a sign.");
  }
}



function handleSubmit() {
  const board = document.getElementById("board");
  const selectedField = board.selectedField;
  const currentPlayer = board.currentPlayer;
  
  const currentCell = getCell(selectedField.dataset.row, selectedField.dataset.col)
  console.log(`Cell found: ${currentCell.dataset.row}, ${currentCell.dataset.col}`) // DELETE
  console.log(`Allowed: ${currentCell.dataset.allowed}`) // DELETE

  if (currentCell.dataset.allowed === "true"){

    console.log("YES")
    nextAllowed = getCell(selectedField.dataset.subRow, selectedField.dataset.subCol)
    

    if(nextAllowed){
    
      setAllAllowedFields(board,false)

    nextAllowed.dataset.allowed = true;
    nextAllowed.classList.add("highlighted");
  }
  else {nextAllowed = currentCell}

  console.log(`Current player = ${board.currentPlayer}`)
  makeMove(currentCell, selectedField.dataset.subRow, selectedField.dataset.subCol, currentPlayer)
  board.currentPlayer = currentPlayer === 1 ? 2 : 1;
  }
  else{
    console.log("Cannot play here")
  }

}

function replaceSubCells(cell, symbol) {
  // if (selectedField.dataset.subRow === currentCell.dataset.row && selectedField.dataset.subCol === currentCell.dataset.col){
  //   setAllAllowedFields(board, true)  
  // }
  const newCell = document.createElement("div");
  newCell.className = "sign-cell";
  newCell.dataset.row = cell.dataset.row;
  newCell.dataset.col = cell.dataset.col;
  newCell.dataset.allowed = cell.dataset.allowed;

  const symbolElement = document.createElement("div");
  symbolElement.className = "sign";
  symbolElement.textContent = symbol;

  newCell.appendChild(symbolElement);

  cell.replaceWith(newCell);
}


// HELPERS

function setAllAllowedFields(board,state){
  const cells = [...board.getElementsByClassName("cell")]; 

    for (const cell of cells) {
      cell.dataset.allowed = state;
      cell.classList.remove("highlighted"); 
    }
}

function GameIsWon(player) {
  const gameContainer = document.getElementById("game-container");
  const moveButton = document.getElementById("move-button")
  const message = document.createElement("div");
  message.textContent = `${player} has won!`;
  message.className = "message";

  moveButton.style.display = "none"
  gameContainer.parentNode.appendChild(message);
}


function getCell(row, col){
  const cells = board.getElementsByClassName("cell");
    for (let i = 0; i < cells.length; i++) {
      const cell = cells[i];
      if (cell.dataset.row === row.toString() && cell.dataset.col === col.toString()) {
        return cell;
      }
    }
    return null;
}

function getSubcell(currentCell,subRow, subCol){

  const subCells = currentCell.getElementsByClassName("sub-cell");
    for (let i = 0; i < subCells.length; i++) {
      const subCell = subCells[i];
      if (subCell.dataset.subRow === subRow.toString() && subCell.dataset.subCol === subCol.toString()) {
        return subCell;
      }
    }
    return null;
}
