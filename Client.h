#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QVariant>


class Client : public QTcpSocket
{
    Q_OBJECT
    Q_ENUMS(Service)
public:
    //Constructor de la clase
    Client (QObject* parent = nullptr);

    enum Service
        {
            clientListUpdate, logIn, newChat, newMessage, newFile, readFile, editFile
        };

    //Metodo que inicia el cliente
    Q_INVOKABLE void init();

    Q_INVOKABLE void sendAuthenticationRequest(QString, QString);

    Q_INVOKABLE void sendChatRequest(QString);

    Q_INVOKABLE void sendChatRequest(QStringList, QString);

    Q_INVOKABLE void sendMessage(QString);

    Q_INVOKABLE void sendMessage();

    //Setter de la GUI

    Q_INVOKABLE void setChatView(QObject*);

    void processResponse(QVariantMap);

    void qmlUpdateUsersList();

    //Getters
    QString getNickname() const;

    QList< QString > getUsers() const;

    //Setters
    void setNickname(const QString);

    void setUsers(const QList<QString>);

signals:
    /*Signals*/

public slots:
    /*SLOTS*/

    //Metodo llamado cada vez que el servidor envia un informacion
    void onReadyRead();
    //Metodo llamado cuando finaliza la conexion
    void onDisconnected();

private:
    //Ventana QML (GUI)
    QObject *chatView;
    QString nickname;
    QStringList users;
};

#endif // CLIENT_H
