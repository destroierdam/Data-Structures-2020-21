#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int> > & adjLists, int node, std::vector<bool> & used) {
    
    used[node] = true;
    std::cout << node << " ";

    for(size_t i = 0; i < adjLists[node].size(); i++) {
        if(used[adjLists[node][i]] == false) {
            dfs(adjLists, adjLists[node][i], used);
        }
    }

    std::cout<<"\n";
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > adjLists(n);

    for(size_t i = 0; i < n; i++) {
        size_t numberOfNeighbors;
        std::cin >> numberOfNeighbors;
        for(size_t j = 0; j < numberOfNeighbors; j++) {
            int neighbor;
            std::cin >> neighbor;
            adjLists[i].push_back(neighbor);
        }
    }

    std::cout << "\n";
    
    std::vector<bool> used(n, false);
    size_t numberOfConnectedComponents = 0;
    
    for(size_t i = 0; i < n; i++) {
        if(used[i] == false) {
            dfs(adjLists, i, used);
            numberOfConnectedComponents++;
        }
    }

    std::cout<<"\nNumber of connected components: "<<numberOfConnectedComponents<<"\n";
    
    // for(auto& neighbors : adjLists) {
    //     for(int neighbor : neighbors) {
    //         std::cout << neighbor << " ";
    //     }
    //     std::cout << "\n";
    // }

}
/*
7
3 2 4 5
2 4 5
3 0 3 4
1 2
5 0 1 2 5 6
3 0 1 4
1 4
*/