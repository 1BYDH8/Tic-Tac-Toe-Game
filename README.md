# Tic-Tac-Toe Game

## Description
Tic-Tac-Toe is a classic game where two players take turns marking a square in a 3×3 grid with their chosen symbol (X or O). The player who places three of their symbols in a horizontal, vertical, or diagonal row wins the game. 

This implementation allows players to choose whether to play against another human or a computer opponent. The game is played in the console and displays the current state of the board after each move.

## Features
- Play against a human or computer.
- Choose your symbol (X or O).
- Clear console-based UI displaying the game board.
- Announce the winner or a draw at the end of the game.
- Replay option after the game concludes.

## Requirements
- A C compiler (e.g., GCC)

## How to Run
1. Clone or download the repository.
2. Open a terminal and navigate to the project directory.
3. Compile the program using the following command:
```bash
gcc tictactoe.c -o tictactoe
```
4. Run the program:
``` bash
./tictactoe
```

## How to Play
1. Start the Game: Compile and run the program.
2. Choose Game Mode: 
- Human vs Human: Two players take turns.
- Human vs Computer: Play against an AI that randomly selects its moves.
3. Choose Your Symbol: Decide whether to play as 'X' or 'O'.
4. Understand the Board: The game board is displayed with positions numbered 1-9.
5. Make Your Move: Players take turns entering the number corresponding to the position where they want to place their mark.
6. Game Continuation: After each move, the updated board is displayed. The game continues until there is a winner or the game ends in a draw.
7. Winning or Draw Announcement: Once a player wins or if the game is a draw, the result will be announced.
8. Play Again: You can restart the game or exit as per your choice.

## Example Game Board
``` lua
  1 | 2 | 3
 ---|---|----
  4 | 5 | 6
 ---|---|----
  7 | 8 | 9
```

