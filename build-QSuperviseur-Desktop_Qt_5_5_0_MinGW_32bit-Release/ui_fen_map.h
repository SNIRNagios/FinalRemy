/********************************************************************************
** Form generated from reading UI file 'fen_map.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
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
    QSplitter *splitter;
    QLabel *LA_Satus;
    QLCDNumber *lcdNumber;
    QTextEdit *textEdit;
    QTreeWidget *treeWidget;

    void setupUi(QDialog *fen_map)
    {
        if (fen_map->objectName().isEmpty())
            fen_map->setObjectName(QStringLiteral("fen_map"));
        fen_map->resize(620, 340);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/LOGOFEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        fen_map->setWindowIcon(icon);
        label_2 = new QLabel(fen_map);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, -10, 621, 301));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/white_wall.jpeg")));
        formLayoutWidget = new QWidget(fen_map);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 291, 281));
        couche = new QFormLayout(formLayoutWidget);
        couche->setObjectName(QStringLiteral("couche"));
        couche->setRowWrapPolicy(QFormLayout::DontWrapRows);
        couche->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(fen_map);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(510, 10, 101, 291));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        line = new QFrame(fen_map);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 290, 621, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        splitter = new QSplitter(fen_map);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(10, 310, 601, 23));
        splitter->setOrientation(Qt::Horizontal);
        LA_Satus = new QLabel(splitter);
        LA_Satus->setObjectName(QStringLiteral("LA_Satus"));
        splitter->addWidget(LA_Satus);
        lcdNumber = new QLCDNumber(splitter);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        splitter->addWidget(lcdNumber);
        textEdit = new QTextEdit(splitter);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setAutoFormatting(QTextEdit::AutoNone);
        textEdit->setLineWrapColumnOrWidth(0);
        textEdit->setReadOnly(true);
        splitter->addWidget(textEdit);
        treeWidget = new QTreeWidget(fen_map);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(320, 11, 291, 281));
        splitter->raise();
        label_2->raise();
        formLayoutWidget->raise();
        widget->raise();
        line->raise();
        treeWidget->raise();

        retranslateUi(fen_map);

        QMetaObject::connectSlotsByName(fen_map);
    } // setupUi

    void retranslateUi(QDialog *fen_map)
    {
        fen_map->setWindowTitle(QApplication::translate("fen_map", "Vue d'ensemble", 0));
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("fen_map", "Lancer", 0));
        LA_Satus->setText(QApplication::translate("fen_map", "LABEL DE STATUT", 0));
    } // retranslateUi

};

namespace Ui {
    class fen_map: public Ui_fen_map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEN_MAP_H
