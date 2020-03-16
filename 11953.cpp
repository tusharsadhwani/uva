#include<bits/stdc++.h>

using namespace std;

pair<int, int> find_adjacent(
        vector< pair<int, int> > &path,
        pair<int, int> point,
        int i)
{
    pair<int, int> adjacent;
    bool flag = false;
    for (auto v : path) {
        if (v.second == point.second) {
            if (point.first - v.first == 1) {
                cout << "forth";
                flag = true;
            }
        }
        if (v.first == point.first) {
            if (point.second - v.second == 1) {
                cout << "left";
                flag = true;
            }
            else if (point.second - v.second == -1) {
                cout << "right";
                flag = true;
            }
        }

        if (flag) {
            if (i != 6) {
                cout << " ";
            }
            adjacent.first = v.first;
            adjacent.second = v.second;

            auto it = find(path.begin(), path.end(), v);
            path.erase(it);
            return adjacent;
        }
    }
    return *path.end();
}

int main() {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // ofstream out("o.txt");
	// cout.rdbuf(out.rdbuf());


    unordered_map<char, int> indices = {
        {'I', 0},
        {'E', 1},
        {'H', 2},
        {'O', 3},
        {'V', 4},
        {'A', 5}
    };

    int n, w, h;
    char x;
    cin >> n;
    for (; n > 0; n--)
    {
        vector< pair<int, int> > path(7);
        pair<int, int> start, end;

        cin >> h >> w;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                scanf(" %c", &x);

                if (x == '@') {
                    start = {i, j};
                    continue;
                }
                if (x == '#') {
                    end = {i, j};
                    continue;
                }

                auto it = indices.find(x);
                if (it != indices.end()) {
                    int index = it->second;
                    path[index] = {i, j};
                }
            }
        }
        path[6] = end;

        auto tmp = start;
        for (int i = 0; i < 7; i++) {
            tmp = find_adjacent(path, tmp, i);
        }
        cout << endl;
    }

	return 0;
}
