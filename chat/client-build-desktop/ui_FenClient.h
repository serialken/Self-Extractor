/********************************************************************************
** Form generated from reading UI file 'FenClient.ui'
**
** Created: Tue 21. Jun 12:20:50 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCLIENT_H
#define UI_FENCLIENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *serveurIP;
    QLabel *label_2;
    QSpinBox *serveurPort;
    QPushButton *boutonConnexion;
    QVBoxLayout *verticalLayout;
    QTextEdit *listeMessages;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *message;
    QPushButton *boutonEnvoyer;

    void setupUi(QWidget *FenClient)
    {
        if (FenClient->objectName().isEmpty())
            FenClient->setObjectName(QString::fromUtf8("FenClient"));
        FenClient->resize(628, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        FenClient->setWindowIcon(icon);
        verticalLayout_2 = new QVBoxLayout(FenClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(FenClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        serveurIP = new QLineEdit(FenClient);
        serveurIP->setObjectName(QString::fromUtf8("serveurIP"));
        serveurIP->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(serveurIP);

        label_2 = new QLabel(FenClient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        serveurPort = new QSpinBox(FenClient);
        serveurPort->setObjectName(QString::fromUtf8("serveurPort"));
        serveurPort->setMinimumSize(QSize(60, 0));
        serveurPort->setMinimum(1024);
        serveurPort->setMaximum(65535);
        serveurPort->setValue(50885);

        horizontalLayout->addWidget(serveurPort);

        boutonConnexion = new QPushButton(FenClient);
        boutonConnexion->setObjectName(QString::fromUtf8("boutonConnexion"));

        horizontalLayout->addWidget(boutonConnexion);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        listeMessages = new QTextEdit(FenClient);
        listeMessages->setObjectName(QString::fromUtf8("listeMessages"));
        listeMessages->setReadOnly(true);

        verticalLayout_2->addWidget(listeMessages);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(FenClient);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        message = new QLineEdit(FenClient);
        message->setObjectName(QString::fromUtf8("message"));

        horizontalLayout_2->addWidget(message);

        boutonEnvoyer = new QPushButton(FenClient);
        boutonEnvoyer->setObjectName(QString::fromUtf8("boutonEnvoyer"));
        boutonEnvoyer->setIcon(icon);

        horizontalLayout_2->addWidget(boutonEnvoyer);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(FenClient);

        QMetaObject::connectSlotsByName(FenClient);
    } // setupUi

    void retranslateUi(QWidget *FenClient)
    {
        FenClient->setWindowTitle(QApplication::translate("FenClient", "ZeroChat - Client", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FenClient", "IP du serveur :", 0, QApplication::UnicodeUTF8));
        serveurIP->setText(QApplication::translate("FenClient", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("FenClient", "Port du serveur :", 0, QApplication::UnicodeUTF8));
        boutonConnexion->setText(QApplication::translate("FenClient", "Connexion", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("FenClient", "Message :", 0, QApplication::UnicodeUTF8));
        boutonEnvoyer->setText(QApplication::translate("FenClient", "Envoyer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FenClient: public Ui_FenClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCLIENT_H
