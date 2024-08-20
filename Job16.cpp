#include <iostream>
#include <vector>
#include <list>
#include <cmath>
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

int dp_bfs1[10000]; // represents the distance from target to node i
int dp_bfs2[10000]; // represents the distance from target to node i

//idea
//use BFS - when checking the neighbours set dp[i] to the parent node's distance + 1

int _cnt = 0;
int _cnt_queues = 0;
vector<int> _graph_begin;
void BFS(int root) {
    // if(find(queue.begin(), queue.end(), root) != queue.end()) {
    // }

    //reset explored list
    for(int i=0; i<n; i++) {
        explored[i]=false;
        dp_bfs1[i]=0;
    }
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
                dp_bfs1[graph[current][i]] = dp_bfs1[current] + 1;
                // BFS(graph[current][i]);
                explored[graph[current][i]] = true;
                _cnt++;
                queue.push_back(graph[current][i]);
                cout << " - [" << dp_bfs1[graph[current][i]] << "]\n";
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

    cout << "Insert node A and node B to find middle point\n";
    int a, b;
    cin >> a >> b;

    //BFS from A
    queue.push_back(a);
    while(queue.size() > 0) {
        int current = queue.front();
        queue.pop_front();

        for(int i=0; i<graph[current].size(); i++) {
            cout << "<Looking at neighbour of node " << current << " - node " << graph[current][i] << ">";
            if(!explored[graph[current][i]]) {
                dp_bfs1[graph[current][i]] = dp_bfs1[current] + 1;
                // BFS(graph[current][i]);
                explored[graph[current][i]] = true;
                _cnt++;
                queue.push_back(graph[current][i]);
                cout << " - [" << dp_bfs1[graph[current][i]] << "]\n";
                cout << endl;
            } else {
                cout << " - [Node already explored]\n";
            }
        }
    }
    //reset explored list
    for(int i=0; i<n; i++) {
        explored[i]=false;
    }

    //BFS from B
    queue.push_back(b);
    while(queue.size() > 0) {
        int current = queue.front();
        queue.pop_front();

        for(int i=0; i<graph[current].size(); i++) {
            cout << "<Looking at neighbour of node " << current << " - node " << graph[current][i] << ">";
            if(!explored[graph[current][i]]) {
                dp_bfs2[graph[current][i]] = dp_bfs2[current] + 1;
                // BFS(graph[current][i]);
                explored[graph[current][i]] = true;
                _cnt++;
                queue.push_back(graph[current][i]);
                cout << " - [" << dp_bfs2[graph[current][i]] << "]\n";
                cout << endl;
            } else {
                cout << " - [Node already explored]\n";
            }
        }
    }
    
    float req = dp_bfs2[a]/2.0;
    cout << req << "\n";

    for(int i=0; i<n; i++) {
        if((dp_bfs1[i] == floor(req) && dp_bfs2[i] == ceil(req))
        || (dp_bfs1[i] == ceil(req) && dp_bfs2[i] == floor(req))) {
            cout << "Bazinga - " << i << endl;
        }
    }

    return 0;
} 