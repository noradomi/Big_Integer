#include "QInt.h"
#include"DocGhiFile.h"
#include"QFLoat.h"
#include"DocGhiFileQFloat.h"



void main(int argc,char* argv[])
{
	if (argc == 4) {
		if (string(argv[3]) == "1") {
			vector< vector<string> > data = docFile(argv[1]);
			ghiFile(argv[2], data);
			cout << "Run Success!" << endl;
		}
		else if (string(argv[3]) == "2") {
			// đọc đối số từ dòng lệnh : argv[0] = tên file thực thi 
			vector< vector<string> > data = docFileQFloat(argv[1]);
			ghiFileQFloat(argv[2], data);
			cout << "Run Success!" << endl;
		}
		else {
			cout << "Lenh khong kha thi" << endl;
		}
	}
	else {
		int chon;
		do {
			cout << "Chon che do:\nNhap 1:QInt\nNhap 2:QFloat\nNhap 3:Thoat\n>> ";
			cin >> chon;
			getchar();
			if (chon == 1) {
				string line;
				vector<string> temp;

				// Đọc 1 dòng
				cout << "Nhap input theo mau: ";
				getline(cin, line);

				// Tách dòng thành các token lưu trong input

				stringstream ss(line);
				string token = "";

				while (ss >> token) {
					temp.push_back(token);
				}
				string p1 = temp[0]; //hệ cơ số của input
				string p2 = temp[1]; // hệ cơ số kết quả
				string in = temp[2]; //số đầu vào
									 // hàm chuyển đổi cơ số từ p1 sang p2
				string res;
				QInt tam;
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
				cout << "Ket Qua: ";
				cout << res << endl;
			}
			else if (chon == 2) {
				string line;
				vector<string> temp;

				// Đọc 1 dòng
				cout << "Nhap input theo mau: ";
				getline(cin, line);

				// Tách dòng thành các token lưu trong input

				stringstream ss(line);
				string token = "";

				while (ss >> token) {
					temp.push_back(token);
				}
				string p1 = temp[0]; //hệ cơ số của input
				string p2 = temp[1]; // hệ cơ số kết quả
				string in = temp[2]; //số đầu vào
									 // hàm chuyển đổi cơ số từ p1 sang p2
				QFLoat tam;
				string res;
				res = tam.chuyenDoiCoSo(p1, p2, in);
				cout << "Ket Qua: ";
				cout << res << endl;
			}
			else if (chon == 3) {
				cout << "Thoat!" << endl;
			}
			else {
				cout << "Lenh khong kha thi" << endl;
			}
		} while (chon != 3);

	}
	system("pause");
	return;
}
