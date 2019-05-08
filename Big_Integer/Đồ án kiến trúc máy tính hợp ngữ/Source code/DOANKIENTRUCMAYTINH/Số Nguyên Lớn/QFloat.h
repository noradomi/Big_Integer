#pragma once
#include <string>
#include <iostream>
#include <math.h>
#include "HamBoTroQFloat.h"
using namespace std;
#define BitExponent 15
#define BitFraction 112
#define N 4
#define N1 32
class QFLoat
{
	unsigned int Bit[4];
public:
	QFLoat();
	~QFLoat();

	int QFLoat::operator[](int k);
	int QFLoat::DocBit(int k);
	void QFLoat::BatBit(int k);
	void QFLoat::TatBit(int k);
	void QFLoat::DaoBit(int k);
	void QFLoat::printBit();
	// HÀM CHUẪN HÓA CHUỖI ĐỂ HỖ TRỢ PHÉP CỘNG CHUỖI 5+500 ----> 005+500
	void ChuanHoa(string &a, string &b);

	// CHUYỂN CHAR SANG SỐ
	int stringToNum(char c);

	// CHUYỂN SỐ SANG CHAR
	char numToString(int n);

	// HÀM CỘNG 2 CHUỖI SỐ DECIMAL
	string cong(string a, string b);

	// HÀM NHÂN 1 SỐ 0->9 VỚI MỘT CHUỖI SỐ DECIMAL 
	string nhanNho(char a, string b, int &nho);

	// HÀM CHUỖI SỐ DECIMAL CHIA 2 HỖ TRỢ CHUYỂN DECIMAL -> BINARY
	string ChuoiChiaHai(const string& str);

	// HÀM CHUYỂN DECIMAL -> BINARY
	string DectoBin(string str);

	// HÀM KIỂM TRA PHẦN THẬP PHÂN SAU KHI NHÂN 2 ĐÃ BẰNG 1 CHƯA
	bool kiemTraBang1(string str);


	string multiple_by_2(string a);

	// HÀM MŨ 2^n
	string two_power_n(int n);

	// HÀM THÊM 0 VÀO ĐUÔI ĐỂ ĐỦ SỐ BIT FRACTION
	string Fraction(string f, int bit);

	// HÀM CHUYỂN SỐ THỰC TỪ THẬP PHÂN -> BINARY
	string FloatDectoBin(string dec);

	// CHUẨN HÓA PHẦN THẬP PHÂN ĐỂ CỘNG VÍ DỤ: 0.5+0.555 ----> 0.500+0.555
	void chuanHoaPhanThapPhan(string &a, string &b);

	// HÀM CHIA 2 ĐỂ HỖ TRỢ CHO HÀM MŨ ÂM  , THAM SỐ TRUYỀN VÀO LÀ PHẦN THẬP PHÂN SAU DẤU CHẤM
	string divide_by_2_float(string a);

	// HÀM CHUYỂN BINARY -> DECIMAL
	string BintoDec(string binary);

	// HÀM CHUYỂN BINARY PHẦN THẬP PHÂN VỀ CHUỖI SỐ THẬP PHÂN
	string  ChuyenBinThapPhan_to_ThapPhan(string binary);

	// HÀM CHUYỂN BINARY -> SỐ THỰC DECIMAL
	string FloatBintoDec(string bit);

	void ReadStringOfBit(string bit);
	string StringOfBits();
	void ScanQFLoat(QFLoat &x, string DecFloat);
	void PrintQFLoat(QFLoat x, string p);
	QFLoat BinToDec(bool *bit);
	bool *DecToBin(QFLoat x);

	string chuyenDoiCoSo(string p1, string p2, string in);
};

