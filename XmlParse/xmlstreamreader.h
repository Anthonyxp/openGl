#ifndef XMLSTREAMREADER_H
#define XMLSTREAMREADER_H
#include <string>
#include <QXmlStreamReader>
class QString;
class QStringRef;


struct Teacher
{
    std::string name;
    int age;
    std::string loveSport;

    Teacher(std::string name_, int age_, std::string loveSport_)
        : name(std::move(name_)), age(age_), loveSport(std::move(loveSport_))
    {

    }
};

struct Student
{
    std::string name;
    int age;
    std::string loveSport;

    Student(std::string name_, int age_, std::string loveSport_)
        : name(std::move(name_)), age(age_), loveSport(std::move(loveSport_))
    {

    }
};

inline void print(std::ostream &out, const Teacher& teacher)
{
    out << "teacher: " << teacher.name << std::endl;
    out << "\tage: " << teacher.age << std::endl;
    out << "\tfavorite sport: " << teacher.loveSport << std::endl;
}

inline void print(std::ostream& out, const Student& student)
{
    out << "student: " << student.name << std::endl;
    out << "\tage: " << student.age << std::endl;
    out << "\tfavorite sport: " << student.loveSport << std::endl;
}


class XmlStreamReader
{
public:
    XmlStreamReader();

    bool readFile(const QString& fileName);
    void printAllMembers();

private:
    void readSchoolMembers();
    void readTeacherMembers();
    void readTeacher(const QStringRef& teacherName);
    void readStudentMembers();
    void readStudent(const QStringRef& studentName);
    void skipUnknownElement();

    QXmlStreamReader reader;

    std::vector<Teacher> m_teachers;
    std::vector<Student> m_students;
};

#endif // XMLSTREAMREADER_H
