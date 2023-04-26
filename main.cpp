/*Разработать программу «Домашняя бухгалтерия», которая выполняет 
следующие функции:
1- Запись траты в файл.
2- Запись прихода денежных средств в файл.
3- Расчет баланса на счетах.
4- Расчет % для каждой категории трат, относительно всех трат за 
последний месяц.
5- Расчет % для каждой категории трат, относительно всех трат.
*/
#include <iostream>
#include <fstream>
#include <map>

using std::string;
using std::ofstream; 
using std::ifstream;

class Balance {
    public:
    string MoneyLog, Category;
    int money;
    Balance(string MoneyLog, string Category, int money) {
        this->MoneyLog = MoneyLog;
        this->Category = Category;
        this->money = money;
    }
    void ChangeCategory (string thisCategory, int Switch) {
        map <int, string> FileList; 
        ifstream file;
        file.open(Category);
        string fileCategory;
        int num;
        for (int i = 0; !file.eof(); i++) {
            file >> str >> num >> fileCategory;
            if (thisCategory == fileCategory) {
                num += Switch;
            }
            FileList[i] = num + " " + fileCategory + "\n";
            
        }
        file.close();
        ofstream fout;
        fout.open(Category);
        for (int i = 0; !fout.eof(); i++) {
            fout << FileList[i];
        }
        fout.close();
        
    }
    void MoneyTransaction(string thisCategory, int Switch) {
        ofstream file;
        file.open(MoneyLog);
        if (Switch > 0) {
            file << "+ " << Switch << " " << thisCategory << "\n";
            ChangeCategory(thisCategory, Switch);
        } else if (Switch < 0) {
            file << "- " << Switch << " " << thisCategory << "\n";
            ChangeCategory(thisCategory, Switch);
        }
        file.close();
    }
};
int main() {
    
}
