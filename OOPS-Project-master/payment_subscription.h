#include <bits/stdc++.h>
#include<fstream>
// #include "account.h"--------------------need to do

using namespace std;
class Payment
{
private:
    map<int, int> plans;

public:
    void plan_details()
    {
        plans.insert({1, 20});
        plans.insert({2, 75});
        plans.insert({3, 200});
        plans.insert({4, 350});
    }
    Payment()
    {
        plan_details();
    }

    void pay_now(int planNumber)
    {
        for (auto i = plans.begin(); i != plans.end(); i++)
        {
            if ((*i).first == planNumber)
            {
                int amount = (*i).second;
                cout<<".............................................................\n";
                cout << "Rs." << amount << " has been detected from your bank account.\n";
                cout<<".............................................................\n";
                cout << "Thank you for taking the subscription.\n\n";
            }
        }
    }
};


// class subscription :
class subscription
{
private:
    int planNumber;
    Payment payment_details;

public:
    bool valid_email(string search)
    {
        int offset;
        string line;
        ifstream Myfile;
        Myfile.open("details.txt");

        while (!Myfile.eof())
        {
            getline(Myfile, line);
            if ((offset = line.find(search, 0)) != string::npos)
            {
                cout << "You are successfully verified... congretulations.\n";
                Myfile.close();
                return true;
            }
        }
        Myfile.close();

        return false;
    }

    void displayPlan()
    {
        cout << "\nThe plans we have in our boat are as follows:";
        cout << "\nPlan 1: for 7 days- Rs.20"
             << "\n";
        cout << "Plan 2: for 1 month- Rs.75"
             << "\n";
        cout << "Plan 3: for 3 months- Rs.200"
             << "\n";
        cout << "Plan 4: for 6 months- Rs.350"
             << "\n\n";
    };

    void planTaken()
    {

        while (1)
        {
            cout << "Enter the plan_number you want to select from 1 to 4:\n";
            int num;
            cin >> num;
            if (num <= 4 && num >= 1)
            {
                cout << "processing...\n\n";
                payment_details.pay_now(num);
                break;
            }
            else
            {
                cout << "Re-enter please:\n";
            }
        }
    };

    subscription()
    {

        while (1)
        {
            cout << "For verification please enter your email id:\n";
            string s;
            cin >> s;
            if (valid_email(s))
            {
                // subscriptonId = subscriptionId;
                displayPlan();
                planTaken();
                break;
            }
            else
            {
                cout << "Sorry, your entered email_id is not matching.\n";
                cout<<"Please re-enter your email id... \n";
            }
        }
    }
};
// int main()
// {
//     subscription s1;

//     return 0;
// }