#include "domxml.h"
#include <QFile>
#include <QDebug>
#include <QDomDocument>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
Domxml::Domxml()
{



}

void Domxml::createxml(QString filepath)
{
   QFile file(filepath);

   if(true==file.exists())
   {


       cout<<"文件已存在";
             return;

   }
   else{

   bool isok=file.open(QIODevice::WriteOnly);
     if(true==isok)
     {
        //创建xml文档
         QDomDocument doc;
         //创建格式头
         QDomProcessingInstruction ins;
         ins=doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'utf-8\'");
         doc.appendChild(ins);

         //创建根元素节点
         QDomElement root=doc.createElement("日销售清单");
         QDomElement studentsElement = doc.createElement("Students");
         QDomElement studentElement1 = doc.createElement("Student");
         studentsElement.appendChild(studentElement1);

         // 添加学生1的信息
         QDomElement id1 = doc.createElement("id");    // 学生编号
         QDomText idText1 = doc.createTextNode("1");    // 学生编号内容
         id1.appendChild(idText1);
         studentElement1.appendChild(id1);
         QDomElement name1 = doc.createElement("name");    // 学生名称
         QDomText nameText1 = doc.createTextNode("小明");    // 学生编号内容
         name1.appendChild(nameText1);
         studentElement1.appendChild(name1);

         doc.appendChild(root);




         //保存
         QTextStream stream(&file);

         doc.save(stream,4);
         file.close();


//         QDomDocument doc;

//     //    ElementNode               = 1,
//     //    AttributeNode             = 2,
//     //    TextNode                  = 3,
//     //    CDATASectionNode          = 4,
//     //    EntityReferenceNode       = 5,
//     //    EntityNode                = 6,
//     //    ProcessingInstructionNode = 7,
//         // 文件头
//         QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml", "version = \'1.0\' encoding = \'UTF-8\'");
//         doc.appendChild(instruction);

//         // 添加一级节点 (学生集合)
//         QDomElement studentsElement = doc.createElement("Students");
//         // 添加学生集合的属性
//         QDomAttr attr = doc.createAttribute("bool");
//         attr.setValue("true");
//         // doc.setAttributeNode(attr);

//         //doc.appendChild(ScenariosElement);

//         // 添加学生1
//         QDomElement studentElement1 = doc.createElement("Student");
//         studentsElement.appendChild(studentElement1);

//         // 添加学生1的信息
//         QDomElement id1 = doc.createElement("id");    // 学生编号
//         QDomText idText1 = doc.createTextNode("1");    // 学生编号内容
//         id1.appendChild(idText1);
//         studentElement1.appendChild(id1);
//         QDomElement name1 = doc.createElement("name");    // 学生名称
//         QDomText nameText1 = doc.createTextNode("小明");    // 学生编号内容
//         name1.appendChild(nameText1);
//         studentElement1.appendChild(name1);

//         // 添加学生2
//         QDomElement studentElement2 = doc.createElement("Student");
//         studentsElement.appendChild(studentElement2);

//         // 添加学生2的信息
//         QDomElement id2 = doc.createElement("id");    // 学生编号
//         QDomText idText2 = doc.createTextNode("2");    // 学生编号内容
//         id2.appendChild(idText2);
//         studentElement2.appendChild(id2);
//         QDomElement name2 = doc.createElement("name");    // 学生名称
//         QDomText nameText2 = doc.createTextNode("小红");    // 学生编号内容
//         name2.appendChild(nameText2);
//         studentElement2.appendChild(name2);

//         // 每下一级，前面多两个空格
//                  QTextStream stream(&file);

//                  doc.save(stream,2);
//                  file.close();
////         doc.save(out, 2);






//刁志强


     }

     else {

         cout<<"WriteOnly error";
         return;

     }



   }




}

void Domxml::appendxml(QString filePath, QStringList list)
{

    QFile file(filePath);
    bool isok=file.open(QIODevice::ReadOnly);

    if(isok==true)
    {
      QDomDocument doc;
      isok=doc.setContent(&file);
      if(true==isok)
      {
      file.close();
          //获取根节点元素
          QDomElement root=doc.documentElement();
          QDateTime datetime=QDateTime::currentDateTime();
          QString datestr=datetime.toString("yyyy-MM-dd");


          if(true==root.hasChildNodes())
          {


          }
          else {
              //创建日期节点元素
              QDomElement dateele=doc.createElement("日期");
              QDomAttr dateattri=doc.createAttribute("date");
              dateattri.setNodeValue(datestr);

              dateele.setAttributeNode(dateattri);
              root.appendChild(dateele);

              //写有效数据
              writeXML(doc,dateele,list);




          }
          //打开文件
          isok=file.open(QIODevice::WriteOnly);
               if(isok==true)
          {


                  QTextStream stream(&file);
                  doc.save(stream,4);
                  file.close();

      }



      }


    }

}

void Domxml::writeXML(QDomDocument &doc, QDomElement &root, QStringList &list)
{

    QDateTime time=QDateTime::currentDateTime();
    QString timestr=time.toString("hh-mm-ss");

    //创建时间节点元素
    QDomElement tiomeEle=doc.createElement("时间");

    QDomAttr tiomeAttr=doc.createAttribute("time");
    tiomeAttr.setNodeValue(timestr);

    tiomeEle.setAttributeNode(tiomeAttr);


    root.appendChild(tiomeEle);


    QDomElement factory=doc.createElement("厂家");
     QDomElement brand=doc.createElement("品牌");
      QDomElement price=doc.createElement("厂家");

      QDomElement num=doc.createElement("数量");

       QDomElement total=doc.createElement("金额");


       QDomText text=doc.createTextNode(list.at(0));
       factory.appendChild(text);



       text=doc.createTextNode(list.at(1));
       brand.appendChild(text);

       text=doc.createTextNode(list.at(2));
       price.appendChild(text);


       text=doc.createTextNode(list.at(3));
       num.appendChild(text);

       text=doc.createTextNode(list.at(4));
       total.appendChild(text);

         tiomeEle.appendChild(factory);
         tiomeEle.appendChild(brand);
         tiomeEle.appendChild(price);
         tiomeEle.appendChild(num);
         tiomeEle.appendChild(total);

}

