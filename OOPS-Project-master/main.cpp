#include <bits/stdc++.h>
#include "payment_subscription.h"
#include "playlist.h"
#include "account_Aleesha.h"
using namespace std;

void maintainerMenu() {
    cout << "\n\t\t----------------";
    cout << "\n\t\t   MAINTAINER\n";
    cout << "\t\t----------------\n";

    const int verificationCode = 789;
    while (true) {
        int num;
        cout << "\nPlease enter Verification code for Maintainer Side:";
        cin >> num;
        if (num == verificationCode) {
            cout << "You are now a Verified Maintainer.";
            break;
        } else {
            cout << "Re-enter Please...";
        }
    }

    while (true) {
        cout << "\n\n\n1. Do you want to add songs to the existing playlist?\n";
        cout << "2. Do you want to see the playlist?\n";
        int choice;
        cin >> choice;
        cin.ignore();

        songs *s1;
        Bollywood_songs Bs1;
        Hit_songs Hs1;
        English_songs Es1;

        if (choice == 1) {
            cout << "In which playlist do you want to add the song:\n";
            cout << "1. Bollywood songs\n2. Hit songs\n3. English songs\n";
            int playlistChoice;
            cin >> playlistChoice;
            switch (playlistChoice) {
                case 1:
                    s1 = &Bs1;
                    break;
                case 2:
                    s1 = &Hs1;
                    break;
                case 3:
                    s1 = &Es1;
                    break;
                default:
                    cout << "Invalid choice.";
                    continue;
            }
            s1->Songs();
            cout << "Do you want to continue (y or n)?: ";
            char cont;
            cin >> cont;
            if (cont == 'n') break;

        } else if (choice == 2) {
            Bs1.display_song();
            Hs1.display_song();
            Es1.display_song();
            cout << "Do you want to continue (y or n)?: ";
            char cont;
            cin >> cont;
            if (cont == 'n') break;
        } else {
            cout << "Invalid choice.";
        }
    }
}

void userMenu() {
    cout << "\n\t\t--------";
    cout << "\n\t\t  USER\n";
    cout << "\t\t--------\n";
    cout << "\nWelcome to the online music service... we hope you enjoy a great time\n";
    cout << "\n1. Existing user account\n2. Create new user account\n";
    int choice;
    cin >> choice;
    cin.ignore();
    Account a1;  // Ensure Account class is declared

    if (choice == 1) {
        a1.existing_account();
        cout << "Do you want to change your password(y or n)? :\n";
        char changePwd;
        cin >> changePwd;
        cin.ignore();
        if (changePwd == 'y') {
            a1.forgetpassword();
        }
    } else if (choice == 2) {
        a1.create_new_account();
    } else {
        cout << "Invalid choice.";
        return;
    }

    cout << "Do you want to take subscription (y or n):\n";
    char takeSubscription;
    cin >> takeSubscription;
    cin.ignore();
    if (takeSubscription == 'y') {
        while (true) {
            string email;
            cout << "For verification please enter your email id:\n";
            getline(cin, email);
            if (a1.verify_email(email)) {
                subscription s1;
                cout << "Subscription taken successfully.\n";
                break;
            } else {
                cout << "Sorry, your entered email_id is not matching.\nPlease re-enter your email id...\n";
            }
        }
    }

    cout << "Do you want to create your own playlist(y or n):\n";
    char createPlaylist;
    cin >> createPlaylist;
    cin.ignore();
    if (createPlaylist == 'y') {
        Playlist p1;
    }
}

int main() {
    while (true) {
        cout << "\n\nENTER:\n\n----------------\n| 1. Maintainer |\n| 2. User       |\n| 3. Exit       |\n----------------\n\n";
        cout << "Enter your choice (1 or 2 or 3):";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                maintainerMenu();
                break;
            case 2:
                userMenu();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.";
        }
    }
    return 0;
}
