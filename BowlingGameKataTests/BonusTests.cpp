#include "stdafx.h"
#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../BowlingGameKata/Bonus.h"

TEST_FIXTURE(BonusTests, GivenBonusForOneBall_WhenBonusRequestedFirstTime_ShouldBeGranted);

void BonusTests::GivenBonusForOneBall_WhenBonusRequestedFirstTime_ShouldBeGranted()
{
    Bonus bonus(1);
    bool bonusGranted = bonus.GrantForOneBall();
    CPPUNIT_ASSERT_EQUAL(true, bonusGranted);
}
