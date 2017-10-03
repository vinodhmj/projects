/*!
  \file
  \brief Node class of Graph
  
  \author Vinodh MJ Human
  \bugs No known bugs
*/

 struct Node
 {
   //Node properties
   unsigned int nDegree;
 };

struct Edge
{
  std::pair<unsigned int,unsigned int> m_NodePair;
      
};
class CGraph
{
  std::vector<Node> m_Nodes;
  std::vector<Edge> m_Edges;
};
