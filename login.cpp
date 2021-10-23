#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;
    
    cout << "Masukkan username: "; cin >> username;
    cout << "Masukkan password: "; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un==username && password == pw)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int pilihan;

    cout << "1. Register\n2. Login\nPilihan: "; cin >> pilihan;
    if(pilihan == 1)
    {
        string username, password;

        cout << "Masukkan username: "; cin >> username;
        cout << "Masukkan password: "; cin >> password;

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if(pilihan==2)
    {
        bool status = IsLoggedIn();

        if(!status)
        {
            cout << "Tidak bisa login!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Berhasil login!" << endl;
            system("PAUSE");
            return 1;
        }
    }

}