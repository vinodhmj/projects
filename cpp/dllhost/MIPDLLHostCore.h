//!
//! \file
//! \brief This includes Load Dll functionality APIs
//!
//! \author Vinodh M J
//! \date 22 August 2016
//! \bug No known bugs
//------------------------------------------------------------------------//
#ifndef  _MIP_DLL_HOST_CORE_PRDC_H_ 
#define  _MIP_DLL_HOST_CORE_PRDC_H_
//------------------------------------------------------------------------//

//! \namespace
namespace MIPDLLHOST
{
  //! \class CMIPDLLHOST "mipdllhost/mipdllhostinclude.h"
  //! \brief The core class to explicitly link dll.
  class CMIPDLLHost
  {
  public:
    CMIPDLLHost(){}
    ~CMIPDLLHost(){CMIPDLLHost::unloadDLL();}
    CMIPDLLHost(const std::string& sDLLName){loadDLL(sDLLName);}
    CMIPDLLHost(const  CMIPDLLHost& MIPLoadDll) = delete;
    CMIPDLLHost& operator =(const  CMIPDLLHost& MIPLoadDll) = delete;

  public: //User APIs
    bool loadDLL(const std::string& sDLLName);
    void* getFunction(const std::string& sFunctionName);
    void unloadDLL(void);
    
  private:
    void setDLLName(const std::string& sDLLName);
    
  private: //Member Variables
    void* m_DLLHandle = nullptr; //!<Holds the DLL pointer
    std::string m_sDLLName = "UNKNOWN DLL"; //!<Stores the DLL Name
    bool m_bLoadStatus = false; //!<Stores DLL loaded status 
    
    
  }; // end of class CMIPDLLHost scope
};// end of namespace MIPLOADDLL

#endif //  _MIP_DLL_HOST_CORE_PRDC_H_ 
