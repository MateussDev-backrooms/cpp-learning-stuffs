#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> graph[10000];
int n, m;
//this 2D array contains a collection of other arrays
//graph[i][j] contains the j neighbour of i, and i is the node

bool explored[10000]; //contains all of the explored nodes
bool explored2[10000];

list<int> queue;

int dp_bfs[10000];


//idea
//use BFS - when checking the neighbours set dp[i] to the parent node's distance + 1
void BFS(int root) {
    // if(find(queue.begin(), queue.end(), root) != queue.end()) {
    // }

    //reset dp_bfs
    for(int i=0; i<n; i++) {
        dp_bfs[i] = 0;
        explored[i] = false;
    }
    if(!explored[root]) {
        queue.push_back(root);
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

    cout << "Insert two tree elements to find their mutual parent:\n";
    int a, b;
    cin >> a >> b;

    //reset dp_bfs 
    BFS(a);
    BFS(b);
    return 0;
}