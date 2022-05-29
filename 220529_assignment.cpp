#include <iostream>
#include <string>
using namespace std;

class Member {
private:
	string a;
	string Name;
	string Id;
	string Password;

public:
	string getName() {
		return Name;
	}

	string getId() {
		return Id;
	}

	string getPassword() {
		return Password;
	}

	string setName(string name) {	// 회원가입 이름
		Name = name;
		return Name;
	}

	string setId(string id) {	// 회원가입 아이디
		Id = id;
		return Id;
	}

	string setPassword(string password) {	// 회원가입 비밀번호
		Password = password;
		return Password;
	}
};

class Cart {
private:
	int i;
	string list_name[3] = { "c++ 프로그래밍", "linux 프로그래밍", "리버싱" };	// 강의 이름
	string list_number[3] = { "0001", "0002", "0003" };	// 강의 학수번호
	string choice;	// 추가할 학수번호 입력
	string number[3];	// 추가된 학수번호 저장
	string name[3];	// 추가된 강의 이름 저장
public:
	void printf() {	// 1번 장바구니 기능 함수
		cout << "========== 강의목록 ==========" << endl;
		cout << "[1]" << list_name[0] << " >> " << list_number[0] << endl;
		cout << "[2]" << list_name[1] << " >> " << list_number[1] << endl;
		cout << "[3]" << list_name[2] << " >> " << list_number[2] << endl;
		cout << endl;
	}

	string bag_course() {	// 2번 강의 담기 기능
		cout << "추가할 학수 번호 >> ";
		cin >> choice;
		cout << endl;

		for (i = 0; ; i++) {
			if (choice == list_number[i]) {	// 같을 경우
				if (number[0] == choice || number[1] == choice || number[2] == choice) {	// 이미 있는 경우
					cout << "이미 MY 장바구니에 담겨져 있습니다." << endl;
					cout << endl;
				}
				number[i] = choice;
				name[i] = list_name[i];
				return name[i];
				break;
			}

			else if (choice != list_number[i]) {	// 아닐 경우
				break;
			}
		}
	}

	void put_bag() {	// 3번 수강신청 확인 기능
		cout << "======== My 장바구니 ========" << endl;
		for (i = 1; ; i++) {
			cout << i << ". " << name[i] << endl;
		}
	}
};

int main(void) {
	int i, k;	// 반복문을 위한 정의
	int number1, number2;	// 번호 선택을 위한 정의
	string name;	// 회원가입에서 이름을 입력받을 때 사용함
	string id;	// 회원가입에서 아이디를 입력받을 때 사용함
	string password;	// 회원가입에서 비밀번호를 입력받을 때 사용함

	Member m;
	Member* p_m = &m;

	string* N = new string;
	string* I = new string;
	string* P = new string;

	Cart c;


	for (i = 0; ; i++) {
		cout << "--------------------- 서울여자대학교 종합정보시스템 ---------------------" << endl;
		cout << "1. 회원가입" << endl;
		cout << "2. 로그인" << endl;
		cout << endl;
		cout << "번호를 입력하세요 >> ";
		cin >> number1;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << endl;

		if (number1 == 1) {
			cout << "이름 : ";
			cin >> name;
			*N = p_m->setName(name);	// *N 에 입력받은 name 저장

			cout << "아이디 : ";
			cin >> id;
			*I = p_m->setId(id);	// *I 에 입력받은 id 저장

			cout << "비밀번호 : ";
			cin >> password;
			*P = p_m->setPassword(password);	// *P 에 입력받은 password 저장

			cout << endl;
			cout << "=== 회원가입 성공 ===" << endl;
			cout << endl;
		}

		else if (number1 == 2) {
			cout << "아이디 : ";
			cin >> id;

			cout << "비밀번호 : ";
			cin >> password;
			cout << endl;

			if (id == *I && password == *P) {	// 회원가입할 때 입력받은 id와 password가 로그인에서의 입력받은 값과 동일한지 판단
				cout << "=== 로그인 성공 ===" << endl << endl;
				cout << *N << "님 환영합니다" << endl << endl;	// 회원가입할 때 받은 name을 출력

				for (k = 0; ; k++) {
					cout << "=========================" << endl;
					cout << "1. 장바구니" << endl;
					cout << "2. 강의 담기" << endl;
					cout << "3. 수강신청 확인" << endl;
					cout << "4. 로그아웃" << endl;
					cout << "번호를 입력하세요 : ";
					cin >> number2;
					cout << endl;

					if (number2 == 1) {
						c.printf();
					}

					else if (number2 == 2) {
						c.bag_course();
					}

					else if (number2 == 3) {
						c.put_bag();
					}

					else if (number2 == 4) {
						cout << "---------- 로그아웃 ----------" << endl;
						cout << "로그아웃 되었습니다. 안녕히 가세요." << endl;
						break;
					}

					else {
						cout << "번호를 다시 입력해주세요" << endl;
						cout << endl;
					}
				}
			}

			else {
				cout << "아이디 혹은 비밀번호가 틀렸습니다" << endl << endl;
			}
		}

		else {
			cout << "1 또는 2만 입력해주세요" << endl;
			cout << endl;
		}
	}
	delete N;
	delete I;
	delete P;
}