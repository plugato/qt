#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PackageBuilder.h"
#include "PackageBuilder.cpp"

#include "packagemensagem.h"
#include "package.h"
#include "socket.h"
#include <QtEndian>
#include <QHostAddress>


/*
quint32 PegaIp( const QString & ip){
      QHostAddress *ha = new QHostAddress( ip );
      return ha->toIPv4Address();
}*/

/*quint32 PegaIp( QByteArray ip ){
      QHostAddress *ha = new QHostAddress(  );
      return ha->toIPv4Address();
}*/




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->pb_atualiza , &QPushButton::clicked, this, &MainWindow::Envia  );
    //connect();
    //connect(this , &MainWindow::SendPack,   Chat::Socket::pack  ,&Chat::Socket::SendPackage  );

    //ui->lineEdit->setText(pack->GetDestinatario());
   // ui->lineEdit_2->setText(pack->GetMsg());

}

void MainWindow::Envia(){
    qDebug("sss");
    QString texto = ui->lineEdit->text();

    // Chat::PackageMensagem * pack;                 //= new Chat::PackageMensagem;
    Chat::PackageMensagem * pack;
    //QByteArray s("\012345678912");
    //QByteArray  q( "\000\xC0\xA8\x01\xB4\000123456789", 15);
    //QByteArray  q( "\000\000123456789", 15);



    quint32 q32 = PegaIp("192.168.1.180");


    QString Msg = texto;
    uchar arraychar[4];
    qToBigEndian( q32, arraychar);         //-1062731340, arraychar);

    QByteArray  q;

    q.append('\0');
    q.append( reinterpret_cast<const char *> (arraychar) , 4);

    uchar a[2];
    quint16 qw16 = Msg.length();
    qToBigEndian( qw16,a );

    q.append(texto);

    pack =  static_cast< Chat::PackageMensagem * > ( Chat::PackageBuilder::buildPackage( q ));


   //emit SendPack( q );
   // Chat::Socket s ;//= new Chat::Socket;


    Chat::Socket *s= new Chat::Socket ;
     //ui->lineEdit->setText(pack->GetDestinatario());
    ui->lineEdit_2->setText(pack->GetMsg());
    //Chat::Socket::SendPackage( pack );


}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::SendPack(QByteArray){

//}

