#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../BowlingGameKata/BowlingGame.h"

TEST_FIXTURE(BowlingGameTests, GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0);

void BowlingGameTests::GivenTwenty0sBowled_WhenGameScoreCalculated_ShouldBe0()
{
    BowlingGame game;
    for (int i = 0; i < 20; ++i)
    {
        game.Roll(0);
    }
    int score = game.Score();
    CPPUNIT_ASSERT_EQUAL(0, score);
}
