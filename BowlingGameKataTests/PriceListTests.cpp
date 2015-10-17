#include "stdafx.h"

#include <cppUnit/TestCase.h>
#include <cppUnit/extensions/HelperMacros.h>

#include "TestFixtureMacro.h"
#include "../SupermarketKata/PriceList.h"

TEST_FIXTURE(PriceListTests, 
	PriceOfTinOfBeansShouldBe40p);

void PriceListTests::PriceOfTinOfBeansShouldBe40p()
{
    PriceList priceList;
    int price = priceList["TinOfBeans"];
    CPPUNIT_ASSERT_EQUAL(40, price);
}

