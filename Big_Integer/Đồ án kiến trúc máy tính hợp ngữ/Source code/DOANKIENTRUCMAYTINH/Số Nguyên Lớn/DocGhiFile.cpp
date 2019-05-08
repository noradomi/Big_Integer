#include"DocGhiFile.h"

vector< vector<string> > docFile(const char* path) {
	ifstream read;
	read.open(path);
	string line;
	// Đọc toàn bộ file vào vector 2 chiều
	vector< vector<string> > input;
	vector<string> temp;
	while (!read.eof()) {
		// Đọc 1 dòng
		getline(read, line);

		// Tách dòng thành các token lưu trong input

		stringstream ss(line);
		string token = "";
		while (ss >> token) {
			temp.push_back(token);
		}
		input.push_back(temp);
		temp.clear();
		string br;
		// Đọc kí tự xuống dòng

	}
	read.close();
	return input;
}

void ghiFile(const char * path, vector<vector<string> > input)
{
	ofstream write;
	write.open(path);
	for (int i = 0; i < input.size(); i++) {
		vector<string> temp = input[i];
		QInt tam;
		string res;
		if (temp.size() <= 3) {
			// Chuyển đổi hệ cơ số
			string p1 = temp[0];
			string p2 = temp[1];
			// Viết hàm chuyển đổi cơ số từ p1 sang p2
			res = tam.chuyenDoiCoSo(p1, p2, temp[2]);
		}
		else {
			res = tam.thucHienPhepToan(temp[0], temp[1], temp[2], temp[3]);
		}
		if (res != "0") {
			remove_zero(res);
		}
		write << res << endl;

	}
	write.close();
}