#include "Game.hpp"

constexpr size_t startMoney = 1000;
constexpr size_t gameDays = 100;
constexpr size_t finalGoal = 2000;

int main() {
    Game game(startMoney, gameDays, finalGoal);
    game.startGame();
    
    return 0;
}
