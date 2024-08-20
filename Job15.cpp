#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> graph[10000];
int n, m;
//this 2D array contains a collection of other arrays
//graph[i][j] contains the j neighbour of i, and i is the node

bool explored[10000]; //contains all of the explored nodes

void DFS(int root, int target) {
    for( int i=0; i<=n; i++) {
        //i = parent
        for(int j=0; j<graph[i].size(); j++) {
            //for every neighbour
            //j = neighbour
            if(!explored[graph[i][j]]) {
                
                explored[graph[i][j]] = true;
                DFS(graph[i][j], target);
            }
        }
    }

    return;
}

list<int> queue;

int dp_bfs[10000]; // represents the distance from target to node i

//idea
//use BFS - when checking the neighbours set dp[i] to the parent node's distance + 1

int _cnt = 0;
int _cnt_queues = 0;
vector<int> _graph_begin;
bool BFS(int root) {
    // if(find(queue.begin(), queue.end(), root) != queue.end()) {
    // }
    _cnt = 0;
    if(!explored[root]) {
        queue.push_back(root);
        _cnt++;
    }
    explored[root] = true;

    while(queue.size() > 0) {
        int current = queue.front();
        queue.pop_front();

        for(int i=0; i<graph[current].size(); i++) {
            cout << "<Looking at neighbour of node " << current << " - node " << graph[current][i] << ">";
            if(!explored[graph[current][i]]) {
                dp_bfs[graph[current][i]] = dp_bfs[current] + 1;
                // BFS(graph[current][i]);
                explored[graph[current][i]] = true;
                _cnt++;
                queue.push_back(graph[current][i]);
                cout << " - [" << dp_bfs[graph[current][i]] << "]\n";
                for(int j=0; j<n; j++) {
                    //render the explored status
                    cout << explored[j] << " ";
                }
                cout << endl;
            } else {
                cout << " - [Node already explored]\n";
            }
        }
    }

    cout << "exit queue with " << _cnt << " changes...\n";
    if(_cnt > 0) {
        _cnt_queues++;
        return true;
    }
    return false;
}

int main()
{
    //we've got a graph!!!!!

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        //add to path array
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    //calculate how many separate graphs are here
    for(int i=0; i<n; i++) {
        bool result = BFS(i);
        if(result) {
            _graph_begin.push_back(i);
        }
    }
    cout << "Separate graphs: " << _cnt_queues;

    cout << endl;
    //render what connections are needed
    for(int i=0; i<_graph_begin.size(); i++) {
        if(i>0) {
            cout << "Connection needed from " << _graph_begin[i] << " -> " << _graph_begin[i-1] << "\n";
        } else {
            cout << "Cannot place connection here...\n";
        }
    }


    return 0;
}