#include<iostream>
#include<string>
#include<vector>
using namespace std;

//class Screen;//先声明Screen类



class Screen {
    friend class Window_mgr;
//    friend void Window_mgr::clear(ScreenIndex);//如果用声明友元函数的方法，则要先定义Window_mrg，并声明clear()函数
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd),
    contents(ht * wd, c) {}
    Screen(pos ht, pos wd): height(ht) ,width(wd),
    contents(ht * wd, ' ') {}
    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
//    typedef string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;
    void do_display(ostream &os) const
    {
        os << contents;
    }
};

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width +col] = ch;
    return *this;
}

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;

    void clear(ScreenIndex);

    Screen &getScreen(ScreenIndex i);

private:
    std::vector<Screen> screens{Screen(5, 5, ' ')};
};

Screen &Window_mgr::getScreen(ScreenIndex i)
{
    return screens[i];
}

void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";

    Window_mgr wm{};
    wm.getScreen(0).set(4, 4                 , '+');
    wm.getScreen(0).display(cout);
}
