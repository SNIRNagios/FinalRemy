/********************************************************************************
** Form generated from reading UI file 'fen_accueil.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEN_ACCUEIL_H
#define UI_FEN_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FEN_Accueil
{
public:
    QAction *actionObjectifs;
    QAction *actionVersion;
    QAction *actionNotice_d_utilisation;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *HLAYOUT_AccesSuperviseur;
    QLabel *LA_AccesSuperviseur;
    QSpacerItem *HSPACER_AccesSuperviseur;
    QToolButton *BTN_AccesSuperviseur;
    QGroupBox *GB_Administration;
    QGridLayout *gridLayout_3;
    QVBoxLayout *VLAYOUT_Formulaire;
    QHBoxLayout *HLAYOUT_Utilisateur;
    QLabel *LA_Utilisateur;
    QSpacerItem *HSPACER_Utilisateur;
    QLineEdit *LE_Utilisateur;
    QHBoxLayout *HLAYOUT_MotDePasse;
    QLabel *LA_MotDePasse;
    QSpacerItem *HSPACER_MotDePasse;
    QLineEdit *LE_MotDePasse;
    QHBoxLayout *HLAYOUT_Connexion;
    QSpacerItem *HSPACER_Connexion;
    QPushButton *BTN_Connexion;
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuInformations;
    QStatusBar *SB_Informations;

    void setupUi(QMainWindow *FEN_Accueil)
    {
        if (FEN_Accueil->objectName().isEmpty())
            FEN_Accueil->setObjectName(QStringLiteral("FEN_Accueil"));
        FEN_Accueil->resize(738, 223);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/LOGOFEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        FEN_Accueil->setWindowIcon(icon);
        FEN_Accueil->setDocumentMode(false);
        actionObjectifs = new QAction(FEN_Accueil);
        actionObjectifs->setObjectName(QStringLiteral("actionObjectifs"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/img/1452464446_Message.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionObjectifs->setIcon(icon1);
        actionVersion = new QAction(FEN_Accueil);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/img/1452464368_gnome-help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionVersion->setIcon(icon2);
        actionNotice_d_utilisation = new QAction(FEN_Accueil);
        actionNotice_d_utilisation->setObjectName(QStringLiteral("actionNotice_d_utilisation"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/img/1452464407_address-book.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNotice_d_utilisation->setIcon(icon3);
        centralWidget = new QWidget(FEN_Accueil);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 140, 281, 31));
        HLAYOUT_AccesSuperviseur = new QHBoxLayout(layoutWidget);
        HLAYOUT_AccesSuperviseur->setSpacing(6);
        HLAYOUT_AccesSuperviseur->setContentsMargins(11, 11, 11, 11);
        HLAYOUT_AccesSuperviseur->setObjectName(QStringLiteral("HLAYOUT_AccesSuperviseur"));
        HLAYOUT_AccesSuperviseur->setContentsMargins(0, 0, 0, 0);
        LA_AccesSuperviseur = new QLabel(layoutWidget);
        LA_AccesSuperviseur->setObjectName(QStringLiteral("LA_AccesSuperviseur"));

        HLAYOUT_AccesSuperviseur->addWidget(LA_AccesSuperviseur);

        HSPACER_AccesSuperviseur = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        HLAYOUT_AccesSuperviseur->addItem(HSPACER_AccesSuperviseur);

        BTN_AccesSuperviseur = new QToolButton(layoutWidget);
        BTN_AccesSuperviseur->setObjectName(QStringLiteral("BTN_AccesSuperviseur"));
        BTN_AccesSuperviseur->setStyleSheet(QLatin1String("QToolButton#BTN_AccesSuperviseur\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"	\n"
"}\n"
"\n"
"QToolButton#BTN_AccesSuperviseur:hover\n"
"{\n"
"	background:rgb(114, 140, 255);\n"
"}\n"
"\n"
"QToolButton#BTN_AccesSuperviseur:pressed\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}"));

        HLAYOUT_AccesSuperviseur->addWidget(BTN_AccesSuperviseur);

        GB_Administration = new QGroupBox(centralWidget);
        GB_Administration->setObjectName(QStringLiteral("GB_Administration"));
        GB_Administration->setGeometry(QRect(430, 20, 293, 116));
        gridLayout_3 = new QGridLayout(GB_Administration);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        VLAYOUT_Formulaire = new QVBoxLayout();
        VLAYOUT_Formulaire->setSpacing(6);
        VLAYOUT_Formulaire->setObjectName(QStringLiteral("VLAYOUT_Formulaire"));
        HLAYOUT_Utilisateur = new QHBoxLayout();
        HLAYOUT_Utilisateur->setSpacing(6);
        HLAYOUT_Utilisateur->setObjectName(QStringLiteral("HLAYOUT_Utilisateur"));
        LA_Utilisateur = new QLabel(GB_Administration);
        LA_Utilisateur->setObjectName(QStringLiteral("LA_Utilisateur"));

        HLAYOUT_Utilisateur->addWidget(LA_Utilisateur);

        HSPACER_Utilisateur = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        HLAYOUT_Utilisateur->addItem(HSPACER_Utilisateur);

        LE_Utilisateur = new QLineEdit(GB_Administration);
        LE_Utilisateur->setObjectName(QStringLiteral("LE_Utilisateur"));

        HLAYOUT_Utilisateur->addWidget(LE_Utilisateur);


        VLAYOUT_Formulaire->addLayout(HLAYOUT_Utilisateur);

        HLAYOUT_MotDePasse = new QHBoxLayout();
        HLAYOUT_MotDePasse->setSpacing(6);
        HLAYOUT_MotDePasse->setObjectName(QStringLiteral("HLAYOUT_MotDePasse"));
        LA_MotDePasse = new QLabel(GB_Administration);
        LA_MotDePasse->setObjectName(QStringLiteral("LA_MotDePasse"));

        HLAYOUT_MotDePasse->addWidget(LA_MotDePasse);

        HSPACER_MotDePasse = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        HLAYOUT_MotDePasse->addItem(HSPACER_MotDePasse);

        LE_MotDePasse = new QLineEdit(GB_Administration);
        LE_MotDePasse->setObjectName(QStringLiteral("LE_MotDePasse"));
        LE_MotDePasse->setEchoMode(QLineEdit::Password);

        HLAYOUT_MotDePasse->addWidget(LE_MotDePasse);


        VLAYOUT_Formulaire->addLayout(HLAYOUT_MotDePasse);

        HLAYOUT_Connexion = new QHBoxLayout();
        HLAYOUT_Connexion->setSpacing(6);
        HLAYOUT_Connexion->setObjectName(QStringLiteral("HLAYOUT_Connexion"));
        HSPACER_Connexion = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        HLAYOUT_Connexion->addItem(HSPACER_Connexion);

        BTN_Connexion = new QPushButton(GB_Administration);
        BTN_Connexion->setObjectName(QStringLiteral("BTN_Connexion"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(186, 186, 186, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 196, 221, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(243, 145, 186, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(115, 47, 76, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(154, 62, 101, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(243, 174, 203, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush9(QColor(231, 94, 152, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        BTN_Connexion->setPalette(palette);
        BTN_Connexion->setStyleSheet(QLatin1String("QPushButton#BTN_Connexion\n"
"{\n"
"	background:rgb(186, 186, 186);\n"
"	\n"
"}\n"
"\n"
"QPushButton#BTN_Connexion:hover\n"
"{\n"
"	background:rgb(94, 94, 94);\n"
"}\n"
"\n"
"QPushButton#BTN_Connexion:pressed\n"
"{\n"
"	background:rgb(114, 140, 255);\n"
"	\n"
"}"));
        BTN_Connexion->setCheckable(false);

        HLAYOUT_Connexion->addWidget(BTN_Connexion);


        VLAYOUT_Formulaire->addLayout(HLAYOUT_Connexion);


        gridLayout_3->addLayout(VLAYOUT_Formulaire, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 631, 181));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(390, 30, 20, 131));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 741, 211));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/white_wall.jpeg")));
        FEN_Accueil->setCentralWidget(centralWidget);
        label_2->raise();
        label->raise();
        layoutWidget->raise();
        GB_Administration->raise();
        line->raise();
        menuBar = new QMenuBar(FEN_Accueil);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 738, 21));
        menuInformations = new QMenu(menuBar);
        menuInformations->setObjectName(QStringLiteral("menuInformations"));
        FEN_Accueil->setMenuBar(menuBar);
        SB_Informations = new QStatusBar(FEN_Accueil);
        SB_Informations->setObjectName(QStringLiteral("SB_Informations"));
        FEN_Accueil->setStatusBar(SB_Informations);

        menuBar->addAction(menuInformations->menuAction());
        menuInformations->addAction(actionVersion);
        menuInformations->addSeparator();
        menuInformations->addAction(actionObjectifs);
        menuInformations->addAction(actionNotice_d_utilisation);

        retranslateUi(FEN_Accueil);

        QMetaObject::connectSlotsByName(FEN_Accueil);
    } // setupUi

    void retranslateUi(QMainWindow *FEN_Accueil)
    {
        FEN_Accueil->setWindowTitle(QApplication::translate("FEN_Accueil", "LES VALLONS DE LA TOUR - Accueil", 0));
        actionObjectifs->setText(QApplication::translate("FEN_Accueil", "Objectifs", 0));
#ifndef QT_NO_TOOLTIP
        actionObjectifs->setToolTip(QApplication::translate("FEN_Accueil", "Le but du projet", 0));
#endif // QT_NO_TOOLTIP
        actionVersion->setText(QApplication::translate("FEN_Accueil", "Version", 0));
        actionNotice_d_utilisation->setText(QApplication::translate("FEN_Accueil", "Notice d'utilisation", 0));
        LA_AccesSuperviseur->setText(QApplication::translate("FEN_Accueil", "Acc\303\251s au superviseur", 0));
        BTN_AccesSuperviseur->setText(QApplication::translate("FEN_Accueil", "...", 0));
        GB_Administration->setTitle(QApplication::translate("FEN_Accueil", "Administration", 0));
        LA_Utilisateur->setText(QApplication::translate("FEN_Accueil", "Utilisateur", 0));
        LE_Utilisateur->setText(QApplication::translate("FEN_Accueil", "Admin", 0));
        LA_MotDePasse->setText(QApplication::translate("FEN_Accueil", "Mot de passe", 0));
        LE_MotDePasse->setInputMask(QString());
        LE_MotDePasse->setText(QApplication::translate("FEN_Accueil", "Admin", 0));
        BTN_Connexion->setText(QApplication::translate("FEN_Accueil", "Connexion", 0));
        label->setText(QString());
        label_2->setText(QString());
        menuInformations->setTitle(QApplication::translate("FEN_Accueil", "Informations", 0));
    } // retranslateUi

};

namespace Ui {
    class FEN_Accueil: public Ui_FEN_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEN_ACCUEIL_H
