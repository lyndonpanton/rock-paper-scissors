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
    
}

function determineGameResult() {

}

function displayGameResult() {

}

function updateGameRecord() {

}

function startGame() {
    let keepPlaying = false;

    while (keepPlaying) {
        let userMove = getUserMove();
        // let computerMove = getComputerMove();

        // let gameResult = determineGameResult(userMove, computerMove);

        // displayGameResult(gameResult);
        // updateGameRecord(gameResult);
    }

    alert("Thank you for playing.");
}

startGame();
