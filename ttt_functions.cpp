#include <iostream>
#include "play.hpp"


std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " ",};
  int player = 1;
  int position =0;

  void introduction() {


  std::cout << "===========\n";
  std::cout << "Tic-Tac-Toe\n";
  std::cout << "===========\n\n";
  
  std::cout << "Player 1) X \n";
  std::cout << "Player 2) O\n\n";

  std::cout << "Here's how the grid will look:\n\n";

  std::cout << "     |     |      \n";
  std::cout << "  1  | 2   |  3   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  4  |  5  |  6   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  7  |  8  | 9    \n";
  std::cout << "     |     |      \n\n";

}

  bool winner_is() {
    // this is the default state
    bool winner = false;
    //for rows
    if ((board[0] == board[1]) && (board[1] == board[2]) && (board[0] != " ") ){
      // std::cout << "You've won \n"; 
      
    }
    else if ((board[3] == board[4]) && (board[4] == board[5]) && (board[3] != " ") ){
     winner = true;
    }
   else if ((board[6] == board[7]) && (board[7] == board[8]) && (board[6] != " ") ){
      winner = true;
    }
  // for columns
     else if ((board[0] == board[3]) && (board[3] == board[6]) && (board[0] != " ") ){
      winner = true;
    }
     else if ((board[1] == board[4]) && (board[4] == board[7]) && (board[1] != " ") ){
      winner = true;
    }
     else if ((board[2] == board[5]) && (board[5] == board[8]) && (board[2] != " ") ){
      winner = true;
    }
  //for diagonals
     else if ((board[0] == board[4]) && (board[4] == board[8]) && (board[0] != " ") ){
      winner = true;
    }
     else if ((board[2] == board[4]) && (board[4] == board[6]) && (board[2] != " ") ){
      winner = true;
    }

    return winner;
  }

//using bool cause it can either be filled up or not i.e yes or no. Basically the defalut of filled is ture (i.e it's filled) but if there are still spaces in the board (i.e board[i]=" ") then filled is false (i.e still spaces). But at the end filled is return whether true or false.
  bool filled_up() {
    bool filled = true;
    for (int i = 0; i < 9; i++){
      if(board[i] == " "){
        filled = false;
      }
    }
  return filled;
  }


  void draw(){

    
    std::cout << " "<< board[0]<<"   |  "<<board[1]<<"  |   " << board[2] << "\n";
   std::cout << "___________________  \n";
    std::cout << " "<< board[3]<<"   |  "<<board[4]<<"  |   " << board[5] << "\n";
    std::cout << "___________________  \n";
    std::cout << " "<< board[6]<<"   |  "<<board[7]<<"  |   " << board[8] << "\n";
    std::cout << "___________________  \n";
  
    
  } 
  void set_position(){

    std::cout << "Player "<< player << "'s turn, Enter a number between 1 - 9 \n";
    // std::cin >> position;

    while (!(std::cin >> position)) {

    std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
    std::cin.clear();
    std::cin.ignore();
    }

  // } do not understand it yet.
    std::cout << "\n";

    while (board[position-1] != " "){
    std::cout << "something is already here \n\n";

    std::cout << "Player "<< player << "'s turn. Enter a number 1 - 9 \n";
    std::cin >> position;
    std::cout << "\n";
  }
  }

//remember from the introduction player 1 = X and player 2 = O. and % shows remainder (i.e if 2/2= 1 remainder 0; with the % it willl show 0). Remember from the beginning (in the global scope, player = 1, so if 1/2 = 0 remainder 1). So player 1 == x, and from this function, the board postion shows x. Then from the change player function if player == 1, player++, then player == 2; then the next turn is for player 2, so whatever action on the board will be O will the update board function.

  void update_board(){
    if (player % 2 == 1){
      board[position-1] = "X";
    } else{
      board[position-1] = "O";
    }
  }


// remember we started with player = 1; so if player is 1, then player++, which means next player (i.e player 2). [From the introduction and update_function above, player 1 = x, then player 2 = o; i.e next palyer]. but In this function if player == 2, then it because player--, (i.e it goes back to player == 1, meaning the turn goes back to the first palyer). If there were more than two players it will go something like if (player == 1){player++} else if (player == 2){player++} else{player == 1}. Here there are 3 players, so after player 1, there's player 2, then player 3. then it goes back to player 1 and the cycle continues.

  void change_player(){
    if (player == 1){
      player++;
    } else{
      player--;
    }
  }

//the functions here keeps running while the winner and space isn't filled, but once the condition change (i.e there's a winner or the spaces are filled), then it runs the code block in which ever function either in the winner_is function ot the filled_up function. Here you just need to call the function, no need to include the return type.


void taking_turns(){
  while (!winner_is() && !filled_up()){
    set_position();
    update_board();
    change_player();
    draw();


  }
}




// if winner is true (refer to the winner_is function) then it display the text, but if the winner is false and the spaces are filled, it displays "there's a tie". because the is_winner function is a bool, if(is_winner) is a truthy, meaning it checks if is_winner is true then outputs/runs the code in the code block. S o there is no need to write the if(winner_is == true); if (winner_is) works the same too.

 void game_over() {
   if (winner_is() == true){
     std::cout << "There's a winner \n";
   }
  else if (filled_up() == true && winner_is() == false){
     std::cout << "It's a tie\n";
   }
 }






  
