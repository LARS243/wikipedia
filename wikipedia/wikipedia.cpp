#include <iostream>
#include <vector>
#include <string>

using namespace std;

class cout_wiki {
private:
    int ln_str(char str[]) {
        int ln = 0;
        while (str[ln]) {
            ln++;
        }
        return ln;
    }
public:
    
    void open_brouser() {
        char url[]{ "start iexplore.exe \"https://ru.wikipedia.org/w/index.php?curid=00000000000000000000\"" };
        int end_zeros = 82;
        char pageid[]{ "13099" };

        int ln = ln_str(pageid);
        
        for (int i = 0; i <= ln; i++) {
            url[end_zeros - i] = pageid[ln - i];
        }

        system(url);
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
