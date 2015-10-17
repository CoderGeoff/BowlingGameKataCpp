#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../BowlingGameKata/FrameState.h"

TEST_FIXTURE(FrameStateTests, GivenNoBallsBowled_FrameShouldNotBeASpare,
    GivenOneSpareFrameBowled_FrameShouldBeASpare);

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
