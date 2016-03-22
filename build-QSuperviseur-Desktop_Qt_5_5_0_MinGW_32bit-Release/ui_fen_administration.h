/********************************************************************************
** Form generated from reading UI file 'fen_administration.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEN_ADMINISTRATION_H
#define UI_FEN_ADMINISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_fen_administration
{
public:

    void setupUi(QDialog *fen_administration)
    {
        if (fen_administration->objectName().isEmpty())
            fen_administration->setObjectName(QStringLiteral("fen_administration"));
        fen_administration->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/img/LOGOFEN.png"), QSize(), QIcon::Normal, QIcon::Off);
        fen_administration->setWindowIcon(icon);

        retranslateUi(fen_administration);

        QMetaObject::connectSlotsByName(fen_administration);
    } // setupUi

    void retranslateUi(QDialog *fen_administration)
    {
        fen_administration->setWindowTitle(QApplication::translate("fen_administration", "LES VALLONS DE LA TOUR - Administration", 0));
    } // retranslateUi

};

namespace Ui {
    class fen_administration: public Ui_fen_administration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEN_ADMINISTRATION_H
