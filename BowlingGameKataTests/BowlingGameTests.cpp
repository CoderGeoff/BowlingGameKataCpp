#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "With.h"

#include "../BowlingGameKata/BowlingGame.h"

TEST_FIXTURE(BowlingGameTests, GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0,
    GivenTwenty1sBowled_WhenGameScoreCalculated_ShouldBe20,
    GivenOneSpareThen3Bowled_WhenGameScoreCalculated_ShouldBe16,
    GivenStrikeFollowedByThreeFourAndFive_WhenGameScoreCalculated_ShouldBe29,
    GivenTwoStrikes_WhenGameScoreCalculated_ShouldBe30);

void BowlingGameTests::GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0()
{
    // Given
    BowlingGame game;

    // When
    With(&game).Roll(0).Times(20);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(0, score);
}

void BowlingGameTests::GivenTwenty1sBowled_WhenGameScoreCalculated_ShouldBe20()
{
    // Given
    BowlingGame game;

    // When
    With(&game).Roll(1).Times(20);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(20, score);
}

void BowlingGameTests::GivenOneSpareThen3Bowled_WhenGameScoreCalculated_ShouldBe16()
{
    // Given
    BowlingGame game;

    // When
    With(&game).Roll(5).Times(1);
    With(&game).Roll(5).Times(1);
    With(&game).Roll(3).Times(1);
    With(&game).Roll(0).Times(17);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(16, score);
}

void BowlingGameTests::GivenStrikeFollowedByThreeFourAndFive_WhenGameScoreCalculated_ShouldBe29()
{
    // Given
    BowlingGame game;

    // When
    With(&game).Roll(10).Times(1);
    With(&game).Roll(3).Times(1);
    With(&game).Roll(4).Times(1);
    With(&game).Roll(5).Times(1);
    With(&game).Roll(0).Times(15);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(29, score);
}

void BowlingGameTests::GivenTwoStrikes_WhenGameScoreCalculated_ShouldBe30()
{
    // Given
    BowlingGame game;

    // When
    With(&game).Roll(10).Times(12);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(300, score);
}
