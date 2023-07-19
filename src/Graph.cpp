#include "Const.h"
#include <list>
#include "Graph.h"
#include <utility>
#include <iostream>

//===========costructor=============
Graph::Graph(int v)
{
    m_v = v;
    m_adj.resize(v);
    m_visited.resize(v, false);
}
//===========clearEdge=============
void Graph::restart() {

    m_dadAndSon.clear();
    m_adj.clear();
    m_adj.resize(m_v);
    m_visited.clear();
    m_visited.resize(m_v, false);
}
//===========addEdge=============
void Graph::addEdge(int v, int w){

    m_adj[v].push_back(w); // Add w to v’s list.
}

//The function executes the DFS algorithm
//===========DFS=============
void Graph::DFS(int currentNode, const int& target,bool & found){

    m_visited[currentNode] = true;// Marks the current node as visited

    for (auto it = m_adj[currentNode].begin(); it != m_adj[currentNode].end() && !found; it++) {
        if (!m_visited[*it]) {
            m_dadAndSon.push_back(make_pair(currentNode, *it));
            if (target == *it)
                found = true;
            else DFS(*it, target, found);
        }
    }
}
//The function returns the track by pass on the tree that the algorithm creates
//===========getTrack=============
vector<int> Graph::getTrack() {
    
    vector<int> track;

    int i = m_dadAndSon.size() - 1;

    while (true)
    {
        if (i == 0) {
            track.push_back(m_dadAndSon[i].second);
            return track;
        }
        
        else {
            //search for the father of current son 
            for (size_t cell = 0; cell < m_dadAndSon.size() - 1; cell++) 
                if (m_dadAndSon[i].first == m_dadAndSon[cell].second) {
                    track.push_back(m_dadAndSon[i].first);
                    i = cell;
                    break;
                }
        }
    }
    return track;
}