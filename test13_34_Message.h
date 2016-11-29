#ifndef TEST13_34_MESSAGE_H
#define TEST13_34_MESSAGE_H

#include<set>
#include<string>

using namespace std;
class Folder;
class Message {
        friend class Folder;
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();

public:
    explicit Message(const string &str = ""):
        contents(str) {}

    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void add_to_Folder(Folder*);//test13.37
    void remove_from_Folder(Folder*);//test 13.37

    void show();

};

class Folder {
private:
    set<Message*> messages;
    string folder_name;
public:
    Folder(const string fm = "fm"):folder_name(fm) {}

    void addMsg(Message*);
    void remMsg(Message*);
    void show();
    const string get_name() const { return folder_name;}

};

void Folder::addMsg(Message *msg) {
    messages.insert(msg);
    msg->folders.insert(this);
}

void Folder::remMsg(Message *msg) {
    messages.erase(msg);
    msg->folders.erase(this);
}

void Folder::show() {
    cout << endl << folder_name << endl;
    cout << "contains: " << endl;
    for(auto m : messages) {
        cout << m->contents << endl;
    }
}

void Message::save(Folder &folder) {
    folders.insert(&folder);
    folder.addMsg(this);
}

void Message::remove(Folder &folder) {
    folders.erase(&folder);
    folder.remMsg(this);
}

void Message::add_to_Folders(const Message &msg) {
    for(auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders() {
    for(auto f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message& msg) :
    contents(msg.contents), folders(msg.folders)
{
    add_to_Folders(msg);
}

Message& Message::operator=(const Message &msg) {
    remove_from_Folders();
    contents = msg.contents;
    folders = msg.folders;
    add_to_Folders(msg);
    return *this;
}

Message::~Message() {
    remove_from_Folders();
}

void Message::add_to_Folder(Folder *folder) {
    folders.insert(folder);
    folder->addMsg(this);
}

void Message::remove_from_Folder(Folder *folder) {
    folders.erase(folder);
    folder->remMsg(this);
}

void Message::show() {
    cout << contents << endl;
    cout << " is contained in: " << endl;
    for(auto f : folders) {
        cout << f->get_name() << endl;
    }
}

#endif // TEST13
