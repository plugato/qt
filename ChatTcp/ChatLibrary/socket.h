#ifndef CHAT_SOCKET_H
#define CHAT_SOCKET_H
#include <QByteArray>
#include "package.h"
#include "PackageBuilder.h"
#include <QTcpServer>
#include <QTcpSocket>

namespace Chat {

class Socket : public QObject
{
    Q_OBJECT

public:
    Socket();
    QTcpServer *tcpServer;



private:

    QTcpSocket * socket;


public slots:
    Package * GetPackage();
    QString SendPackage(const Package &data );



};


} // namespace Chat
#endif // CHAT_SOCKET_H
