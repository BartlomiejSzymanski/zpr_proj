/**
 * Creates board dynamically based on board_size set in board.html
 */
function createBoard() {
  const board = document.getElementById("board");
  boardSize = board.dataset.boardSize;
  board.dataset.gameMode = document.getElementById("mode").getAttribute("data-game-mode");
  
  // Set CSS custom property
  board.style.setProperty("--board-size", boardSize); 
  
  console.log(`GAME MODE: ${board.dataset.gameMode}`)

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

/**
 * 
 * @param {HTMLElement} subCell subcell of a Cell that has been selected
 * @param {HTMLElement} board current board which contains selectedField
 */
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
/**
 * Sets a sign corresponding to player id to a given field of a subcell in a given cell
 * @param {HTMLElement} targetCell cell to which the move will be made
 * @param {number} subRow row number in subcell of target cell
 * @param {number} subCol column number in subcell of target cell
 * @param {number} currentPlayer player that makes the move
 * @returns set of: row and col of target cell, subRow and subCol of subcell, player id
 */
function makeMove(targetCell, subRow, subCol, currentPlayer){
  selectedField = getSubcell(targetCell,subRow, subCol);
  board = document.getElementById("board")
  const hasSignX = selectedField.querySelector(".signX");
  const hasSignO = selectedField.querySelector(".signO");
  
  if (targetCell.dataset.allowed === "true"){

    nextAllowed = getCell(selectedField.dataset.subRow, selectedField.dataset.subCol)    

    if(nextAllowed){
      setAllAllowedFields(board,false)

      nextAllowed.dataset.allowed = true;
      nextAllowed.classList.add("highlighted");
    }
  else {nextAllowed = targetCell}

  console.log(`Current player = ${board.currentPlayer}`)

  
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
    moveData = {
      row: parseInt(targetCell.dataset.row),
      col: parseInt(targetCell.dataset.col),
      subRow: parseInt(subRow),
      subCol: parseInt(subCol),
      currentPlayer: board.currentPlayer
      
    };
    return moveData;
  }
  
  
  else {
    console.log("The selected field already has a sign.");
  }
}
  else{
    console.log("Cannot play here")
    return 
  }
}


/**
 * Make move button handler. Used in player vs player gamemode.
 */
function humanMove() {
  const board = document.getElementById("board");
  const selectedField = board.selectedField;
  const currentPlayer = board.currentPlayer;
  
  const targetCell = getCell(selectedField.dataset.row, selectedField.dataset.col)

  const moveData = makeMove(targetCell, selectedField.dataset.subRow, selectedField.dataset.subCol, currentPlayer);
  
  console.log(`Current player = ${board.currentPlayer}`)

  passMoveToEngine(moveData);

}

/**
 * Removes all subcells from given cell and displays sign from parameter
 * @param {HTMLElement} moveData Dataset of player move conatining {row,col, subRow, subCol, player}
 */
function replaceSubCells(moveData) {

  if (moveData["row"] === moveData["subRow"] && moveData["col"] === moveData["subCol"]){
    setAllAllowedFields(board, true)
  }
  const newCell = document.createElement("div");
  newCell.className = "sign-cell";
  newCell.dataset.row = cell.dataset.row;
  newCell.dataset.col = cell.dataset.col;
  newCell.dataset.allowed = cell.dataset.allowed;

  const symbolElement = document.createElement("div");
  symbolElement.className = "sign";
  symbolElement.textContent = "";
  if(moveData["currentPlayer"] === 1){
    symbolElement.textContent = "O";
  }
  else {symbolElement.textContent = "X"}

  newCell.appendChild(symbolElement);

  cell.replaceWith(newCell);
}


// HELPERS
/**
 * Sets all subcells allowed state to true or false
 * @param {HTMLElement} board board which cells should be set
 * @param {string} state state which will be set
 */
function setAllAllowedFields(board,state){
  const cells = [...board.getElementsByClassName("cell")]; 

    for (const cell of cells) {
      cell.dataset.allowed = state;
      cell.classList.remove("highlighted"); 
    }
}

/**
 * Implements game finish after game is won. Disables further moves
 * @param {number} player Player that has won.
 */
function GameIsWon(player) {
  const gameContainer = document.getElementById("game-container");
  const moveButton = document.getElementById("move-button")
  const message = document.createElement("div");
  board = document.getElementById("board")
  gameMode = board.dataset.gameMode
  console.log(`Player :${player} and game mode: ${gameMode} `)
  if(gameMode === "1" && player === 2){
    message.textContent = `CPU won!`;
  }
  else{
  message.textContent = `Player${player} won!`;
  }
  message.className = "message";

  moveButton.style.display = "none"
  gameContainer.parentNode.appendChild(message);
}

/**
 * Getter function to return cell object from given coordinates
 * @param {number} row row parameter of given cell
 * @param {number} col col parameter of given cell
 * @returns {HTMLElement} Cell of given row and col
 */
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

/**
 * Getter function to return subcell object from given cell with set coordinates
 * @param {HTMLElement} targetCell cell which should be searched
 * @param {number} subRow row parameter of given subcell 
 * @param {number} subCol column parameter of given subcell
 * @returns {HTMLElement}
 */
function getSubcell(targetCell,subRow, subCol){

  const subCells = targetCell.getElementsByClassName("sub-cell");
    for (let i = 0; i < subCells.length; i++) {
      const subCell = subCells[i];
      if (subCell.dataset.subRow === subRow.toString() && subCell.dataset.subCol === subCol.toString()) {
        return subCell;
      }
    }
    return null;
}

/**
 * Gets cookie of a given name
 * @param {string} name Cookie name
 * @returns cookie object
 */
function getCookie(name) {
  const value = `; ${document.cookie}`;
  const parts = value.split(`; ${name}=`);
  if (parts.length === 2) return parts.pop().split(';').shift();
}

// w tej funkcji chcemy wykonany ruch przekazać do silnika i zapytać, która plansza wygrana. Specjalny kod oznacza wygraną grę

/**
 * Communicates to Django views function. Passes one of the players move
 * @param {HTMLElement} moveData dataset representing move of a player
 */
function passMoveToEngine(moveData){

  const csrftoken = getCookie('csrftoken')
  const xhr = new XMLHttpRequest();
  xhr.open('POST', '/pass_move', true);
  xhr.setRequestHeader('Content-Type', 'application/json');
  xhr.setRequestHeader('X-CSRFToken', csrftoken)
  gameMode = document.getElementById("board").dataset.gameMode;
  
  if (moveData){
  moveData =  JSON.stringify(moveData)
  move = JSON.parse(moveData)
  console.log(`MoveData: ${moveData}`)
  
  xhr.send(moveData);

  xhr.onreadystatechange = function () {
    if (xhr.readyState === XMLHttpRequest.DONE && xhr.status === 200) {
      const response = JSON.parse(xhr.responseText)
      console.log(response)
      if (response["gameWon"]) {GameIsWon(move["currentPlayer"]);}
      
      if (response["subCellWon"]) {
        cell = getCell(move["row"], move["col"]);
        replaceSubCells(move);
      }
      
      else if(gameMode === "1") {
        const targetCell = getCell(response["row"], response["col"]);
        makeMove(targetCell,response["subRow"], response["subCol"],2)}
    
    }
  };


  }
}
