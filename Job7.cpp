#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


int graph[1024][4]; //2D array with first dimension being the node ID and second being the node's connections

int path[1024]; //array of node ids that form a path
int player = 64;
int target = 888;
void generate_map_graph() {
    //generates a 32x32 graph
    //each node has its adjacent nodes as neighbours
    for(int x=0; x<1024; x++) {
        if(x%32!=0) {graph[x][0] = x-1;}
        else {graph[x][0] = -1;}
        if((x+1)%32 != 0) {graph[x][1] = x+1;}
        else {graph[x][1] = -1;}
        if(x>=32) {graph[x][2] = x-32;}
        else {graph[x][2] = -1;}
        if(x < 992) {graph[x][3] = x+32;}
        else {graph[x][3] = -1;}
    }
}


list<int> pathDFC;
int pathDFCArr[1024];
void DFC(int start, int target) {
    list<int> stack;
    bool explored[1024]; //array of bools that checks if a node has been explored


    while(!stack.empty()) {
        int u = stack.back();
        stack.pop_back();

        for(int n=0; n<4; n++) {
            bool found = (find(stack.begin(), stack.end(), u) != stack.end());
            if(!explored[u] && !found) {
                if(graph[u][n] == target) {
                    return;
                }
                stack.push_back(graph[u][n]);
            }
        }
        explored[u] = true;
    }
}

void render_map() {
    for(int i=0; i<1024; i++) {
        string val = "□";

        for(int p=0; p<pathDFC.size(); p++) {
            if(i==p) {
                val = "■";
                break;
            }
        }

        if(i == player) {
            val = "P";
        }
        if(i == target) {
            val = "T";
        }
        cout << val << " ";

        if((i+1)%32 == 0) {
            cout << "\n";
        }
    }
}
int main()
{
    generate_map_graph();
    DFC(player, 888);
    copy(pathDFC.begin(), pathDFC.end(), pathDFCArr);
    render_map();
    return 0;
}