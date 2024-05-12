//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//// User class representing a user of the social media app
//class User {
//public:
//    User(const string& username, const string& password) : username(username), password(password) {}
//
//    string getUsername() const { return username; }
//
//    // Function to check if the provided password matches the user's password
//    bool checkPassword(const string& inputPassword) const {
//        return password == inputPassword;
//    }
//
//    // Function to write user data to a file
//    void writeToFile(ofstream& file) const {
//        file << username << "," << password << endl;
//    }
//
//private:
//    string username;
//    string password;
//};
//
//// SocialMediaApp class representing the main application
//class SocialMediaApp {
//public:
//    // Constructor to initialize users array
//    SocialMediaApp(int maxUsers) : maxUsers(maxUsers), numUsers(0) {
//        users = new User * [maxUsers];
//    }
//
//    // Destructor to deallocate memory
//    ~SocialMediaApp() {
//        for (int i = 0; i < numUsers; ++i) {
//            delete users[i];
//        }
//        delete[] users;
//    }
//
//    // Function to sign up a new user
//    void signUp() {
//        if (numUsers < maxUsers) {
//            string username, password;
//            cout << "Enter username: ";
//            cin >> username;
//            cout << "Enter password: ";
//            cin >> password;
//            users[numUsers++] = new User(username, password);
//            saveUsersToFile();
//            cout << "Sign up successful!\n";
//        }
//        else {
//            cout << "Sign up failed. Maximum users reached!\n";
//        }
//    }
//
//    // Function to log in an existing user
//    bool login() {
//        string username, password;
//        cout << "Enter username: ";
//        cin >> username;
//        cout << "Enter password: ";
//        cin >> password;
//        for (int i = 0; i < numUsers; ++i) {
//            if (users[i]->getUsername() == username && users[i]->checkPassword(password)) {
//                cout << "Login successful!\n";
//                return true;
//            }
//        }
//        cout << "Login failed. Invalid username or password.\n";
//        return false;
//    }
//
//private:
//    int maxUsers;
//    int numUsers;
//    User** users;
//
//    // Function to save user data to a file
//    void saveUsersToFile() {
//        ofstream file("users.txt");
//        if (file.is_open()) {
//            for (int i = 0; i < numUsers; ++i) {
//                users[i]->writeToFile(file);
//            }
//            file.close();
//        }
//        else {
//            cout << "Failed to open file for writing!\n";
//        }
//    }
//};
//
//int main() {
//    // Create SocialMediaApp instance with maximum 10 users
//    SocialMediaApp app(10);
//
//    // Example sign up
//    app.signUp();
//
//    // Example login
//    app.login();
//
//    return 0;
//}
