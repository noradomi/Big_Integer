#include"DocGhiFileQFloat.h"

vector< vector<string> > docFileQFloat(const char* path) {
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

void ghiFileQFloat(const char * path, vector<vector<string> > input)
{
	ofstream write;
	write.open(path);
	for (int i = 0; i < input.size(); i++) {
		vector<string> temp = input[i];
		if (temp.size() < 3)
		{
			break;
		}
		QFLoat tam;
		string res;

		string p1 = temp[0]; //hệ cơ số của input
		string p2 = temp[1]; // hệ cơ số kết quả
		string in = temp[2]; //số đầu vào
							 // hàm chuyển đổi cơ số từ p1 sang p2

		res = tam.chuyenDoiCoSo(p1, p2, in);
		write << res << endl;
	}

	write.close();
}