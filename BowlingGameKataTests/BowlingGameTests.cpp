#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "With.h"

#include "../BowlingGameKata/BowlingGame.h"

TEST_FIXTURE(BowlingGameTests, GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0,
    GivenTwenty1sBowled_WhenGameScoreCalculated_ShouldBe20);

void BowlingGameTests::GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0()
{
    // Given
    BowlingGame game;

    // When
    With<BowlingGame>(&game).Roll(0).Times(20);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(0, score);
}

void BowlingGameTests::GivenTwenty1sBowled_WhenGameScoreCalculated_ShouldBe20()
{
    // Given
    BowlingGame game;

    // When
    With<BowlingGame>(&game).Roll(1).Times(20);

    // Then
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(20, score);
}
