#include "QFLoat.h"



QFLoat::QFLoat()
{
	Bit[0] = 0;
	Bit[1] = 0;
	Bit[2] = 0;
	Bit[3] = 0;
}


QFLoat::~QFLoat()
{
}

//Đọc bit thứ k
int QFLoat::operator[](int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	return (Bit[i] >> (n - j - 1)) & 1;
}
//Đọc bit thứ k
int QFLoat::DocBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	return (Bit[i] >> (n - j - 1)) & 1;
}
//Bật bit thứ k
void QFLoat::BatBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	Bit[i] = Bit[i] | (1 << (n - 1 - j));
}
//Tắt bit thứ k
void QFLoat::TatBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	Bit[i] = Bit[i] & (~(1 << (n - 1 - j)));
}
//Đảo bit thứ k
void QFLoat::DaoBit(int k) {
	int i = k / N1;
	int j = k % N1;
	int n = N * N1;

	Bit[i] = (1 << (n - j - 1)) ^ Bit[i];
}
void QFLoat::printBit() {
	for (int i = 0; i < N * N1; i++) {
		cout << (*this)[i];
	}
	cout << endl;
}

void QFLoat::ChuanHoa(string & a, string & b)
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		b.insert(0, l1 - l2, '0');
	}
	else
	{
		a.insert(0, l2 - l1, '0');
	}
}

int QFLoat::stringToNum(char c) {
	return c - '0';
}

char QFLoat::numToString(int n)
{
	return (char)(n + 48);
}

string QFLoat::cong(string a, string b)
{
	string s = "";
	ChuanHoa(a, b);
	int l = a.length();

	int temp = 0;
	int tempA, tempB;
	char tempC;
	for (int i = l - 1; i >= 0; i--)   // duyet va cong
	{
		tempA = a[i] - '0';
		tempB = b[i] - '0';
		temp = tempA + tempB + temp;
		tempC = (char)((temp % 10) + 48);
		s.insert(0, 1, tempC);         // gan phan don vi vao
		temp = temp / 10;     // lấy số nhớ 
	}
	if (temp > 0)  // neu hang chuc > 0 thi them vao KQ
	{
		tempC = (char)(temp + 48);
		s.insert(0, 1, tempC);
	}
	return s;
}

string QFLoat::nhanNho(char a, string b, int & nho)
{
	string s = "";
	int temp = 0;
	int tempA, tempB;
	char tempC;
	for (int i = b.length() - 1; i >= 0; i--)
	{
		tempA = a - '0'; // đưa về số nguyên
		tempB = b[i] - '0';// đưa về số nguyên
		temp = tempA * tempB + temp;
		tempC = (char)((temp % 10) + 48);
		s.insert(0, 1, tempC);
		temp = temp / 10;
		nho = temp;
	}

	/*if (temp>0)
	{
	s.insert(0, 1, numToString(temp));
	}*/
	return s;
}

string QFLoat::ChuoiChiaHai(const string & str)
{
	string kq;
	int temp = 0;

	for (int i = 0; i < str.size(); i++)
	{
		temp = temp * 10 + (str[i] - '0');

		if (i > 0 || (i == 0 && temp >= 2))
		{
			kq.push_back((temp / 2) + '0');
		}

		temp = temp % 2;
	}

	return kq;
}

string QFLoat::DectoBin(string str)
{
	string kq;
	int temp1;
	char temp2;
	while (str != "") {
		temp2 = (str[str.size() - 1] - '0') % 2 + '0';
		kq.push_back(temp2);
		str = ChuoiChiaHai(str);
	}

	if (kq.size() < BitExponent) {
		for (int i = kq.size(); i < BitExponent; i++) {
			kq.push_back('0');
		}

	}
	reverse(kq.begin(), kq.end());


	return kq;
}

bool QFLoat::kiemTraBang1(string str)
{
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '0') {
			return false;
		}
	}
	return true;
}

string QFLoat::multiple_by_2(string a)
{
	char *b = new char[50];

	int c = 0;
	int d;

	for (int i = a.size() - 1; i >= 0; i--) {
		c = c + 2 * (int)(a[i] - '0');
		d = c % 10;
		c = c / 10;
		b[i] = (char)(d + '0');
	}
	b[a.size()] = '\0';

	if (c != 0) {
		return "1" + string(b);
	}

	return string(b);
}

