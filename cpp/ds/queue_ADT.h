/*!
  \file
  \brief Implementation of a Circular-Queue
  \author Vinodh MJ Human
  \bugs No known bugs
*/

#ifndef _QUEUE_ADT_ARRAY_H_INCLUDE_
#define _QUEUE_ADT_ARRAY_H_INCLUDE_

#include <stdexcept>

typedef unsigned int USINT;
const USINT MAX_QUEUE_LENGTH = 5; //<!Queue length>

//! \class CQueue_ADT
//! \brief RAII of an array based Queue Data strucute
//!
template<typename Datatype>
class CQueue_ADT
{
public: 
  CQueue_ADT() {init();}
  ~CQueue_ADT(){}
  CQueue_ADT(const CQueue_ADT& rQueue) { *this = rQueue; }
  CQueue_ADT& operator =(const CQueue_ADT& rQueue);
  
public:
  USINT length(void);
  void push(Datatype val);
  Datatype pop(void);
  
private:
  void init(void);
  const USINT& find_next_index(USINT& iVal);
    
private:
  USINT m_iBegin = 0; //!<Variable to track the head of the queue
  USINT m_iEnd = 0;   //!<Variable to track the tail of the queue
  bool m_bIsEmpty = true;    //!<Variable to check the empty status of the queue
  Datatype m_Array[MAX_QUEUE_LENGTH]; //!<Static array used as data structure for queue
  
};// End of the class CQueue_ADT
//--------------------------------------------------------------------------------------//

//! \fn CQueue_ADT<Datatype>& CQueue_ADT<Datatype>::operator = (const CQueue_ADT& rQueue)
//! \brief Assignment operator
template <typename Datatype>
CQueue_ADT<Datatype>& CQueue_ADT<Datatype>::operator = (const CQueue_ADT& rQueue)
{
  if(this != &rQueue)
  {
    m_iBegin = rQueue.m_iBegin;
    m_iEnd = rQueue.m_iEnd;
    m_bIsEmpty = rQueue.m_bIsEmpty;

    int i(0);
    for (i = 0; i < MAX_QUEUE_LENGTH; ++i)
      m_Array[i] = rQueue.m_Array[i];
  }
  return *this;
    
}// End of assignment operator
//---------------------------------------------------//

//! \fn unsigned int CQueue_ADT::length(void)
//! \brief find the length of the queue
//!
//! \param void
//! \return The length (count of element) of the Queue
template <typename Datatype>
USINT CQueue_ADT<Datatype>::length(void)
{
  if(m_bIsEmpty) return 0;
  else if(m_iBegin == m_iEnd) return 1;
  else return ((m_iBegin < m_iEnd) ? (m_iEnd - m_iBegin + 1) : ((MAX_QUEUE_LENGTH - m_iBegin) + (m_iEnd + 1)));
  
}// End of the function length
//---------------------------------------------------//

//! \fn void push(Datatype data)
//! \brief push the element to the queue
//!
//! The m_iEnd index will advance at every push
//!
//! \param data The value to be pushed in the queue 
//! \return void
template <typename Datatype>
void CQueue_ADT<Datatype>::push(Datatype data)
{
  if(m_bIsEmpty)  {
    m_Array[m_iEnd] = data;
    m_bIsEmpty = false;
    return;
  }
  if(m_iBegin == find_next_index(m_iEnd))
    throw std::runtime_error("CQueue_ADT::push - 'Queue is FULL. Cannot push anymore.'\n");

  m_Array[m_iEnd] = data;
  
}// End of the function push
//---------------------------------------------------//

//! \fn Datatype pop(void)
//! \brief pop the begin element of the queue
//!
//! The m_iBegin index will advance at every pop
//!
//! \param void
//! \return The begin element of the queue
template <typename Datatype>
Datatype CQueue_ADT<Datatype>::pop(void)
{
  if((m_iBegin == m_iEnd) && m_bIsEmpty)
    throw std::runtime_error("CQueue_ADT::pop - 'Queue is EMPTY. Nothing to pop.'\n");

  Datatype Temp_Elem = m_Array[m_iBegin];
  if(m_iBegin == m_iEnd)  {
    m_iBegin = m_iEnd = 0;
    m_bIsEmpty = true;
  }
  else
    find_next_index(m_iBegin);

  return Temp_Elem;
  
}// End of the function pop
//---------------------------------------------------//

//! \fn void init(void)
//! \brief Initializes/Resets the queue to default values of Datatype
//!
//! \param void
//! \return void
template <typename Datatype>
void CQueue_ADT<Datatype>::init(void)
{
  int i(0);
  for (i = 0; i < MAX_QUEUE_LENGTH; ++i) {
    m_Array[i] = Datatype();
  }
  
}// End of the function length
//---------------------------------------------------//

//! \fn const USINT& CQueue_ADT<Datatype>::find_next_index(USINT& iVal)
//! \brief Finds the next value of m_iBegin and m_iEnd
//!
//! \param iVal Begin or End
//! \return const reference of new m_iBegin or m_iEnd
template <typename Datatype>
const USINT& CQueue_ADT<Datatype>::find_next_index(USINT& iVal)
{
  if(iVal == MAX_QUEUE_LENGTH - 1)
    iVal = (iVal+1) % MAX_QUEUE_LENGTH;
  else ++iVal;
  
  return iVal;
}// End of the function find_next_index
//---------------------------------------------------//


#endif //End of _QUEUE_ADT_ARRAY_H_INCLUDE_
