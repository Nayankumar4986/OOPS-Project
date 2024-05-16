#include <bits/stdc++.h>
#include <string>
#include <fstream>
using namespace std;

class Account
{
private:
    string name;
    string email;
    string date_of_birth;
    string password;

public:
    Account() {}

    void forgetpassword()
    {
        string new_password;
        string new_p;
        ofstream fout;
        fout.open("details.txt", ios::in | ios::app);
        if (!fout.is_open())
        {
            cout << "File not opened";
        }
        else
        {
            cout << "<------Verify account----->\n";
            cout << "Enter your name:";
            cin.ignore();
            getline(cin, name);
            fout << name << " ";
            cout << "Enter date of birth:";
            getline(cin, date_of_birth);
            fout << date_of_birth << " ";
            cout << "Enter email-id: ";
            cin.ignore();
            getline(cin, email);
            fout << email << " ";
            int offset;
            string line;
            ifstream fin;
            fin.open("details.txt");
            while (!fin.eof())
            {
                getline(fin, line);
                if ((offset = line.find(email, 0)) != string::npos)
                {
                    cout << "<-------Email-id found------->\n";
                    cout << "Enter new password:\n";
                    getline(cin, new_password);
                    cout << "Re-enter password:\n";
                    getline(cin, new_p);
                    if (new_password == new_p)
                    {
                        cout << "<------Password changed------->\n";
                        fout << new_password << " " << endl;
                    }
                    else
                    {
                        cout << "password is not matched";
                    }
                    fin.close();
                }
            }
        }
        fout.close();
    }

    void existing_account()
    {
        int offset;
        string line;
        ifstream fin;
        cout << "Enter your email-id: ";
        getline(cin, email);
        cout << "Enter your password: ";
        getline(cin, password);
        fin.open("details.txt");

        if(!fin.is_open()){
            cout<<"file is closed\n";
        }
        int n = 0;
        while (!fin.eof())
        {
            getline(fin, line);
            if ((offset = line.find(email, 0)) != string::npos)
            {
                if (offset = line.find(password, 0) != string::npos)
                {
                    cout << "You have successfully verified\n";
                    n = 1;
                    fin.close();
                }
            }
         }
             if(n == 0)
                {
                    int choice;
                    cout << "Your password and email-id does not match\n";
                    cout << "1.Create password\n2.Create new account\n3.Exit\n";
                    cout << "Enter your choice:";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        forgetpassword();
                        break;
                    case 2:
                         create_new_account();
                         break;

                    case 3:
                        exit(0);
                    }
                }
    }
    void create_new_account()
    {
        ofstream fout;
        fout.open("details.txt", ios::out | ios::app);
        
        if (!fout.is_open())
        {
            cout << "File is not opened";
        }
        else
        {
            cin.ignore();
            cout << "Enter your name:";
            getline(cin, name);
            fout << name;

            cout << "Enter your date of birth:";
            cin.ignore();
            getline(cin, date_of_birth);
            fout << date_of_birth << " ";

            cout << "Enter your email id:";
            getline(cin, email);
            fout << email<< " ";

            cout << "Enter your password:";
            getline(cin, password);
            fout << password<< "\n";
        }
        fout.close();
    }
};