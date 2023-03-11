#include <iostream>
#include <vector>
#include <numeric>
#include <complex>

using namespace std;

class Student {
    string name;
    string surname;
    int albumNumber;
    vector<float> grades;

public:
    float mean_grade() {
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    bool add_grade(float grade) {
    if (grade >= 2.0 && grade <= 5.0) {
        // The grade is valid
        grades.push_back(grade);
        return true;
    }
    // The grade is invalid
    return false;
    }
    void set_name(string name) { // name setter
            this->name = name;
        }

    void set_surname(string surname) { // surname setter
            this->surname = surname;
        }
    bool set_album_number(int albumNumber) { // album Number setter
        int length = sizeof(albumNumber)/sizeof(int);
        if(length == 5 ||  length == 6) 
        {
            this->albumNumber = albumNumber;
            return true;
        }
        return false;
    }
    void display(){
        cout << name << " " << surname << " " << albumNumber << " ";
        for(auto grade:grades){
            cout << grade <<" ";
        }
        cout << endl;
    }
    bool add_new_grade(int grade){
        if(grade <= 2 && grade >= 5){
            grades.push_back(grade);
            cout << "Grade Added Successfully";
            return true;
        }
        cout << "Grade Not Added";
        return false;
    }
    bool check_semester_passed(){
        int track = 0;
        float mean_grd = mean_grade();
        for (auto grade: grades)
        {
            if(grade == 2.0){
                track++;
            }

        }
        if(track>1) return false;
        else
        {
            if (mean_grd >= 3.0)
            {
                cout << "Student passed " << endl;
                return true;
            }
            else 
            {
                cout << "Student did not passed " << endl;
                return false;
            }
            
        }
        return true;
        
    }
};
class Complex {
    double real_;
    double imag_;
public:
    Complex(double real = 0.0, double imag = 0.0)
        : real_(real), imag_(imag)
    {}

    void set_imag(double imag){
        imag_ = imag;
    }

    void set_real(double real){
        real_ = real;
    }

    double get_im() {return real_;}

    double get_real(){ return imag_;}
    
    void print(){
        std::cout << real_ << (imag_ >= 0.0 ? "+" : "-") << std::abs(imag_) << "i" << std::endl;
    }
    Complex add(const Complex& other) const {
        return Complex(real_ + other.real_, imag_ + other.imag_);
    }
};
int main(){
    Complex a(1.0, -2.0);
    Complex b(3.14);
    b.set_imag(-5);
    Complex c = a.add(b);
    c.print(); // prints 4.14-7i

}