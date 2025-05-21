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

    alert(
        userText + " (user) vs. " + computerText + " (computer) -> "
            + resultText
    );
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

    alert(
        "Game record (win | lose | draw): "
            + record["win"] + " | " + record["lose"] + " | " + record["draw"]
    );
}

function displayGameRecord(record) {
    let win = document.getElementById("record-win");
    let lose = document.getElementById("record-lose");
    let draw = document.getElementById("record-draw");

    win.textContent = record["win"];
    lose.textContent = record["lose"];
    draw.textContent = record["draw"];
}

function startGame(record) {
    let keepPlaying = true;
    // let gameCount = 0;

    while (keepPlaying) {
        let userMove = getUserMove();
        let computerMove = getComputerMove();

        let gameResult = determineGameResult(userMove, computerMove);

        displayGameResult(userMove, computerMove, gameResult);
        updateGameRecord(record, gameResult);
        displayGameRecord(record);

        keepPlaying = confirm("Would you like to play again?");
        // gameCount += 1;
    }

    alert("Thank you for playing.");
}

let record = {
    "win": 0,
    "lose": 0,
    "draw": 0
};

startGame(record);
