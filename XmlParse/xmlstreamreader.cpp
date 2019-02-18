#include "xmlstreamreader.h"
#include <QFile>
#include <iostream>
#include <QDebug>

XmlStreamReader::XmlStreamReader()
{

}

bool XmlStreamReader::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }
    reader.setDevice(&file);

    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isStartElement())
        {
            if (reader.name() == "school")
            {
                readSchoolMembers();
            }
            else
            {
                reader.raiseError(QObject::tr("Not a school file"));
            }
        }
        else
        {
            reader.readNext();
        }
    }

    file.close();
    if (reader.hasError())
    {
        std::cerr << "Error: Failed to parse file "
                  << qPrintable(fileName) << ": "
                  << qPrintable(reader.errorString()) << std::endl;
        return false;
    }
    else if (file.error() != QFile::NoError)
    {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
    }
    return true;
}

void XmlStreamReader::printAllMembers()
{
    std::cout << "All teachers: " << std::endl;
    for (const auto& teacher : m_teachers)
    {
        print(std::cout, teacher);
    }
    std::cout << "All students: " << std::endl;
    for (const auto& student : m_students)
    {
        print(std::cout, student);
    }
}

void XmlStreamReader::readSchoolMembers()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "teacher")
            {
                readTeacherMembers();
            }
            else if (reader.name() == "student")
            {
                readStudentMembers();
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readTeacherMembers()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                readTeacher(reader.attributes().value("name"));
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readTeacher(const QStringRef& teacherName)
{
    reader.readNext();

    int age = 0;
    std::string favoriteSport;

    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "age")
            {
                age = reader.readElementText().toInt();
            }
            else if (reader.name() == "sport")
            {
                favoriteSport = reader.readElementText().toStdString();
            }
            else
            {
                skipUnknownElement();
            }
        }
        reader.readNext();
    }

    m_teachers.emplace_back(teacherName.toString().toStdString(), age, favoriteSport);
}

void XmlStreamReader::readStudentMembers()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "entry")
            {
                readStudent(reader.attributes().value("name"));
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            reader.readNext();
        }
    }
}

void XmlStreamReader::readStudent(const QStringRef &studentName)
{
    reader.readNext();

    int age = 0;
    std::string favoriteSport;

    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            if (reader.name() == "age")
            {
                age = reader.readElementText().toInt();
            }
            else if (reader.name() == "sport")
            {
                favoriteSport = reader.readElementText().toStdString();
            }
            else
            {
                skipUnknownElement();
            }
        }
        reader.readNext();
    }

    m_students.emplace_back(studentName.toString().toStdString(), age, favoriteSport);
}

void XmlStreamReader::skipUnknownElement()
{
    reader.readNext();
    while (!reader.atEnd())
    {
        if (reader.isEndElement())
        {
            reader.readNext();
            break;
        }

        if (reader.isStartElement())
        {
            skipUnknownElement();
        }
        else
        {
            reader.readNext();
        }
    }
}
