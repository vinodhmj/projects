class Graph:
    """class graph
    """
    def __init__(self, gdict=None):
        """constructor
        """
        if gdict is None:
            gdict = {}
        self.gdict = gdict
        
    def addEdge(self, vertex, edge):
        """function to add edge
        """
        self.gdict[vertex].append(edge)

    def bfs(self, vertex):
        visited = [vertex]
        queue = [vertex]
        while queue:
            deVertex = queue.pop(0)
            print(deVertex)
            for adjacentVertex in self.gdict[deVertex]:
                if adjacentVertex not in visited:
                    visited.append(adjacentVertex)
                    queue.append(adjacentVertex)
        
def main():
    print("hello")
    """main funtion
    """
    temp = { "a" : {"c"},
          "b" : {"c", "e"},
          "c" : {"a", "b", "d", "e"},
          "d" : {"c"},
          "e" : {"c", "b"},
          "f" : {}
        }
    g = Graph(temp)
    g.bfs("a")
    
if __name__ == '__main__':
    main()
