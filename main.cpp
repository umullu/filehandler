#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <memory>

#include "xmldocument.h"

using namespace std;
namespace fs = std::filesystem;

string get_suffix(int i)
{
    string suffix = to_string(i);
    suffix.insert(0, 4 - suffix.size(), '0');
    return suffix;
}

int main()
{
    const int MAX_SUFFIX_NUM = 9999;

    const string in_dir_name = "input_data";
    const string out_dir_name = "output_data";
    const string del_dir_name = "to_delete";

    const string in_file_name = "test.xml";
    const string out_file_name = "out.txt";


    fs::path app_path = fs::current_path().parent_path();
    fs::path in_path = app_path/in_dir_name/in_file_name;
    fs::path out_path = app_path/out_dir_name/out_file_name;
    fs::path del_path = app_path/del_dir_name;

    while (!fs::exists(in_path)) {
        std::this_thread::sleep_for(1000ms);
    }
    //fs::copy(app_path/in_file_name, in_path, fs::copy_options::update_existing);

    ifstream in_file;
    in_file.open(in_path, ios::in);
    if (!in_file.is_open()) {
        cout << "Error of openning file for reading, file name " << in_file_name << endl;
        return -1;
    }

    string str;
    string line;
    while (getline(in_file, line)){
      str += line;
    }

    unique_ptr<XmlDocument> xml = make_unique<XmlDocument>(str);

    ofstream out_file;
    out_file.open(out_path, ios::out|ios::trunc);
    if (!out_file.is_open()) {
        cout << "Error of openning file for writing, file name " << out_file_name << endl;
        return -1;
    }

    for (auto& row: xml->rootElement->rows) {
        vector<string> cols = row;
        for (auto& c: cols) {
            cout  << c << endl;
            out_file << c << endl;
        }
        out_file << endl;
    }

    out_file.close();
    in_file.close();

    fs::path path;
    int i = 0;
    do {
        i++;
        // Switch to begin file of buckup loop
        if (i == MAX_SUFFIX_NUM + 1) {
            i = 1;
        }
        path = del_path/(in_file_name + "." + get_suffix(i));
        //cout << suffix << endl;
    } while (exists(path));

    fs::rename(in_path, path);

    // Remove file for next suffix
    if (i == MAX_SUFFIX_NUM)
        i = 0;
    path = del_path/(in_file_name + "." + get_suffix(i+1));
    if (exists(path))
        remove(path);

    return 0;
}
