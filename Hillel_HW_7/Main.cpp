//Game: Rock, Paper, or Scissors

#include <iostream>

class Player
{
public:
   virtual int makeChoice() = 0;
};

class HumanPlayer : public Player
{
public: 
   virtual int makeChoice() override
   {
      int choice;
      std::cout << "Enter your move (1 - Rock, 2 - Paper, 3 - Scissors): ";
      std::cin >> choice;
      return choice;
   }
};

class BotPlayer : public Player
{
public:
   virtual int makeChoice() override
   {
      return (rand() % 3) + 1;
   }
};

class Game
{
public:
   Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

   void play() {

      while (true)
      {
         int move1 = player1->makeChoice();
         int move2 = player2->makeChoice();

         if ((move1 == 1 && move2 == 2) || (move1 == 2 && move2 == 3) || (move1 == 3 && move2 == 1)) {
            std::cout << "Player 2 wins!" << std::endl;
            break;
         }
         else if ((move1 == 1 && move2 == 3) || (move1 == 2 && move2 == 1) || (move1 == 3 && move2 == 2)) {
            std::cout << "Player 1 wins!" << std::endl;
            break;
         }
         else {
            std::cout << "It's a draw! Play again." << std::endl;
         }
      }

   }
private:
   Player* player1;
   Player* player2;
};

int main()
{
   // Create Human player and Bot player
   HumanPlayer humanPlayer;
   BotPlayer botPlayer;

   // Create game
   Game game1(&humanPlayer, &botPlayer);
   game1.play();

   // Create two human players
   HumanPlayer humanPlayer2;
   HumanPlayer humanPlayer3;
   Game game2(&humanPlayer2, &humanPlayer3);
   game2.play();

   return 0;
}