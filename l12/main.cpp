#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

class interface{
public:
    virtual void print()const = 0;//------------eight from fifth laba
};

class Student : public interface{
protected:
    string name;
    int age;
    static int count;
    int studentcode;

public:

    static int globalStudentCount;
    Student() : name("Unknown"), age(0) {
    }

    Student(string n, int a): name(n), age(a) {
        Student::count++;
        studentcode = generateStudentCode();
    }

    Student(Student&& temp) : name(move(temp.name)),age(move(temp.age)){
        cout<<"move constructor for "<<temp.name<<"\n";
        temp.name="\n";
        temp.age=0;
    }

    Student(Student& temp): name(temp.name), age(temp.age){
        cout<<"copy constructor for "<<temp.name<<"\n";
    }

    Student& operator++(){
        age++;
        cout<<"incrised age for "<<this->name<<"\n";
        return *this;
    }

    Student& operator=(Student& temp){//--------operator= forth laba
          this->name=temp.name;
          this->age=temp.age;
          return *this;
    }

    static int generateStudentCode() {
        return globalStudentCount++; // Студент отримує код по черзі.
    }

    void print()const override{//------------eight from fifth laba
      cout<<"la;alalalalal\n";
    }

    virtual void setname(string temp){
        this->name=temp;
    }

    virtual void show() const {
        cout << "Student: " << name << "  Age: " << age  << " Code: " << studentcode  << "\n";
    }

    virtual void showname() const {
        cout << "Student: " << name <<" ";
    }

    virtual void showage()const{
        cout << " age:"<<age;
    }

    static void studentcount() {
      cout<<"count of student "<< count<<"\n";
    }

    string getName() const {
        return this->name;
    }

    int getAge() const {
        return this->age;
    }

    int getStudentCode() const {
        return studentcode;
    }

