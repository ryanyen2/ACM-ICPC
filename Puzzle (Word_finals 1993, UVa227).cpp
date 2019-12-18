#include <iostream>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); i++)

string instruction;
string strs[5];			// !!!!!!!! IMPORTANT 
void get_input(){
	// get origin matrics
	_for(i, 0, 5) {
		getline(cin, strs[i]);
	}
	// get_instruct
	getline(cin, instruction);
}

// get the blank coordenation
int obx = 0, oby = 0;
void find_blank() {
	_for(x, 0, 5) {
		_for(y, 0, 5) {
			if (strs[x][y] == ' ') {
				obx = x;
				oby = y;
				break;
			}
		}
	}
}

int main() {
	
	get_input();
	
	_for(i, 0, instruction.size()) {
		find_blank();	// renew the blank position
		if (instruction[i] == 'A') {
			strs[obx][oby] = strs[obx - 1][oby];
			strs[obx - 1][oby] = ' ';
		}
		else if (instruction[i] == 'B') {
			strs[obx][oby] = strs[obx + 1][oby];
			strs[obx + 1][oby] = ' ';
		}
		else if (instruction[i] == 'L') {
			strs[obx][oby] = strs[obx][oby - 1];
			strs[obx][oby - 1] = ' ';
		}
		else if (instruction[i] == 'R') {
			strs[obx][oby] = strs[obx][oby + 1];
			strs[obx][oby + 1] = ' ';
		}
		else break;
	}

	// output the answer
	_for(x, 0, 5) {
		_for(y, 0, 5) {
			cout << strs[x][y] << ' ';
		}
		cout << endl;
	}

	return 0;
}











// Another solution
#include <iostream>
#include <vector>
#include <string>
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
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};
typedef Point Vector;

const int GSize = 5;
vector<string> grid;
Point ePos;
map<char, Vector> DIRS;

bool valid(const Point& p) {
	return p.x >= 0 && p.x < GSize && p.y >= 0 && p.y < GSize;
}

void print_grid() {
	_for(i, 0, GSize) {
		_for(j, 0, GSize) {
			if (j) cout << ' ';
			cout << grid[i][j];
		}
		cout << endl;
	}
}

bool try_move(char cmd) {
	if (!DIRS.count(cmd)) return false;
	Point p = ePos + DIRS[cmd];
	if (!valid(p)) return false;
	swap(grid[p.x][p.y], grid[ePos.x][ePos.y]);
	ePos = p;
	return true;
}


int main() {

	int t = 1;
	string line;
	DIRS['A'] = Vector(-1, 0); DIRS['B'] = Vector(1, 0); DIRS['L'] = Vector(0, -1); DIRS['R'] = Vector(0, 1);
	while (true) {
		grid.clear();
		ePos.x = -1;
		ePos.y = -1;
		_for(i, 0, GSize) {
			getline(cin, line);
			if (line == "Z") return 0;
			assert(line.size() == GSize);
			_for(j, 0, GSize) {
				if (line[j] == ' ') {
					assert(ePos.x == -1 && ePos.y == -1);
					ePos.x = i;
					ePos.y = j;
				}
				grid.push_back(line);
			}
		}
		char move;
		string moves;
		while (true) {
			getline(cin, moves);
			assert(!line.empty());
			bool end = *(line.rbegin()) == '0';
			if (!end) moves.append(line);
			else moves.append(line, 0, line.size() - 1);
			if (end) break;
		}
		bool legal = true;
		_for(i, 0, moves.size())
			if (!try_move(moves[i])) { legal = false; break; }
		if (t > 1) cout << endl;
		cout << "Puzzle #" << t++ << " : " << endl;
		if (legal) print_grid();
		else cout << "This puzzle has no final configuration." << endl;
	}
	return 0;
}
