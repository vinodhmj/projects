
#include "queue_test_suite.h"

void CQueueTest::setUp()
{
  qlength = new CQueue_ADT<int>();
      
}//end of the function setUp

void CQueueTest::tearDown()
{
  delete  qlength;
}//end of the function tearDown

void CQueueTest::testEmpty()
{
  
}//end of the function testEmpty

void CQueueTest::testPush()
{
  
}//end of the function testPush

void CQueueTest::testPop()
{
   
}//end of the function testPop

void CQueueTest::testLength()
{
  CPPUNIT_ASSERT(qlength->length() == 0);
  
}//end of the function testLength
