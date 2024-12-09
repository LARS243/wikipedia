#include <iostream>
#include <vector>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <boost/beast.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace std;
const int end_zeros = 82;//Сеня, напиши потом, нахрена

const string search_wiki_ip = "https://ru.wikipedia.org/w/api.php?action=query&list=search&utf8=&format=json&srsearch=";
const string search_wiki = "https://ru.wikipedia.org/w/index.php?curid=";
const string wiki = "ru.wikipedia.org";
const string wiki_ip = "/w/api.php?action=query&list=search&utf8=&format=json&srsearch=";

//class WIKI
//{
//private:
//    string standart_url_for_search_ip;
//    char url[end_zeros];
//    int end_zeros;
//
//    int ln_str(char str[]) {
//        int ln = 0;
//        while (str[ln]) {
//            ln++;
//        }
//        return ln;
//    }
//
//    void open_brouser() {
//        char pageid[]{ "13099" };
//
//        int ln = ln_str(pageid);
//
//        for (int i = 0; i <= ln; i++) {
//            url[end_zeros - i] = pageid[ln - i];
//        }
//
//        system(url);
//    }
//
//    string url_encode(const string& value) {
//        ostringstream escaped;
//        escaped.fill('0');
//        escaped << hex;
//
//        for (string::const_iterator i = value.begin(), n = value.end(); i != n; ++i) {
//            string::value_type c = (*i);
//
//            // Keep alphanumeric and other accepted characters intact
//            if (isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
//                escaped << c;
//                continue;
//            }
//
//            // Any other characters are percent-encoded
//            escaped << uppercase;
//            escaped << '%' << setw(2) << int((unsigned char)c);
//            escaped << nouppercase;
//        }
//
//        return escaped.str();
//    }
//
//public:
//
//    WIKI()
//    {
//        standart_url_for_search_ip = "https://ru.wikipedia.org/w/api.php?action=query&list=search&utf8=&format=json&srsearch=";
//        char url[]{ "start iexplore.exe \"https://ru.wikipedia.org/w/index.php?curid=00000000000000000000\"" };
//    }
//
//    void search(string search_input)
//    {
//        search_input = url_encode(search_input);
//        standart_url_for_search_ip += search_input;
//        int len = standart_url_for_search_ip.length();
//        char* standart_url_char_mass = new char[len];
//        if (standart_url_char_mass == nullptr)
//        {
//            cout << "Ошибка выделения памяти!";
//        }
//        else
//        {
//            int j = 0;
//            for (string::const_iterator i = standart_url_for_search_ip.begin(), n = standart_url_for_search_ip.end(); i != n; ++i)
//            {
//                string::value_type c = (*i);
//                standart_url_char_mass[j] = c;
//                j++;
//            }
//            for (int i = 0; i < len; i++)
//            {
//                cout << standart_url_char_mass[i];
//            }
//            cout << endl;
//            system(standart_url_char_mass);
//        }
//    }
//};
//
////system("start iexplore.exe \"www.cyberforum.ru\"");
//
//int main(){
//    setlocale(LC_ALL, "RU");
//    WIKI wikipedia;
//    string search_input;
//    system("start iexplore.exe \"www.cyberforum.ru\"");
//    cout << "Введите ваш поисковой запрос: ";
//    cin >> search_input;
//    wikipedia.search(search_input);
//}

class responce_wiki
{
public:
	static string get_responce(string search)
	{
		boost::asio::io_context io;
		boost::asio::ip::tcp::resolver resolver(io);
		boost::asio::ip::tcp::socket socket(io);
		boost::asio::connect(socket, resolver.resolve(wiki, "80"));
		string search_complete = wiki_ip + search;
		cout << search_complete;
		boost::beast::http::request<boost::beast::http::string_body> req(boost::beast::http::verb::get, search_complete, 11);
		req.set(boost::beast::http::field::host, wiki);
		req.set(boost::beast::http::field::user_agent, BOOST_BEAST_VERSION_STRING);
		boost::beast::http::write(socket, req);
		string responce;
		{
			boost::beast::flat_buffer buffer;
			boost::beast::http::response<boost::beast::http::dynamic_body> res;
			boost::beast::http::read(socket, buffer, res);
			responce += boost::beast::buffers_to_string(res.body().data());
			std::cout << res << std::endl;
		}
		socket.shutdown(boost::asio::ip::tcp::socket::shutdown_both);
		return (responce);
	}
};

int main()
{
	string command;
	cin >> command;
	responce_wiki WIKI;
	string responce = WIKI.get_responce(command);
	cout << responce;
}