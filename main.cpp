#include <iostream>
#include <fstream>
#include <map>
#include <time.h>
#include <string.h>
//
#include <conio.h>

using std::map;
using std::string;
using std::ofstream; 
using std::ifstream;
using std::ios;

class Balance {
    public:
    string MoneyLog, Category;
    int money;
    Balance(string MoneyLog, string Category, int money) {
        this->MoneyLog = MoneyLog;
        this->Category = Category;
        this->money = money;
    }
    void ChangeCategory (string thisCategory, int Switch) { //!!!!
        map <int, string> FileList;
        //
        const char *SEPARATORS = "!?.,;/*-+\n\t ";
        //
        ifstream file;
        file.open(Category);
        string fileCategory = "";
        int num = 0;
        bool CategoryFound = false;
        int i = 0;
        for (; !file.eof(); i++) {
            //*
            num = (string)strtok((char*)fileCategory.c_str(),SEPARATORS);
            //*
            file  >> fileCategory;
            if (thisCategory == fileCategory) {
                num += Switch;
                CategoryFound = true;
            }
            string str = fileCategory + " " + std::to_string(num) + "\n";
            FileList[i] = str;
            std::cout << "num: " << fileCategory << " fcat: " << num << "\n";
        }
        if (!CategoryFound) {
            i++;
            FileList[i] = thisCategory + " " + std::to_string(Switch) + "\n";
            std::cout << FileList[i];
        }
        file.close();
        ofstream fout;
        fout.open(Category);
        for (int j = 0; j <= i; j++) {
            fout << FileList[j];
        }
        fout.close(); //!!!!
    }
    void MoneyTransaction(string thisCategory, int Switch) {
        // std:: cout << "!!!";
        ofstream file;
        file.open(MoneyLog, ios::app);
        time_t mon = time(NULL) / 1036800;
        // std:: cout <<"Switch: " << Switch;
        if (Switch != 0) {
            file << Switch << " " << thisCategory << " " << mon << "\n";
            // std:: cout << "??";
            ChangeCategory(thisCategory, Switch);
        }
        file.close();
    }
    // void BalanceCounting() {
    //     ifstream file;
    //     file.open(MoneyLog);
    //     string fileCategory, str;
    //     int num;
    //     time_t tm;
    //     for (int i = 0; !file.eof(); i++) {
    //         file >> str >> num >> fileCategory >> tm;
    //         money += num;
    //     }
    //     std::cout << money << "\n";
    // }
    // void CategryCount(time_t thisMon) {
    //     map <string, int> CategryC;
    //     ifstream file;
    //     file.open(MoneyLog);
    //     string str, thisCategory;
    //     int num;
    //     time_t mon;
    //     int i = 0;
    //     for (; !file.eof(); i++) {
    //         file >> str >> num >> thisCategory >> mon;
    //         if (str == "-" && mon == thisMon) {
    //             CategryC[thisCategory] += abs(num);
    //         }
    //     }
    //     file.close();
    //     string Catigories[i];
    //     ifstream C;
    //     C.open(Category);
    //     for (int j = 0; !file.eof(); j++) {
    //         C >> num >> Catigories[j];
    //     }
    //     C.close();
    //     num = 0;
    //     for (int j = 0; j <= i; j++) {
    //         num += CategryC[Catigories[j]];
    //     }
    //     map <string, int> CategoryProzent;
    //     for (int j = 0; j <= i; j++) {
    //         CategoryProzent[Catigories[j]] = (CategryC[Catigories[j]] / num) * 100;
    //         std::cout << "\% on this mounth for category " << Catigories[j] << " : " << CategoryProzent[Catigories[j]] << "\n";
    //     }
    // }
    // void CategryCount() {
    //     map <string, int> CategryC;
    //     ifstream file;
    //     file.open(MoneyLog);
    //     string str, thisCategory;
    //     int num;
    //     time_t mon;
    //     int i = 0;
    //     for (; !file.eof(); i++) {
    //         file >> str >> num >> thisCategory >> mon;
    //         if (str == "-") {
    //             CategryC[thisCategory] += abs(num);
    //         }
    //     }
    //     file.close();
    //     string Catigories[i];
    //     ifstream C;
    //     C.open(Category);
    //     for (int j = 0; !file.eof(); j++) {
    //         C >> num >> Catigories[j];
    //     }
    //     C.close();
    //     num = 0;
    //     for (int j = 0; j <= i; j++) {
    //         num += CategryC[Catigories[j]];
    //     }
    //     map <string, int> CategoryProzent;
    //     for (int j = 0; j <= i; j++) {
    //         CategoryProzent[Catigories[j]] = (CategryC[Catigories[j]] / num) * 100;
    //         std::cout << "\% for category " << Catigories[j] << " : " << CategoryProzent[Catigories[j]] << "\n";
    //     }
    // }
};
int main() {
    Balance* balance1 = new Balance("Moneylogbalance1.txt", "Categorybalance1.txt", 10000);
    balance1->MoneyTransaction("Transport", -60);
    //balance1->MoneyTransaction("Business", -1000);
    //balance1->MoneyTransaction("Real_estate", -15000);
    // balance1->MoneyTransaction("Business", 10000);
    // balance1->MoneyTransaction("Transport", -60);
    // balance1->MoneyTransaction("Salary", 20000);
    // balance1->MoneyTransaction("food", -1000);
    // balance1->CategryCount();
    // balance1->BalanceCounting();
    return 0;
}