    friend ostream& operator <<(ostream& out, const Student& temp){
        temp.showname();
        temp.showage();
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
    virtual void study() const =0;//----------------seven from fifth

    virtual ~Student() {
        cout << "---Destroying student: " << name << "\n";
    }
};

class firstyearStudent :public Student {
  public:
    firstyearStudent& operator=(Student& temp){//--------operator= forth laba
        Student::operator=(temp);
        cout<<"-------------aleale---";
        return *this;
    }
    void study()const override{
      cout<<this->name<<" learning basicks\n";
      }
    firstyearStudent(string n,int a) :Student(n,a){}
    firstyearStudent() : Student() {}
    void show() const override{
        cout<<"first-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
    void showname() const override{//-------------------second fifth laba------------------second virtual
      cout<<"name-"<<this->name;
    }
};

class secondyearStudent :public Student {
public:
    secondyearStudent(string n,int a) :Student(n,a){}
    secondyearStudent() : Student() {}
    void study()const override{
        cout<<this->name<<" learning oop\n";
    }
    void show() const override{
        cout<<"second-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

class thirdyearStudent :public Student {
public:
    thirdyearStudent(string n,int a) :Student(n,a){}
    thirdyearStudent() : Student() {}
    void study()const override{
        cout<<this->name<<" learning ooop\n";
    }
    void show() const override{
        cout<<"third-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

class forthyearStudent :public Student {
public:
    forthyearStudent(string n,int a) :Student(n,a){}
    forthyearStudent() : Student() {}
    void study()const override{
        cout<<this->name<<" learning oooop\n";
    }
    void show() const override{
        cout<<"forth-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

class fifthyearStudent:public Student {
public:
    fifthyearStudent(string n,int a) :Student(n,a){}
    fifthyearStudent() : Student() {}
    void study()const override{
        cout<<this->name<<" learning xl oop\n";
    }
    void show() const override{
        cout<<"fifth-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

int Student::globalStudentCount = 1;
int Student::count=0;

class Para:public interface {
protected:
    string name;
    string duration;

public:
    Para() : name("Unknown"), duration(0) {}

    Para(string n, string d) : name(n), duration(d) {}

    void print()const override{//------------eight from fifth laba
        cout<<"la;alalalalal\n";
    }

    virtual void show() const{
        cout << "para: " << name << " Duration:" << duration << " min\n";
    }
    virtual void showpara() const{
        cout<< name;
    }
    virtual void showduration() const{
      cout<<duration;
    }
    string getName()const {
        return name;
    }
    string getDuration()const {
        return duration;
    }
    virtual ~Para() {
        cout << "---Destroying paru: " << name << "\n";
    }
};

class Lecture:public Para{
public:
    Lecture(string n, string d) : Para (n,d){}
    void show() const override{
        cout<<"lecture "<<this->name<<" duration:"<<this->duration<<"\n";
    }
};

class Laba:public Para{
public:
    Laba(string n, string d) : Para (n,d){}
    void show() const override{
        cout<<"Laba "<<this->name<<" duration:"<<this->duration<<"\n";
    }
};

class Teacher {
protected:
    string name;

public:
    Teacher() : name("Unknown") {}

    Teacher(string n) : name(n) {}

    string getName()const {
      return name;
    }
    virtual void show()const{
      cout<<"Teacher "<<this->name<<"\n";
    }

    virtual void teach( Student& student,  Para& para) const{
        cout << name << " is teaching " ;
        para.showpara();
        cout<< " to ";
        student.showname();
        cout<<"for: ";
        para.showduration();
        cout<<"min"<<endl;
    }

    virtual ~Teacher() {
        cout << "---Destroying teacher: " << name << "\n";
    }
};

class Profesor :public Teacher{
public:
   Profesor(string n): Teacher(n){}
    void teach( Student& student,  Para& para) const override{
       cout << name << " is teaching " ;
       para.showpara();
       cout<< " to ";
       student.showname();
       cout<<"for: ";
       para.showduration();
       cout<<"min"<<endl;
   }
    void show()const override{
       cout<<"Profesor's name "<<this->name<<"\n";
   }
};

class Asist :public Teacher{
public:
    Asist(string n): Teacher(n){}
    void teach( Student& student,  Para& para) const override{\
        cout<<"assit-";
        cout << name << " is helping with " ;
        para.showpara();
        cout<< " to ";
        student.showname();
        cout<<endl;
    }
    void show()const override{
        cout<<"Asist's name "<<this->name<<"\n";
    }
};

class Curs{
private:
    string name;
    Teacher *teacher;
    Para *para;

public:
    Curs(string n,Teacher* t,Para* p) : name(n), teacher(t), para(p) {}
    void startCurs(Student& student) const{
      cout<<"-curs "<<name<<" starting\n";
      teacher->teach(student,*para);
    }
    Curs(string n) : name(n), teacher(nullptr), para(nullptr) {}
    Curs() : name(""), teacher(nullptr), para(nullptr) {}
    void show()const{
        cout<<"Curs "<<this->name<<"\n";
    }
    string GetName()const {
      return name;
    }
    ~Curs(){
      cout<<"---destroing curs " <<name<<"\n";
    }
};
void saveStudentsToFile(const vector<firstyearStudent>& student1,
                        const vector<secondyearStudent>& student2,
                        const vector<thirdyearStudent>& student3,
                        const vector<forthyearStudent>& student4,
                        const vector<fifthyearStudent>& student5) {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto& s : student1) file << "1 " << s.getName() << " " << s.getAge() << " " << s.getStudentCode() << "\n";
    for (const auto& s : student2) file << "2 " << s.getName() << " " << s.getAge() << " " << s.getStudentCode() << "\n";
    for (const auto& s : student3) file << "3 " << s.getName() << " " << s.getAge() << " " << s.getStudentCode() << "\n";
    for (const auto& s : student4) file << "4 " << s.getName() << " " << s.getAge() << " " << s.getStudentCode() << "\n";
    for (const auto& s : student5) file << "5 " << s.getName() << " " << s.getAge() << " " << s.getStudentCode() << "\n";

    file.close();
}

void loadStudentsFromFile(vector<firstyearStudent>& student1,
                          vector<secondyearStudent>& student2,
                          vector<thirdyearStudent>& student3,
                          vector<forthyearStudent>& student4,
                          vector<fifthyearStudent>& student5) {
    ifstream file("students.txt");
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }

    int year, code, age;
    string name;
    int maxCode = 0;

    while (file >> year >> name >> age >> code) {
        switch (year) {
            case 1: student1.emplace_back(name, age); break;
            case 2: student2.emplace_back(name, age); break;
            case 3: student3.emplace_back(name, age); break;
            case 4: student4.emplace_back(name, age); break;
            case 5: student5.emplace_back(name, age); break;
            default: cout << "Error: Invalid student year in file.\n"; break;
        }
        maxCode = max(maxCode, code);
    }
    Student::globalStudentCount = maxCode + 1;
    file.close();
}
void saveTeacherToFile(vector<Asist>& teacher1,
                    vector<Profesor>& teacher2){
    ofstream file("teachers.txt");
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto& t : teacher1) file << "1 " << t.getName() << "\n";
    for (const auto& t : teacher2) file << "2 " << t.getName() << "\n";

    file.close();
}
void loadTeacherFromFile(vector<Asist>& teacher1,
                       vector<Profesor>& teacher2) {
    ifstream file("teachers.txt");
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }

    int prof;
    string name;

    while (file >> prof >> name) {
        switch (prof) {
            case 1: teacher1.emplace_back(name); break;
            case 2: teacher2.emplace_back(name); break;
            default: cout << "Error: Invalid prof/asis in file.\n"; break;
        }
    }
    file.close();
}
void saveParaToFile(vector<Lecture>& para1,
                    vector<Laba>& para2){
  ofstream file("paras.txt",ios::out);
  if (!file) {
     cout << "Error opening file for reading.\n";
  }
  for (const auto& p : para1) file << "1 " << p.getName() << " " << p.getDuration() << "\n";
  for (const auto& p : para2) file << "2 " << p.getName() << " " << p.getDuration() << "\n";

  file.close();
}
void loadParaFromFile(vector<Lecture>& para1,
                        vector<Laba>& para2){
    ifstream file("paras.txt",ios::out);
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }

    int type;
    string duration;
    string name;

    while (file >> type >> name >> duration) {
        switch (type) {
            case 1: para1.emplace_back(name,duration); break;
            case 2: para2.emplace_back(name,duration); break;
            default: cout << "Error: Invalid prof/asis in file.\n"; break;
        }
    }
    file.close();
}
void saveCursToFile(vector<Curs>& curs1){
    ofstream file("curses.txt");
    if (!file) {
        cout << "Error opening file for reading.\n";
    }
    for (const auto& c : curs1) file << "1 " << c.GetName() << "\n";

    file.close();
}
void loadCursFromFile(vector<Curs>& curs1){
    ifstream file("curses.txt");
    if (!file) {
        cout << "Error opening file for reading.\n";
        return;
    }

    int type;
    string cursname;

    while (file >> type >> cursname) {
        switch (type) {
            case 1: curs1.emplace_back(cursname); break;
            default: cout << "Error: Invalid prof/asis in file.\n"; break;
        }
    }
    file.close();
}

bool adminuser() {
    string useradmin = "";
    bool corect = false;
    string adminpasword = "1234";
    string password = "";
    bool admin = false;

    do {
        corect = false;
        cout << "hello chose who are u\n";
        cout << "A-User   B-Admin\n";
        cin >> useradmin;

        if (useradmin.size() != 1) {
            cout << "enter 1 digit\n";
        } else {
            for (int i = 0; i < useradmin.size(); i++) {
                if ((useradmin[i] == 'A') || (useradmin[i] == 'B') || (useradmin[i] == 'b') || (useradmin[i] == 'a')) {
                    corect = true;
                }
            }
            if (!corect) {
                cout << "wrong input\n";
            }
        }
    } while (!corect);
    switch (useradmin[0]) {
        case 'B':
        case 'b': {
            int corectdigits;
            do {
                corectdigits = 0;
                admin = false;
                cout << "enter password\n";
                cin >> password;

                if (password.size() == adminpasword.size()) {
                    for (int i = 0; i < password.size(); i++) {
                        if (password[i] == adminpasword[i]) {
                            corectdigits++;
                        }
                    }
                    if (corectdigits == adminpasword.size()) {
                        admin = true;
                    } else {
                        cout << "wrong password\n";
                    }
                } else {
                    cout << "wrong password\n";
                }
            } while (!admin);

            if (admin) {
                cout << "welcome admin\n";
            }
            break;
        }
        case 'A':
        case 'a': {
            cout << "welcome new user\n";
            break;
        }
        default:{cout << "someting wrong\n";
        break;}
    }
    return admin;
}
void adminmenu(vector<firstyearStudent>& student1,
               vector<secondyearStudent>& student2,
               vector<thirdyearStudent>& student3,
               vector<forthyearStudent>& student4,
               vector<fifthyearStudent>& student5,
               vector<Asist>& teacher1,
               vector<Profesor>& teacher2,
               vector<Lecture>& para1,
               vector<Laba>& para2,
               vector<Curs>& curs1){
   string menu = "";
   bool quit = false;
   do{
     do{
       menu="";
       quit = false;
       cout<< "----ADMIN MENU----\n\n";

       cout<< "A-Add student\n";//
       /*cout<< "B-Copy student\n";*/
       cout<< "D-Delete student\n";
       cout<< "C-show count of students\n";//
       cout<< "E-Show all students\n\n";//

       cout<< "F-Add teacher\n";//
       cout<< "G-Delete teacher\n";
       cout<< "R-Show all teachers\n\n";//

       cout<< "T-Add para\n";//
       cout<< "Y-Delete Para\n";
       cout<< "i-Show all para\n\n";//

       cout<< "W-Add curs\n";//
       cout<< "X-Delete curs\n";
       cout<< "l-Show all curses\n\n";//

       cout<< "Q-Exit\n";//
       cin >> menu;
       if (menu.size() == 1) {
         string tempyear;
         switch(menu[0]){
             case 'A':
             case 'a': {
               cout<<"\nname of student: ";
               string tempname;
               cin >> tempname;
               cout<<"\nage of student: ";
               int tempage;
               cin >> tempage;
               do{
                   cout<<"\nwhat year student(number): ";
                   cin >> tempyear;
                   if(tempyear.size() ==1) {
                     switch (tempyear[0]) {
                       case '1':{
                          student1.emplace_back(tempname, tempage);
                          cout<<"\nStudent successfully added\n";
                       }break;
                       case '2':{
                           student2.emplace_back(tempname, tempage);
                           cout<<"\nStudent successfully added\n";
                       }break;
                       case '3':{
                           student3.emplace_back(tempname, tempage);
                           cout<<"\nStudent successfully added\n";
                       }break;
                       case '4':{
                           student4.emplace_back(tempname, tempage);
                           cout<<"\nStudent successfully added\n";
                       }break;
                       case '5':{
                           student5.emplace_back(tempname, tempage);
                           cout<<"\nStudent successfully added\n";
                       }break;
                       default:{
                         cout << "something wrong in year\n";
                       }break;
                     }
                   }else{
                     cout<<"wrong year student\n";
                   }
               }while(tempyear.size() != 1);
                 saveStudentsToFile(student1, student2, student3, student4, student5);
             } break;
             case 'B':
             case 'b': {
               cout<<"\ncopy what year student: ";
               string tempyear;
               cin >> tempyear;

             }break;
             case 'C':
             case 'c':{
                 Student::studentcount();
             }break;
             case 'D':
             case 'd': {

             }break;
             case 'e':
             case 'E': {
                cout << "\nFirst-year students:\n";
                for (const auto& student : student1) {
                     student.show();
                }
                cout << "\nSecond-year students:\n";
                for (const auto& student : student2) {
                    student.show();
                }

                cout << "\nThird-year students:\n";
                for (const auto& student : student3) {
                    student.show();
                }

                cout << "\nFourth-year students:\n";
                for (const auto& student : student4) {
                    student.show();
                }

                cout << "\nFifth-year students:\n";
                for (const auto& student : student5) {
                    student.show();
                }
             }break;
             case 'F':
             case 'f': {
               cout << "\nteachers name: ";
               string tempname;
               cin >> tempname;
               string tempprof;
                 do{
                     cout<<"\n1-asist;2-profesor: ";
                     cin >> tempprof;
                     if(tempprof.size() ==1) {
                         switch (tempprof[0]) {
                             case '1':{
                                 teacher1.emplace_back(tempname);
                                 cout<<"\nAsist successfully added\n";
                             }break;
                             case '2':{
                                 teacher2.emplace_back(tempname);
                                 cout<<"\nProfesor successfully added\n";
                             }break;
                             default:{
                               cout << "something wrong in year\n";
                             }break;
                         }
                     }else{
                         cout<<"wrong prof(1asis,2prof)\n";
                     }
                 }while(tempprof.size() != 1);
                 saveTeacherToFile(teacher1, teacher2);
             }break;
             case 'G':
             case 'g': {

             }break;
             case 'R':
             case 'r': {
                 cout << "\nAsists:\n";
                 for (const auto& teacher : teacher1) {
                     teacher.show();
                 }
                 cout << "\nProfesors:\n";
                 for (const auto& teacher : teacher2) {
                     teacher.show();
                 }
             }break;
             case 't':
             case 'T':{
               cout <<"\npara name:";
               string tempname;
               cin >> tempname;
               cout <<"\npara duration:";
               string tempduration;
               cin >> tempduration;
               bool corect;
               string temppara;
               do{
                 corect = false;
                 cout<<"\n1-Lecture;2-Laba:";
                 cin >> temppara;
                 if(temppara.size() == 1) {
                   switch(temppara[0]) {
                       case '1':{
                           para1.emplace_back(tempname, tempduration);
                           cout<<"\nLecture successfully added\n";
                           corect = true;
                       }break;
                       case '2':{
                           para2.emplace_back(tempname, tempduration);
                           cout<<"\nLaba successfully added\n";
                           corect = true;
                       }break;
                     default:{
                       cout << "\nwrong input\n";
                     }break;
                   }
                 }else{
                   cout<<"wrong inputuuu\n";
                 }
               }while(!corect);
             saveParaToFile(para1, para2);
             }break;
             case 'i':
             case 'I': {
               cout << "\nLecture:\n";
               for (const auto& Para : para1) {
                 Para.show();
               }
               cout << "\nLaba:\n";
               for (const auto& Para : para2) {
                 Para.show();
               }
             }break;
             case 'w':
             case 'W': {
               cout << "\nCurs name:";
               string tempname;
               cin >> tempname;
               bool corect;
               string tempcurs;
               do{
                 corect = false;
                 cout<<"\nEnter curse type (num): ";
                 cin >> tempcurs;
                 if(tempcurs.size() == 1) {
                   switch(tempcurs[0]) {
                       case '1':{
                           curs1.emplace_back(tempname);
                           cout<<"\nCurs1 successfully added\n";
                           corect = true;
                       }break;
                     default:{
                       cout << "\nwrong input\n";
                     }break;
                   }
                 }else{
                   cout<<"wrong input\n";
                 }
               }while(!corect);
             saveCursToFile(curs1);
             }break;
             case 'l':
             case 'L': {
                 cout << "\nCurses:\n";
                 for (const auto& Curs : curs1) {
                     Curs.show();
                 }
             }break;
             case 'q':
             case 'Q':{
                quit = true;
             }break;

             default:{
               cout << "someting wrong\n";
             }break;
         }
       }else{cout<<"only 1 deigit!\n";}
       }while(menu.size() != 1);{
     }
   }while(!quit);
}

void usermenu(vector<firstyearStudent>& student1,
              vector<secondyearStudent>& student2,
              vector<thirdyearStudent>& student3,
              vector<forthyearStudent>& student4,
              vector<fifthyearStudent>& student5,
              vector<Asist>& teacher1,
              vector<Profesor>& teacher2,
              vector<Lecture>& para1,
              vector<Laba>& para2,
              vector<Curs>& curs1){
  bool quit=false;
  do{
    quit = false;
    cout<<"\n----USER MENU----\n";
    cout<< "A-Show all students\n";
    cout<< "B-Show all teachers\n";
    cout<< "C-Show all paras\n";
    cout<< "D-Show all curses\n";
    cout<< "Q-Exit\n";
    string menu;
    cin>>menu;
    if (menu.size() != 1) {
      cout<<"\nonly 1 leter\n";
    }else{
      switch (menu[0]) {
        case 'A':
        case 'a': {
            cout << "\nFirst-year students:\n";
            for (const auto& student : student1) {
                student.show();
            }
            cout << "\nSecond-year students:\n";
            for (const auto& student : student2) {
                student.show();
            }

            cout << "\nThird-year students:\n";
            for (const auto& student : student3) {
                student.show();
            }

            cout << "\nFourth-year students:\n";
            for (const auto& student : student4) {
                student.show();
            }

            cout << "\nFifth-year students:\n";
            for (const auto& student : student5) {
                student.show();
            }
        }break;
        case 'B':
        case 'b': {
            cout << "\nAsists:\n";
            for (const auto& teacher : teacher1) {
                teacher.show();
            }
            cout << "\nProfesors:\n";
            for (const auto& teacher : teacher2) {
                teacher.show();
            }
        }break;
        case 'C':
        case 'c': {
            cout << "\nLecture:\n";
            for (const auto& Para : para1) {
                Para.show();
            }
            cout << "\nLaba:\n";
            for (const auto& Para : para2) {
                Para.show();
            }
        }break;
        case 'D':
        case 'd': {
            cout << "\nCurses:\n";
            for (const auto& Curs : curs1) {
                Curs.show();
            }
        }break;
        case 'q':
        case 'Q': {
          quit = true;
        }break;
        default:{
          cout << "something wrong\n";
        }break;
      }
    }
  }while(!quit);
}


int main() {
    vector<firstyearStudent> student1;
    vector<secondyearStudent> student2;
    vector<thirdyearStudent> student3;
    vector<forthyearStudent> student4;
    vector<fifthyearStudent> student5;

    vector<Asist> teacher1;
    vector<Profesor> teacher2;

    vector<Lecture> para1;
    vector<Laba> para2;

    vector<Curs> curs1;

    loadStudentsFromFile(student1, student2, student3, student4, student5);
    loadTeacherFromFile(teacher1, teacher2);
    loadParaFromFile(para1, para2);
    loadCursFromFile(curs1);

    bool admin=adminuser();
    if(admin){
       adminmenu(student1,student2,student3,student4,student5,teacher1,teacher2,para1,para2,curs1);
    }else{
        usermenu(student1,student2,student3,student4,student5,teacher1,teacher2,para1,para2,curs1);
    }
}