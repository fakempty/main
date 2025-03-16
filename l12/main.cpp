#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
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
        temp.name="\n";
        temp.age=0;
        count++;
    }

    Student(Student& temp): name(temp.name), age(temp.age){
        cout<<"copy constructor for "<<temp.name<<"\n";
        count++;
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

    /*Student operator+(Student& temp){
        int evarageage=(this->age+temp.age)/2;
        string bothname=this->name+" and "+temp.name;
        return Student(bothname,evarageage);
    }*/

    virtual void setname(string temp){
        this->name=temp;
    }

    virtual void show() const {
        cout << "Student: " << name << "  Age: " << age  << "\n";
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
    void study()const override{
        cout<<this->name<<" learning oooop\n";
    }
    void show() const override{
        cout<<"forth-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

class fifthyearStudent final:public Student {
public:
    fifthyearStudent(string n,int a) :Student(n,a){}
    void study()const override{
        cout<<this->name<<" learning xl oop\n";
    }
    void show() const override{
        cout<<"fifth-year student-"<<this->name<<" age:"<<this->age<<"\n";
    }
};

/*class fifthfinal:public fifthyearStudent {// ---------------fifth form fifht laba
  public:
};*/

 int Student::count=0;

class Para {
protected:
    string name;
    int duration;

public:
    Para() : name("Unknown"), duration(0) {}

    Para(string n, int d) : name(n), duration(d) {}

    virtual void show() const{
        cout << "para: " << name << " Duration:" << duration << " min\n";
    }
    virtual void showpara() const{
        cout<< name;
    }
    virtual void showduration() const{
      cout<<duration;
    }
    virtual ~Para() {
        cout << "---Destroying paru: " << name << "\n";
    }
};

class Lecture:public Para{
public:
    Lecture(string n, int d) : Para (n,d){}
    void show() const override{
        cout<<"lecture "<<this->name<<" duration:"<<this->duration<<"\n";
    }
};

class Laba:public Para{
public:
    Laba(string n, int d) : Para (n,d){}
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
};

class Curs{
private:
    string cursname;
    Teacher *teacher;
    Para *para;

public:
    Curs(string n,Teacher* t,Para* p) : cursname(n), teacher(t), para(p) {}
    void startCurs(Student& student) const{
      cout<<"-curs "<<cursname<<" starting\n";
      teacher->teach(student,*para);
    }
    ~Curs(){
      cout<<"---destroing curs " <<cursname<<"\n";
    }
};

/*class Randomazer{--------------------first form 4------------
protected:
  string name;

public:
  Randomazer (string n) :name(n){}
    void show(Randomazer& r)const{//virtual
     cout<<"test show--";
     }
     ~Randomazer();// -------------no virtual
  };

class random:public Randomazer{
  void show(Randomazer& r)const {//override
    cout<<"test show another --";
    }
  };*/

int main() {

    /*Student student1("vasya", 19);
    Teacher teacher1("olga");
    Para para1("Algebra", 120);

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
    student4.display();*/

    firstyearStudent student1("Bodya",19);
    secondyearStudent student2("oleg",17);
    thirdyearStudent student3("kolia",18);
    forthyearStudent student4("sasha",20);
    fifthyearStudent student5("olya",19);

    Profesor profesor1("profisional");
    Asist asist1("helper");

    Lecture lecture1("algebra",120);
    Laba laba1("laba(oop)",60);

    Curs curs1("ipz",&profesor1,&lecture1);
    Curs curs2("phizicalistu",&asist1,&laba1);

    student1.show();//-----------------six of fifth laba
    student2.show();
    student3.show();
    student4.show();
    student5.show();

    curs1.startCurs(student1);
    curs2.startCurs(student2);
    curs1.startCurs(student3);
    curs2.startCurs(student4);
    curs2.startCurs(student5);

    Student* student6 = new firstyearStudent("alesha",19);//-----------third of fifth lab
    (*student6).show();
    delete student6;

    Student::studentcount();

    firstyearStudent st(" ",1);//--------operator= forth laba
    thirdyearStudent st2("3",2);
    st=st2;
    st.show();
    st2.show();

    student2.study();

    return 0;
}