string QFLoat::two_power_n(int n)
{
	string a("1");
	for (int i = 1; i <= n; i++) {
		a = multiple_by_2(a);
	}
	return a;
}

string QFLoat::Fraction(string f, int bit)
{
	// trả về chuỗi phần định trị
	string res = f;
	int dem = 0;// đếm số 0 cần thêm vào phần định trị
	for (int i = f.size(); i < bit; i++) {
		res.push_back('0');
		dem++;
	}

	return res;
}

string QFLoat::FloatDectoBin(string dec)
{
	string res;
	string sign;
	string exponent;
	string F;
	string DecPhanNguyen;
	string BinPhanNguyen;
	string temp3;
	string temp4; // lưu bit phần thập phân
	int demF = 0;
	int nho;
	if (dec[0] == '-') {
		sign = "1";
		DecPhanNguyen = dec.substr(1, dec.find('.') - 1);// lấy phần nguyên trước dấu phẩy 
		if (DecPhanNguyen != "0") { // TRƯỜNG HỢP NHẬP VÀO LÀ KHÁC SỐ 0.00........
			BinPhanNguyen = DectoBin(DecPhanNguyen);// chuyển phần trc dấu phẩy về nhị phân
			temp3 = dec.substr(dec.find('.') + 1, dec.size() - dec.find('.'));// lấy chuỗi số phần thập phân 
			res = temp3;
			//Lặp để lấy các bit phần thập phân

			int MAX_BIN_THAP_PHAN = BitFraction;// CHUYỂN 23BIT SANG 112BIT THEO YÊU CẦU ĐỀ BÀI
			while (kiemTraBang1(temp3) == false & demF <= MAX_BIN_THAP_PHAN) { // kiểm tra phần thập phân demo 23 bit, CÓ THỂ ĐỔI demFraction = 112bit THEO YÊU CẦU ĐỀ BÀI
				temp3 = nhanNho('2', temp3, nho);
				if (nho > 0) {
					temp4.push_back('1');
					demF++;
				}
				else {
					temp4.push_back('0');
					demF++;
				}
			}
			res = BinPhanNguyen + "," + temp4;

			// Đưa về dạng +-1.F*2^E

			F = BinPhanNguyen.substr(BinPhanNguyen.find('1') + 1, BinPhanNguyen.size() - 1) + temp4;
			int e = BinPhanNguyen.size() - BinPhanNguyen.find('1') - 1;
			//string temp6; // lưu số mũ E dưới dạng chuỗi
			//temp6 = to_string(e - 1);
			//exponent = DectoBin(cong(temp6, two_power_n(8 - 1))); //Exponent= (E-1) + 2^(8-1) = temp6 + 2^7 , exponent demo 8bit, CÓ THỂ ĐỔI SANG 15BIT THEO ĐỀ BÀI
			int k = e - 1 + pow(2, BitExponent - 1);
			string t = to_string(k);
			exponent = DectoBin(t);
			res = sign + exponent + Fraction(F, BitFraction); // fraction demo 23bit, CÓ THỂ ĐỔI SANG 112BIT THEO ĐỀ BÀI 
		}
		else {  // TRƯỜNG HỢP NHẬP VÀO LÀ SỐ 0.00........
			temp3 = dec.substr(dec.find('.') + 1, dec.size() - dec.find('.'));// lấy chuỗi số phần thập phân 
			res = temp3;
			//Lặp để lấy các bit phần thập phân
			int MAX_BIN_THAP_PHAN = 0;
			string temp = temp3;
			while (kiemTraBang1(temp) == false) {
				temp = nhanNho('2', temp, nho);
				if (nho > 0) {
					MAX_BIN_THAP_PHAN++;
					break;
				}
				else {
					MAX_BIN_THAP_PHAN++;
				}
			}
			MAX_BIN_THAP_PHAN += BitFraction;// CHUYỂN 23BIT SANG 112BIT THEO YÊU CẦU ĐỀ BÀI
			while (kiemTraBang1(temp3) == false & demF <= MAX_BIN_THAP_PHAN) { // kiểm tra phần thập phân demo 23 bit, CÓ THỂ ĐỔI demFraction = 112bit THEO YÊU CẦU ĐỀ BÀI
				temp3 = nhanNho('2', temp3, nho);
				if (nho > 0) {
					temp4.push_back('1');
					demF++;
				}
				else {
					temp4.push_back('0');
					demF++;
				}
			}
			// Đưa về dạng +-1.F*2^E
			int e = -1 * (temp4.find('1') + 1);
			//string temp6; // lưu số mũ E dưới dạng chuỗi
			//temp6 = to_string(e - 1);
			//exponent = DectoBin(cong(temp6, two_power_n(8 - 1))); // Exponent= (E-1) + 2^(8-1) = temp6 + 2^7  
			int t = e - 1 + pow(2, BitExponent - 1);
			string k = to_string(t);
			exponent = DectoBin(k);
			F = temp4.substr(temp4.find('1') + 1, temp4.size() - temp4.find('1'));
			res = sign + exponent + Fraction(F, BitFraction);

		}
	}


	else {
		sign = "0";
		DecPhanNguyen = dec.substr(0, dec.find('.'));// lấy phần nguyên trước dấu phẩy 
		if (DecPhanNguyen != "0") { // TRƯỜNG HỢP NHẬP VÀO LÀ KHÁC SỐ 0.00........
			BinPhanNguyen = DectoBin(DecPhanNguyen);// chuyển phần trc dấu phẩy về nhị phân
			temp3 = dec.substr(dec.find('.') + 1, dec.size() - dec.find('.'));// lấy chuỗi số phần thập phân 
			res = temp3;
			//Lặp để lấy các bit phần thập phân

			int MAX_BIN_THAP_PHAN = BitFraction;// CHUYỂN 23BIT SANG 112BIT THEO YÊU CẦU ĐỀ BÀI
			while (kiemTraBang1(temp3) == false & demF <= MAX_BIN_THAP_PHAN) {
				temp3 = nhanNho('2', temp3, nho);
				if (nho > 0) {
					temp4.push_back('1');
					demF++;
				}
				else {
					temp4.push_back('0');
					demF++;
				}
			}
			res = BinPhanNguyen + "," + temp4;

			// Đưa về dạng +-1.F*2^E

			F = BinPhanNguyen.substr(BinPhanNguyen.find('1') + 1, BinPhanNguyen.size() - 1) + temp4;
			int e = BinPhanNguyen.size() - BinPhanNguyen.find('1') - 1;
			string temp6;
			temp6 = to_string(e - 1 + (int)pow(2, BitExponent - 1));
			//temp6.push_back(numToString(e));
			exponent = DectoBin(temp6); // exponent demo 8bit, CÓ THỂ ĐỔI SANG 15BIT THEO ĐỀ BÀI 
			res = sign + exponent + Fraction(F, BitFraction);// fraction demo 23bit, CÓ THỂ ĐỔI SANG 112BIT THEO ĐỀ BÀI 
		}
		else {  // TRƯỜNG HỢP NHẬP VÀO LÀ SỐ 0.00........
			temp3 = dec.substr(dec.find('.') + 1, dec.size() - dec.find('.'));// lấy chuỗi số phần thập phân 
			res = temp3;
			//Lặp để lấy các bit phần thập phân
			int MAX_BIN_THAP_PHAN = 0;
			string temp = temp3;
			while (kiemTraBang1(temp) == false) {
				temp = nhanNho('2', temp, nho);
				if (nho > 0) {
					MAX_BIN_THAP_PHAN++;
					break;
				}
				else {
					MAX_BIN_THAP_PHAN++;
				}
			}
			MAX_BIN_THAP_PHAN += BitFraction;// CHUYỂN 23BIT SANG 112BIT THEO YÊU CẦU ĐỀ BÀI
			while (kiemTraBang1(temp3) == false & demF <= MAX_BIN_THAP_PHAN) { // kiểm tra phần thập phân demo 23 bit, CÓ THỂ ĐỔI demFraction = 112bit THEO YÊU CẦU ĐỀ BÀI
				temp3 = nhanNho('2', temp3, nho);
				if (nho > 0) {
					temp4.push_back('1');
					demF++;
				}
				else {
					temp4.push_back('0');
					demF++;
				}
			}
			// Đưa về dạng +-1.F*2^E
			int e = -1 * (temp4.find('1') + 1);
			//string temp6; // lưu số mũ E dưới dạng chuỗi
			//temp6 = to_string(e - 1);
			//exponent = DectoBin(cong(temp6, two_power_n(8 - 1))); // Exponent= (E-1) + 2^(8-1) = temp6 + 2^7  
			int t = e - 1 + pow(2, BitExponent - 1);
			string k = to_string(t);
			exponent = DectoBin(k);
			F = temp4.substr(temp4.find('1') + 1, temp4.size() - temp4.find('1'));
			res = sign + exponent + Fraction(F, BitFraction);

		}
	}


	return res;
}

