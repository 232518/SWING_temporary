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

	string setName(string name) {	// ȸ������ �̸�
		Name = name;
		return Name;
	}

	string setId(string id) {	// ȸ������ ���̵�
		Id = id;
		return Id;
	}

	string setPassword(string password) {	// ȸ������ ��й�ȣ
		Password = password;
		return Password;
	}
};

class Cart {
private:
	int i;
	string list_name[3] = { "c++ ���α׷���", "linux ���α׷���", "������" };	// ���� �̸�
	string list_number[3] = { "0001", "0002", "0003" };	// ���� �м���ȣ
	string choice;	// �߰��� �м���ȣ �Է�
	string number[3];	// �߰��� �м���ȣ ����
	string name[3];	// �߰��� ���� �̸� ����
public:
	void printf() {	// 1�� ��ٱ��� ��� �Լ�
		cout << "========== ���Ǹ�� ==========" << endl;
		cout << "[1]" << list_name[0] << " >> " << list_number[0] << endl;
		cout << "[2]" << list_name[1] << " >> " << list_number[1] << endl;
		cout << "[3]" << list_name[2] << " >> " << list_number[2] << endl;
		cout << endl;
	}

	string bag_course() {	// 2�� ���� ��� ���
		cout << "�߰��� �м� ��ȣ >> ";
		cin >> choice;
		cout << endl;

		for (i = 0; ; i++) {
			if (choice == list_number[i]) {	// ���� ���
				if (number[0] == choice || number[1] == choice || number[2] == choice) {	// �̹� �ִ� ���
					cout << "�̹� MY ��ٱ��Ͽ� ����� �ֽ��ϴ�." << endl;
					cout << endl;
				}
				number[i] = choice;
				name[i] = list_name[i];
				return name[i];
				break;
			}

			else if (choice != list_number[i]) {	// �ƴ� ���
				break;
			}
		}
	}

	void put_bag() {	// 3�� ������û Ȯ�� ���
		cout << "======== My ��ٱ��� ========" << endl;
		for (i = 1; ; i++) {
			cout << i << ". " << name[i] << endl;
		}
	}
};

int main(void) {
	int i, k;	// �ݺ����� ���� ����
	int number1, number2;	// ��ȣ ������ ���� ����
	string name;	// ȸ�����Կ��� �̸��� �Է¹��� �� �����
	string id;	// ȸ�����Կ��� ���̵� �Է¹��� �� �����
	string password;	// ȸ�����Կ��� ��й�ȣ�� �Է¹��� �� �����

	Member m;
	Member* p_m = &m;

	string* N = new string;
	string* I = new string;
	string* P = new string;

	Cart c;


	for (i = 0; ; i++) {
		cout << "--------------------- ���￩�ڴ��б� ���������ý��� ---------------------" << endl;
		cout << "1. ȸ������" << endl;
		cout << "2. �α���" << endl;
		cout << endl;
		cout << "��ȣ�� �Է��ϼ��� >> ";
		cin >> number1;
		cout << "-------------------------------------------------------------------------" << endl;
		cout << endl;

		if (number1 == 1) {
			cout << "�̸� : ";
			cin >> name;
			*N = p_m->setName(name);	// *N �� �Է¹��� name ����

			cout << "���̵� : ";
			cin >> id;
			*I = p_m->setId(id);	// *I �� �Է¹��� id ����

			cout << "��й�ȣ : ";
			cin >> password;
			*P = p_m->setPassword(password);	// *P �� �Է¹��� password ����

			cout << endl;
			cout << "=== ȸ������ ���� ===" << endl;
			cout << endl;
		}

		else if (number1 == 2) {
			cout << "���̵� : ";
			cin >> id;

			cout << "��й�ȣ : ";
			cin >> password;
			cout << endl;

			if (id == *I && password == *P) {	// ȸ�������� �� �Է¹��� id�� password�� �α��ο����� �Է¹��� ���� �������� �Ǵ�
				cout << "=== �α��� ���� ===" << endl << endl;
				cout << *N << "�� ȯ���մϴ�" << endl << endl;	// ȸ�������� �� ���� name�� ���

				for (k = 0; ; k++) {
					cout << "=========================" << endl;
					cout << "1. ��ٱ���" << endl;
					cout << "2. ���� ���" << endl;
					cout << "3. ������û Ȯ��" << endl;
					cout << "4. �α׾ƿ�" << endl;
					cout << "��ȣ�� �Է��ϼ��� : ";
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
						cout << "---------- �α׾ƿ� ----------" << endl;
						cout << "�α׾ƿ� �Ǿ����ϴ�. �ȳ��� ������." << endl;
						break;
					}

					else {
						cout << "��ȣ�� �ٽ� �Է����ּ���" << endl;
						cout << endl;
					}
				}
			}

			else {
				cout << "���̵� Ȥ�� ��й�ȣ�� Ʋ�Ƚ��ϴ�" << endl << endl;
			}
		}

		else {
			cout << "1 �Ǵ� 2�� �Է����ּ���" << endl;
			cout << endl;
		}
	}
	delete N;
	delete I;
	delete P;
}