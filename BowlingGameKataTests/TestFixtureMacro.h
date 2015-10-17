#pragma once


#define EXPAND( x ) x

#define FOR_EACH_1(what, x, ...) what(x)
#define FOR_EACH_2(what, x, ...) what(x) EXPAND(FOR_EACH_1(what, __VA_ARGS__))
#define FOR_EACH_3(what, x, ...) what(x) EXPAND(FOR_EACH_2(what, __VA_ARGS__))
#define FOR_EACH_4(what, x, ...) what(x) EXPAND(FOR_EACH_3(what, __VA_ARGS__))
#define FOR_EACH_5(what, x, ...) what(x) EXPAND(FOR_EACH_4(what, __VA_ARGS__))
#define FOR_EACH_6(what, x, ...) what(x) EXPAND(FOR_EACH_5(what, __VA_ARGS__))
#define FOR_EACH_7(what, x, ...) what(x) EXPAND(FOR_EACH_6(what, __VA_ARGS__))
#define FOR_EACH_8(what, x, ...) what(x) EXPAND(FOR_EACH_7(what, __VA_ARGS__))
#define FOR_EACH_9(what, x, ...) what(x) EXPAND(FOR_EACH_8(what, __VA_ARGS__))
#define FOR_EACH_10(what, x, ...) what(x) EXPAND(FOR_EACH_9(what, __VA_ARGS__))
#define FOR_EACH_11(what, x, ...) what(x) EXPAND(FOR_EACH_10(what, __VA_ARGS__))
#define FOR_EACH_12(what, x, ...) what(x) EXPAND(FOR_EACH_11(what, __VA_ARGS__))
#define FOR_EACH_13(what, x, ...) what(x) EXPAND(FOR_EACH_12(what, __VA_ARGS__))
#define FOR_EACH_14(what, x, ...) what(x) EXPAND(FOR_EACH_13(what, __VA_ARGS__))
#define FOR_EACH_15(what, x, ...) what(x) EXPAND(FOR_EACH_14(what, __VA_ARGS__))
#define FOR_EACH_16(what, x, ...) what(x) EXPAND(FOR_EACH_15(what, __VA_ARGS__))
#define FOR_EACH_17(what, x, ...) what(x) EXPAND(FOR_EACH_16(what, __VA_ARGS__))
#define FOR_EACH_18(what, x, ...) what(x) EXPAND(FOR_EACH_17(what, __VA_ARGS__))
#define FOR_EACH_19(what, x, ...) what(x) EXPAND(FOR_EACH_18(what, __VA_ARGS__))
#define FOR_EACH_20(what, x, ...) what(x) EXPAND(FOR_EACH_19(what, __VA_ARGS__))

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,NAME,...) NAME 
#define FOR_EACH(action,...) EXPAND(GET_MACRO(__VA_ARGS__, FOR_EACH_20,FOR_EACH_19,FOR_EACH_18,FOR_EACH_17,FOR_EACH_16,FOR_EACH_15,FOR_EACH_14,FOR_EACH_13,FOR_EACH_12,FOR_EACH_11,FOR_EACH_10,FOR_EACH_9,FOR_EACH_8,FOR_EACH_7,FOR_EACH_6,FOR_EACH_5,FOR_EACH_4,FOR_EACH_3,FOR_EACH_2,FOR_EACH_1)(action, __VA_ARGS__))

#define REGISTER_TEST(name) CPPUNIT_TEST(name);
#define REGISTER_TESTS(...) FOR_EACH(REGISTER_TEST, __VA_ARGS__)
#define DECLARE_TEST(name) void name();
#define DECLARE_TESTS(...) FOR_EACH(DECLARE_TEST, __VA_ARGS__)

// TEST_FIXTURE describes a test fixture with no additional members
// It takes the name of the fixture followed by a comma-separated list of test methods
// e.g. TEST_FIXTURE(MyTests, TestFeature1, TestFeature2);
#define TEST_FIXTURE(name, ...)\
class name : public CppUnit::TestFixture {\
	CPPUNIT_TEST_SUITE(name);\
	REGISTER_TESTS(__VA_ARGS__);\
	CPPUNIT_TEST_SUITE_END();\
public:\
	DECLARE_TESTS(__VA_ARGS__);\
};\
CPPUNIT_TEST_SUITE_REGISTRATION(name)

// TEST_FIXTURE_START and TEST_FIXTURE_END are used as bookends to define a test fixture, allowing you to 
// define class members between the two declarations, e.g.
// TEST_FIXTURE_START(MyTests);
//     void setUp();
//     void tearDown();
//     bool flag;
// TEST_FIXTURE_END();
#define TEST_FIXTURE_START(name, ...)\
class name;\
CPPUNIT_TEST_SUITE_REGISTRATION(name);\
class name : public CppUnit::TestFixture {\
	CPPUNIT_TEST_SUITE(name);\
	REGISTER_TESTS(__VA_ARGS__);\
	CPPUNIT_TEST_SUITE_END();\
public:\
	DECLARE_TESTS(__VA_ARGS__);

#define TEST_FIXTURE_END };

