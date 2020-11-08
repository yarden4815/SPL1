#include <vector>


class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix){
        edges = matrix;
    }

    void infectNode(int nodeInd){
        infected.push_back(nodeInd);
    }

    bool isInfected(int nodeInd){
        std::vector<int>::iterator it;
        for (it = infected.begin(); it != infected.end(); ++it){
            if (infected[*(it)] == nodeInd)
                return true;
        }
        return false;
    }

private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected;
};



