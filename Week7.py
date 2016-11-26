class Stack:
    #class stack that allows pushing and poping
    def __init__(self):
        self.values=[]
        
    def push(self,n):
        self.values.append(n)
        
    def pop(self):
        #keep the last value from the list and return it afterwards
        x=self.values[-1]
        #del function has the O(n) complexity
        del self.values[-1]
        return x
    
class Queue:
    #class queue with enqueue and dequeue
    def __init__(self):
        self.values=[]
        
    def enqueue(self,n):
        self.values.append(n)
        
    def dequeue(self):
        x=self.values[0]
        #take the first value from the list and return it afterwards
        del self.values[0]
        return x
    
class Node:
    #we habe the class node that contains the value of a node and its neighbours
    def __init__(self,val):
        self.value=val
        self.neighbours=[]
        
    def getNeighbours(self):
        #when retriving the neighbours print their values 
        for i in range(0,len(self.neighbours)):
            print(str(self.neighbours[i].value)+str(' '),end="")
        #return nothing so the function does not return NONE
        return ""
    
class Graph:
    #in the graph class we have a list that represents the nodes in the graph
    def __init__(self):
        self.items_in_graph=[]
        
    def addNode(self,n):
        #create a new node and append it to the graph list of nodes
        self.items_in_graph.append(Node(n))
        
    def addEdge(self,x,y):
        ok1=0
        ok2=0
        # we have 2 variables that will tell us if the nodes
        #between we add the edge are in the graph
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
            self.items_in_graph[n].neighbours.append(self.items_in_graph[m])
            self.items_in_graph[m].neighbours.append(self.items_in_graph[n])
            #append both of the node's neigbour list with the other node
        elif ok1==1 and ok2==0:
            #if the first node is in the graph but not the second
            self.items_in_graph.append(Node(y))
            self.items_in_graph[n].neighbours.append(self.items_in_graph[len(self.items_in_graph)-1])
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append(self.items_in_graph[n])
            #we have the n for the first node's index and the last index in the list is the second node's index
            #because we just append it to the graph list of nodes
        elif ok1==0 and ok2==1:
            self.items_in_graph.append(Node(x))
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append(self.items_in_graph[m])
            self.items_in_graph[m].neighbours.append(self.items_in_graph[len(self.items_in_graph)-1])
            #we have the m for the second node's index and the last index in the list is the first node's index
            #because we just append it to the graph list of nodes
        else:
            self.items_in_graph.append(Node(x))
            self.items_in_graph.append(Node(y))
            self.items_in_graph[len(self.items_in_graph)-2].neighbours.append(self.items_in_graph[len(self.items_in_graph)-1])
            self.items_in_graph[len(self.items_in_graph)-1].neighbours.append(self.items_in_graph[len(self.items_in_graph)-2])
            #we have bot x and y not in the graph so we append them to the graph's list of node
            #we append their neghbours list with the other node
    def getGraph(self):
        for i in range(0,len(self.items_in_graph)):
            print(str(self.items_in_graph[i].value)+str(': '),end="")
            print(str(self.items_in_graph[i].getNeighbours()))
            #when printing the graph, for every node in the graph we print its value
            #and its neighbours, the result being a adjacency list
        return ""
    def DS (self,n):
        #we have as argument the node's index
        s=Stack()
        visited=[]
        s.push(n)
        #we put that first element in the stack
        while s.values:
            #while the stack is not empty
            n=s.pop()
            if n not in visited:
                #if the element poped has not been visited
                visited.append(n)
                for i in range (0,len(n.neighbours)):
                    s.push(n.neighbours[i])
                #all the node to the visited list and add all its neigbours to the stack
        return visited  
    def BS(self,n):
        #we have as argument the node's index
        q=Queue()
        visited=[]
        q.enqueue(n)
        #we put that first element in the queue
        while q.values:
            #while the queue is not empty
            n=q.dequeue()
            if n not in visited:
                #if the element poped has not been visited
                visited.append(n)                                                                                                                                                                       
                for i in range(0,len(n.neighbours)):
                    q.enqueue(n.neighbours[i])
                #all the node to the visited list and add all its neigbours to the queue
        return visited

g=Graph()
g.addNode(1)
g.addNode(2)
g.addNode(4)
g.addNode(5)
g.addNode(6)
g.addNode(8)
g.addNode(9)
g.addNode(10)
g.addEdge(1,2)
g.addEdge(1,4)
g.addEdge(2,5)
g.addEdge(3,6)
g.addEdge(5,9)
g.addEdge(5,6)
g.addEdge(4,8)
g.addEdge(8,10)
g.addEdge(6,13)
g.addEdge(15,9)
g.addEdge(18,20)
g.getGraph()

f=open('ds-bs.txt','w')
f.write('DS:')
for i in range(0,len(g.DS(g.items_in_graph[1]))):
    x=(str(g.DS(g.items_in_graph[1])[i].value)+str(" "))
    f.write(x)
f.write('\nBS:')
for i in range(0,len(g.BS(g.items_in_graph[1]))):
    x=(str(g.BS(g.items_in_graph[1])[i].value)+str(" "))
    f.write(x)
f.close()



