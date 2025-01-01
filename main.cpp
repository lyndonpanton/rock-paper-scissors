#include <iostream>
#include <vector>
#include <ctime>

void clear_record();
void exit_game();
void play_game();
void print_introduction(); // Done
void print_options(std::vector<std::string>&); // Done
void print_record();
void set_options(std::vector<std::string>&); // Done

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

void clear_record()
{
    // Check record file exists

    // Reset values to 0 if it does
    std::cout << std::endl << "No record found..." << std::endl;
}

void exit_game()
{
    // Save any data necessary...

    std::cout << std::endl << "Thank you for playing!";
}

void play_game()
{
    std::cout << "What are you using (R, P, or S)? ";

    char playerOption;
    bool validOption = false;

    while (!validOption)
    {
        std::cin >> playerOption;

        switch (playerOption)
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

    int aiOption = rand() % 3;
    std::string aiMove;

    switch (aiOption)
    {
        case 0:
            aiMove = "Rock";
            break;
        case 1:
            aiMove = "Paper";
            break;
        case 2:
            aiMove = "Scissor";
            break;
    }

    std::cout << aiMove << std::endl << std::endl;

    // std::cout << "Rock, Paper, Scissors...!" << std::endl;
    // std::cout << "{ player option } " << "(Player) vs. " << " {ai option}";
    // std::cout << " (AI)" << std::endl << std::endl;

    // std::cout << " {winner} " << " wins!" << std::endl;
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
    std::cout << std::endl << "No record found..." << std::endl;

    /*
        Create a record file with the following format:

            { Player wins } 
            { AI wins }
    */

   // Check if record file exists

}

void set_options(std::vector<std::string>& options)
{
    options.push_back("Play (vs. AI)");
    options.push_back("Check record");
    options.push_back("Exit");
}
