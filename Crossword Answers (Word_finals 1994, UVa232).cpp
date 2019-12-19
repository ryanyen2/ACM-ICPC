#include <stdio.h>

char maps[15][15];
int nums[15][15];
int main()
{
    int r,c;
    int index = 1;
    int counts = 1;
    int firstFlag = 1;
    int i, j, k;
    while(scanf("%d", &r) && r != 0)
    {
        scanf("%d", &c);
        if(!firstFlag)
            printf("\n");

        counts = 1;
        printf("puzzle #%d:\n", index++);
        for(i = 0 ; i < r;++i)
        {
            scanf("%s", maps[i]);
        }

        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;++j)
            {
                if(maps[i][j] != '*' && (i == 0 || j == 0 || maps[i-1][j] == '*' || maps[i][j-1] == '*'))
                {
                    nums[i][j] = counts++;
                }
            }
        }
        printf("Across\n");
        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;)
            {
                if(maps[i][j] != '*'){
                    printf("%3d.", nums[i][j]);
                    for(k = j;k < c && maps[i][k] != '*';++k)
                    {
                        printf("%c", maps[i][k]);
                    }
                    printf("\n");
                    j = k + 1;
                }
                else{
                    j++;
                }
            }
        }

        printf("Down\n");
        for(i = 0 ; i < r;++i)
        {
            for(j = 0 ; j < c;++j)
            {
                if(maps[i][j] != '*' && (i == 0 || maps[i-1][j] == '*')){
                    printf("%3d.", nums[i][j]);
                    for(k = i;k < r && maps[k][j] != '*';++k)
                    {
                        printf("%c", maps[k][j]);
                    }
                    printf("\n");
                }
            }
        }

        firstFlag = 0;
    }
    return 0;
}




// Another answer
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	_for(i, 0, v.size()) os << v[i] << " ";
	return os;
}

struct Point {
	int x, y;
	Point(int x = 0, int y = 0):x(x), y(y){}
};
typedef Point Vector;

Vector operator+(const Vector& A, const Vector& B) { return Vector(A.x + B.x, A.y + B.y); }
int row, col;
const int MAXC = 16;
char grid[MAXC][MAXC];

inline bool valid(const Point& p) {
	return p.x >= 0 && p.x < row && p.y >= 0 && p.y < col;
}
int main() {

	char buf[MAXC]; int buf_len;
	const Vector dLeft(0, -1), dRight(0, 1), dUp(-1, 0), dDown(1, 0);
	for (int t = 1; cin >> row && (row); t++) {
		cin >> col;
		vector <Point> eligible;
		vector <int> down, accross;

		if (t > 1) cout << " ";
		printf("Puzzle #%d:\n", t);
		_for(i, 0, row) {
			cin >>  grid[i];
			_for(j, 0, col) {
				if (grid[i][j] == '*') continue;
				Point p(i, j), left = p + dLeft, up = p + dUp;
				bool isCross = !valid(left) || grid[left.x][left.y] == '*';
				bool isDown = !valid(up) || grid[up.x][up.y] == '*';
				if (isCross) accross.push_back(eligible.size());
				if (isDown) down.push_back(eligible.size());
				if (isDown || isCross) eligible.push_back(p);
			}
		}
		puts("Accross");
		for (auto n : accross) {
			buf_len = 0, memset(buf, 0, sizeof(buf));
			Point p = eligible[n];
			while (valid(p) && grid[p.x][p.y] != '*') {
				buf[buf_len++] = grid[p.x][p.y];
				p = p + dRight;
			}
			printf("%3d.%s\n", n + 1, buf);
		}
		puts("Down");
		for (auto m : down) {
			buf_len = 0, memset(buf, 0, sizeof(buf));
			Point p = eligible[m];
			while (valid(p) && grid[p.x][p.y] != '*') {
				buf[buf_len++] = grid[p.x][p.y];
				p = p + dDown;
			}
			printf("%3d.%s\n", m + 1, buf);
		}
	}
	
	return 0;
}

