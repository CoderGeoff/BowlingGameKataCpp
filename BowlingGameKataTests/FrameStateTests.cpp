#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../BowlingGameKata/FrameState.h"
#include "With.h"

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
