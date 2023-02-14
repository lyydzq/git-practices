#ifndef DOMXML_H
#define DOMXML_H
#include <QDomDocument>

class Domxml
{
public:
    Domxml();
    static void createxml(QString filepath);
    static void appendxml(QString filePath,QStringList list);//追加元素
    static void writeXML(QDomDocument&doc,QDomElement& root,QStringList &list);

    static void writeXml();


};

#endif // DOMXML_H
