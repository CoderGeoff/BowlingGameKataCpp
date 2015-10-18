# Bowling Game Kata
The start of the classic bowling game kata, in C++ with CppUnit
For Visual Studio 2013 

This is the well-known "Bowling Game Kata". It's presented here as an introduction to TDD.

## Introduction

### The objective
Following TDD (Red, Green, Refactor) implement a class, BowlingGame, that calculates a single player's score in a bowling game.
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
Each time you make an improvement, run the tests again to verify they pass, and **commit the changes to the git repository**.

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
  * the first frame is a spare (say, 0 then 10)
  * the next ball scores (say, 3)
  * the remaining balls all go down the gutter
  
So implement the test, GivenOneSpareThen3Bowled_WhenGameScoreCalculated_ShouldBe16.

2. Compile and run the test.
3. Verify that it fails on the assert.

### Step 9. Starting the implementation for the spare bonus
To implement spares, we're going to need some information about frames. We're going give the responsibility of monitoring the state of a frame to another class FrameState.
We're going to calculate spare bonnus using a third class SpareBonus. We'll implement both these classes using TDD, starting out with writing a failing test. But we've got 
a problem: we've already got one test failing; now we need to write another failing test before we can get this one to pass. There are a few options

* Mark the current failing test to be ignored, so that it's not run when we run the tests.
* Revert the last commit and go back to the point where all the tests were passing.
* Stash the changes we've made in Step8 away somewhere.
  
Each has it's merits. Here we're going to go with the last option.

1. Create a stash of the changes made in Step8. You can do this in SourceTree by clicking on the Stash icon and giving the stash a suitable name.

### Step 10. The first test for the class FrameState, Red Stage
FrameState has three methods

```
void Roll(int pins)
bool IsSpare()
bool IsStrike()
```

IsSpare() returns true whenever the last call to Roll() marked the end of a frame that resulted in a spare.

All we need the Frame to do right now is to tell us whenever we're at the end of a Spare frame.

1. Create a new test ficture, FrameStateTests in a new file, FrameTests.cpp in BowlingGameTests.
2. Implement the test GivenNoBallsBowled_FrameShouldNotBeASpare. The test should create a FrameState object, call IsSpare() and verify that the result is false. 
3. Write just enough code to get the test to fail. When you create FrameState, implement it in the BowlingGame project. Take care when implementing IsSpare(); you're aiming to get a failing test.
4. Run the tests and verify that the test fails on the assert.

### Step 11. Continue implementing FrameState, using TDD

1. Green. Get the test passing. Commit the code.
2. Refactor. There's probably not a lot to do here, but check over your test to see if it can be improved. Commit after each improvement.
3. Red. Write the next failing test: GivenOneSpareFrameBowled_FrameShouldBeASpare. Run the test and get it to fail on the assert.
4. Green. Implement the code to pass the test. Implement just enough to detect the end of the first frame. Commit.
5. Refactor. Commit your improvements as you go.
6. Red. Write the third test: GivenOneSpareFrameFollowedByAZeroBall_FrameShouldNotBeASpare.
7. Green. Implement sufficient code to pass the test. Commit.
8. Refactor. Look at your code and your tests for any improvements. Commit as you go.
9. Continue in the same way, adding the test, GivenSeventeenOnesAndOneTen_FrameShouldBeASpare. Commit your changes as you go.
At this point, FrameState successfully handles spares. It doesn't handle strikes, and it doesn't handle any bonus balls bowled in the 10th frame.

### Step 12. Implement scoring for spares
 
1. Reinstate the test, GivenOneSpareThen3Bowled_WhenGameScoreCalculated_ShouldBe16, from Step 8. You can do this SourceTree by expanding the "Stashes" node in the view on the left, right clicking on the stash you saved and selecting the option to apply it.
2. Buld the solution. 
3. Run the tests. The new test should fail.
4. Implement the behavior by introducing FrameState into BowlingGame. Run the test and verify it passes. Commit.

### Step 13. Implement scoring for strikes
1. Use TDD drive the implementation of FrameState::IsStrike() for frames 1 - 10. Stick to the Red, Green, Refactor cycle and commit the code as you go. Start with the tests 
  1. FrameStateTests::GivenNoBallsBowled_FrameShouldNotBeAStrike
  2. FrameStateTests::GivenOneStrikeFrameBowled_FrameShouldBeAStrike
and add as many additional tests as necessary to complete the implementation. Don't write anything to handle the bonus balls in the 10th frame yet.
2. Use the test, BowlingGameTests::GivenStrikeFollowedByThreeFourAndFive_WhenGameScoreCalculated_ShouldBe29 to implement scoring for strikes. 

### Step 14. Refactor
Consider carefully any improvements you can make to the code. Can you extract a class? e.g. to handle bonuses? If you find you want to create a new class, implement it using TDD.

### Step 15. Continue using TDD to implement the tenth frame
The tenth frame is different, in that it can be

* a strike and two bonus balls
* a spare and one bonus ball
* or just two balls that are scored normally

## Questions

1. In Step 12, where we were implementing scoring for a spare, we could have gone on to write the test GivenOneSpareThen18OnesBowled_WhenGameScoreCalculated_ShouldBe29 
to validate that the bonus score only applies to the first ball following the spare. What would have been the advantages of doing this? Disadvantages?
2. What tests did you include in Step 13? What was your reasoning?