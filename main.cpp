#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

/*
    TODO

    - Add formatting and dividers to make output clearer
    - Complete reset_record function
*/

/*
    Record file format:

    { Player win count }
    { AI win count }
    { Draw count}
*/

int calculateWinner(char, char); // Done
void reset_record();
void exit_game(); // Done
void play_game(); // Done
void print_introduction(); // Done
void print_options(std::vector<std::string>&); // Done
void print_record(); // Done
void set_options(std::vector<std::string>&); // Done
void update_record(int); // Done

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

            if (option > 0 && option < 5)
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
                reset_record();
                break;
            case 4:
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
                break;
            default:
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
    std::cout << std::endl;

    std::ifstream record("record.txt");

    if (record.good())
    {
        
        int player_win_count;
        int ai_win_count;
        int draw_count;

        while (record >> player_win_count)
        {
            record >> ai_win_count >> draw_count;

            std::cout << "The Player has won " << player_win_count << " time(s)!";
            std::cout << std::endl;
            
            std::cout << "The AI has won " << ai_win_count << " time(s)!";
            std::cout << std::endl;

            std::cout << "There have been " << draw_count << " draws!";
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "No record exists..." << std::endl;
    }

    record.close();

    std::cout << std::endl;
}

void reset_record()
{
    std::cout << std::endl;
       
    std::ofstream record("record.txt");

    if (record.good())
    {
        record << 0 << std::endl;
        record << 0 << std::endl;
        record << 0 << std::endl;

        std::cout << "Record has been reset" << std::endl;
    }
    else
    {
        // Write to the file
        std::cout << "No record found..." << std::endl;
    }

    std::cout << std::endl;

    record.close();
}

void set_options(std::vector<std::string>& options)
{
    options.push_back("Play (vs. AI)");
    options.push_back("Check record");
    options.push_back("Clear record");
    options.push_back("Exit");
}

void update_record(int result)
{
    std::ifstream record("record.txt");
    
    int player_win_count = 0;
    int ai_win_count = 0;
    int draw_count = 0;

    if (record.good())
    {
        record >> player_win_count >> ai_win_count >> draw_count;

        switch (result)
        {
            case 0:
                ai_win_count++;
                break;
            case 1:
                draw_count++;
                break;
            case 2:
                player_win_count++;
                break;
        }

        std::ofstream current_record("record.txt");

        current_record << player_win_count << std::endl;
        current_record << ai_win_count << std::endl;
        current_record << draw_count << std::endl;

        std::cout << std::endl;
    }
    else
    {
        // Write to the file
        std::ofstream new_record("record.txt");

        switch (result)
        {
            case 0:
                ai_win_count++;
                break;
            case 1:
                draw_count++;
                break;
            case 2:
                player_win_count++;
                break;
        }

        // Update the file
        new_record << player_win_count << std::endl;
        new_record << ai_win_count << std::endl;
        new_record << draw_count << std::endl;

        new_record.close();
    }

    record.close();
}
