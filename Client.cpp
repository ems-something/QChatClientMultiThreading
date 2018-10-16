#include "Client.h"

/*Metodos publicos*/

Client::Client (QObject* parent) : QTcpSocket(parent)
{
    setNickname("");
}

//Metodo que inicia el cliente
void Client::init()
{
    //Establecemos la conexion con el servidor que esta corriendo
    //en la direccion ip... en el puerto...
    connectToHost("localhost", 1234);
    connect(this, SIGNAL(readyRead()), SLOT(onReadyRead()));
    connect(this, SIGNAL(disconnected()), SLOT(onDisconnected()));
}

//Setter de la GUI
void Client::setChatView(QObject *chatView)
{

    this->chatView = chatView;
}


//Getter nickanme
QString Client::getNickname() const
{
    return nickname;
}

//Getter Users
QList<QString> Client::getUsers() const
{
    return users;
}

//Setter nickanme
void Client::setNickname(const QString nickname)
{
    this->nickname = nickname;
}

//Setter users
void Client::setUsers(const QList<QString> users)
{
    this->users = users;
}


void Client::sendAuthenticationRequest(QString nickname, QString password)
{
    QVariantMap map;
    QJsonObject object;
    QJsonDocument document;

    qDebug() << "nickname: " << nickname <<endl <<"password: " << password << endl;

    map.insert("service", logIn);
    map.insert("nickname", nickname);
    map.insert("password", password);

    //Transformamos la data en un doc JSON
    object = QJsonObject::fromVariantMap(map);
    document.setObject(object);

    //Enviamos la data encapsulada en un doc JSON, al servidor.
    write(document.toJson());

    flush();

    qDebug() << "sendAuthenticationRequest(QString nickname, QString password) ha sido llamada exitosamente!!" << endl;
}


//Metodo que añade un cliente nuevo a la lista de conectados
void Client::qmlUpdateUsersList()
{

    QObject* qmlLis = chatView->findChild< QObject* >("usersListView");

    if(qmlLis)
    {
        qmlLis->setProperty("model", QVariant::fromValue(users));

        qDebug() <<"Users: " << endl;

        foreach(QString user, users)
        {

            qDebug() << user << endl;
        }
    }

}


void Client::sendChatRequest(QString user)
{

    QVariantMap map;
    QJsonObject object;
    QJsonDocument document;

    QStringList users;

    users.append(nickname);
    users.append(user);

    map.insert("service", newChat);
    map.insert("members", users);
    map.insert("isGroup", false);
    map.insert("groupName", "");

    //Transformamos la data en un doc JSON
    object = QJsonObject::fromVariantMap(map);
    document.setObject(object);

    //Enviamos la data encapsulada en un doc JSON, al cliente.
    write(document.toJson());

    flush();

    qDebug() << "sendChatRequest(QString user) was send" << endl;
    qDebug() << "user: " << user << endl;
}


void Client::sendChatRequest(QStringList users, QString groupName)
{

    QVariantMap map;
    QJsonObject object;
    QJsonDocument document;

    map.insert("service", newChat);
    map.insert("members", users);
    map.insert("isGroup", true);
    map.insert("groupName", groupName);

    //Transformamos la data en un doc JSON
    object = QJsonObject::fromVariantMap(map);
    document.setObject(object);

    //Enviamos la data encapsulada en un doc JSON, al cliente.
    write(document.toJson());

    flush();
}


//Metodo que envia el archivo al servidor
void Client::sendMessage()
{
    QByteArray bytes;
    QVariantMap map;
    QJsonObject object;
    QJsonDocument document;

    //Recibimos la ruta del archivo a enviar...
    //path.replace(QString("file:///"), QString(""));

    //Lo abrimos en modo binario
    //QFileInfo info(path);
    //QFile file(path);

    //file.open(QIODevice::ReadOnly);

    //Guardamos el flujo de datos en un Array de Bytes
    //bytes = file.readAll();

    map.insert("service", newFile);
    //map.insert("name", info.fileName());
    //map.insert("size", info.size());
    //map.insert("file", bytes.toBase64());

    //Transformamos la data en un doc JSON
    object = QJsonObject::fromVariantMap(map);
    document.setObject(object);

    //Enviamos la data encapsulada en un doc JSON, al servidor.
    write(document.toJson());

    flush();

    //file.close();//cerramos el archivo

}


