#include <iostream>
#include <vector>
#include <string>

using namespace std;

class cout_wiki {
private:
    string base_url = "https://ru.wikipedia.org/w/api.php";
    
public:
    //char pageid[] = element;

    void open_brouser() {
        char pageid[]{ "13099" };
        int ln = 0;
        while (pageid[ln]) {
            ln++;
        }
        cout << ln;
        char url[]{ "start iexplore.exe \"https://ru.wikipedia.org/w/index.php?curid=00000000000000000000\"" };
        cout << url[62];
        //system(url);
    }
};

//system("start iexplore.exe \"www.cyberforum.ru\"");

class search_wiki {
private:
    vector<string> results;
    string base_url = "https://ru.wikipedia.org/w/api.php";
};
int main(){
    setlocale(LC_ALL, "RU");
    cout_wiki new_page;
    new_page.open_brouser();
}
