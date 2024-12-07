#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class WIKI
{
private:
    string standart_url_for_search_ip;

    int ln_str(char str[]) {
        int ln = 0;
        while (str[ln]) {
            ln++;
        }
        return ln;
    }

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

public:

    WIKI()
    {
        standart_url_for_search_ip = "https://ru.wikipedia.org/w/api.php?action=query&list=search&utf8=&format=json&srsearch=";
    }

    string search(string search_input)
    {
        search_input = url_encode(search_input);
    }
};

//system("start iexplore.exe \"www.cyberforum.ru\"");

int main(){
    setlocale(LC_ALL, "RU");
    cout_wiki new_page;
    IP_wiki IP;
    string search_input;
    cout << "Введите ваш поисковой запрос: ";
    cin >> search_input;
    IP.set_search(search_input);
    
    new_page.open_brouser();
}