void Client::sendMessage(QString message)
{
    QVariantMap map;
    QString date("15/09/2018");
    QJsonObject object;
    QJsonDocument document;

    map.insert("service", newMessage);
    map.insert("from", nickname);
    map.insert("to", "miguix");
    map.insert("body", message);
    map.insert("date", date);

    //Transformamos la data en un doc JSON
    object = QJsonObject::fromVariantMap(map);
    document.setObject(object);

    //Enviamos la data encapsulada en un doc JSON, al servidor.
    write(document.toJson());

    flush();

    QObject* qmlLis = chatView->findChild< QObject* >("messagesListView");

    if(qmlLis)
    {
        qmlLis->setProperty("model", QVariant::fromValue(message));
    }

}



//Metodo llamado cada vez que el servidor envia un informacion
void Client::onReadyRead()
{
    //Llamada cada vez que el servidor envia informacion
    QByteArray bytes = readAll();
    QJsonDocument document = QJsonDocument::fromJson(bytes);
    QVariantMap response = document.toVariant().toMap();

    //Refrescamos el estado del archivo respectivo
    //fileList.at(result["index"].toInt()) -> setStatus(result["status"].toString());

    processResponse(response);
}


//Metodo llamado cuando se recibio la data completa
void Client::processResponse(QVariantMap response)
{

    qDebug() << "inside processResponse()" << endl;

    //logIn, newChat, newMessage, newFile, readFile, editFile

    qDebug() << response << endl;


    if (response.contains("service"))
    {
        qDebug() << "Servicio: " << response.value("service").toInt() << endl;

        switch(response.value("service").toInt())
        {

            case clientListUpdate:

                if(response.contains("users"))
                {

                    users = response.value("users").toStringList();

                    qmlUpdateUsersList();
                }

            break;


            case logIn:

                if(response.contains("pass"))
                {
                    if(response.value("pass").toBool())
                    {

                        setNickname(response.value("nickname").toString());

                        qDebug() << "Solicitud de logIn aceptada" << endl;
                    }

                }

             break;


             case newChat:

                //if(request.contains("") && request.contains(""))
                {


                }

            break;


            case newMessage:

                //if(request.contains("") && request.contains(""))
                {


                }

            break;


            case newFile:

                //if(request.contains("") && request.contains(""))
                {

                    //El flujo de datos correspondiente al archivo recibido,
                    //lo guardamos en un archivo con el mismo nombre,
                    //en la carpeta ../../debug/Archivos de Impresion/
                    /*QFile file(QString(QDir::currentPath()).toLatin1() + "/debug/Archivos de Impresion/" + dataFile->getFileName());
                    file.open(QIODevice::Append);
                    file.write(QByteArray::fromBase64(result["file"].toByteArray()));
                    file.close();*/
                }

            break;


            case readFile:

                //if(request.contains("") && request.contains(""))
                {


                }

            break;


            case editFile:

                //if(request.contains("") && request.contains(""))
                {


                }

            break;


            default:


            break;

        }

    }

}


//Metodo llamado cuando finaliza la conexion
void Client::onDisconnected()
{


}

//Metodo que actualiza la cola de archivos (GUI)
/*void Client::qmlUpdateTable()
{
    //Actualizamos la interfaz grafica de usuario (GUI)
    QString rg;
    for (int i = 0; i < users.size(); i++)
    {
        QString pr;

    }

    QObject* qmlTab = view -> findChild<QObject*>("clientTabView");

    if(qmlTab)
    {
        qmlTab -> setProperty("text", QVariant::fromValue(rg));
    }
}*/
