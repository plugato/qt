#include "package.h"
#include "PackageBuilder.h"
#include "packagemensagem.h"
#include <QtEndian>
#include <QHostAddress>
#include <QtEndian>

quint32 PegaIp( const QString & ip){
      QHostAddress *ha = new QHostAddress( ip );
      return ha->toIPv4Address();
}
namespace Chat {

PackageBuilder::PackageBuilder()
{

}


Package * PackageBuilder::buildPackage( const QByteArray & data  ){

    if( data[ 0 ] == Package::Msg )
        return buildMsgPackage( data.right(data.length() - 1));

   // if( data[ 0 ] == Package::Version )
   //     return buildMsgPackage( data.right(5 ));
    return buildMsgPackage( data.right(data.length() - 1));

}

PackageMensagem * PackageBuilder::buildMsgPackage(const QByteArray & data ){
    //uchar charTamanho[2];
    //qint16 intTamanho;
    //intTamanho = qFromBigEndian( *charTamanho );

    PackageMensagem  *pm = new PackageMensagem;

    quint32 e = qFromBigEndian <quint32>( reinterpret_cast <const uchar * >(data.left(4).constData()) );

    QHostAddress *ip = new QHostAddress( e );

    pm->SetDestinatario(   ip->toString() );
    pm->SetMsg( data.right( data.length() -4));

    //qDebug(data.right( data.length() -4));

    return pm;

}

QByteArray PackageBuilder::unbuildPackage( const PackageMensagem  *data ){

     QByteArray bamensagem =  "1";//data->GetMsg().toUtf8();
   // quint32 q32=  bamensagem;


     uchar arraychar[4];
     qToBigEndian( bamensagem.size(), arraychar);

    //QByteArray baip =;

     uchar arrayip[4];
     qToBigEndian(  PegaIp( data->Destinatario ), arrayip);

     QByteArray a;
     a.append( reinterpret_cast <const char * >( data->type()  ));
     a.append( reinterpret_cast <const char *> ( arrayip  ) , 4);
     a.append( reinterpret_cast <const char *> ( arraychar) , 4);
     a.append( bamensagem );

     //qDebug(a);

     return a;


    //data.Destinatario sobrecarga unbuild


   // pack =  static_cast< Chat::PackageMensagem * > (  data );



}

}
