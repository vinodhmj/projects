
#ifndef __QUEUE_TEST_SUITE_INCLUDE_H__
#define __QUEUE_TEST_SUITE_INCLUDE_class__

#include "queue_ADT.h"

#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

class CQueueTest : public CppUnit::TestFixture
{

public:
  CPPUNIT_TEST_SUITE(CQueueTest);
  CPPUNIT_TEST(testEmpty);
  CPPUNIT_TEST(testPush);
  CPPUNIT_TEST(testPop);
  CPPUNIT_TEST(testLength);               
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp();
  void tearDown();
  
public:
  void testEmpty();
  void testPush();
  void testPop();
  void testLength();
  
private:
  CQueue_ADT<int>* qlength = nullptr;

};


#endif // __QUEUE_TEST_SUITE_INCLUDE_H__
