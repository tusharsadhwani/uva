#include<bits/stdc++.h>

using namespace std;

void floodfill(char grid[100][100], int seen[100][100], int n, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n)
        return;
    
    if (seen[i][j] == 1)
        return;

    if (grid[i][j] == 'x' || grid[i][j] == '@') {
        seen[i][j] = 1;

        floodfill(grid, seen, n, i, j-1);
        floodfill(grid, seen, n, i, j+1);

        floodfill(grid, seen, n, i-1, j);
        floodfill(grid, seen, n, i+1, j);
    }
}

int main() {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // ofstream out("o.txt");
	// cout.rdbuf(out.rdbuf());

    char grid[100][100];

    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int seen[100][100] = {0};
        int count = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            scanf(" %s", grid[i]);
        }
        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (seen[i][j] == 0 && grid[i][j] == 'x') {
                    floodfill(grid, seen, n, i, j);
                    count++;
                }
            }
        }
        cout << "Case " << c << ": " << count << endl;
    }
	return 0;
}
