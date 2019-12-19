#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)

int main() {

	int times;
	cin >> times;
	_for(ti, 0, times) {
		int amount, length = 0;
		string dna[50];
		cin >> amount >> length;
		// user_input the possible DNA
		_for(i, 0, amount) 
			cin >> dna[i];

		vector<char>ans_line[50];
		_for(i, 0, length) {
			_for(j, 0, amount) {
				ans_line[i].push_back(dna[j][i]);
			}
		}
		string final_answer;
		_for(i, 0, length) {
			int count_A = count(ans_line[i].begin(), ans_line[i].end(), 'A');
			int count_C = count(ans_line[i].begin(), ans_line[i].end(), 'C');
			int count_G = count(ans_line[i].begin(), ans_line[i].end(), 'G');
			int count_T = count(ans_line[i].begin(), ans_line[i].end(), 'T');
			if (count_A >= count_C && count_A >= count_G && count_A >= count_T) final_answer.push_back('A');
			if (count_C > count_A && count_C >= count_G && count_C >= count_T) final_answer.push_back('C');
			if (count_G > count_C && count_G > count_A && count_G >= count_T) final_answer.push_back('G');
			if (count_T > count_C && count_T > count_G && count_T > count_A) final_answer.push_back('T');
		}
		cout << final_answer << endl;
	}



	return 0;
}
