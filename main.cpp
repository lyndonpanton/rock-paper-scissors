#include <iostream>
#include <vector>

void printOptions(std::vector<std::string>&);
void setOptions(std::vector<std::string>&);

int main(int argc, char* argv[])
{
    bool playing = true;
    std::vector<std::string> options;
    setOptions(options);

    while (playing)
    {
        std::cout << std::endl;
        std::cout << "Welcome to Rock, Paper, Scissors game!" << std::endl;
        std::cout << std::endl;

        std::cout << "What would you like to do?" << std::endl;
        std::cout << std::endl;

        bool validOption = false;

        while (!validOption)
        {
            printOptions(options);

            int option;

            std::cin >> option;

            if (option > 0 && option < 4)
            {
                break;
            }

            std::cout << std::endl;

            std::cout << "Invalid option entered..." << std::endl << std::endl;
        }

        break;
    }

    return 0;
}

void setOptions(std::vector<std::string>& options)
{
    options.push_back("Play (vs. AI)");
    options.push_back("Check record");
    options.push_back("Exit");
}

void printOptions(std::vector<std::string>& options)
{
    int i = 1;

    for (std::string option: options)
    {
        std::cout << i++ << " - " << option << std::endl;
    }

    std::cout << std::endl << "Enter a number (" << "1 - " << options.size();
    std::cout << "): ";
}
