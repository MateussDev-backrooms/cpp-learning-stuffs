#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> graph[10000];
int n, m;
//this 2D array contains a collection of other arrays
//graph[i][j] contains the j neighbour of i, and i is the node

bool explored[10000]; //contains all of the explored nodes
bool path[10000]; //checks if a given node is a part of the path


void DFS(int root, int target) {
    path[root] = true;
    // cout << root << "Begin of path\n";
    if(path[root]) {
    }
        for(int j=0; j<graph[root].size(); j++) {
            //for every neighbour
            //j = neighbour
            //what has always fascinated me is to look out at the night sky and see all the stars and think wow I wonder what it's like in other parts of the universe.
            //now at the moment we can't travel there, but we can still measure the light coming from those stars
            //I learnt about the wonders of the universe in this way
            if(!explored[graph[root][j]]) {
                explored[graph[root][j]] = true;
                DFS(graph[root][j], target);
            }
            if(path[graph[root][j]]) {
                cout << "There's a loop\n";
            }

        }
    // cout << root << " End of DFS - remove from path\n";
    path[root] = false;
    return;
}

list<int> queue;

int dp_bfs[10000]; // represents the distance from target to node i

//idea
//use BFS - when checking the neighbours set dp[i] to the parent node's distance + 1

int _cnt = 0;
int _cnt_queues = 0;
vector<int> _graph_begin;
void BFS(int root) {
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
                if(!path[graph[current][i]]) {
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
                }
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
        
        //instead of adding a connection pointing outwards, we point inwards
        graph[b].push_back(a);
        // graph[b].push_back(a);
    }

    vector<bool> deleted;
    vector<int> found_elems;
        while(deleted.size() <= n) {
            for(int i=0; i<n; i++) {
                int cnt=0;
                cout << "\n<" << i << "> ";
                bool _baz = find(found_elems.begin(), found_elems.end(), i) == found_elems.end();
                for(int j=0; j<graph[i].size(); j++) {
                    cout << "j - " << j << " g - " << graph[i][j] << " ";
                    bool _baz2 = find(found_elems.begin(), found_elems.end(), graph[i][j]) == found_elems.end();
                    if(!deleted[ graph[i][j] ] && _baz2) {
                        cnt++;
                        cout << "/" << graph[i][j] << "/";
                    }
                }
                if(cnt == 0) {
                    deleted.insert(deleted.begin() + i, true);
                    if(_baz) {
                        cout << "[" << i << " is deleted]";
                        found_elems.push_back(i);
                    }
                    cnt = 0;
                }
            }
        }

    // DFS(0, n-1);
    cout << endl;
    for(int i=0; i<found_elems.size(); i++) {
        cout << found_elems[i] << " ";
    }

    return 0;
}