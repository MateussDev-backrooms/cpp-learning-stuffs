#include <iostream>
using namespace std;

int board[128][128]; //2D board no more than 100 by 100
int n, m; //board real size
//board contains a number which is the cell type
//0 is empty, 1 is virus, 2 is protected and 3 is transitional (for flood fill)

bool flood_fill(int origin_x, int origin_y) {
    // render the entire board
    // cout << "\n[ Board ]" << endl;
    // for(int i=0; i<=n; i++) {
    //     for(int j=0; j<=m; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //do the flood fillin
    int cnt = 0;
    if(board[origin_x][origin_y] == 0) {
        board[origin_x][origin_y] = 3;
        cnt++;
    }

    if(board[origin_x][origin_y] == 0 || board[origin_x][origin_y] == 3) {
        if(origin_x > 0) {
            if(board[origin_x-1][origin_y] == 0) {
                board[origin_x-1][origin_y] = 3;
                cnt++;
                flood_fill(origin_x-1, origin_y);
            }
        }
        if(origin_y > 0) {
                if(board[origin_x][origin_y-1] == 0) {
                    board[origin_x][origin_y-1] = 3;
                    cnt++;
                    flood_fill(origin_x, origin_y-1);
                }
        }
        if(origin_x < n-1) {
            if(board[origin_x+1][origin_y] == 0) {
                board[origin_x+1][origin_y] = 3;
                cnt++;
                flood_fill(origin_x+1, origin_y);
            }
        }
        if(origin_y < m-1) {
            //all sides are available
            if(board[origin_x][origin_y+1] == 0) {
                board[origin_x][origin_y+1] = 3;
                cnt++;
                flood_fill(origin_x, origin_y+1);            
            }
        }        
    }
    

    if(cnt <= 0) {
        return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;

    int p_amount;
    cin >> p_amount;
    //get the board
    for(int i=0; i<p_amount; i++) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 2;
    }

    int successful_flood_fills_cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            bool result = flood_fill(i, j);
            if(result) {
                successful_flood_fills_cnt++;
            }
            // cout << "Result of flood fill at (" << i << ", " << j << ") is - " << result;
        }
    }

    

    cout << successful_flood_fills_cnt;

    //do a flood fill
    return 0;
}