void QFLoat::chuanHoaPhanThapPhan(string & a, string & b)
{
	int l1 = a.length(), l2 = b.length();
	if (l1 >= l2)
	{
		//b.insert(0, l1 - l2, '0');
		b.insert(b.size(), l1 - l2, '0');

	}
	else
	{
		//a.insert(0, l2 - l1, '0');
		a.insert(a.size(), l2 - l1, '0');
	}
}

string QFLoat::divide_by_2_float(string a)
{
	//Gia su a < 1
	string res = "";
	int k = 0;
	int bienNho = 0, chuSo = 0;
	while (k < a.size() || bienNho != 0) { // Hàm kết thúc khi a hết số khác không và ko còn phần dư
		if (k < a.size()) bienNho = bienNho * 10 + (a[k] - '0'); //Hạ chữ số thứ k xuống
		else bienNho = bienNho * 10; // Nếu hết chữ số thì thêm 0
		chuSo = bienNho / 2; // tính chữ số thứ k của kết quả(từ trái qua)
		bienNho = bienNho - chuSo * 2; // Tính phần dư của phép chia
		res = res + (char)(chuSo + '0');
		k++;
	}
	return res;
}

string QFLoat::BintoDec(string binary)
{
	string res = "0";
	int dem = 0;
	string temp1;
	string temp2;
	for (int i = binary.size() - 1; i >= 0; i--) {
		if (binary[i] == '1') {
			temp1 = two_power_n(dem);
			ChuanHoa(res, temp1);
			res = cong(res, temp1);
			dem++;

		}
		else {
			dem++;
		}
	}
	return res;
}

