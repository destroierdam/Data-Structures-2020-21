#include <iostream>
#include <vector>

class Graph {
private:
    struct Node {
        int nodeId;
    };

    size_t n, m;

    std::vector<std::vector<Node> > adjacencyLists;

public:
    void read() {
        adjacencyLists.clear();

        std::cin >> n >> m;
        adjacencyLists.resize(n);

        for(size_t i = 0; i < m; i++) {
            int from, to;
            std::cin >> from >> to;
            adjacencyLists[from].push_back(Node{to});
            adjacencyLists[to].push_back(Node{from});
        }
    }

    bool checkForCycle(Node current, Node parent, std::vector<bool> & isVisited) {
        isVisited[current.nodeId] = true;

        for(size_t i = 0; i < adjacencyLists[current.nodeId].size(); i++) {
            Node neighbor = adjacencyLists[current.nodeId][i];

            if(isVisited[neighbor.nodeId] && parent.nodeId != neighbor.nodeId) {
                return true;
            }

            if(isVisited[neighbor.nodeId] == false) {

                if(checkForCycle(neighbor, current, isVisited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasCycle() {
        std::vector<bool> visited(n);

        bool ans = false;

        for(size_t i = 0; i < n; i++) {

            if(visited[i] == false) {
                ans = ans || checkForCycle(Node{(int)i}, Node{(int)-1}, visited);
                if(ans) {
                    std::cout << "Found a cycle in: " << i << std::endl; 
                    break;
                }
            }
        }

        return ans;
    }


};

int main() {
    Graph graph;
    graph.read();
    std::cout << graph.hasCycle() << std::endl;
    return 0;
}

/* 8 vurha 5 rebra
8 5

0 1
1 2
5 6
6 7
7 5



*/

/*
1 // vryh 0
0 2 // vruh 1
1 // vruh 2


6 7
5 7
5 6
*/