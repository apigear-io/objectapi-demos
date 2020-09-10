#pragma once

#include <QtCore>
#include <iostream>

class Dice;
class Random;

class Console : public QObject {
    Q_OBJECT
public:
    Console(QObject *parent=nullptr);
    void run();
private:
    void process();
Q_SIGNALS:
    void quit();
private:
    QSocketNotifier *m_notifier;
    Random *m_rand;
    Dice *m_dice;
};
