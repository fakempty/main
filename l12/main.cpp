#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int age;
    static int count;

public:

    Student() : name("Unknown"), age(0) {
        count++;
    }

    Student(string n, int a): name(n), age(a) {
        count++;
    }

    Student(Student&& temp) : name(move(temp.name)),age(move(temp.age)){
        cout<<"move constructor for "<<temp.name<<"\n";
        temp.name="";
        temp.age=0;
        count++;
    }

    Student(Student& temp): name(temp.name), age(temp.age){
        count++;
    }

    Student& operator++(){
        age++;
        return *this;
    }

    Student operator+(Student& temp){
        int evarageage=(this->age+temp.age)/2;
        string bothname=this->name+" and "+temp.name;
        return Student(bothname,evarageage);
    }

    void setname(string temp){
        this->name=temp;
    }

    void display() const {
        cout << "Student: " << name << "  Age: " << age  << "\n";
    }

    void displayname() const {
        cout << "Student: " << name << "\n";
    }

    void displayage()const{
        cout << " age:"<<age<<"\n";
    }

    static void studentcount() {
      cout<<"count of student "<< count<<"\n";
    }

    friend ostream& operator <<(ostream& out, const Student& temp){
        temp.displayname();
        temp.displayage();
        cout<<"name of student-"<<temp.name<<" age:"<<temp.age;
        return out;
    }

    friend istream& operator >>(iostream& in, Student& temp){
        cout<<"enter student name-";
        in>>temp.name;
        cout<<"enter student age-";
        in>>temp.age;
        return in;
    }

    ~Student() {
        cout << "---Destroying student: " << name << "\n";
    }
};

class Para {
private:
    string name;
    int duration;

public:
    Para() : name("Unknown"), duration(0) {}

    Para(string n, int d) : name(n), duration(d) {}

    void info() {
        cout << "para: " << name << "\nDuration: " << duration << " min\n";
    }
    void showpara(){
        cout<< name;
    }
    void showduration(){
      cout<<duration;
    }
    ~Para() {
        cout << "---Destroying paru: " << name << "\n";
    }
};

class Teacher {
private:
    string name;

public:
    Teacher() : name("Unknown") {}

    Teacher(string n) : name(n) {}

    void teach( Student& student,  Para& para) {
        cout << name << " is teaching " ;
        para.showpara();
        cout<< " to ";
        student.displayname();
        cout<<"for: ";
        para.showduration();
        cout<<"min"<<endl;
    }

    ~Teacher() {
        cout << "---Destroying teacher: " << name << "\n";
    }
};
    int Student::count=0;
int main() {

    Student student1("vasya", 19);
    Teacher teacher1("olga");
    Para para1("Algebra", 120);

    const Student studentconst("const student", 00);
    //studentconst.displaynoconst();
    studentconst.display();

    student1.display();
    teacher1.teach(student1, para1);
    //para1.info();

    Student student2 = student1;
    Student student3 = move(student2);
    student2.display();
    student3.display();
    string newname="kolia";
    student1.setname(newname);
    student1.displayname();
    Student::studentcount();

    ++student1;
    student1.display();

    Student student4=student3+student1;
    student4.display();
    return 0;
}
