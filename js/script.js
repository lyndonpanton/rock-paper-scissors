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

function determineGameResult() {

}

function displayGameResult() {

}

function updateGameRecord() {

}

function startGame() {
    let keepPlaying = true;

    while (keepPlaying) {
        // let userMove = getUserMove();
        let computerMove = getComputerMove();
        console.log(computerMove);

        // let gameResult = determineGameResult(userMove, computerMove);

        // displayGameResult(gameResult);
        // updateGameRecord(gameResult);

        keepPlaying = false;
    }

    alert("Thank you for playing.");
}

startGame();
