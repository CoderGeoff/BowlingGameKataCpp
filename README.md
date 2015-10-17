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

1. Look over your test and see if there's anything - variable names, use of whitespace, etc. - that could be improved. 
Each time you make an improvement, run the tests again to verify they pass, and ##commit the changes to the git repository##.

### Step 5. The second test: 20 ones should score 20

1. Create a new test in the BowlingGameTests test suite, called GivenTwenty1sBowled_WhenGameScoreCalculated_ShouldBe20.
2. Implement the test. Don't worry about any duplication between the test you're writing and the one that's already there; you'll deal with that in the refactor step.
3. Run it and verify that it fails on the assert.

### Step 6. Implementation for the second test

1. Implement just enough code in Game::Roll() and Game::Score() to get both tests passing. 
The implementation should do no more than keep a running total of the number of pins scored; the rest of the implementation can wait until we have 
a test to validate it.
2. Run the tests and verify that they pass.
3. Commit the code to the git repository.

### Step 7. Refactor

1. Go back to the tests, and remove the duplication in the calls to Roll() by factoring out a useful common method that both tests can use. 
2. Compile and run the tests to verify they still both work.
3. Commit to git.
1. Look over your tests and the BowlingGame class to check whether there's anything else that could be improved. Each time you make an improvement, run the tests again to verify they pass, and commit.

### Step 8. The third test, Red stage: A spare should collect a bonus

1. Write a failing test to capture the bonus after a spare. The simplest test we can write is:
  ## the first frame is a spare (say, 0 then 10)
  ## the next ball scores (say, 3)
  ## the remaining balls all go down the gutter
So implement the test, GivenOneSpareThen3Bowled_WhenGameScoreCalculated_ShouldBe16.

2. Compile and run the test.
3. Verify that it fails on the assert.

### Step 9. The third test, Green stage: implement the bonus for a spare
To implement spares, we're going to need some information about frames. We're going give the responsibility of monitoring the state of a frame to another class FrameState.
We're going to calculate spare bonnus using a third class SpareBonus. We'll implement both these classes using TDD, starting out with writing a failing test. But we've got 
a problem: we've already got one test failing; now we need to write another failing test before we can get this one to pass. There are a few options

  ## Mark the current failing test to be ignored, so that it's not run when we run the tests.
  ## Revert the last commit and go back to the point where all the tests were passing.
  ## Create a new branch from the point of the last commit and develop the classes we need there.
  
Each has it's merits. Here we're going to go with the last option.
