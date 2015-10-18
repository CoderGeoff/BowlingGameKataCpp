#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../BowlingGameKata/FrameState.h"

TEST_FIXTURE(FrameStateTests, GivenNoBallsBowled_FrameShouldNotBeASpare,
    GivenOneSpareFrameBowled_FrameShouldBeASpare,
    GivenOneSpareFrameFollowedByAZeroBall_FrameShouldNotBeASpare,
    GivenSeventeenOnesAndOneNine_FrameShouldBeASpare);

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
    frameState.Roll(0);
    frameState.Roll(10);

    // When
    bool isSpare = frameState.IsSpare();
    
    // Then
    CPPUNIT_ASSERT_EQUAL(true, isSpare);
}

void FrameStateTests::GivenOneSpareFrameFollowedByAZeroBall_FrameShouldNotBeASpare()
{
    // Given
    FrameState frameState;
    frameState.Roll(0);
    frameState.Roll(10);
    frameState.Roll(0);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(false, isSpare);
}

void FrameStateTests::GivenSeventeenOnesAndOneNine_FrameShouldBeASpare()
{
    // Given
    FrameState frameState;
    for (int i = 0; i < 17; ++i)
    {
        frameState.Roll(1);
    }
    frameState.Roll(9);

    // When
    bool isSpare = frameState.IsSpare();

    // Then
    CPPUNIT_ASSERT_EQUAL(true, isSpare);
}
