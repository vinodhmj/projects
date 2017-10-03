//! \file
//! \author Vinodh M J
//! \brief automated test case using cppunit
//!
//! FIXTURE - A fixture is a known set of objects that serves as a base for a set of test cases.
//!

#include "queue_test_suite.h"

CPPUNIT_TEST_SUITE_REGISTRATION( CQueueTest );

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main( int argc, char **argv)
{
  CppUnit::TextUi::TestRunner runner;
  CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  runner.addTest( registry.makeTest() );
  bool wasSuccessful = runner.run( "", false );
  return !wasSuccessful;
}