string QFLoat::ChuyenBinThapPhan_to_ThapPhan(string binary)
{
	string exp_2 = "5";
	string res = "0";
	for (int i = 0; i < binary.size(); i++) {
		string temp = exp_2;
		if (binary[i] == '1') {
			chuanHoaPhanThapPhan(res, temp);
			res = cong(res, temp);
		}
		exp_2 = divide_by_2_float(exp_2);
	}
	return res;
}

string QFLoat::FloatBintoDec(string bit)
{
	//Thêm '0' vào bên phải để chuẩn hóa thành chuỗi 128 bit
	string tam = "";
	for (int i = bit.size(); i < 128; i++) {
		tam = tam + '0';
	}

	bit = bit + tam;

	string res;
	string sign;
	string exponent;
	string fraction;
	if (bit[0] == '1') {
		sign = '-';
	}
	else {
		sign = "";
	}
	for (int i = 1; i <= BitExponent; i++) {// DEMO 8BIT, CÓ THỂ SỬA 15 BIT THEO YÊU CẦU ĐỀ BÀI
		exponent.push_back(bit[i]);
	}
	for (int i = BitExponent + 1; i < bit.size(); i++) {// DEMO 23BIT, CÓ THỂ SỬA 112 BIT THEO YÊU CẦU ĐỀ BÀI
		fraction.push_back(bit[i]);
	}
	string PhanNguyen;// lưu chuỗi decimal trước chấm phẩy
	string ThapPhan; // lưu chuỗi decimal sau chấm phẩy
	string BinPhanNguyen;
	string BinThapPhan;
	string temp2 = BintoDec(exponent);
	int e = atoi(temp2.c_str()) - (pow(2, BitExponent - 1) - 1); // demo exponent 8bit 2^(8-1) - 1=127, CÓ THỂ CHUYỂN VỀ 15BIT THEO ĐỀ BÀI
	if (e >= 0) {
		BinPhanNguyen = fraction.substr(0, e);
		BinThapPhan = fraction.substr(e, fraction.size() - e);
		BinPhanNguyen = "1" + BinPhanNguyen;

		PhanNguyen = BintoDec(BinPhanNguyen);//  trả về phần nguyên DEC trước dấu phẩy
		res = PhanNguyen;
		int demThapPhan = 0;
		//string temp3 = "";// lưu decimal sau dấu phẩy
		ThapPhan = ChuyenBinThapPhan_to_ThapPhan(BinThapPhan);
		res = sign + PhanNguyen + "." + ThapPhan;
	}
	else {
		reverse(fraction.begin(), fraction.end());
		fraction.push_back('1');
		for (int i = 0; i < abs(e) - 1; i++) {
			fraction.push_back('0');
		}

		reverse(fraction.begin(), fraction.end());
		BinThapPhan = fraction;
		ThapPhan = ChuyenBinThapPhan_to_ThapPhan(BinThapPhan);
		res = sign + "0" + "." + ThapPhan;
	}
	return res;

}

