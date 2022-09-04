def modi_graph(graph,c,conc):
    for cell in conc:
        graph[c-1][cell-1]=1
        graph[cell-1][c-1]=1
    return graph


def make_graph(r):
    number_of_rows = r*2-1
    number_of_cells = (r**3)-((r-1)**3)
    graph = [[0 for i in range(number_of_cells)] for j in range(number_of_cells)]
    rows = []
    leng = r
    cell = 1
    for i in range(r):
        rows.append([cell,cell+leng-1,leng])
        cell+=leng
        leng+=1
    leng-=1
    for i in range(r-1):
        leng-=1
        rows.append([cell,cell+leng-1,leng])
        cell+=leng
    #print(rows)
    for i in range(number_of_rows):
        #if the first row
        if i==0:
            start = rows[i][0]
            end = rows[i][1]
            up=r+1
            down=r+1
            for c in range(start,end+1):
                conc = []
                if c==start:
                    conc.append(c+1)
                    conc.append(c+down)
                    conc.append(c+down-1)
                    graph = modi_graph(graph, c, conc)
                elif c==end:
                    conc.append(c-1)
                    conc.append(c+down)
                    conc.append(c+down-1)
                    graph = modi_graph(graph, c, conc)
                else:
                    conc.append(c-1)
                    conc.append(c+1)
                    conc.append(c+down)
                    conc.append(c+down-1)
                    graph = modi_graph(graph, c, conc)
                    
        #if the last row
        elif i==(number_of_rows-1):
            start = rows[i][0]
            end = rows[i][1]
            up=r+1
            down=r+1
            for c in range(start,end+1):
                conc = []
                if c==start:
                    conc.append(c+1)
                    conc.append(c-up)
                    conc.append(c-up+1)
                    graph = modi_graph(graph, c, conc)
                elif c==end:
                    conc.append(c-1)
                    conc.append(c-up)
                    conc.append(c-up+1)
                    graph = modi_graph(graph, c, conc)
                else:
                    conc.append(c-1)
                    conc.append(c+1)
                    conc.append(c-up)
                    conc.append(c-up+1)
                    graph = modi_graph(graph, c, conc)
            
        else:
            start = rows[i][0]
            end = rows[i][1]
            maxup = number_of_rows
            #first half
            if i<r-1:
                up=r+i
                down=up+1
            elif i==r-1:
                up=r+i
                down = up
            else:
                up=maxup-(i-r)
                down = up-1
            for c in range(start,end+1):
                conc = []
                if c==start:
                    if i<r-1:
                        conc.append(c+1)
                        conc.append(c-up+1)
                        conc.append(c+down)
                        conc.append(c+down-1)
                        graph = modi_graph(graph, c, conc)
                    elif i==r-1:
                        conc.append(c+1)
                        conc.append(c-up+1)
                        conc.append(c+down)
                        graph = modi_graph(graph, c, conc)
                    else:
                        conc.append(c+1)
                        conc.append(c-up)
                        conc.append(c-up+1)
                        conc.append(c+down)
                        graph = modi_graph(graph, c, conc)
                elif c==end:
                    if i<r-1:
                        conc.append(c-1)
                        conc.append(c-up)
                        conc.append(c+down)
                        conc.append(c+down-1)
                        graph = modi_graph(graph, c, conc)
                        
                    elif i==r-1:
                        conc.append(c-1)
                        conc.append(c-up)
                        conc.append(c-up+1)
                        conc.append(c+down-1)
                        graph = modi_graph(graph, c, conc)
                            
                    else:
                        conc.append(c-1)
                        conc.append(c-up)
                        conc.append(c-up+1)
                        conc.append(c+down-1)
                        graph = modi_graph(graph, c, conc)
                else:
                    conc.append(c-1)
                    conc.append(c+1)
                    conc.append(c-up)
                    conc.append(c-up+1)
                    conc.append(c+down)
                    conc.append(c+down-1)
                    graph = modi_graph(graph, c, conc)
    return graph


def modi_wax(graph,n,wax_list):
    for wc in wax_list:
        for i in range(n):
            graph[i][wc-1]=0
            graph[wc-1][i]=0
    return graph

r,n,A,B,x = map(int, input().split())
graph = make_graph(r)
wax_list = list(map(int, input().split()))
#print(wax_list)
#print(graph[3-1])
nc = (r**3)-((r-1)**3)
graph = modi_wax(graph,nc, wax_list)
#print(graph[3-1])

# Python program for Dijkstra's single
# source shortest path algorithm. The program is
# for adjacency matrix representation of the graph
class Graph():

    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] for row in range(vertices)]

    def printSolution(self, dist,des):
        #print(dist[des])
        return dist[des]

    def minDistance(self, dist, sptSet):
        
        mini = 10000000
        min_index = -1
        for v in range(self.V):
            if dist[v] < mini and sptSet[v] == False:
                mini = dist[v]
                min_index = v
        return min_index

    def dijkstra(self, src,des):

        dist = [1e7] * self.V
        dist[src] = 0
        sptSet = [False] * self.V

        for cout in range(self.V):

            u = self.minDistance(dist, sptSet)
            if u!=-1:
                sptSet[u] = True

            for v in range(self.V):
                if (self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]):
                    dist[v] = dist[u] + self.graph[u][v]

        return self.printSolution(dist,des)

# Driver program
#print("NC:",nc)
#print(graph[14-1])
#print(graph[15-1])
#print(graph[16-1])
#print(graph[3-1])
#print(graph[7-1])
g = Graph(nc)
g.graph = graph

res = g.dijkstra(A-1,B-1)
#print(res)
if res<=n:
    print(res)
else:
    print("no")