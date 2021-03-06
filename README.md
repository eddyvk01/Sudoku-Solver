# Sudoku-Solver ![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)

This Sudoku Game Is Made in C++ using Bracktracking algorithm
This repo consists of file It includes a graphical GUI as well as a text based version.

Run `Sudoku_end.cpp` to play sudoku.<br>

**BACKTRACKING** is simply reverting back to the previous step or solution as soon as we determine that our current solution cannot be continued into a complete one. We will use this principle of backtracking to implement the following algorithm.

## ALGORITHM

Starting with an incomplete board:

1. Find some empty space
2. Attempt to place the digits 1-9 in that space
3. Check if that digit is valid in the current spot based on the current board
4. *a.* If the digit is valid, recursively attempt to   fill the board using steps 1-3.<br>
 *b.* If it is not valid, reset the square you just filled and go back to the previous step.
5. Once the board is full by the definition of this algorithm we have found a solution.

we will finish the algorithm and continue to understand by running through our code step by step. We will use a recursive function to implement the algorithm 
In part 2 (look below) we will implement the entire algorithm with the GUI to show the visuall implimentaion of the game.

Hope You Will Like The Game. also u can use the code to make your own version of game.

<!-- ### DEMO - sudokuGUI.py -->
<!-- ![sudokudemo](https://user-images.githubusercontent.com/91308138/161383210-7c0cf10f-9c40-4ab7-b92c-473c09a99f5d.gif) -->

###  DEMO - Sudoku_end.cpp
```
=============== SUDOKU ================
              EASY LEVEL
=======================================

                             ________________________
                            |7 8 0  | 4 0 0  | 1 2 0 |
                            |6 0 0  | 0 7 5  | 0 0 9 |
                            |0 0 0  | 6 0 1  | 0 7 8 |
                            |_______|________|_______|
                            |0 0 7  | 0 4 0  | 2 6 0 |
                            |0 0 1  | 0 5 0  | 9 3 0 |
                            |9 0 4  | 0 6 0  | 0 0 5 |
                            |_______|________|_______|
                            |0 7 0  | 3 0 0  | 0 1 2 |
                            |1 2 0  | 0 0 7  | 4 0 0 |
                            |0 4 9  | 2 0 6  | 0 0 7 |
                            |_______|________|_______|

 Press [1]  to Pause the Game.
 and  Press[2] to find solution of the SUDOKU

```
Pressing-'2' for solution:
```
=============== SOLUTION ================
                             ________________________
                            |7 8 5  | 4 3 9  | 1 2 6 |
                            |6 1 2  | 8 7 5  | 3 4 9 |
                            |4 9 3  | 6 2 1  | 5 7 8 |
                            |_______|________|_______|
                            |8 5 7  | 9 4 3  | 2 6 1 |
                            |2 6 1  | 7 5 8  | 9 3 4 |
                            |9 3 4  | 1 6 2  | 7 8 5 |
                            |_______|________|_______|
                            |5 7 8  | 3 9 4  | 6 1 2 |
                            |1 2 6  | 5 8 7  | 4 9 3 |
                            |3 4 9  | 2 1 6  | 8 5 7 |
                            |_______|________|_______|
successfully solved the board!

Here , the solution.

=======================================
(Press any key to go back!)
```

PLEASE FEEL FREE TO FORK THE PROJECT AND START CONTRIBUTING. :)

### How to Play the game:
```
=============== SUDOKU ================

[1] START
[2] INSTRUCTIONS
[3] EXIT
=======================================
(Press the number of your choice!)
```
PRESSING THE '1' TO START THE GAME: 
```
=============== SUDOKU ================
          SELECT A DIFFICULTY
[1] EASY
[2] MEDIUM
[3] HARD
=======================================
[4] BACK
=======================================
(Press the number of your choice!)
```
SELECTING THE LEVEL OF DEFICULTY ACCORDING TO YOUR CHOICE !<BR>
>***EXAMPLE:-***
PRESSING 2 FOR MEDIUM LEVEL GAME PLAY
```
=============== SUDOKU ================
             MEDIUM LEVEL
=======================================

                             ________________________
                            |0 8 4  | 2 0 0  | 0 0 9 |
                            |1 0 2  | 8 0 0  | 5 0 0 |
                            |9 0 0  | 0 6 0  | 0 0 3 |
                            |_______|________|_______|
                            |0 9 0  | 0 0 0  | 2 7 0 |
                            |5 0 0  | 0 0 0  | 0 0 8 |
                            |0 4 8  | 0 0 0  | 0 3 0 |
                            |_______|________|_______|
                            |7 0 0  | 0 2 0  | 0 0 1 |
                            |0 0 3  | 0 0 6  | 7 0 4 |
                            |4 0 0  | 0 0 5  | 3 9 0 |
                            |_______|________|_______|

 Press [1]  to Pause the Game.
 and  Press[2] to find solution of the SUDOKU
```
Finally to solve the board press `2`, sit back and watch the algorithm run.

## PRE-REQUISITES
Your laptop with C++ installed.

**NOTE:** Those with Linux and MacOSX would have C++ installed by default, no action required.

Windows: Download the version for your laptop via https://sourceforge.net/projects/orwelldevcpp/

**NOTES**
In your preferred editor, make sure indentation is set to "4 spaces".

---

## Run using DevC++
1. Clone or download repositiory: https://github.com/eddyvk01/Sudoku-Solver.git
2. In source folder, run `Sudoku_end.exe` to start program, optionally, run with `--help` argument to see other runtime options.
 
### ThankYou!
