# Bowling Game Kata
The start of the classic bowling game kata, in C++ with CppUnit
For Visual Studio 2013 

This is the well-known "Bowling Game Kata". It's presented here as an introduction to TDD.

## Introduction

### The objective
Following TDD (Red, Green, Refactor) implement a class, ```BowlingGame```, that calculates a single player's score in a bowling game.
The class has two methods

```
// Call Roll() any number of times in succession to record the number of pins knocked down by the player's balls
void Roll(int pins);
// Call Score() at any time to calculate the score 
int Score();
```

There's no requirement to score individual frames, or or determine when an complete game has been played.

### The scoring rules
A bowling game consists of 10 frames.  In each frame the player has to try to knock down 10 pins, by bowling two balls at them. 
If the player knocks down all 10 with the first ball, the frame ends and the second ball isn’t bowled. 

The score for the frame is the total number of pins knocked down, plus bonuses for strikes (all pins knocked down by the first ball) 
and spares (all pins knocked down by the end of the frame). The bonus for a spare is the number of pins knocked down by the next roll.  
So if in one frame, a player scored 5 and 5 (a spare) and in the next, they score 2 and 3, their score for the first frame is 5 + 5 
(the number of pins knocked down in the frames) + 2 (the bonus for the spare). That is, 12. The next frame scores 2 + 3, i.e. 5.
The bonus for a strike is the number of pins knocked down by the next two rolls.  So if in one frame, a player scored 10, and the in next frame 
10 and the in one after 10 again, then the score for the first frame is 10 + 10 + 10, i.e. 30. 
A player who rolls a spare or strike in the tenth frame is allowed to roll extra balls to allow the bonus for the frame to be scored. 

## Instructions

### Step 1. Getting started

1. Clone the repository. This creates a new git repository on your local machine.
2. Open the solution file in Visual Studio.
There are two projects. BowlingGameKata is an empty project, where you will develop the BowlingGame class. BowlingGameKataTests is the project where you will develop the tests.
BowlingGameKata already contains a file, BowlingGameTests.cpp, which contains the skeleton of your first test. 
3. Build the solution.
4. Run the test executable, Debug\BowlingGameKataTests.exe. It should output

```
OK (1)
```

to show that one test has passed and none failed.

### Step 2. The first test, Red stage: write the first failing test
1. Open the file BowlingGameTests.cpp. The first test, When20GutterBallsRolled_ScoreShouldBe0, has been started for you. 
1. Implement the test as follows
  1. Creates a new BowlingGame object. Don't worry that the code won't complile, just carry on coding.
  2. Use it to call Roll(0) 20 times
  3. Call the game's Score() method to request the score. 
  4. Finally the test checks that the score is 0. 
1. Now implement just enough code to get the assert to fail. You will have to 
  1. Write a new BowlingGame class in the BowlingGame project.
  2. Incude the class's header file in BowlingGameTests.cpp.
  3. Create a new method, void Game::Roll(int pins). Leave the method body empty.
  4. Create a new method, int Game::Score(). Implement the method by returning -1. (Why don't we return 0 here?)
  5. Build the code, ensure it compiles and links.
  6. Run the test executable, Debug\BowlingGameKataTests.exe. It should output
  
```
Test name: BowlingGameTests::When20GutterBallsRolled_ScoreShouldBe0
equality assertion failed
- Expected: 0
- Actual  : -1

Failures !!!
Run: 1   Failure total: 1   Failures: 1   Errors: 0
```

Nice. 

### Step 3. The first test, Green stage: get the first test to pass
In the green stage, we write just enough code to get the test to pass. So
1. Change the implementation of Game::Score() to return 0.
2. Compile and run the tests.
3. Verify that the test passes.
4. Commit your changes to your local git repository.

### Step 4. The first test, refactor stage.
1. Look over your test and see if there's anything - variable names, formatting etc. - that could be improved. 
Each time you make an improvement, run the tests again to verify they pass, and ##commit the changes to the git repository##.

