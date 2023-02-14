#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextCodec>
#include <QFileDevice>
#include "domxml.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Domxml::createxml("../demo3.xml");
    //Domxml::appendxml()
    Domxml::writeXml();

    //点击按钮，选取文件
    connect(ui->pushButton,&QPushButton::clicked,[=](){

      QString path=QFileDialog::getOpenFileName(this,"打开文件","D:\Qt_project\FILE");
        if(path.isEmpty()){

            QMessageBox::warning(this,"警告","打开失败");

        }
        else{

            ui->lineEdit->setText(path);
            QTextCodec *code=QTextCodec::codecForName("gbk");

            QFile file(path);//参数路径名称
            //指定打开方式
            file.open(QIODevice::ReadOnly);
            QByteArray array;

            while(!file.atEnd()){

                array+= file.readLine();//把字节数组中的字符串数据连接起来
            }





            //设置到文本编辑框
            ui->textEdit->setText(code->toUnicode(array));
              file.close();
           //写文件
            //重新指定打开方式
            file.open(QFileDevice::Append);
            file.write("ghrejaipghdiuo");
            file.close();



        }


    });
}

Widget::~Widget()
{
    delete ui;
}

