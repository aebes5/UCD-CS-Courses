import Graph as graph
import sys

# #########################
#
#  Dijkstra's SSSP
#
# ######################### 
def dijkstra_city_distance(graph, s):
  visited = {s: 0}
  path = dict.fromkeys(graph.nodes, "")

  nodes = set(graph.nodes)

  # as long as there is a node to process
  while nodes: 
    min_node = None
    # finding the min node from from visited nodes dictionary
    for node in nodes:
      if node in visited:
        if min_node is None:
          min_node = node
        elif visited[node] < visited[min_node]:
          min_node = node

    # no more min_node to process --> done
    if min_node is None:
      break

    nodes.remove(min_node)
    current_weight = visited[min_node]

    # diplay path information of new min_node
    pathStr = ""
    currentCity = min_node

    pathStr = []
    currentCity = min_node

    pathStr.append(currentCity)
    temp = currentCity
    while path[temp] != '':
        pathStr.append(path[temp])
        temp = path[temp]

    pathStr = pathStr[::-1]

    print(f"Distance from {s} to {currentCity}: {current_weight} with path: {pathStr}")
    

    # Releaxation - updating relaxation information (visited[v] and path[v])
    for v in graph.edges[min_node]:
      weight = current_weight + graph.distances[(min_node, v)]
      if v not in visited or weight < visited[v]:
        visited[v] = weight
        path[v] = min_node
        

# #########################
#
#  MST
#
# #########################  

# A utility function to print the constructed MST stored in parent[] 
def printMST(parent, g): 
    print ("\n\t\tEdge \t\t\t\tWeight\n")
    total = 0
    for i in parent.keys():
        total += g.distances[(i, parent[i])]
        if (parent[i] == "") :
            print (f"{i:>15} {i:>15} {g.distances[(i, parent[i])]:.>20d}")
        else:
            print (f"{parent[i]:>15} {i:>15} {g.distances[(i, parent[i])]:.>20d}")

    print ("\nTotal MST: ", "\t", total)

# A utility function to find the vertex with  
# minimum distance value, from the set of vertices  
# not yet included in shortest path tree 
def minKey(g, key, mstSet): 

    # Initilaize min value 
    min = sys.maxsize 

    min_index = None

    for v in g.nodes:
        if key[v] < min and mstSet[v] == False:
            min = key[v]
            min_index = v

    # print the selected min node (city name) and its distance 
    print(min_index, "is selected. Distance:", min)

    return min_index 

# Function to construct and print MST for a graph  
# represented using adjacency matrix representation 
def primMST(graph, s): 

    # Key values used to pick minimum weight edge in cut 
    #key = [sys.maxsize] * len(graph.nodes)
    key = dict.fromkeys(graph.nodes, sys.maxsize)
    parent = dict.fromkeys(graph.nodes, None) # Dictionary to store constructed MST 

    # Make key 0 so that this vertex is picked as first vertex 
    key[s] = 0 
    mstSet = dict.fromkeys(graph.nodes, False)

    parent[s] = "" # First node is always the root of 

    for aNode in graph.nodes: 

        # Pick the minimum distance vertex from  
        # the set of vertices not yet processed.  
        # u is always equal to src in first iteration 
        u = minKey(graph, key, mstSet) 

        # Put the minimum distance vertex in  
        # the shortest path tree 
        mstSet[u] = True

        # Update dist value of the adjacent vertices  
        # of the picked vertex only if the current  
        # distance is greater than new distance and 
        # the vertex in not in the shotest path tree 
        for v in graph.nodes: 
            # graph[u][v] distance is non zero only for adjacent vertices of m 
            # mstSet[v] is false for vertices not yet included in MST 
            # Update the key only if graph[u][v] is smaller than key[v] 
            if graph.distances[(u, v)] > 0 and mstSet[v] == False and key[v] > graph.distances[(u, v)]: 
                key[v] = graph.distances[(u, v)]
                parent[v] = u

    printMST(parent, graph)

