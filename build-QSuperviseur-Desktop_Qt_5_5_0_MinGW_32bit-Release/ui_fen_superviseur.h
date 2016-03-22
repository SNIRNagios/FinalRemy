/********************************************************************************
** Form generated from reading UI file 'fen_superviseur.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEN_SUPERVISEUR_H
#define UI_FEN_SUPERVISEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fen_superviseur
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *GB_Contenu;
    QTableWidget *TW_Hotes;
    QTextEdit *TE_Hotes;
    QPushButton *BTN_getHosts;
    QPushButton *BTN_getServices;
    QTableWidget *TW_Services;
    QLabel *label_3;
    QSplitter *splitter_3;
    QLabel *LA_Boucle;
    QLCDNumber *LCDN_Chrono;
    QGroupBox *GB_Connexion;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BTN_Timer;
    QPushButton *BTN_StopTimer;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *BTN_Connexion;
    QPushButton *BTN_Deconnexion;
    QToolButton *toolButton;
    QGroupBox *GB_Interrogation;
    QSplitter *splitter;
    QLabel *LA_Frequence;
    QSpinBox *SB_Frequence;
    QSplitter *splitter_2;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_5;
    QLabel *LA_Status;
    QListWidget *listWidget;
    QToolButton *toolButton_2;

    void setupUi(QDialog *fen_superviseur)
    {
        if (fen_superviseur->objectName().isEmpty())
            fen_superviseur->setObjectName(QStringLiteral("fen_superviseur"));
        fen_superviseur->resize(950, 392);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/LOGOFEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        fen_superviseur->setWindowIcon(icon);
        fen_superviseur->setStyleSheet(QLatin1String("QDialog#fen_superviseur\n"
"{\n"
"	background: rgb(255, 255, 255);\n"
"}"));
        buttonBox = new QDialogButtonBox(fen_superviseur);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(700, 710, 151, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        GB_Contenu = new QGroupBox(fen_superviseur);
        GB_Contenu->setObjectName(QStringLiteral("GB_Contenu"));
        GB_Contenu->setGeometry(QRect(130, 130, 781, 251));
        GB_Contenu->setStyleSheet(QLatin1String("QGroupBox#GB_Contenu\n"
"{\n"
"	color:rgb(0, 0, 0);\n"
"}"));
        TW_Hotes = new QTableWidget(GB_Contenu);
        TW_Hotes->setObjectName(QStringLiteral("TW_Hotes"));
        TW_Hotes->setEnabled(true);
        TW_Hotes->setGeometry(QRect(10, 50, 281, 181));
        TE_Hotes = new QTextEdit(GB_Contenu);
        TE_Hotes->setObjectName(QStringLiteral("TE_Hotes"));
        TE_Hotes->setEnabled(false);
        TE_Hotes->setGeometry(QRect(300, 70, 131, 161));
        TE_Hotes->setReadOnly(true);
        BTN_getHosts = new QPushButton(GB_Contenu);
        BTN_getHosts->setObjectName(QStringLiteral("BTN_getHosts"));
        BTN_getHosts->setGeometry(QRect(10, 20, 111, 23));
        BTN_getHosts->setStyleSheet(QLatin1String("QPushButton#BTN_getHosts\n"
"{\n"
"	background:rgb(200, 200, 200);\n"
"}\n"
"\n"
"QPushButton#BTN_getHosts:hover\n"
"{\n"
"	background:rgb(220, 236, 255);\n"
"}"));
        BTN_getServices = new QPushButton(GB_Contenu);
        BTN_getServices->setObjectName(QStringLiteral("BTN_getServices"));
        BTN_getServices->setGeometry(QRect(440, 20, 111, 23));
        BTN_getServices->setStyleSheet(QLatin1String("QPushButton#BTN_getServices\n"
"{\n"
"	background:rgb(200, 200, 200);\n"
"}\n"
"\n"
"QPushButton#BTN_getServices:hover\n"
"{\n"
"	background:rgb(220, 236, 255);\n"
"}"));
        TW_Services = new QTableWidget(GB_Contenu);
        TW_Services->setObjectName(QStringLiteral("TW_Services"));
        TW_Services->setGeometry(QRect(440, 50, 321, 181));
        label_3 = new QLabel(GB_Contenu);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 50, 81, 16));
        splitter_3 = new QSplitter(GB_Contenu);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(630, 20, 131, 23));
        splitter_3->setOrientation(Qt::Horizontal);
        LA_Boucle = new QLabel(splitter_3);
        LA_Boucle->setObjectName(QStringLiteral("LA_Boucle"));
        splitter_3->addWidget(LA_Boucle);
        LCDN_Chrono = new QLCDNumber(splitter_3);
        LCDN_Chrono->setObjectName(QStringLiteral("LCDN_Chrono"));
        splitter_3->addWidget(LCDN_Chrono);
        GB_Connexion = new QGroupBox(fen_superviseur);
        GB_Connexion->setObjectName(QStringLiteral("GB_Connexion"));
        GB_Connexion->setGeometry(QRect(710, 10, 201, 111));
        GB_Connexion->setStyleSheet(QLatin1String("QGroupBox#GB_Connexion\n"
"{\n"
"	color:rgb(0, 0, 0);\n"
"}"));
        label = new QLabel(GB_Connexion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 52, 16));
        comboBox = new QComboBox(GB_Connexion);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(71, 30, 112, 20));
        comboBox->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(GB_Connexion);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 161, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        BTN_Timer = new QPushButton(layoutWidget);
        BTN_Timer->setObjectName(QStringLiteral("BTN_Timer"));
        BTN_Timer->setStyleSheet(QLatin1String("QPushButton#BTN_Timer\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"}\n"
"\n"
"QPushButton#BTN_Timer:hover\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}\n"
"\n"
"QPushButton#BTN_Timer:pressed\n"
"{\n"
"	\n"
"}"));

        horizontalLayout_2->addWidget(BTN_Timer);

        BTN_StopTimer = new QPushButton(layoutWidget);
        BTN_StopTimer->setObjectName(QStringLiteral("BTN_StopTimer"));
        BTN_StopTimer->setStyleSheet(QLatin1String("QPushButton#BTN_StopTimer\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"	\n"
"	\n"
"}\n"
"\n"
"QPushButton#BTN_StopTimer:hover\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}\n"
"\n"
"QPushButton#BTN_StopTimer:pressed\n"
"{\n"
"	\n"
"}"));

        horizontalLayout_2->addWidget(BTN_StopTimer);

        layoutWidget1 = new QWidget(GB_Connexion);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 181, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BTN_Connexion = new QPushButton(layoutWidget1);
        BTN_Connexion->setObjectName(QStringLiteral("BTN_Connexion"));
        BTN_Connexion->setStyleSheet(QLatin1String("QPushButton#BTN_Connexion\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"}\n"
"\n"
"QPushButton#BTN_Connexion:hover\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}\n"
"\n"
"QPushButton#BTN_Connexion:pressed\n"
"{\n"
"	\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
""));

        horizontalLayout->addWidget(BTN_Connexion);

        BTN_Deconnexion = new QPushButton(layoutWidget1);
        BTN_Deconnexion->setObjectName(QStringLiteral("BTN_Deconnexion"));
        BTN_Deconnexion->setStyleSheet(QLatin1String("QPushButton#BTN_Deconnexion\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"	\n"
"	\n"
"}\n"
"\n"
"QPushButton#BTN_Deconnexion:hover\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}\n"
"\n"
"QPushButton#BTN_Deconnexion:pressed\n"
"{\n"
"	\n"
"}"));

        horizontalLayout->addWidget(BTN_Deconnexion);

        toolButton = new QToolButton(fen_superviseur);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setEnabled(false);
        toolButton->setGeometry(QRect(920, 10, 25, 19));
        GB_Interrogation = new QGroupBox(fen_superviseur);
        GB_Interrogation->setObjectName(QStringLiteral("GB_Interrogation"));
        GB_Interrogation->setGeometry(QRect(20, 20, 191, 71));
        GB_Interrogation->setStyleSheet(QLatin1String("QGroupBox#GB_Connexion\n"
"{\n"
"	color:rgb(0, 0, 0);\n"
"}"));
        splitter = new QSplitter(GB_Interrogation);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 20, 161, 18));
        splitter->setOrientation(Qt::Horizontal);
        LA_Frequence = new QLabel(splitter);
        LA_Frequence->setObjectName(QStringLiteral("LA_Frequence"));
        splitter->addWidget(LA_Frequence);
        SB_Frequence = new QSpinBox(splitter);
        SB_Frequence->setObjectName(QStringLiteral("SB_Frequence"));
        SB_Frequence->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        SB_Frequence->setMinimum(5);
        SB_Frequence->setMaximum(60);
        SB_Frequence->setSingleStep(5);
        SB_Frequence->setValue(10);
        splitter->addWidget(SB_Frequence);
        splitter_2 = new QSplitter(GB_Interrogation);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(10, 40, 161, 20));
        splitter_2->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(splitter_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        splitter_2->addWidget(label_2);
        comboBox_2 = new QComboBox(splitter_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        splitter_2->addWidget(comboBox_2);
        splitter->raise();
        splitter_2->raise();
        comboBox->raise();
        label->raise();
        label_5 = new QLabel(fen_superviseur);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(350, -30, 341, 201));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        LA_Status = new QLabel(fen_superviseur);
        LA_Status->setObjectName(QStringLiteral("LA_Status"));
        LA_Status->setGeometry(QRect(570, 110, 381, 16));
        listWidget = new QListWidget(fen_superviseur);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(false);
        listWidget->setGeometry(QRect(20, 140, 101, 241));
        toolButton_2 = new QToolButton(fen_superviseur);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(20, 0, 25, 19));
        label_5->raise();
        buttonBox->raise();
        GB_Contenu->raise();
        GB_Connexion->raise();
        toolButton->raise();
        GB_Interrogation->raise();
        LA_Status->raise();
        listWidget->raise();
        toolButton_2->raise();

        retranslateUi(fen_superviseur);
        QObject::connect(buttonBox, SIGNAL(accepted()), fen_superviseur, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fen_superviseur, SLOT(reject()));

        QMetaObject::connectSlotsByName(fen_superviseur);
    } // setupUi

    void retranslateUi(QDialog *fen_superviseur)
    {
        fen_superviseur->setWindowTitle(QApplication::translate("fen_superviseur", "LES VALLONS DE LA TOUR - Superviseur", 0));
        GB_Contenu->setTitle(QApplication::translate("fen_superviseur", "D\303\251butez le programme en cliquant sur \"Commencer\"", 0));
        BTN_getHosts->setText(QApplication::translate("fen_superviseur", "Obtenir les h\303\264tes", 0));
        BTN_getServices->setText(QApplication::translate("fen_superviseur", "Obtenir les services", 0));
        label_3->setText(QApplication::translate("fen_superviseur", "Equipement : ", 0));
        LA_Boucle->setText(QString());
        GB_Connexion->setTitle(QApplication::translate("fen_superviseur", "Connexion \303\240 un collecteur distant", 0));
        label->setText(QApplication::translate("fen_superviseur", "Adresse IP", 0));
        BTN_Timer->setText(QApplication::translate("fen_superviseur", "Commencer", 0));
        BTN_StopTimer->setText(QApplication::translate("fen_superviseur", "Arr\303\252ter", 0));
        BTN_Connexion->setText(QApplication::translate("fen_superviseur", "Connexion", 0));
        BTN_Deconnexion->setText(QApplication::translate("fen_superviseur", "D\303\251connexion", 0));
        toolButton->setText(QApplication::translate("fen_superviseur", "...", 0));
        GB_Interrogation->setTitle(QApplication::translate("fen_superviseur", "Configuration", 0));
        LA_Frequence->setText(QApplication::translate("fen_superviseur", "P\303\251riode de connexion", 0));
        label_2->setText(QApplication::translate("fen_superviseur", "Filtre", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("fen_superviseur", "Erreurs", 0)
         << QApplication::translate("fen_superviseur", "Danger", 0)
         << QApplication::translate("fen_superviseur", "Inconnu", 0)
         << QApplication::translate("fen_superviseur", "Critique", 0)
        );
        label_5->setText(QString());
        LA_Status->setText(QString());
        toolButton_2->setText(QApplication::translate("fen_superviseur", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class fen_superviseur: public Ui_fen_superviseur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEN_SUPERVISEUR_H
