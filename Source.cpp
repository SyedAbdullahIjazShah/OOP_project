//#include <iostream>
//#include <vector>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//// Forward declaration
//class Post;
//class User;
//
//// Activity type enum
//enum class ActivityType {
//    FEELING,
//    THINKING,
//    MAKING,
//    CELEBRATING
//};
//
//// Activity struct
//struct Activity {
//    ActivityType type;
//    string value;
//};
//
//// Comment class
//class Comment {
//public:
//    Comment(User* user, const string& text) : user(user), text(text) {}
//
//    string getText() const { return text; }
//    User* getUser() const { return user; }
//
//private:
//    User* user;
//    string text;
//};
//
//// Post class
//class Post {
//public:
//    Post(int id, const string& description, time_t sharedDate) : id(id), description(description), sharedDate(sharedDate) {}
//
//    int getId() const { return id; }
//    string getDescription() const { return description; }
//    time_t getSharedDate() const { return sharedDate; }
//
//    void addComment(User* user, const string& text) {
//        comments.push_back(Comment(user, text));
//    }
//
//private:
//    int id;
//    string description;
//    time_t sharedDate;
//    vector<Comment> comments;
//};
//
//// User class
//class User {
//public:
//    User(int id, const string& name) : id(id), name(name) {}
//
//    int getId() const { return id; }
//    string getName() const { return name; }
//
//    void addFriend(User* friendUser) {
//        friends.push_back(friendUser);
//    }
//
//    void addLikedPage(Page* page) {
//        likedPages.push_back(page);
//    }
//
//    void addPost(Post* post) {
//        posts.push_back(post);
//    }
//
//private:
//    int id;
//    string name;
//    vector<User*> friends;
//    vector<Page*> likedPages;
//    vector<Post*> posts;
//};
//
//// Page class
//class Page {
//public:
//    Page(int id, User* owner, const string& title) : id(id), owner(owner), title(title) {}
//
//    int getId() const { return id; }
//    string getTitle() const { return title; }
//    User* getOwner() const { return owner; }
//
//    void addPost(Post* post) {
//        posts.push_back(post);
//    }
//
//private:
//    int id;
//    User* owner;
//    string title;
//    vector<Post*> posts;
//};
//
//// SocialNetworkApp class
//class SocialNetworkApp {
//public:
//    User(int id, const string& name) : id(id), name(name) {}
//
//    int getId() const { return id; }
//    string getName() const { return name; }
//
//    void addFriend(User* friendUser) {
//        friends.push_back(friendUser);
//    }
//
//    const vector<User*>& getFriends() const {
//        return friends;
//    }
//
//    void addLikedPage(Page* page) {
//        likedPages.push_back(page);
//    }
//
//    const vector<Page*>& getLikedPages() const {
//        return likedPages;
//    }
//
//    void addPost(Post* post) {
//        posts.push_back(post);
//    }
//
//    const vector<Post*>& getPosts() const {
//        return posts;
//    }
//
//private:
//    int id;
//    std::string name;
//    vector<User*> friends;
//    vector<Page*> likedPages;
//    vector<Post*> posts;
//};
//
//
//int main() {
//    // Sample usage
//    User u1(1, "User1");
//    User u2(2, "User2");
//    User u3(3, "User3");
//    Page p1(1, &u1, "Page1");
//
//    u1.addFriend(&u2);
//    u1.addFriend(&u3);
//    u1.addLikedPage(&p1);
//
//    SocialNetworkApp app;
//    app.setCurrentUser(&u1);
//    app.viewFriendList();
//    app.viewLikedPages();
//    app.viewHome();
//    // Add more commands execution here...
//
//    return 0;
//}