# main function  
if __name__ == "__main__":
  g = graph.Graph()
  # set up nodes
  g.add_node('Atlanta')
  g.add_node('Boston')
  g.add_node('Chicago')
  g.add_node('Dallas')
  g.add_node('Denver')
  g.add_node('Houston')
  g.add_node('LA')
  g.add_node('Memphis')
  g.add_node('Miami')
  g.add_node('NY')
  g.add_node('Philadelphia')
  g.add_node('Phoenix')
  g.add_node('SF')
  g.add_node('Seattle')
  g.add_node('Washington')

  # set up edges for Prim's algrithm
  g.initializeDistances()

  # set up distances (edges)
  g.add_edge('Seattle', 'SF', 1092)
  g.add_edge('SF','Seattle',  1092)
  g.add_edge('Seattle', 'LA', 1544)
  g.add_edge('LA', 'Seattle', 1544)
  g.add_edge('LA', 'SF', 559)
  g.add_edge('SF', 'LA', 559)
  g.add_edge('LA', 'Houston', 2205)
  g.add_edge('Houston', 'LA', 2205)
  g.add_edge('LA', 'Denver', 1335)
  g.add_edge('Denver', 'LA', 1335)
  g.add_edge('LA', 'NY', 3933)
  g.add_edge('NY', 'LA', 3933)
  g.add_edge('LA', 'Miami', 3755)
  g.add_edge('Miami', 'LA', 3755)
  g.add_edge('Denver', 'Dallas', 1064)
  g.add_edge('Dallas', 'Denver', 1064)
  g.add_edge('Denver', 'Boston', 2839)
  g.add_edge('Boston', 'Denver', 2839)
  g.add_edge('Denver', 'Memphis', 1411)
  g.add_edge('Memphis', 'Denver', 1411)
  g.add_edge('Denver', 'Chicago', 1474)
  g.add_edge('Chicago', 'Denver', 1474)
  g.add_edge('Chicago', 'Boston', 1367)
  g.add_edge('Boston', 'Chicago', 1367)
  g.add_edge('Chicago', 'NY', 1145)
  g.add_edge('NY', 'Chicago', 1145)
  g.add_edge('Boston', 'NY', 306)
  g.add_edge('NY', 'Boston', 306)
  g.add_edge('Boston', 'Atlanta', 1505)
  g.add_edge('Atlanta', 'Boston', 1505)
  g.add_edge('Atlanta', 'Dallas', 1157)
  g.add_edge('Dallas', 'Atlanta', 1157)
  g.add_edge('Dallas', 'Houston', 362)
  g.add_edge('Houston', 'Dallas', 362)
  g.add_edge('Atlanta', 'Miami', 973)
  g.add_edge('Miami', 'Atlanta', 973)
  g.add_edge('Atlanta', 'SF', 3434)
  g.add_edge('SF', 'Atlanta', 3434)
  g.add_edge('Dallas', 'Memphis', 675)
  g.add_edge('Memphis', 'Dallas', 675)
  g.add_edge('Memphis', 'Philadelphia', 1413)
  g.add_edge('Philadelphia', 'Memphis', 1413)
  g.add_edge('Miami', 'Phoenix', 3182)
  g.add_edge('Phoenix', 'Miami', 3182)
  g.add_edge('Miami', 'Washington', 1487)
  g.add_edge('Washington', 'Miami', 1487)
  g.add_edge('Phoenix', 'NY', 3441)
  g.add_edge('NY', 'Phoenix', 3441)
  g.add_edge('Phoenix', 'Chicago', 2332)
  g.add_edge('Chicago', 'Phoenix', 2332)
  g.add_edge('Phoenix', 'Dallas', 1422)
  g.add_edge('Dallas', 'Phoenix', 1422)
  g.add_edge('Philadelphia', 'Washington', 199)
  g.add_edge('Washington', 'Philadelphia', 199)
  g.add_edge('Philadelphia', 'Phoenix', 3342)
  g.add_edge('Phoenix', 'Philadelphia', 3342)
  g.add_edge('Washington', 'Dallas', 1900)
  g.add_edge('Dallas', 'Washington', 1900)
  g.add_edge('Washington', 'Denver', 2395)
  g.add_edge('Denver', 'Washington', 2395)


  # first we run dijisktras to find the shortest path from denver to anotherwith 5.1 output

  # next we find the MST minimum spanning tree for visiting ALL cities from denver with 5.2 output

  dijkstra_city_distance(g, 'Denver')
  primMST(g, 'Denver')