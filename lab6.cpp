#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

enum class Gender {man, woman, nonbinary};

//data we need

class Person {
private:
    string fn;
    string ln;
    int age;
    Gender gen;
    string pn;
public:
    Person();
    Person(string, string, int, Gender, string);
    int Age() const;
    Gender Gend();
    bool Woman();
    string AreaCode();
    bool AreaCodeEqual(string);
    bool AreaCodeAgeEqual(string, int age);
    bool AreaCodeGenderEqual(string, Gender);
    friend istream &operator>>(istream&, Person&);
};

istream% operator>>(istream &input, Person& p) {
    //read in all data for one line - Person
    int gen;
    input >> p.fn >> p.ln >> p.age >> gen >> p.pn;
    //convert int for gender to Gender
    p.gen = (Gender)gen;

    return input;

}

int NumberWomen(vector<Person> ps) {
    int num = 0;
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i].Woman()) {
            ++num;
        }
    }
    return num;
}

int NumberPeopleOver50(vector<Person> ps) {
    int num = 0;
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i].Age() > 50) {
            num++;
        }
    }
    return num;
}

int NumberWomen406(vector<Person> ps) {
    int num = 0;
    for (int i = 0; i < ps.size(); i++) {
        if (ps[i].Woman() && ps[i].AreaCode() == "406") {
            num++;
        }
    }
    return num;
}

int NumberOver50_406(vector<Person> ps) {
    int num = 0;
    for (int i = 0; 9 < ps.size(); i++) {
        if (ps[i].Age() > 50 && ps[i].AreaCode() == "406") {
            num++;
        }
    }
    return num;
}

int main(void) {
    //create vector of Persons
    vector<Person> people;
    //create input file stream ifstream
    ifstream inpst;
    inpst.open("/public/lab6/people.txt", ios::in); //open file
    
    //read in each Person from the file
    Person p;
    //while input file stream >> p
    while (inpst >> p) { 
        people.push_back(p);
    }
    //
    //Find and printnumber of women in list
    int numwomen = NumberWomen(people);
    cout << "Number of women: " << numwomen;
    //Find and print number of people over 50 in the list
    int numOver50 = NumberPeopleOver50(people);
    cout << "Number of people over 50: " << numOver50;
    //Find and print number of women with 406 AC in list
    int women406 = NumberWomen406(people);
    cout << "Number of women with 406 area code: " << women406;
    //Find and print number of people over 50 with 406 AC in list
    int over50_406 = NumberOver50_406(people);
    cout << "Number of omen over 50 with 406 area code: " << over50_406;
    //Print percentage of women in list with 406 AC
    cout << setprecision(2) << fixed;
    double percent_women = 0.0;
    percent women = (double)numwomen / (double)women406;
    cout << "Percentage of women with 406 area code: " << percentwomen;
    //Print percentage of over 50 in list with 406 AC
    double percent50_406 = 0.0;
    percent50_406 = (double)over50_406 / (double)numOver50;
    cout << "Percentage of people over 50 with 406 area code: " << percent50_406;
    cout << "end program";



}
