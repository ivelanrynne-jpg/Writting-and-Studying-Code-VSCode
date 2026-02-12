/* Bài tập về nhà: HỆ THỐNG QUẢN LÝ DANH BẠ ĐIỆN THOẠI
🎯 Chức năng:
1. Menu
2. Thêm liên hệ
3. Hiển thị
4. Tìm kiếm
5. Sắp xếp
6. Xóa */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

void displayChoose();
void Running_Program(); // Main function to run foreign programs
void deleteWhiteSpace(string& str); // Xoa khoang trang o dau va cuoi chuoi
void YesNoConfirm(string& YoN, vector<string>& name_contacts, vector<string>& phone_contacts); // Xac nhan yes/no

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 1. Xem danh sach 
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 2. Them lien he
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 3. Tim kiem lien he
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 4. Sap xep danh ba
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts); // 5. Xoa lien he
bool exitProgram(); // 6. Thoat 

int main()                          // ------------------------------- MAIN FUNCTION -------------------------------
{
	Running_Program();
	return 0;
}

void displayChoose()
{
	cout << "\n=== HE THONG QUAN LY DANH BA DIEN THOAI! ===\n"
		<< setfill('-') << setw(22) << "MENU" << setfill('-') << setw(22) << "\n"
		<< "1. Xem danh sach" << "\n"
		<< "2. Them lien he" << "\n"
		<< "3. Tim kiem lien he" << "\n"
		<< "4. Sap xep danh ba" << "\n"
		<< "5. Xoa lien he" << "\n"
		<< "6. Thoat" << "\n"
		<< "============================================" << "\n"
		<< "\nVui long chon chuc nang (1-6): ";
}
void deleteWhiteSpace(string& str) // Xoa khoang trang o dau va cuoi chuoi
{
	while (str[0] == ' ')
	{
		str.erase(0, 1);
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.length() - 1, 1);
	}
}

void displayContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 1. Xem danh sach
{
	if (name_contacts.empty() && phone_contacts.empty())
	{
		cout << "\n"
     	<< setfill('-') << setw(8) << "" 
     	<< " Danh ba hien dang trong... "
     	<< setw(8) << "" << endl;
		return;
	}
	cout << "\n"
	 	 << setfill('-') << setw(20) << "" 
	 	 << " Toan bo danh ba "
	 	 << setw(20) << "" << endl;
	for (long long i = 0; i < name_contacts.size(); i++)
	{
		cout << "[" << (i + 1) << "]: " << name_contacts[i] << " - " << phone_contacts[i] << endl;
	}
	cout << setfill('-') << setw(57) << "" << endl;
}
void addContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 2. Them lien he
{
	string __name_contacts, __phone_contacts;
	string num_add;
    do // Nhap so luong lien he can them
    {
		cout << "Nhap so luong lien he can them: ";
		getline(cin, num_add);
		deleteWhiteSpace(num_add);
		
		if (num_add == "n" || num_add == "N")
		{
			return;
		}
        for (long long i = 0; i < num_add.length(); i++)
		{
            if (!isdigit(num_add[i]))
            {
                cout << "Ban phai nhap vao mot so nguyen duong hoac an (n/N) de quay lai MENU!" << "\n";
                num_add.clear();
                break;
            } 
        	if (stoi(num_add) <= 0 || stoi(num_add) > 5)
			{
				cout << "Ban chi co the them toi da 5 hoac it nhat 1 nguoi hoac an (n/N) de quay lai MENU!" << "\n";
				num_add.clear();
				break;
			}
		}
    } while (num_add.empty());

    cout << "\n"
     	 << setfill('-') << setw(20) << "" 
     	 << " Luu y! "
     	 << setw(20) << "" << "\n"
         << " - Ten lien he chi duoc chua chu cai va khoang trang.\n"
         << " - So dien thoai chi co the chua tu 7-15 chu so.\n"
		 << " - De quay lai MENU, ban co the nhap (n/N) khi duoc yeu cau nhap ten hoac so dien thoai.\n"
		 << setfill('-') << setw(50) << "" << endl;

	for (long long i = 0; i < stoi(num_add); i++)
	{
		do // Nhap ten lien he
		{
			cout << "Nhap ten lien he thu " << (i + 1) << ": ";
			getline(cin, __name_contacts);
			deleteWhiteSpace(__name_contacts);

		for (long long i = 0; i < __name_contacts.length(); i++)
			{
				if (__name_contacts[i] == ' ' && __name_contacts[i + 1] == ' ')
				{
					__name_contacts.erase(i, 1);
					i--;
				}
			}
            if (__name_contacts == "n" || __name_contacts == "N")
            {
                return;
            }
			for (char& ki_tu : __name_contacts)
			{
				if (ki_tu == ' ')
				{
					continue;
				}
				else if (isalpha(ki_tu))
				{
					ki_tu = tolower(ki_tu);
				}
				else if (!isalpha(ki_tu))
				{
					cout << "Ten lien he chi duoc chua chu cai va khoang trang. Vui long nhap lai hoac an (n/N) de quay lai MENU!" << endl;
                    __name_contacts.clear();
					break;
				}
			}
			__name_contacts[0] = toupper(__name_contacts[0]);

		for (long long i = 0; i < __name_contacts.length(); i++)
			{
				if (__name_contacts[i] == tolower(__name_contacts[i]) && __name_contacts[i - 1] == ' ')
				{
					__name_contacts[i] = toupper(__name_contacts[i]);
				}
			}
		} while (__name_contacts.empty());

		name_contacts.push_back(__name_contacts);
		do // Nhap so dien thoai
		{
			cout << "Nhap so dien thoai cho " << __name_contacts << ": ";
			getline(cin, __phone_contacts);
			deleteWhiteSpace(__phone_contacts);

            if (__phone_contacts == "n" || __phone_contacts == "N")
            {
                name_contacts.pop_back();
                return;
            }
            for (char& ki_tu : __phone_contacts)
            {
                if (!isdigit(ki_tu))
                {
                    cout << "So dien thoai chi duoc chua chu so. Vui long nhap lai hoac an (n/N) de quay lai MENU!" << endl;
                    __phone_contacts.clear();
                    break;
                } else if (__phone_contacts.length() < 7 || __phone_contacts.length() > 15)
                {
                    cout << "So dien thoai phai co do dai tu 7 den 15 chu so. Vui long nhap lai hoac an (n/N) de quay lai MENU!" << endl;
                    __phone_contacts.clear();
                    break;
                }
            }
		} while (__phone_contacts.empty());

		phone_contacts.push_back(__phone_contacts);
	}
}
void lookforContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 3. Tim kiem lien he
{
	string search_input;

    while (true)
	{
		if (name_contacts.empty() && phone_contacts.empty())
		{
			cout << "\n"
				<< setfill('-') << setw(8) << "" 
				<< " Danh ba hien dang trong... "
				<< setw(8) << "" << endl;
			return;
		}
		cout << "\n"
			<< setfill('-') << setw(20) << "" 
			<< " Luu y! "
			<< setw(20) << "" << "\n"
			<< " - Ten lien he chi duoc chua chu cai va khoang trang.\n"
			<< " - So dien thoai chi co the chua tu 7-15 chu so.\n"
			<< " - De quay lai MENU, ban co the nhap (n/N) khi duoc yeu cau tim kiem.\n"
			<< " - Hoac an (y/Y) de xem toan bo danh ba.\n"
			<< setfill('-') << setw(50) << "" << "\n"
			<< "Nhap ten lien he hoac so dien thoai can tim de ra lien he giong hoac gan giong: ";

		do // Vong lap de xu ly nhap
		{
			getline(cin, search_input);
			deleteWhiteSpace(search_input);
			
			if (search_input == "n" || search_input == "N")
			{
				search_input.clear();
				return;
			}
			if (search_input == "y" || search_input == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
			}
		} while (search_input.empty());
	}
}
void sortContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 4. Sap xep danh ba
{

}
void deleteContacts(vector<string>& name_contacts, vector<string>& phone_contacts) // 5. Xoa lien he
{
    string index_delete;
    string num_delete;
    string YoN;
    
    while (true)
    {
        cout << "\n"
             << setfill('-') << setw(20) << "" 
             << " Luu y! "
             << setw(20) << "" << "\n"
             << " - Ban co the chon xoa mot hoac nhieu lien he cung luc.\n"
             << " - De quay lai MENU, ban co the nhap (n/N) khi duoc yeu cau nhap.\n"
             << " - Hoac an (y/Y) de xem toan bo danh ba.\n"
             << setfill('-') << setw(50) << "" << "\n";
        do // Vong lap de xu ly so luong nhap
		{
			cout << "Nhap so luong lien he can xoa: ";
			getline(cin, num_delete);
			deleteWhiteSpace(num_delete);
			
			if (num_delete == "n" || num_delete == "N")
			{
				num_delete.clear();
				return;
			}
			if (num_delete == "y" || num_delete == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				num_delete.clear();
				break;
			}
            for (long long i = 0; i < num_delete.length(); i++)
            {
                if (!isdigit(num_delete[i]))
                {
                    cout << "Ban phai nhap vao mot so nguyen duong hoac an (n/N) de quay lai MENU!" << "\n";
                    num_delete.clear();
                    break;
                } 
                if (stoi(num_delete) <= 0 || stoi(num_delete) > 5)
                {
                    cout << "Ban chi co the xoa toi da 5 hoac it nhat 1 nguoi hoac an (n/N) de quay lai MENU!" << "\n";
                    num_delete.clear();
                    break;
                }
            }
		} while (num_delete.empty());

        for (int i = 0; i < stoi(num_delete); i++) // Vong lap de nhap chi so lien he can xoa
        {
            cout << "Nhap chi so lien he thu " << i + 1 << " can xoa: ";
			getline(cin, index_delete);
			deleteWhiteSpace(index_delete);
			
			if (index_delete == "n" || index_delete == "N")
			{
				index_delete.clear();
				return;
			}
			if (index_delete == "y" || index_delete == "Y")
			{
				displayContacts(name_contacts, phone_contacts);
				index_delete.clear();
				break;
			}
            for (long long i = 0; i < index_delete.length(); i++)
            {
                if (!isdigit(index_delete[i])) 
                {
                    cout << "Ban phai nhap vao mot so nguyen duong hoac an (n/N) de quay lai MENU!" << "\n";
                    index_delete.clear();
                    break;
                } 
                if (stoi(index_delete) <= 0 || stoi(index_delete) > name_contacts.size())
                {
                    cout << "Ban chi co the xoa toi da " << name_contacts.size() << " hoac it nhat 1 nguoi hoac an (n/N) de quay lai MENU!" << "\n";
                    index_delete.clear();
                    break;
                }
                
                do // Xac nhan xoa lien he
                {
                    cout << "Ban co chac chan muon xoa lien he: " << name_contacts[stoi(index_delete) - 1] << " - " 
                                                                  << phone_contacts[stoi(index_delete) - 1] << " ? (y/Y or n/N): ";
                    getline (cin, YoN);
                    deleteWhiteSpace(YoN);
                
                    if (YoN == "n" || YoN == "N")
                    {
                        YoN.clear();
                        return;
                    }
                    if (YoN == "y" || YoN == "Y")
                    {
                        name_contacts.erase(name_contacts.begin() + stoi(index_delete) - 1);
                        phone_contacts.erase(phone_contacts.begin() + stoi(index_delete) - 1);
                        cout << "Da xoa lien he thu " << index_delete << " khoi danh ba." << "\n";
                        YoN.clear();
                        index_delete.clear();
                        break;
                    }
                } while (YoN != "y" && YoN != "Y" && YoN != "n" && YoN != "N");
            }
        }
	}
}
bool exitProgram() // 6. Thoat
{
	string exit_confirm;
	cout << "\n"
     	 << setfill('-') << setw(20) << "" 
     	 << " Luu y: "
     	 << setw(20) << "" << "\n"
         << "Viec thoat chuong trinh se lam mat tat ca du lieu da nhap!\n"
		 << setfill('-') << setw(50) << "" << "\n"
		 << "Ban co chac chan muon thoat chuong trinh? (y/n): ";

	while (true)
	{
		getline(cin, exit_confirm);

		deleteWhiteSpace(exit_confirm);
		if (exit_confirm == "y" || exit_confirm == "Y")
		{
			cout << "\n"
				<< setfill('-') << setw(4) << "" 
				<< " Da thoat chuong trinh. Cam on ban da su dung! "
				<< setw(4) << "" << endl;
			return true;
		}
		else if (exit_confirm == "n" || exit_confirm == "N")
		{
			cout << "\n"
     		<< setfill('-') << setw(10) << "" 
     		<< " Tiep tuc chuong trinh... "
     		<< setw(10) << "" << endl;
			return false;
		}
		else
		{
			cout << "Lua chon khong hop le. Vui long nhap lai (y/n): ";
		}
	} 
}

