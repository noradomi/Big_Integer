#include "QInt.h"


QInt::QInt()
{
	for (int i = 0; i < N; i++) {
		BigInt[i] = 0;
	}
}//Constructor khởi tạo cho QInt
QInt::~QInt() {}
int QInt::operator[](int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;
	return (BigInt[i] >> (n - j - 1)) & 1;
}//operator lấy giá trị của bit ở vị trí k của QInt
void QInt::DocBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	BigInt[i] = (BigInt[i] >> (n - j - 1)) & 1;
}//Hàm Đọc bit ở vị trí k của QInt
void QInt::BatBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	BigInt[i] = BigInt[i] | (1 << (n - 1 - j));
}//Hàm Bật bit ở vị trí k của QInt
void QInt::TatBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	BigInt[i] = BigInt[i] & (~(1 << (n - 1 - j)));
}//Hàm Tắt bit ở vị trí k của QInt
void QInt::DaoBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	BigInt[i] = (1 << (n - j - 1)) ^ BigInt[i];
}//Hàm Đảo bit ở vị trí k của Qint
void QInt::printBit() {
	for (int i = 0; i < N * N1; i++) {
		cout << (*this)[i];//Ứng với mỗi vị trí từ 0->127 gọi toán operator[]  để lấy giá trị của bit tại vị trí đó
	}
	cout << endl;
}//Hàm in ra số QInt dạng dãy bit nhị phân
void QInt::ScanQInt(QInt & x, string a)
{


	// Xét trương hợp số input là âm: Hệ 10
	int flag = 0;
	if (a[0] == '-') {
		a = a.substr(1, a.size() - 1);
		flag = 1;
	}
	// Khởi tạo 1 mảng char 128 phần tử để lưu biễu diễn nhị phân cho chuỗi BigInt a
	char * input_bin = new char[128];
	convert_to_bin(a, input_bin);

	/*for (int i = 0; i < 128; i++)
	cout << input_bin[i];
	cout << endl;*/
	// Từ mảng input_bin thu được, chuyển sang lưu ở mảng int BigInt[4] với mỗi phần tử là giá trị thập phân
	// của 32 bits (32 phần tử) của input_bin từ trái sang phải.
	// Chuyển dãy bit sang QInt
	for (int i = 0; i < 128; i++) {
		if (input_bin[i] == '1') {

			// Tiến hành bật bit tại vị trí vt=i % 32 của phần tử int BigInt[i/32]
			//x.BigInt[i / 32] = bat_bit(i % 32, 32, x.BigInt[i / 32]); // Bật bit cho số BigInt[i/32] có 32 bits tại bit thứ i % 32
			x.BatBit(i);
		}
	}

	if (flag == 1) {
		QInt temp;
		ScanQInt(temp, "1");
		x = ~x + temp;
	}

	delete[] input_bin;
}//Hàm nhập vào số QInt hệ 10(chuyển từ số nguyên lớn ở dạng chuỗi sang kiểu QInt định nghĩa)
void QInt::div_string_by_2(string &data)
{
	int next_add = 0, add = 0;
	for (int i = 0; i < data.size(); i++)
	{
		add = next_add;
		if ((data[i] - '0') % 2 != 0) {
			//nếu phần tử thứ i của số tính từ trái sang không chia hết cho 2 thì gán next_add=5,tức là ta sẽ tăng lên 10 đơn vị,10/2=5 và ta sẽ
			//lấy phần dư của số i+1 cộng với 5( VD:13/2=(10+3)/2=5+3/2=6)
			next_add = 5;
		}
		else next_add = 0;
		data[i] = (data[i] - '0') / 2 + add + '0';
	}
}//Hàm chia nguyên số nguyên lớn hệ 10 cho 2,để dụng cho quá trình xác định dạng nhị phân của 1 số
void QInt::convert_to_bin(string a, char *& BigInt_bin)
{
	for (int i = 127; i >= 0; i--) {
		if ((a[a.size() - 1] - '0') % 2 != 0) // chữ sô cuối của chuỗi BigInt là số lẻ
			BigInt_bin[i] = '1';
		else
			BigInt_bin[i] = '0';

		// Thực hiện chia lấy phần nguyên chuỗi BigInt cho 2
		div_string_by_2(a);
	}
}//Hàm chuyển đổi từ số nguyên lớn(string) hệ 10 sang dãy bit nhị phân
void QInt::print()
{
	for (int i = 0; i < 4; i++) {
		cout << "BigInt[" << i << "] = " << BigInt[i];
		cout << endl;
	}
}//Hàm in ra từng giá trị trong mảng unsigned int BigInt[4] (128 bit) đã khai báo để định nghĩa cho QInt
string QInt::ToDecimal() {
	QInt TriTuyetDoi = (*this).Abs();
	string res = "0";
	string mul_2 = "1";
	for (int i = 127; i >= 0; i--) {
		if (TriTuyetDoi[i] == 1) {
			res = find_sum(res, mul_2);  //Nếu bit ở vị trí thứ i là 1 thì thực hiện phép cộng vào kết quả trả về
		}
		mul_2 = multiple_by_2(mul_2);
		//Cứ mỗi vòng lặp thì cứ nhân 2 dần lên,để khi có bit bằng 1 thì cộng vào kết quả, còn là 0 thì không cần cộng vào
	}
	if (TriTuyetDoi != (*this)) {
		return "-" + res;
	}
	return res;
}//Hàm chuyển từ số QInt đã định nghĩa sang số nguyên hệ 10 dạng string 
void QInt::ToBool(bool *&bit) {
	for (int i = 0; i < N1 * N; i++) {
		bit[i] = (*this)[i];//Gán giá trị bit[i] bằng giá trị của bit trong QInt ở vị trí i
	}
}//Hàm chuyển từ số QInt sang dãy bit nhị phân kiểu bool
void QInt::PrintQint(QInt x)
{
	cout << ToDecimal();
}//Hàm in ra số QInt hệ 10
bool* QInt::DecToBin(QInt x)
{
	/*string a = ToDecimal();
	char *temp = new char[128];
	convert_to_bin(a, temp);
	bool*temp2 = new bool[128];
	for (int i = 0; i < 128; i++)
	{
	if (temp[i] == '0')
	temp2[i] = 0;
	else
	temp2[i] = 1;
	}
	return temp2;*/
	bool*temp2 = new bool[128];
	ToBool(temp2);//Chuyển số QInt sang dãy bit nhị phân kiểu bool
	return temp2;
}//Hàm chuyển từ số QInt hệ 10 sang dãy bit nhị phân kiểu bool, trả về QInt
QInt  QInt::BinToDec(bool *bit)
{
	QInt temp;
	for (int i = 0; i < 128; i++) {
		if (bit[i] == 1) {


			temp.BatBit(i);
			//Nếu bit tại vị trí i trong mảng bit gồm 128 phần tử là 1 thì tiến hành gọi hàm bật bit tại vị trí i để lưu trữ vào QInt
		}
	}
	return temp;
}//Hàm chuyển từ dãy bit nhị phân kiểu bool sang số QInt hệ 10
char* QInt::BinToHex(bool *bit)
{
	char* result = new char[32];
	//Con trỏ result là kết quả trả về của số QInt hệ 16
	int dem = 0;
	int i = 0;
	while (i < 128)
	{
		int mu = 3;
		int sum = 0;
		for (int j = i; j < i + 4; j++)
		{
			if (bit[j] == 1)
			{
				sum += pow(2, mu);//Gom nhóm 4 bit liên tiếp vào tính giá trị của 4 bit này

			}
			mu--;

		}
		if (sum < 10)
		{
			result[dem] = sum + '0';//Nếu giá trị 4 bit nhỏ hơn 10 thì giữ nguyên giá trị của nó cho số QInt hệ 16
		}
		else//nếu giá trị của 4 bit từ 10 đến 15 thì lần lượt gán nó cho A,B,C,D,E,F
		{
			if (sum == 10)
				result[dem] = 'A';
			if (sum == 11)
				result[dem] = 'B';
			if (sum == 12)
				result[dem] = 'C';
			if (sum == 13)
				result[dem] = 'D';
			if (sum == 14)
				result[dem] = 'E';
			if (sum == 15)
				result[dem] = 'F';
		}
		dem++;
		i += 4;//Sau mỗi vòng lặp tăng vị trí t lên 4 để đến vị trí đầu của bộ 4 bit tiếp theo
	}

	return result;
}//Hàm chuyển từ dãy bit nhị phân(bool) sang số QInt hệ 16
char* QInt::DecToHex(QInt x)
{
	bool * temp = new bool[128];
	x.ToBool(temp);//Chuyển số QInt hệ 10 sang hệ 2
	char *temp2 = new char[32];
	temp2 = BinToHex(temp);//Chuyển số QInt hệ 2 sang hệ 16
	return temp2;
}//Hàm chuyển từ số QInt hệ 10 sang QInt hệ 16
QInt QInt::operator~() {
	QInt res;
	for (int i = 0; i < N; i++) {
		res.BigInt[i] = ~BigInt[i];//Đảo bit ở vị trí i
	}
	return res;
}//Toán tử đảo bit của QInt,trả về giá trị QInt sau khi đảo bit(NOT)
QInt QInt::operator&(QInt b) {
	QInt res;
	for (int i = 0; i < N; i++) {
		res.BigInt[i] = BigInt[i] & b.BigInt[i];//& giữa 2 bit của 2 số ở vị trí i
	}
	return res;
}//Toán tử 2 ngôi,trả về kết quả &(AND) giữa các bit 2 số QInt
QInt QInt::operator^(QInt b) {
	QInt res;
	for (int i = 0; i < N; i++) {
		res.BigInt[i] = BigInt[i] ^ b.BigInt[i];//XOR giữa 2 bit của 2 số QInt
	}
	return res;
}//Toán tử 2 ngôi,trả về kết quả ^(XOR) giữa các bit của 2 số QInt
QInt QInt::operator|(QInt b) {
	QInt res;
	for (int i = 0; i < N; i++) {
		res.BigInt[i] = BigInt[i] | b.BigInt[i];//OR giữa 2 bit của 2 số QInt
	}
	return res;
}//Toán tử 2 ngôi,trả về kết quả |(OR) giữa các bit của 2 số QInt
bool QInt::operator>(QInt b) {
	if ((*this)[0] != b[0]) {
		if ((*this)[0] == 1)
			return false;
		else return true;
	}
	else
		if ((*this)[0] != 0) {
			(*this) = (*this).Abs();
			b = b.Abs();
			for (int i = 0; i < N * N1; i++) {
				if ((*this)[i] != b[i]) {
					return (*this)[i] < b[i];
				}
			}
		}
		else {
			for (int i = 0; i < N * N1; i++) {
				if ((*this)[i] != b[i]) {
					return (*this)[i] > b[i];
				}
			}
		}
		return false;
}//Hàm so sánh số lớn hơn giữa 2 số QInt
bool QInt::operator>=(QInt b) {
	return (*this) == b || (*this) > b;
	//Trả về kết quả là 1 nếu số thứ nhất lớn hơn hoặc bằng(gọi 2 toán tử == và > đã cái đặt)
}//Hàm so sánh lớn hơn hoặc bằng giữa 2 số QInt
bool QInt::operator!=(QInt b) {
	return !(*this == b);
}//Hàm so sánh xem 2 số QInt có khác nhau hay không
bool QInt::operator==(QInt b) {
	for (int i = 0; i < N * N1; i++) {
		if ((*this)[i] != b[i]) {
			//Nếu có 1 bit ở vị trí i khác nhau thì trả về 0
			return 0;
		}
	}
	return 1;
}//Hàm so sánh xem 2 số QInt có bằng nhau hay không
bool QInt::operator<(QInt b) {
	return ((*this) > b) ? false : true;//Dùng hàm so sánh >
}//Hàm so sánh số nhỏ hơn trong 2 số QInt
bool QInt::operator<=(QInt b) {
	return (*this) == b || (*this) < b;//Dùng 2 toán tử so sánh là == và <đã cái đặt
}//Hàm so sánh số nhỏ hơn hoặc bằng giữa 2 số QInt
QInt QInt::operator=(QInt result)
{
	for (int i = 0; i < 4; i++)
	{
		BigInt[i] = result.BigInt[i];
	}
	return *this;
}//Operator gán bằng
string QInt::StringOfBit() {
	string res = "";
	for (int i = 0; i < N * N1; i++) {
		if ((*this)[i] == 1) {
			res = res + "1";
		}
		else {
			res = res + "0";
		}
	}
	return res;
}//Lấy giá trị dãy bit nhị phân(kiểu string) từ số QInt
void QInt::ReadStringOfBit(string bit) {
	reverse(bit.begin(), bit.end());
	for (int i = 0; i < N * N1; i++) {
		TatBit(i);
	}

	for (int i = bit.size() - 1; i >= 0; i--) {
		if (bit[i] == '1') {
			BatBit(127 - i);
		}
		else {
			TatBit(127 - i);
		}
	}
}//Từ dãy bit nhị phân(kiểu string) chuyển sang số QInt
QInt QInt::operator<< (const int &shift) {
	string Bit;
	Bit = StringOfBit();//Chuyển số QInt sang dãy bit nhị phân 
	ShiftTrai(Bit, shift);//Đẩy trái dãy bit nhị phân shift lần 

	QInt res;
	res.ReadStringOfBit(Bit);//Chuyển dãy bit nhị phân sau khi đã đẩy trái về Qint

	return res;
}//Operator đẩy trái số QInt với shift là số lần đẩy trái
QInt QInt::operator >> (const int &shift) {
	string Bit;
	Bit = StringOfBit();//Chuyển số QInt sang dãy bit nhị phân
	ShiftPhai(Bit, shift);//Đẩy phải dãy bit nhị phân shift lần 

	QInt res;
	res.ReadStringOfBit(Bit);//Chuyển dãy bit nhị phân sau khi đã đẩy phải về Qint

	return res;
}//Operator đẩy phải số QInt shift lần
QInt QInt::RoL(const int &shift) {
	string Bit;
	Bit = StringOfBit();//Chuyển số QInt sang dãy bit nhị phân
	XoayTrai(Bit, shift);//Xoay trái dãy bit nhị phân shift lần 
	QInt res;
	res.ReadStringOfBit(Bit);//Chuyển dãy bit nhị phân sau khi đã xoay trái về Qint
	return res;
}//Xoay trái số QInt shift lần 
QInt QInt::RoR(const int &shift) {
	string Bit;
	Bit = StringOfBit();//Chuyển số QInt sang dãy bit nhị phân
	XoayPhai(Bit, shift);//Xoay phải dãy bit nhị phân shift lần 

	QInt res;
	res.ReadStringOfBit(Bit);//Chuyển dãy bit nhị phân sau khi đã xoay phải về Qint

	return res;
}//Xoay phải số QInt shift lần 
QInt QInt::operator+(QInt b)
{
	QInt res;
	bool *temp = new bool[128];
	bool *temp2 = new bool[128];
	(*this).ToBool(temp);//Chuyển số QInt đầu sang dãy bit nhị phân(kiểu bool)
	b.ToBool(temp2);//Chuyển số QInt thứ hai sang dãy bit nhị phân(kiểu bool)
	char *s11 = new char[128];
	char *s22 = new char[128];
	string s1, s2, result1;
	for (int i = 0; i < 128; i++)
	{
		s11[i] = temp[i] + '0';
		s22[i] = temp2[i] + '0';
	}//Chuyển dãy bit nhị phân kiểu bool sang char
	for (int i = 0; i < 128; i++)
	{
		s1.push_back(s11[i]);
		s2.push_back(s22[i]);
	}//Chuyển dãy bit nhị phân kiểu char sang string

	 /*cout << "\nXUat chuoi 1 ::"<<s1;
	 cout << "\nXUat chuoi 2 ::" << s2;
	 cout << "\n";*/

	delete s11;
	delete s22;
	delete temp;
	delete temp2;
	result1 = addBinary(s1, s2); // cong chuoi s1,s2 luu vao result 
								 //cout << result1;
	bool *tam = new bool[128];
	for (int i = 0; i < 128; i++)
	{
		if (result1[i] == '0')
		{
			tam[i] = 0;
		}
		else
		{
			tam[i] = 1;
		}
		//cout << tam[i];
	}
	// chuyen sang todecimal, lay dang chuoi luu vao res1 de dua gia tri res1 vao QInt res.
	string res1 = "0";
	string mul_2 = "1";
	for (int i = 127; i >= 0; i--) {
		if (tam[i] == 1) {
			res1 = find_sum(res1, mul_2);
		}
		mul_2 = multiple_by_2(mul_2);
	}
	QInt::ScanQInt(res, res1);//Chuyển từ kết quả sau khi cộng(kiểu string) sang Qint
	return res;

}//Cộng 2 số QInt với nhau
QInt QInt::operator*(QInt b)
{

	//QInt mul;
	///*bool *temp = new bool[128];
	//bool *temp2 = new bool[128];
	//(*this).ToBool(temp);
	//b.ToBool(temp2);*/
	///*(*this) = (*this) << 7;
	//(*this).printBit();*/
	//for (int i = 127; i >= 0; i--)
	//{
	//	
	//	QInt tam;
	//	tam = b << (127 - i);
	//	if ((*this)[i] == 1)
	//	{
	//		mul = mul + tam;
	//	}
	//}
	///*delete []temp;
	//delete []temp2;*/
	//return mul;

	/*
	Thuật toán nhân có dấu, kết quả lưu vào biến Q.
	*/
	QInt A;
	QInt Q = (*this); //Copy giá trị của this
	int k = 128; //Khởi tạo k cho vòng lặp

				 //Chuẩn bị chuỗi bit A, Q, Q-1
	string A_str = A.StringOfBit();
	string Q_str = Q.StringOfBit();
	string Q1 = "0";

	// Ghép bit [A, Q, Q1]
	string AQQ1 = A_str + Q_str + Q1;
	// Xét 2 bit cuối chuỗi [A, Q, Q1] 
	string QQ1 = Q_str.substr(127, 1) + Q1;

	while (k > 0) {
		if (QQ1 == "10") {
			A = A - b;
			A_str = A.StringOfBit(); //Cập nhật chuỗi bit của A (nết có thay đổi)
		}
		if (QQ1 == "01") {
			A = A + b;
			A_str = A.StringOfBit();//Cập nhật chuỗi bit của A (nết có thay đổi)
		}

		AQQ1 = A_str + Q_str + Q1; //Cập nhật chuỗi bit của AQQ-1
		ShiftPhai(AQQ1, 1); //Shift phải chuỗi

		A_str = AQQ1.substr(0, 128); //Cập nhật chuỗi Bit A
		Q_str = AQQ1.substr(128, 128);//Cập nhật chuỗi Bit Q
		Q1 = AQQ1.substr(256, 1);//Cập nhật Q1

		A.ReadStringOfBit(A_str);//Cập nhật A
		Q.ReadStringOfBit(Q_str);// Cập nhật Q
		QQ1 = Q_str.substr(127, 1) + Q1; //Cập nhật đuôi QQ-1

		k--;
	}
	return Q;
}//Opeaton nhân 2 số QInt
QInt QInt::operator-(QInt b)
{
	QInt temp;
	temp.ScanQInt(temp, "1");//Chuyển số 1 sang Qint đề dùng operator +

	QInt bu1 = (~b); // Cộng 1 vào bit của bù 1 của B (~b).  => res: bù 2 của B

	QInt bu2 = temp + bu1;//Dùng opeator + đã cái đặt
	QInt res = bu2 + (*this);//Cộng số bù 2 của b với (*this)
	return  res;

}//Opearor trừ 2 số QInt(cộng với bù 2 của b)
QInt QInt::operator/(QInt b)
{

	QInt res;
	if ((*this).Abs()[0] == 1)
		res = ~res; // Tạo res n bit 1.
	int k = 128;
	string temp = res.StringOfBit() + (*this).Abs().StringOfBit();
	QInt Qtemp;
	QInt Atemp;
	while (k > 0)
	{
		ShiftTrai(temp, 1);
		string A = temp.substr(0, 128);
		string Q = temp.substr(128, 128);

		Atemp.ReadStringOfBit(A);// doc chuoi String cua bit thanh QInt

		Qtemp.ReadStringOfBit(Q);
		Atemp = Atemp - b;
		if (Atemp[0] == 1) {
			Qtemp.TatBit(127); // set Qo = 0;
			Atemp = Atemp + b;
		}
		else
			Qtemp.BatBit(127); // set Qo =1;
		k = k - 1;
		temp = Atemp.StringOfBit() + Qtemp.StringOfBit(); // Cập nhật chuỗi [A;Q]
	}
	if ((*this)[0] != b[0]) // Số âm
	{
		QInt temp;
		ScanQInt(temp, "1");
		Qtemp = (~Qtemp) + temp;// bù 2 của QTemp
	}
	return Qtemp;
}//Opertor chia 
string QInt::chuyenDoiCoSo(string p1, string p2, string input) {
	QInt temp;
	if (p1 == "10") {
		temp.ScanQInt(temp, input); // đọc string sang QInt hệ 10
		if (p2 == "~")

			return (~temp).ToDecimal();
	}
	if (p1 == "2") {
		temp.ReadStringOfBit(input); // đọc string sang QInt hệ 2
		if (p2 == "~")
			return (~temp).StringOfBit();
	}
	if (p1 == "16") {
		temp = temp.ReadStringOfHex(input);//đọc string sang QInt hệ 16
		if (p2 == "~")
			return (~temp).dec_to_hex(temp);
	}
	// Bắt đầu chuyển đổi

	if (p2 == "10") {
		return temp.ToDecimal();//Trả về QInt hệ 10
	}
	if (p2 == "2") {
		return temp.StringOfBit();//Trả về QInt hệ 2
	}
	if (p2 == "16") {
		return temp.dec_to_hex(temp);//Trả về QInt hệ 16
	}
}//Hàm chuyển đổi cơ số của số QInt hoặc Toán tử 1 ngôi,trả về kết quả kiểu string
string QInt::thucHienPhepToan(string p, string num1, string sign, string num2) {
	QInt temp1, temp2;
	if (p == "10") {
		temp1.ScanQInt(temp1, num1); // đọc string sang QInt hệ 10
		temp2.ScanQInt(temp2, num2);
	}
	if (p == "2") {
		temp1.ReadStringOfBit(num1); // đọc string sang QInt hệ 10
		temp2.ReadStringOfBit(num2); // đọc string sang QInt hệ 2
	}
	if (p == "16") {
		temp1 = temp1.ReadStringOfHex(num1);
		temp2 = temp2.ReadStringOfHex(num2);
	}
	// Xét dấu
	QInt res; // lưu kết quả
			  // +, - , * , /
	if (sign == "+") {
		res = temp1 + temp2;
		if ((temp1[0] == 1 && temp2[0] == 1 && res[0] != 1) || (temp1[0] != 1 && temp2[0] != 1 && res[0] == 1)) // tràn số
			return "Warning: Overflow!!!";
	}
	if (sign == "-") {
		if ((temp1[0] == 1 && temp2[0] == 0) || (temp1[0] == 0 && temp2[0] == 1)) {
			QInt res1;
			res1 = temp1.Abs() + temp2.Abs();
			if (res1[0] == 1) // tràn số
				return "Warning: Overflow!!!";
		}
		res = temp1 - temp2;
	}
	if (sign == "*") {
		QInt ze_ro;
		if (temp1 == ze_ro || temp2 == ze_ro)
			return "0";
		res = temp1 * temp2;
		if (temp1[0] == temp2[0]) {
			if (res[0] == 1)
				return "Warning: Overflow!!!";

		}
		else
			if (res[0] == 0)
				return "Warning: Overflow!!!";

	}
	if (sign == "/") {
		res = temp1 / temp2;
	}


	// >> , <<
	if (sign == "<<") {
		string sobitdich = temp2.ToDecimal();
		res = temp1 << atoi(sobitdich.c_str());
	}
	if (sign == ">>") {
		string sobitdich = temp2.ToDecimal();
		res = temp1 >> atoi(sobitdich.c_str());
	}

	// ROL, ROR
	if (sign == "rol") {
		res = temp1.RoL(atoi(num2.c_str()));
	}
	if (sign == "ror") {
		res = temp1.RoR(atoi(num2.c_str()));
	}

	// So sánh : >,<,==,>=,<=,!=
	if (sign == ">") {
		bool p = temp1 > temp2;
		return (p == 1) ? ("True") : ("False");
	}
	if (sign == "<") {
		bool p = temp1 < temp2;
		return (p == 1) ? ("True") : ("False");
	}
	if (sign == ">=") {
		bool p = temp1 >= temp2;
		return (p == 1) ? ("True") : ("False");

	}
	if (sign == "<=") {
		bool p = temp1 <= temp2;
		return (p == 1) ? ("True") : ("False");
	}
	if (sign == "==") {
		bool p = temp1 == temp2;
		return (p == 1) ? ("True") : ("False");

	}
	if (sign == "!=") {
		bool p = temp1 != temp2;
		return (p == 1) ? ("True") : ("False");
	}

	// &, ^, |
	if (sign == "&") {
		res = temp1 & temp2;
	}

	if (sign == "^") {
		res = temp1 ^ temp2;
	}
	if (sign == "|") {
		res = temp1 | temp2;
	}

	// Trả kết quả cho các phép toán không là so sánh
	if (p == "2") {
		return res.StringOfBit();
	}
	if (p == "10")
		return res.ToDecimal();
	if (p == "16") {
		return res.dec_to_hex(res);
	}

}//Hàm Thực hiện toán tử  2 ngôi,trả về kết quả sau khi đã thực hiện toàn tử(kiểu string)
QInt QInt::Abs() {
	QInt One;
	One.ReadStringOfBit("1");//Chuyển số 1 sang QInt

	if ((*this)[0] == 1) {
		return ~(*this) + One;//Nếu QInt là số âm thì chuyển sang dạng bù 2
	}
	else
		return (*this);
}//Hàm trả về kết quả sau khi lấy trị tuyệt đối của 1 số QInt
string QInt::dec_to_hex(QInt x)
{
	bool*temp = x.DecToBin(x);

	//if (temp[0] == 1)
	//{
	//	QInt t;
	//	t.ScanQInt(t, "1");
	//	QInt bu1 = (~x); // Cộng 1 vào bit của bù 1 của B (~b).  => res: bù 2 của B
	//	QInt bu2 = bu1 + t;
	//	bool *temp2 = bu2.DecToBin(x);
	//	char *temp3 = (*this).BinToHex(temp2);
	//	temp3[32] = '\0';
	//	string res(temp3);
	//	return "-" + res;
	//}

	char *temp4 = (*this).BinToHex(temp);
	temp4[32] = '\0';
	string res(temp4);
	return res;

}//Hàm chuyển từ số QInt hệ 10 sang hệ 16(kiểu string)
QInt QInt::ReadStringOfHex(string data)
{
	QInt res;
	char* temp = new char[128];
	for (int i = 0; i < 128; i++)
	{
		temp[i] = 0;
	}
	int vt = 127;
	for (int i = data.size() - 1; i >= 0; i--)
	{

		if (data[i] - '0' <= 9)
		{
			string result;
			ostringstream convert;
			convert << data[i] - '0';
			result = convert.str();
			res.convert_to_binforHex(result, temp, vt);
			result.clear();
		}
		if (data[i] == 'A')
		{
			res.convert_to_binforHex("10", temp, vt);

		}
		else if (data[i] == 'B')
		{
			res.convert_to_binforHex("11", temp, vt);

		}
		else if (data[i] == 'C')
		{
			res.convert_to_binforHex("12", temp, vt);

		}
		else if (data[i] == 'D')
		{
			res.convert_to_binforHex("13", temp, vt);

		}
		else if (data[i] == 'E')
		{
			res.convert_to_binforHex("14", temp, vt);

		}
		else if (data[i] == 'F')
		{
			res.convert_to_binforHex("15", temp, vt);

		}

		vt -= 4;
	}
	for (int i = 0; i < 128; i++)
	{
		if (temp[i] == '1')
		{
			res.BatBit(i);
		}
	}
	return res;

}//Hàm chuyển từ số QInt hệ 16 sang số QInt hệ 10
void QInt::convert_to_binforHex(string a, char *& BigInt_bin, int j)
{
	for (int i = j; i >= j - 3; i--) {
		if ((a[a.size() - 1] - '0') % 2 != 0) // chữ sô cuối của chuỗi BigInt là số lẻ
			BigInt_bin[i] = '1';
		else
			BigInt_bin[i] = '0';

		// Thực hiện chia lấy phần nguyên chuỗi BigInt cho 2
		div_string_by_2(a);
	}
}//Hàm chuyển từ số QInt hệ 16 sang hệ 2
bool QInt::kiemTraTranSoNhapVao(string p, string num) {
	if (p == "10") {
		string tam = num;
		int dem = 0;
		while (dem < 128) {
			div_string_by_2(tam);
			dem++;
		}
		if (tam != "0")
			return true; // Số nhập vào bị tràn
		return false;
	}
	if (p == "2") {
		if (num.size() > 128)
			return true;
		return false;
	}
	if (p == "16") {
		if (num.size() > 32)
			return true;
		else
			false;
	}
}//Kiểm tra số nhập vào 