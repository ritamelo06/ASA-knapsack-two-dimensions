#include <iostream>
#include <vector>
#define max(a, b) (a > b ? a : b)

using namespace std;

int maximizeProfit(int X, int Y, vector<vector<int>>& values){   
     
    for (int i = 1; i <= X; i++) {
        for (int j = 1; j <= Y; j++) {
            for(int corteV = 0; corteV <= i-1; corteV++){
                // vertical cut 
                values[i][j] = max(values[i][j], values[i - corteV][j] + values[corteV][j]);    // choose the most profitable arrangement
            }
            for(int corteH = 0; corteH <= j-1; corteH++){
                // horizontal cut
                values[i][j] = max(values[i][j], values[i][j - corteH] + values[i][corteH]);    // choose the most profitable arrangement
            }
        }
    }
    return values[X][Y];
}

int main(){  
    int X, Y, n, maxProfit;
    scanf("%d %d", &X, &Y);                // reads board's dimensions
    scanf("%d", &n);                       // reads number of types of pieces
    
    if(n == 0 || X == 0 || Y == 0){
        maxProfit = 0;
    }
    else{    
        vector<vector<int>> values(X + 1, vector<int>(Y + 1, 0));      // stores the maximum total value for each subproblem   
        
        for(int i = 0; i < n; i++){
            int ai, bi, pi;
            scanf("%d %d %d", &ai, &bi, &pi);                          // reads the information on each piece
        
            if((X >= ai && Y >= bi) && (X >= bi && Y >= ai)){          // piece fits rotated and not rotated
                values[ai][bi] = max(values[ai][bi], pi);
                values[bi][ai] = max(values[bi][ai], pi); 
            }
            else if ((X >= ai && Y >= bi) && !(X >= bi && Y >= ai))    // piece only fits if not rotated
                values[ai][bi] = max(values[ai][bi], pi);
            
            else if (!(X >= ai && Y >= bi) && (X >= bi && Y >= ai))    // piece only fits if rotated
                values[bi][ai] = max(values[bi][ai], pi);
        }
        maxProfit = maximizeProfit(X, Y, values);
    }    
    printf("%d\n", maxProfit);
    return 0;
}
