/********************************************************************************
** Form generated from reading UI file 'fen_map.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEN_MAP_H
#define UI_FEN_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fen_map
{
public:
    QLabel *label_2;
    QWidget *formLayoutWidget;
    QFormLayout *couche;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QFrame *line;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_Logs;
    QLabel *LA_Logs;
    QTableWidget *TW_Hotes;
    QTextEdit *textEdit;
    QLabel *LA_Satus;
    QLCDNumber *lcdNumber;
    QTableWidget *TW_Services;
    QLabel *label;

    void setupUi(QDialog *fen_map)
    {
        if (fen_map->objectName().isEmpty())
            fen_map->setObjectName(QStringLiteral("fen_map"));
        fen_map->resize(1094, 708);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/LOGOFEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        fen_map->setWindowIcon(icon);
        label_2 = new QLabel(fen_map);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -10, 1171, 481));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/white_wall.jpeg")));
        formLayoutWidget = new QWidget(fen_map);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(90, 550, 371, 131));
        couche = new QFormLayout(formLayoutWidget);
        couche->setObjectName(QStringLiteral("couche"));
        couche->setRowWrapPolicy(QFormLayout::DontWrapRows);
        couche->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(fen_map);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(930, 490, 101, 201));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        line = new QFrame(fen_map);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 460, 1091, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        treeWidget = new QTreeWidget(fen_map);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(10, 210, 281, 241));
        layoutWidget = new QWidget(fen_map);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 500, 161, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PB_Logs = new QPushButton(layoutWidget);
        PB_Logs->setObjectName(QStringLiteral("PB_Logs"));

        horizontalLayout->addWidget(PB_Logs);

        LA_Logs = new QLabel(layoutWidget);
        LA_Logs->setObjectName(QStringLiteral("LA_Logs"));

        horizontalLayout->addWidget(LA_Logs);

        TW_Hotes = new QTableWidget(fen_map);
        TW_Hotes->setObjectName(QStringLiteral("TW_Hotes"));
        TW_Hotes->setGeometry(QRect(310, 210, 371, 241));
        textEdit = new QTextEdit(fen_map);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(480, 500, 431, 181));
        LA_Satus = new QLabel(fen_map);
        LA_Satus->setObjectName(QStringLiteral("LA_Satus"));
        LA_Satus->setGeometry(QRect(90, 500, 86, 16));
        lcdNumber = new QLCDNumber(fen_map);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(220, 500, 64, 23));
        TW_Services = new QTableWidget(fen_map);
        TW_Services->setObjectName(QStringLiteral("TW_Services"));
        TW_Services->setGeometry(QRect(700, 210, 371, 241));
        label = new QLabel(fen_map);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 20, 331, 161));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        LA_Satus->raise();
        lcdNumber->raise();
        layoutWidget->raise();
        label_2->raise();
        formLayoutWidget->raise();
        widget->raise();
        line->raise();
        treeWidget->raise();
        TW_Hotes->raise();
        textEdit->raise();
        TW_Services->raise();
        label->raise();

        retranslateUi(fen_map);

        QMetaObject::connectSlotsByName(fen_map);
    } // setupUi

    void retranslateUi(QDialog *fen_map)
    {
        fen_map->setWindowTitle(QApplication::translate("fen_map", "Vue d'ensemble", 0));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("fen_map", "Lancer", 0));
        PB_Logs->setText(QApplication::translate("fen_map", "LOGS", 0));
        LA_Logs->setText(QString());
        LA_Satus->setText(QApplication::translate("fen_map", "LABEL DE STATUT", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fen_map: public Ui_fen_map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEN_MAP_H
