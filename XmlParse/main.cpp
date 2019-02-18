#include <QCoreApplication>
#include <string>
#include "xmlstreamreader.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    XmlStreamReader *xml = new XmlStreamReader();
    xml->readFile("F:\\openGl\\XmlParse\\debug\\xml.xml");
    xml->printAllMembers();

    return a.exec();
}
