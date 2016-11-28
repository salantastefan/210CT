class Node:
    #we have the class node that contains the value of a node and its neighbours
    #along with tentative weight and a prev variable, to be able to track back the path
    def __init__(self,val):
        self.value=val
        self.tw=None
        #in the neighbours list we store a tuple (node,weight of the edge)
        self.neighbours=[]
        self.prev=None
        
    def getNeighbours(self):
        #when retriving the neighbours print their values 
        for i in range(0,len(self.neighbours)):
            print(str(self.neighbours[i][0].value)+str('(')+str(self.neighbours[i][1])+str(') '),end="")
        #return nothing so the function does not return NONE
        return ""
    
class Graph:
    #in the graph class we have a list that represents the nodes in the graph
    def __init__(self):
        self.items_in_graph=[]
        
    def addNode(self,n):
        #create a new node and append it to the graph list of nodes
        self.items_in_graph.append(Node(n))
        
    def addEdge(self,x,y,w):
        ok1=0
        ok2=0
        #we have 2 variables that will tell us if the nodes
        #between which we add the edge are in the graph
        for i in range(0,len(self.items_in_graph)):
            if self.items_in_graph[i].value==x:
                #check if the first node is in the graph and remember its index
                ok1=1
                n=i
            if self.items_in_graph[i].value==y:
                #check if the second node is in the graph and remember its index
                ok2=1
                m=i
        if ok1==1 and ok2==1:
            #if both are in the graph
            self.items_in_graph[n].neighbours.append((self.items_in_graph[m],w))
            self.items_in_graph[m].neighbours.append((self.items_in_graph[n],w))
            #append both of the node's neigbour list with the other node and weight of the edge
        elif ok1==1 and ok2==0:
            #if only the first node is in the graph create the second node(y)
            self.items_in_graph.append(Node(y))
            self.items_in_graph[n].neighbours.append((self.items_in_graph[len(self.items_in_graph)-1],w))
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append((self.items_in_graph[n],w))
            #we have the n for the first node's index and the last index in the list is the second node's index
            #because we just append it to the graph list of nodes
            #append both of the node's neigbour list with the other node and weight of the edge
        elif ok1==0 and ok2==1:
            self.items_in_graph.append(Node(x))
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append((self.items_in_graph[m],w))
            self.items_in_graph[m].neighbours.append((self.items_in_graph[len(self.items_in_graph)-1],w))
            #we have the m for the second node's index and the last index in the list is the first node's index
            #because we just append it to the graph list of nodes
            #append both of the node's neigbour list with the other node and weight of the edge
        else:
            #if only the second node is in the graph create the first node(x)
            self.items_in_graph.append(Node(x))
            self.items_in_graph.append(Node(y))
            self.items_in_graph[len(self.items_in_graph)-2].neighbours.append((self.items_in_graph[len(self.items_in_graph)-1],w))
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append((self.items_in_graph[len(self.items_in_graph)-2],w))
            #we have bot x and y not in the graph so we append them to the graph's list of node
            #append both of the node's neigbour list with the other node and weight of the edge
            
    def getGraph(self):
        for i in range(0,len(self.items_in_graph)):
            print(str(self.items_in_graph[i].value)+str(': '),end="")
            print(str(self.items_in_graph[i].getNeighbours()))
            #when printing the graph, for every node in the graph we print its value
            #and its neighbours, the result being a adjacency list
        return ""
    
    def DIJKSTRA(self,s,d):
        #we have the source and destination nodes as inputs
        current=s
        for i in range(0,len(self.items_in_graph)):
            self.items_in_graph[i].tw=float("inf")
            #we set every node's tentative weight to infinity
        s.tw=0
        #set the source's tw to 0
        visited=[]
        path=[]
        while current!=d:
            #untill we reach the destination node
            for i in range(0,len(current.neighbours)):
                #we check every neighbour of the current node
                if current.tw+current.neighbours[i][1]<current.neighbours[i][0].tw:
                    current.neighbours[i][0].tw=current.tw+current.neighbours[i][1]
                    current.neighbours[i][0].prev=current
                    #if the tw of the current node +the weight of the edge to the neighbour
                    #is less then the neighbour's tw then set the tw of the neighbour to that value and
                    #set the neighbour's prev to the current
            visited.append(current)
            minim=float("inf")
            #set the minimum variable to infinity
            #this will help us to find the node with the minimum tw to go to next
            for i in range(0,len(self.items_in_graph)):
                if (self.items_in_graph[i] not in visited)  and (self.items_in_graph[i].tw<minim):
                    current=self.items_in_graph[i]
                    minim=self.items_in_graph[i].tw
                    #for every not in the graph, check if was visited and if its tw is less then minimum
                    #if those two condition meet we change the current node and the minimum
                    
        while current.prev!=None:
            path=[current]+path
            current=current.prev
            #after we reached the destination we find the way back by following the prevs
        path=[current]+path
            #add the source node to the path
        return path
    
g=Graph()
g.addNode(1)
g.addNode(2)
g.addNode(4)
g.addNode(5)
g.addNode(6)
g.addNode(8)
g.addNode(9)
g.addNode(10)
g.addEdge(1,2,2)
g.addEdge(1,4,4)
g.addEdge(2,5,5)
g.addEdge(3,6,1)
g.addEdge(5,9,7)
g.addEdge(5,6,4)
g.addEdge(4,8,6)
g.addEdge(8,10,8)
g.addEdge(6,13,5)
g.addEdge(15,9,11)
g.addEdge(18,20,3)
g.addEdge(4,9,13)
g.addEdge(10,15,2)
g.addEdge(13,15,1)
g.addEdge(18,10,2)
g.getGraph()

x=g.DIJKSTRA(g.items_in_graph[1],g.items_in_graph[7])
for i in range(0,len(x)):
    print(str(x[i].value)+str(" "),end="")
    #print the values of the nodes in the path






