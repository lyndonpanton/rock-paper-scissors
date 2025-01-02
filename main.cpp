#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

/*
    TODO

    - Add formatting and dividers to make output clearer
    - Call update_record function after a game is completed
    - Complete clear_record function
    - Complete print_record function
    - Complete update_record function
*/

int calculateWinner(char, char);
void clear_record();
void exit_game(); // Done
void play_game(); // Done
void print_introduction(); // Done
void print_options(std::vector<std::string>&); // Done
void print_record();
void set_options(std::vector<std::string>&); // Done
void update_record(int);

enum Result
{
    LOST, DREW, WON
};

int main(int argc, char* argv[])
{
    std::cout << std::endl;

    bool playing = true;
    std::vector<std::string> options;
    set_options(options);

    while (playing)
    {

        std::cout << "What would you like to do?" << std::endl;
        std::cout << std::endl;

        int option;
        bool validOption = false;

        while (!validOption)
        {
            print_options(options);

            std::cin >> option;

            if (option > 0 && option < 4)
            {
                break;
            }

            std::cout << std::endl;

            std::cout << "Invalid option entered..." << std::endl << std::endl;
        }

        switch (option)
        {
            case 1:
                play_game();
                break;
            case 2:
                print_record();
                break;
            case 3:
                playing = false;
                exit_game();
                break;
        }
    }

    std::cout << std::endl;

    return 0;
}

int calculateWinner(char player, char ai)
{
    if (player == ai)
    {
        return DREW;
    } else if (player == 'R')
    {
        if (ai == 'P') return LOST;
        if (ai == 'S') return WON;
    } else if (player == 'P')
    {
        if (ai == 'R') return WON;
        if (ai == 'S') return LOST;
    }


    if (ai == 'R')
    {
        return LOST;
    } else {
        return WON;
    }
}

void clear_record()
{
    // Check record file exists

    // Reset values to 0 if it does
    std::cout << std::endl << "No record found..." << std::endl;
}

void exit_game()
{
    std::cout << std::endl << "Thank you for playing!";
}

std::string get_move_as_text(char move)
{
    if (move == 'R') return "Rock";
    else if (move == 'P') return "Paper";
    else return "Scissors";
}

void play_game()
{
    std::cout << "What are you using (R, P, or S)? ";

    char playerMove;
    bool validOption = false;

    while (!validOption)
    {
        std::cin >> playerMove;

        switch (playerMove)
        {
            case 'R':
            case 'P':
            case 'S':
                validOption = true;
                std::cout << "Invalid option entered..." << std::endl;
                std::cout << std::endl;
                break;
        }
    }

    srand(time(0));

    int randomOption = rand() % 3;
    char aiMove;

    switch (randomOption)
    {
        case 0:
            aiMove = 'R';
            break;
        case 1:
            aiMove = 'P';
            break;
        case 2:
            aiMove = 'S';
            break;
    }

    std::cout << "Rock, Paper, Scissors...!" << std::endl;

    std::string playerText = get_move_as_text(playerMove);
    std::string aiText = get_move_as_text(aiMove);

    std::cout << playerText << " (Player) vs. " << aiText << " (Computer)";
    std::cout << "..." << std::endl << std::endl; 

    int result = calculateWinner(playerMove, aiMove);

    switch (result)
    {
        case 0:
            std::cout << "Computer wins!" << std::endl;
            break;
        case 1:
            std::cout << "Draw!" << std::endl;
            break;
        case 2:
            std::cout << "Player wins!" << std::endl;
            break;
    }

    std::cout << std::endl;

    /*
        Update record file
    */
   update_record(result);
}

void print_introduction()
{
    std::cout << std::endl;
    std::cout << "Welcome to Rock, Paper, Scissors game!" << std::endl;
    std::cout << std::endl;
}

void print_options(std::vector<std::string>& options)
{
    int i = 1;

    for (std::string option: options)
    {
        std::cout << i++ << " - " << option << std::endl;
    }

    std::cout << std::endl << "Enter a number (" << "1 - " << options.size();
    std::cout << "): ";
}

void print_record()
{

    /*
        Create a record file with the following format:

            { Player win count } 
            { AI win count }
            { Draw count }
    */

    // Check if record file exists
    std::cout << std::endl;

    std::ifstream record("record.txt");

    if (record.good())
    {
        
        int playerWinCount;
        int aiWinCount;
        int drawCount;

        while (record >> playerWinCount)
        {
            record >> aiWinCount >> drawCount;

            std::cout << "The Player has won " << playerWinCount << " time(s)!";
            std::cout << std::endl;
            
            std::cout << "The AI has won " << aiWinCount << " time(s)!";
            std::cout << std::endl;

            std::cout << "There have been " << drawCount << " draws!";
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No record exists..." << std::endl;
    }

    std::cout << std::endl;
}

void set_options(std::vector<std::string>& options)
{
    options.push_back("Play (vs. AI)");
    options.push_back("Check record");
    options.push_back("Exit");
}

void update_record(int result)
{
    // File should have 
    // Check if
    std::ifstream record("record.txt");

    if (record.good())
    {
        
    }
    else
    {
        // Create the file
        // Re-read the file
    }
}