void Running_Program()
{
	vector<string> name_contacts, phone_contacts;
	string choice;
	bool shouldExit = false;

	do
	{
		displayChoose(); // Display Choice Menu
		do // Nhap vao lua chon
    	{
			getline(cin, choice);
        	deleteWhiteSpace(choice);

        	for (long long i = 0; i < choice.length(); i++)
        	{
            	if (!isdigit(choice[i]))
            	{
            	    cout << "Ban chi co the nhap vao mot so tu 1 den 6. Vui long chon lai!" << "\n";
            	    choice.clear();
					displayChoose();
            	    break;
        	    } 
        	}
    } while (choice.empty());

		switch (stoi(choice))
		{
		case 1:
			displayContacts(name_contacts, phone_contacts); // Xem danh sach
			break;
		case 2:
			addContacts(name_contacts, phone_contacts); // Them lien he
			break;
		case 3:
			lookforContacts(name_contacts, phone_contacts); // Tim kiem lien he
			break;
		case 4:
			sortContacts(name_contacts, phone_contacts); // Sap xep danh ba
			break;
		case 5:
			deleteContacts(name_contacts, phone_contacts); // Xoa lien he
			break;
		case 6:
			shouldExit = exitProgram(); // Thoat 
			break;
		default:
			cout << "Ban chi co the chon tu 1 den 6. Vui long chon lai!" << endl; // Invalid choice
			break;
		}
	} while (!shouldExit);
}
