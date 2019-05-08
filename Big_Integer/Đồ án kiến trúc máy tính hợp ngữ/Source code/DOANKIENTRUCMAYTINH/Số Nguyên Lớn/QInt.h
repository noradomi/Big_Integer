#pragma once
#include <iostream>
#include <string>
#include "HamBoTro.h"
#include<sstream>
#define N 4
#define N1 32

using namespace std;

class QInt
{
private:
	unsigned int BigInt[N]; // Mảng int 4 phần tử 16 bytes = 128 bits
public:

	QInt();
	~QInt();

	//Tra ve Bit vi tri k
	int operator[](int k);
	//Đọc Bit ở vịt trí k
	void DocBit(int k);
	//Bật Bit ở vị trí k
	void BatBit(int k);
	//Tắt Bit ở vị trí k
	void TatBit(int k);
	//Đảo Bit ở vị trí k
	void DaoBit(int k);

	//In ra dãy Bit
	void printBit();

	//Đọc chuỗi a là 1 số thập phân
	void ScanQInt(QInt &x, string a);

	// Hàm chia lấy phần nguyên QInt cho 2
	void div_string_by_2(string &data);

	// Hàm chuyển chuỗi string BigInt thập phân sang nhị phân
	// Hàm trả về 1 mảng 128 phần tử biểu diễn nhị phân cho chuỗi string BigInt
	void convert_to_bin(string a, char *&BigInt_bin);

	//int bat_bit(int vt, int n, int x);
	// Hàm int giá trị mảng int BigInt1 128 bits thể hiện cho chuỗi string BigInt
	void print();

	//Trả về giá trị thập phân
	string ToDecimal();
	//Viết dãy bit ra 1 mảng bool
	void ToBool(bool *&bit);
	void PrintQint(QInt);//Hàm in ra số thập phân QInt
	bool *DecToBin(QInt); //Hàm chuyển đổi số QInt thập phân sang nhị phân
	QInt BinToDec(bool *bit); // Hàm chuyển đổi số QInt nhị phân sang thập phân
	char *BinToHex(bool *bit); //Hàm chuyển đổi số QInt nhị phân sang thập lục phân
	char *DecToHex(QInt x); //Hàm chuyển đổi số QInt thập phân sang thập lục phân
	string dec_to_hex(QInt x); // Hàm chuyển đổi số QInt thập phân sang thập lục phân,trả về string
	void convert_to_binforHex(string a, char *& BigInt_bin, int j);
	//Hàm chuyển đổi số QInt hệ 16 sang dãy bit nhị phân
// Câu i: Các toán tử: AND “&”, OR “|”, XOR “^”, NOT “~”
	QInt operator~();
	QInt operator&(QInt b);
	QInt operator^(QInt b);
	QInt operator|(QInt b);

	// Câu h:Các toán tử so sánh và gán: “<”, “>”, “==”, “<=”, “>=”, “=”
	bool operator>(QInt b);
	bool operator>=(QInt b);
	bool operator!=(QInt b);
	bool operator==(QInt b);
	bool operator<(QInt b);
	bool operator<=(QInt b);
	QInt operator=(QInt b); // Toán tử gán bằng

	// Hàm hỗ trợ câu j
	string StringOfBit();//Hàm chuyển từ số QInt thập phân sang dãy bit nhị phân(kiểu string)
	void ReadStringOfBit(string bit);//Hàm chuyển dãy bit nhị phân sang QInt thập phân
	QInt ReadStringOfHex(string data);//Hàm chuyển từ số QInt hệ 16 sang số QInt hệ 10

	// Câu j: Các toán tử: dịch trái “<<”, dịch phải “>>”, xoay trái: “rol”, xoay phải: “ror”

	QInt operator<< (const int &shift);
	QInt  operator >> (const int &shift);
	QInt  RoL(const int &shift);
	QInt  RoR(const int &shift);

	// Câu g: Các operator toán tử : “+”, “-” , “*”, “/”
	QInt operator+(QInt b);
	QInt operator*(QInt b);
	QInt operator-(QInt b);
	QInt operator/(QInt b);

	//Trị tuyệt đối
	QInt Abs();

	// Chuyển đổi hệ cơ số
	string chuyenDoiCoSo(string p1, string p2, string input);

	string thucHienPhepToan(string p, string num1, string sign, string num2);//Thực hiện phép toán

	bool kiemTraTranSoNhapVao(string p, string num);
};
