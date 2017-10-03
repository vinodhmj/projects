
#include <dlfcn.h>
#include <exception>
#include <stdexcept>
#include <string>
#include "MIPDLLHostCore.h"

using namespace MIPDLLHOST;

//!\fn MIPEXCEPTIONTYPE CMIPDLLHost::loadDLL(const std::string& sDLLName)
//!\brief Loads the DLL pointer to member variable DLL Handle
//!
//!\param sDLLName The DLL (Name/Absolute Path)
//!\return bool Success or failure status
//!
bool CMIPDLLHost::loadDLL(const std::string& sDLLName)
{
  setDLLName(sDLLName); 
  m_DLLHandle = dlopen(m_sDLLName.c_str(), RTLD_LAZY);
  if(!m_DLLHandle)
    {
      throw(std::runtime_error("Unable to load dll " + sDLLName));
    }
  else
    {
      m_bLoadStatus = true;
    }
  return true;  
}// End of the function 

//!\fn void* CMIPDLLHost::getFunction(const std::string& sFunctionName)
//!\brief Get the address of the function
//!
//!\param Function Name exported
void* CMIPDLLHost::getFunction(const std::string& sFunctionName)
{
  void* fnPtr = dlsym(m_DLLHandle, sFunctionName.c_str()); 
   if(!fnPtr)
    {
      throw(std::runtime_error("Unable to load function " + sFunctionName + "in " + m_sDLLName));
    }
   
    return fnPtr;
    
}// End of the function 


void CMIPDLLHost::unloadDLL(void)
{
  if(m_DLLHandle)
    {
      dlclose(m_DLLHandle);
    }
  m_bLoadStatus = false;
  m_sDLLName = "UNKNOWN DLL";
  m_DLLHandle = nullptr;
  
}// End of the function 

void CMIPDLLHost::setDLLName(const std::string& sDLLName)
{
  m_sDLLName = sDLLName.substr(sDLLName.find_last_of('.'), sDLLName.size());
  if(m_sDLLName == ".so" || m_sDLLName==".dll")
    {
      m_sDLLName = sDLLName;
    }
  else
    {
      m_sDLLName = m_sDLLName + ".so";
    }
}

//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[


 
