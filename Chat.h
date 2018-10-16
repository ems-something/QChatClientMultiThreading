#ifndef CHAT_H
#define CHAT_H

#include <QObject>
#include <QList>
#include "Message.h"

class Chat : public QObject
{
    Q_OBJECT
public:
    Chat(QObject *parent = nullptr);

private:
    QList< Message > messages;
};

#endif // CHAT_H
