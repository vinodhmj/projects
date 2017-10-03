
#include "queue_ADT.h"
#include <iostream>
#include <string>
#include <chrono>
#include <exception>
#include <sys/time.h>

using namespace std;

void print_time(void)
{
 timeval curTime;
 gettimeofday(&curTime, NULL);
 int milli = curTime.tv_usec / 1000;

 char buffer [80];
 strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

 char currentTime[84] = "";
 sprintf(currentTime, "%s:%d", buffer, milli);
 cout << "current time: " << currentTime << endl;

}

int main(int argc, char *argv[])
{
  try
  {
    CQueue_ADT<int> iq;

    //print_time();
    int i(0);
    //for (i=0; i < MAX_QUEUE_LENGTH; ++i) {
    //iq.push(5);
    //}
    //print_time();
    //return 0;
    cout<<  iq.length() << endl;
    iq.push(1);
    iq.push(-1);
    iq.push(3);
    iq.push(5);
    iq.push(false);
    //    iq.push(4);
    for (i = 0; i < 4; i++) {
      iq.pop();
    }
    //iq.pop();
    cout <<  iq.length() << endl;
    // iq.pop();
    // iq.pop();
    //cout <<  iq.length() << endl;
    iq.push(345);
    iq.push(314);
    iq.push(31324);
    iq.pop();
    iq.pop();
    
    
    cout <<  iq.length() << endl;
    CQueue_ADT<int> iq2(iq);
    cout<<  iq.length() << endl;
    cout<<  iq.pop() << endl;
    cout<<  iq.pop() << endl;
    cout<<  iq.length() << endl;
  }
  catch(std::string& myex)
  {
    cout<<myex<<endl;
  }
  catch(std::exception& myex)
  {
    cout<< myex.what() << endl;
  }
  catch(...)
  {
    cout << "unhandled exception" << endl;
  }
  
  return 0;
}