//Đọc dãy bit  đưa vào dưới dạng string, phải có đủ 1 bit dấu và 12 bit mũ
void QFLoat::ReadStringOfBit(string bit)
{
	string tam = "";
	for (int i = bit.size(); i < 128; i++) {
		tam = tam + '0';
	}

	bit = bit + tam;

	for (int i = 0; i < 128; i++) {
		if (bit[i] == '1') {
			BatBit(i);
		}
		else {
			TatBit(i);
		}
	}
}
//Trả về dãy bit đã lưu dưới dạng string
string QFLoat::StringOfBits()
{
	string bits = "";
	for (int i = 0; i < 128; i++) {
		if ((*this)[i] == 1) {
			bits = bits + '1';
		}
		else
			bits = bits + '0';
	}
	return bits;
}
//Đọc một số thập phân có dạng string "xxx.xxxx" hoặc "-xxx.xxxx"
void QFLoat::ScanQFLoat(QFLoat & x, string DecFloat)
{
	if (is_zero(DecFloat)) {
		return;
	}
	string temp = x.FloatDectoBin(DecFloat);
	for (int i = 0; i < 128; i++) {
		if (temp[i] == '1')
			x.BatBit(i);
	}
}
//In ra giá trị của x với định dạng cơ số p
void QFLoat::PrintQFLoat(QFLoat x, string p)
{
	string bits = x.StringOfBits();
	string res;
	if (p == "10") {
		string exp = bits.substr(1, BitExponent);
		string fra = bits.substr(BitExponent + 1, BitFraction);

		if (all_c(exp, '1') && all_c(fra, '0')) {
			string sign = (bits[0] == '0') ? "+" : "-";
			res = sign + " infinity";
		}
		else if (all_c(exp, '1') && !all_c(fra, '0')) {
			res = "NaN";
		}
		else if (all_c(bits, '0')) {
			res = "0.0";
		}
		else {
			res = x.FloatBintoDec(bits);
		}
	}
	else if (p == "2") {
		res = bits;
	}
	cout << res;
}
//Trả về QFLoat có giá trị bằng với mảng bool (chứa các bit) đưa vào
QFLoat QFLoat::BinToDec(bool * bit)
{
	for (int i = 0; i < 128; i++) {
		TatBit(i); //Trường hợp dãy bit trước khi scan khác 0
		if (bit[i] == 1) {
			BatBit(i);//Bật bit nếu giá trị bool tại đó là 1
		}
	}
	return (*this);
}
//Trả về mảng bool chứa các bit đã lưu của x
bool * QFLoat::DecToBin(QFLoat x)
{
	bool * bit = new bool[128];
	for (int i = 0; i < 128; i++) {
		bit[i] = 0;
		if (x[i] == 1) {
			bit[i] = 1;//Bật bit nếu giá trị bool tại đó là 1
		}
	}
	return bit;
}
//Chuyển số in (hệ 2 hoặc 10) từ hệ cơ số p1 sang p2
string QFLoat::chuyenDoiCoSo(string p1, string p2, string in)
{
	string res;
	QFLoat temp;
	if (p1 == "2") {
		temp.ReadStringOfBit(in);
	}
	else if (p1 == "10") {
		temp.ScanQFLoat(temp, in);
	}

	if (p2 == "2") {
		res = temp.StringOfBits();
	}
	else if (p2 == "10") {
		string bits;
		bits = temp.StringOfBits();

		string exp = bits.substr(1, BitExponent);
		string fra = bits.substr(BitExponent + 1, BitFraction);

		if (all_c(exp, '1') && all_c(fra, '0')) {
			string sign = (bits[0] == '0') ? "+" : "-";
			res = sign + " infinity";
		}
		else if (all_c(exp, '1') && !all_c(fra, '0')) {
			res = "NaN";
		}
		else if (all_c(bits, '0')) {
			res = "0.0";
		}
		else {
			res = temp.FloatBintoDec(bits);
		}
	}
	return res;
}
