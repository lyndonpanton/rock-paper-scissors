function getUserMove() {
    let userMove = prompt("What is your move?").toLowerCase();

    while (true) {
        let isMoveValid = true;

        switch (userMove) {
            case "r":
            case "rock":
                userMove = "r";
                break;
            case "p":
            case "paper":
                userMove = "p";
                break;
            case "s":
            case "scissor":
            case "scissors":
                userMove = "s";
                break;
            default:
                isMoveValid = false;
                break;
        }

        if (isMoveValid) break;

        alert("Invalid move (please enter 'rock', 'paper', or 'scissors')");

        userMove = prompt("What is your move?").toLowerCase();
    }

    return userMove;
}

function getComputerMove() {
    let computerMove = Math.floor(Math.random() * 3);

    while (true) {
        let isMoveValid = true;

        switch (computerMove) {
            case 0:
                computerMove = "r";
                break;
            case 1:
                computerMove = "p";
                break;
            case 2:
                computerMove = "s";
                break;
            default:
                isMoveValid = false;
                break;
        }

        if (isMoveValid) break;
    }

    return computerMove;
}

function determineGameResult(userMove, computerMove) {
    let result;

    if (userMove === computerMove) {
        result = 0;
    } else {
        if (userMove === "r") {
            if (computerMove === "p") {
                result = -1;
            } else {
                result = 1;
            }
        } else if (userMove === "p") {
            if (computerMove === "r") {
                result = 1;
            } else {
                result = -1
            }
        } else {
            if (computerMove === "r") {
                result = -1;
            } else {
                result = 1;
            }
        }
    }
    
    return result;
}

function displayGameResult(userMove, computerMove, gameResult) {
    let userText;

    switch (userMove) {
        case "r":
            userText = "Rock";
            break;
        case "p":
            userText = "Paper";
            break;
        case "s":
            userText = "Scissors";
            break;
    }

    let computerText;

    switch (computerMove) {
        case "r":
            computerText = "Rock";
            break;
        case "p":
            computerText = "Paper";
            break;
        case "s":
            computerText = "Scissors";
            break;
    }

    let resultText = (gameResult == 1) ? "Player wins!" :
            ((gameResult == -1) ? "Computer wins!" : "Draw!");

    let output = document.querySelector("#result");

    output.textContent =
            userText + " vs. " + computerText + " -> "
            + resultText;
}

function updateGameRecord(record, gameResult) {
    switch (gameResult) {
        case -1:
            record["lose"] += 1;
            break;
        case 0:
            record["draw"] += 1;
            break;
        case 1:
            record["win"] += 1;
            break;
    }
}

function displayGameRecord(record) {
    let win = document.getElementById("record-win");
    let lose = document.getElementById("record-lose");
    let draw = document.getElementById("record-draw");

    win.textContent = record["win"];
    lose.textContent = record["lose"];
    draw.textContent = record["draw"];
}

function startGame(record, userMove) {
    let keepPlaying = true;
    // let gameCount = 0;

    let computerMove = getComputerMove();

    let gameResult = determineGameResult(userMove, computerMove);

    displayGameResult(userMove, computerMove, gameResult);
    updateGameRecord(record, gameResult);
    displayGameRecord(record);

    if (record["win"] >= 5) {
        endGame(true);
    } else if (record["lose"] >= 5) {
        endGame(false);
    }

    // gameCount += 1;
}

function endGame(isPlayerWinner) {
    let output = document.querySelector("#result");

    if (isPlayerWinner) {
        output.textContent = "Player wins!"
    } else {
        output.textContent = "Computer wins!"
    }
}

function chooseOption(e) {
    let choice = e.target.getAttribute("id");

    switch (choice) {
        case "rock":
            startGame(record, "r");
            break;
        case "paper":
            startGame(record, "p");
            break;
        case "scissors":
            startGame(record, "s");
            break;
    }
}

let buttons = document.querySelectorAll(".rps-button");
buttons.forEach((button) => {
    button.addEventListener("click", chooseOption);
});

let record = {
    "win": 0,
    "lose": 0,
    "draw": 0
};

// startGame(record);

// module.exports = {
//     determineGameResult   
// };
