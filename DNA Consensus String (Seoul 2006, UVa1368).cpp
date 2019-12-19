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



//Another answer
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define _for(i, a, b) for (int i = (a); i<(b); ++i)

int main() {

	int testcase;
	int n, m;
	char DNA[64][1024];
	cin >> testcase;
	while (testcase--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> DNA[i];
		int final_dis = 0;
		char final_ans[1024] = {}, index[] = "ACGT";
		_for(i, 0, m) {
			int cnt[4] = {}, max = 0;
			_for(j, 0, n)
				cnt[find(index, index + 4, DNA[j][i]) - index]++;

			_for(j, 0, 4) {
				if (cnt[j] > cnt[max])
					max = j;
			}
			final_ans[i] = index[max], final_dis += n - cnt[max];

		}
		printf("%s\n%d\n", final_ans, final_dis);
	}
	return 0;
}

