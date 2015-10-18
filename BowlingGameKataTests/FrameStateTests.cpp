#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "With.h"

#include "../BowlingGameKata/FrameState.h"

TEST_FIXTURE(FrameStateTests, GivenNoBallsBowled_FrameShouldNotBeASpare,
    GivenOneSpareFrameBowled_FrameShouldBeASpare,
    GivenOneSpareFrameFollowedByAZeroBall_FrameShouldNotBeASpare,
    GivenSeventeenOnesAndOneNine_FrameShouldBeASpare,
    GivenNoBallsBowled_FrameShouldNotBeAStrike,
    GivenOneStrikeFrameBowled_FrameShouldBeAStrike,
    GivenOneStrikeFollowedbySpare_FrameShouldBeASpare,
    GivenAStrike_FrameShouldNotBeASpare,
    GivenAStrikeInTenthFrame_WhenNextBallBowled_ShouldBeBonusBall,
    GivenAStrikeInNinthFrame_WhenNextBallBowled_ShouldNotBeBonusBall);

void FrameStateTests::GivenNoBallsBowled_FrameShouldNotBeASpare()
{
    FrameState frameState;
    bool isSpare = frameState.IsSpare();
    CPPUNIT_ASSERT_EQUAL(false, isSpare);
}

void FrameStateTests::GivenOneSpareFrameBowled_FrameShouldBeASpare()
{
    // Given
    FrameState frameState;
    With(&frameState).Roll(0).Times(1);
    With(&frameState).Roll(10).Times(1);

    // When
    bool isSpare = frameState.IsSpare();
    
    // Then
    CPPUNIT_ASSERT_EQUAL(true, isSpare);
}

void FrameStateTests::GivenOneSpareFrameFollowedByAZeroBall_FrameShouldNotBeASpare()
{
    // Given
    FrameState frameState;
    With(&frameState).Roll(0).Times(1);
    With(&frameState).Roll(10).Times(1);
    With(&frameState).Roll(0).Times(1);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(false, isSpare);
}

void FrameStateTests::GivenSeventeenOnesAndOneNine_FrameShouldBeASpare()
{
    // Given
    FrameState frameState;
    With(&frameState).Roll(1).Times(17);
    With(&frameState).Roll(9).Times(1);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(true, isSpare);
}

void FrameStateTests::GivenNoBallsBowled_FrameShouldNotBeAStrike()
{
    FrameState frameState;
    bool isStrike = frameState.IsStrike();
    CPPUNIT_ASSERT_EQUAL(false, isStrike);
}

void FrameStateTests::GivenOneStrikeFrameBowled_FrameShouldBeAStrike()
{
    // Given    
    FrameState frameState;
    With(&frameState).Roll(10).Times(1);

    // When
    bool isStrike = frameState.IsStrike();

    // Then
    CPPUNIT_ASSERT_EQUAL(true, isStrike);
}

void FrameStateTests::GivenOneStrikeFollowedbySpare_FrameShouldBeASpare()
{
    // Given    
    FrameState frameState;
    With(&frameState).Roll(10).Times(1);
    With(&frameState).Roll(0).Times(1);
    With(&frameState).Roll(10).Times(1);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(true, isSpare);
}

void FrameStateTests::GivenAStrike_FrameShouldNotBeASpare()
{
    // Given    
    FrameState frameState;
    With(&frameState).Roll(10).Times(1);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(false, isSpare);
}

void FrameStateTests::GivenAStrikeInTenthFrame_WhenNextBallBowled_ShouldBeBonusBall()
{
    // Given
    FrameState frameState;
    With(&frameState).Roll(10).Times(10);

    // When 
    With(&frameState).Roll(0).Times(1);
    bool isBonusBall = frameState.IsBonusBall();

    // Then
    CPPUNIT_ASSERT_EQUAL(true, isBonusBall);
}

void FrameStateTests::GivenAStrikeInNinthFrame_WhenNextBallBowled_ShouldNotBeBonusBall()
{
    // Given
    FrameState frameState;
    With(&frameState).Roll(10).Times(9);

    // When 
    With(&frameState).Roll(0).Times(1);
    bool isBonusBall = frameState.IsBonusBall();

    // Then
    CPPUNIT_ASSERT_EQUAL(false, isBonusBall);
}