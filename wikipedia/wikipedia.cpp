#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <sstream>
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

string url_encode(const string& value) {
    ostringstream escaped;
    escaped.fill('0');
    escaped << hex;

    for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
        string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << uppercase;
        escaped << '%' << setw(2) << int((unsigned char)c);
        escaped << nouppercase;
    }

    return escaped.str();
}

int main(){
    setlocale(LC_ALL, "RU");
    cout_wiki new_page;
    string search_input;
    cout << "Введите ваш поисковой запрос: ";
    cin >> search_input;
    cout << search_input << endl;
    search_input = url_encode(search_input);
    cout << search_input;
    new_page.open_brouser();
}
