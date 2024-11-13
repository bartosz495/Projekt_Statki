#include <iostream>
#include "player.h"

void game(int& player1wins, int& player2wins, bool& play_again) {
    Player player1("Gracz 1");
    Player player2("Gracz 2");


    player1.setShips();
    player2.setShips();

    bool isEnd = false;
    int round = 1; 

    while (!isEnd) {
        Player& activePlayer = (round == 1) ? player1 : player2;
        Player& opponent = (round == 1) ? player2 : player1;

        std::cout << activePlayer.name << " - Twoja tura!\n";
        activePlayer.board.showBoard(false);

        int x, y;
        bool correct = false;
        while (!correct) {
            std::cout << "Podaj wspolrzedne do strzalu (x y): ";
            std::cin >> x >> y;

            if (x >= 0 && x < 10 && y >= 0 && y < 10) {
                correct = true;
                if (activePlayer.shootToOpponent(x, y)) {
                    if (opponent.ifAllDestroyed()) {
                        std::cout << "Gratulacje! " << activePlayer.name << " wygral!\n";
                        if (round == 1) {
                            player1wins++;
                        } else {
                            player2wins++;
                        }
                        std::cout << "Czy chcesz zagrac ponownie? (T/N): ";
                        char choice;
                        std::cin >> choice;
                        if (choice == 'T' || choice == 't') {
                            play_again = true; 
                        } else {
                            play_again = false; 
                        }
                        return;
                    } else {
                        std::cout << "Masz kolejna ture!\n";
                    }
                } else {
                    round = (round == 1) ? 2 : 1; 
                }
            } else {
                std::cout << "Niewlasciwe wspolrzedne! Wprowadź liczby od 0 do 9.\n";
            }
        }
    }
}

int main() {
    int winsPlayer1 = 0;
    int winsPlayer2 = 0;
    bool playAgain = true;

    while (playAgain) {
        game(winsPlayer1, winsPlayer2, playAgain);
        std::cout << "Wyniki:\n";
        std::cout << "Gracz 1: " << winsPlayer1 << " wygranych\n";
        std::cout << "Gracz 2: " << winsPlayer2 << " wygranych\n";
    }

    std::cout << "Dziekujemy za gre!" << std::endl;
    return 0;
}

