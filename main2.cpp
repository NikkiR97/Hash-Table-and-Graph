// completeGraph.cpp

#include <cstring>
#include <iostream>
using namespace std;

template <int N>
class Graph {
public:
    // start with no edges at all
    Graph() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                matrix[i][j] = 0;
            }
        }

        count = 0;
    }

    // insert an edge
    void insertEdge(const char fromcity[], const char tocity[], int cost) {
        int from = lookup(fromcity);
        int to = lookup(tocity);
        matrix[from][to] = cost;
        matrix[to][from] = cost;
    }

    // lookup the index of a name
    int lookup(const char name[]) const {
        for(int i = 0; i < count; i++) {
            if(strcmp(names[i], name) == 0) {
                return i;
            }
        }

        return -1;
    }

    // return name of an index
    const char* name(int index) const {
        return names[index];
    }

    // insert a node
    void insertNode(const char* name) {
        strcpy(names[count], name);
        count++;
    }

    // return the cost of an edge or 0 for none
    int getCost(int from, int to) const {
        return matrix[from][to];
    }

    // remove an edge
    void removeEdge(const char fromcity[], const char tocity[]) {
        int from = lookup(fromcity);
        int to = lookup(tocity);
        matrix[from][to] = 0;
        matrix[to][from] = 0;
    }

    // return the number of nodes
    int size() const {
        return count;
    }

    // return whether the graph is complete
    bool complete() const {
        // fill in!
        // needs to traverse the entire graph to see if it's complete
        // all the adjacent nodes to any vertex should be the same as other vertices
        // the ajacency matrix needs to have entire row filled  for the corresponding element
        bool complete = true;

        for(int i=0; i<count; i++){//row
            for(int j=0; j<count; j++){//column
                if(i!=j) {//do the next check only if i and j are looking at the same node (there cannot be a connection of a node to itself)
                    if ((matrix[i][j] != 1)) {
                        complete = false;
                    }
                }
            }
        }

        return complete;
    }


private:
    int matrix[N][N];
    char names[N][25];
    int count;
};

int main() {
    Graph<5> graph;
    graph.insertNode("A");
    graph.insertNode("B");
    graph.insertNode("C");
    graph.insertNode("D");
    graph.insertNode("E");

    graph.insertEdge("A", "B", 1);
    graph.insertEdge("A", "C", 1);
    graph.insertEdge("A", "D", 1);
    graph.insertEdge("A", "E", 1);

    graph.insertEdge("B", "C", 1);
    graph.insertEdge("B", "D", 1);
    graph.insertEdge("B", "E", 1);

    graph.insertEdge("C", "D", 1);
    graph.insertEdge("C", "E", 1);

    graph.insertEdge("D", "E", 1);

    // should print "Complete!"
    if(graph.complete()) {
        cout << "Complete!" << endl;
    } else {
        cout << "Not complete!" << endl;
    }

    // remove an edge and try it again
    graph.removeEdge("B", "C");

    // should print "Not complete!"
    if(graph.complete()) {
        cout << "Complete!" << endl;
    } else {
        cout << "Not complete!" << endl;
    }

    return 0;
}