void Domxml::writeXml()
{
    // 文件路径
    QString fileName = "test.xml";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return;
    }

    qDebug()<<"5732189055789";

    QTextStream out(&file);
    QDomDocument doc;

//    ElementNode               = 1,
//    AttributeNode             = 2,
//    TextNode                  = 3,
//    CDATASectionNode          = 4,
//    EntityReferenceNode       = 5,
//    EntityNode                = 6,
//    ProcessingInstructionNode = 7,
    // 文件头
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml", "version = \'1.0\' encoding = \'UTF-8\'");
    doc.appendChild(instruction);

    // 添加一级节点 (学生集合)
    QDomElement studentsElement = doc.createElement("Students");
    // 添加学生集合的属性
    QDomAttr attr = doc.createAttribute("bool");
    attr.setValue("true");
    // doc.setAttributeNode(attr);

    doc.appendChild(studentsElement);

    // 添加学生1
    QDomElement studentElement1 = doc.createElement("Student");
    studentsElement.appendChild(studentElement1);

    // 添加学生1的信息
    QDomElement id1 = doc.createElement("id");    // 学生编号
    QDomText idText1 = doc.createTextNode("1");    // 学生编号内容
    id1.appendChild(idText1);
    studentElement1.appendChild(id1);
    QDomElement name1 = doc.createElement("name");    // 学生名称
    QDomText nameText1 = doc.createTextNode("小明");    // 学生编号内容
    name1.appendChild(nameText1);
    studentElement1.appendChild(name1);

    // 添加学生2
    QDomElement studentElement2 = doc.createElement("Student");
    studentsElement.appendChild(studentElement2);

    // 添加学生2的信息
    QDomElement id2 = doc.createElement("id");    // 学生编号
    QDomText idText2 = doc.createTextNode("2");    // 学生编号内容
    id2.appendChild(idText2);
    studentElement2.appendChild(id2);
    QDomElement name2 = doc.createElement("name");    // 学生名称
    QDomText nameText2 = doc.createTextNode("小红");    // 学生编号内容
    name2.appendChild(nameText2);
    studentElement2.appendChild(name2);



    QDomElement student3=doc.createElement("student3");
    studentsElement.appendChild(student3);
    QDomElement id3=doc.createElement("id");
    QDomText id2Text=doc.createTextNode("3");
    id3.appendChild(id2Text);

    student3.appendChild(id3);
    QDomElement name3=doc.createElement("name");
    QDomText nametext3=doc.createTextNode("刁志强");
    name3.appendChild(nametext3);
    student3.appendChild(name3);

    // 每下一级，前面多两个空格
    doc.save(out, 2);
    file.close();
}

// 写 XML 文件
void wirteXml()
{
    // 文件路径
    QString fileName = "test.xml";
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&file);
    QDomDocument doc;

//    ElementNode               = 1,
//    AttributeNode             = 2,
//    TextNode                  = 3,
//    CDATASectionNode          = 4,
//    EntityReferenceNode       = 5,
//    EntityNode                = 6,
//    ProcessingInstructionNode = 7,
    // 文件头
    QDomProcessingInstruction instruction = doc.createProcessingInstruction("xml", "version = \'1.0\' encoding = \'UTF-8\'");
    doc.appendChild(instruction);

    // 添加一级节点 (学生集合)
    QDomElement studentsElement = doc.createElement("Students");
    // 添加学生集合的属性
    QDomAttr attr = doc.createAttribute("bool");
    attr.setValue("true");
    //doc.setAttributeNode(attr);

    //doc.appendChild(ScenariosElement);

    // 添加学生1
    QDomElement studentElement1 = doc.createElement("Student");
    studentsElement.appendChild(studentElement1);

    // 添加学生1的信息
    QDomElement id1 = doc.createElement("id");    // 学生编号
    QDomText idText1 = doc.createTextNode("1");    // 学生编号内容
    id1.appendChild(idText1);
    studentElement1.appendChild(id1);
    QDomElement name1 = doc.createElement("name");    // 学生名称
    QDomText nameText1 = doc.createTextNode("小明");    // 学生编号内容
    name1.appendChild(nameText1);
    studentElement1.appendChild(name1);

    // 添加学生2
    QDomElement studentElement2 = doc.createElement("Student");
    studentsElement.appendChild(studentElement2);

    // 添加学生2的信息
    QDomElement id2 = doc.createElement("id");    // 学生编号
    QDomText idText2 = doc.createTextNode("2");    // 学生编号内容
    id2.appendChild(idText2);
    studentElement2.appendChild(id2);
    QDomElement name2 = doc.createElement("name");    // 学生名称
    QDomText nameText2 = doc.createTextNode("小红");    // 学生编号内容
    name2.appendChild(nameText2);
    studentElement2.appendChild(name2);



    QDomElement student3=doc.createElement("student3");
    studentsElement.appendChild(student3);
    QDomElement id3=doc.createElement("id");
    QDomText id2Text=doc.createTextNode("3");
    id2.appendChild(id2Text);

    student3.appendChild(id3);
    QDomElement name3=doc.createElement("name");
    QDomText nametext3=doc.createTextNode("刁志强");
    name3.appendChild(nametext3);
    student3.appendChild(name3);

    // 每下一级，前面多两个空格
    doc.save(out, 2);
}
