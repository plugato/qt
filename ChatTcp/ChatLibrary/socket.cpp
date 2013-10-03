#include "socket.h"
#include "PackageBuilder.h"
#include <QtEndian>
#include <QTcpSocket>


namespace Chat {
Socket::Socket()
{
    tcpServer = new QTcpServer ;
    tcpServer->listen( QHostAddress::AnyIPv4 , 666);

    socket = new QTcpSocket ;
    socket->connectToHost("192.168.1.180",666);


    connect( socket, &QTcpSocket::readyRead, this, &Chat::Socket::GetPackage  );


}




QString Socket::SendPackage(const Package &data ){



   //  static Chat::PackageMensagem * pack;

  //   pack =  static_cast< Chat::PackageMensagem * > ( Chat::PackageBuilder::buildPackage( data ));




}

Package *Socket::GetPackage(  ){
    qDebug("funfo");
    //PackageMensagem packmsg = new PackageMensagem;

    QByteArray bytea = socket->readAll();
    Chat::PackageMensagem * unpack ;

    unpack = static_cast< Chat::PackageMensagem * > ( Chat::PackageBuilder::buildPackage( bytea ));

    QByteArray ba = Chat::PackageBuilder::unbuildPackage(  unpack );

    //packmsg.GetMsg();

    qDebug(ba);

}




} // namespace Chat
