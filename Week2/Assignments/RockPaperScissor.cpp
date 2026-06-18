#include <iostream>
#include <random>
#include <ctime>

int main() {
    //to be a able to generate a new random number (1-3) every time we run it, instead of the same one.
    srand(time(0));

    char player;
    int bot_choice;
    char play_again = 'y';
    int player_wins = 0;
    int bot_wins = 0;
    
std::cout << "Welcome to our new remodeled rock, paper, scissors game!\n";
std::cout << "--------------------------------------------------------\n";
std::cout << "There are some clear instructions we need you to understand:\n ";
std::cout << "1) You must select either Rock, Paper or Scissors to play the game\n";
std::cout << "2) This game is not multiplayer, you will be matched against a computer generated player (bot)\n";
std::cout << "3) In this game: Rock beats Scissors, Scissors beats paper and Paper beats rock\n";
std::cout << "4) If you win two out of three rounds, you will be considered the winner\n";
std::cout << "5) Have fun! and remember the luck may always (or not) be by your side.\n";
 while (play_again == 'y') {

        int player_wins = 0;
        int bot_wins = 0;

        while (player_wins < 2 && bot_wins < 2) {

            // validate the user input
            do {
                std::cout << "Select: 'r' Rock | 'p' Paper | 's' Scissors\n";
                std::cin >> player;
            } while (player != 'r' && player != 'p' && player != 's');

            bot_choice = (rand() % 3) + 1;

            // the player choices
            std::cout << "You selected: ";
            switch (player) {
                case 'r': std::cout << "Rock\n";
                break;
                case 'p': std::cout << "Paper\n";
                break;
                case 's': std::cout << "Scissors\n";
                break;
            }
            //bot choices
            std::cout << "Bot selected: ";
            switch (bot_choice) {
                case 1: std::cout << "Rock\n";
                break;
                case 2: std::cout << "Paper\n";
                break;
                case 3: std::cout << "Scissors\n";
                break;
            }
            // Results for tie crowd comments
            if ((player == 'r' && bot_choice == 1) ||
                (player == 'p' && bot_choice == 2) ||
                (player == 's' && bot_choice == 3)) {
                std::cout << "Tie!!! Crowd: Come on bro, you got this!\n";
            }
            // players victory and crowd comments
            else if ((player == 'r' && bot_choice == 3) ||
                     (player == 'p' && bot_choice == 1) ||
                     (player == 's' && bot_choice == 2)) {
                player_wins++;
                std::cout << "You win!!! | Crowd: ";
                switch (player_wins) {
                    case 1:  std::cout << "That's what i like to see\n";
                    break;
                    case 2:  std::cout << "Hell yeah!!\n";
                    break;
                    default: std::cout << "I always believed in you!!!\n";
                    break;
                }
            }
            //bot victory and crowd comments
            else {
                bot_wins++;
                std::cout << "Bot wins!!! | Crowd: ";
                switch (bot_wins) {
                    case 1:  std::cout << "you got this! dont start lacking off!\n";
                    break;
                    case 2:  std::cout << "Come on.Momma did not raise a quitter!!\n";
                    break;
                    default: std::cout << "Better luck next time :c \n";
                    break;
                }
            }

            std::cout << "Score:\n You: " << player_wins << " Bot: " << bot_wins << "\n\n";
        }

        // the final result
        std::cout << "=== Final Score:\n You " << player_wins << " - " << bot_wins << " Bot ===\n";
        if (player_wins > bot_wins) std::cout << "Crowd: YOU ARE THE GOAT!!!!\n";
        else                        std::cout << "Crowd: WOW, I guess machines were better this time >:c\n";

        std::cout << "\nPlay again? 'y' Yes | 'n' No\n";
        std::cin >> play_again;
        std::cout << "\n";
    }

    std::cout << "Thanks for playing!\n";

}