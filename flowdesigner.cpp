#include <QDrag>
#include <QMimeData>
#include <QPixmap>

#include "mainwindow.h"

#include "flowdesigner.h"
#include "designeritem.h"

#include "flowitem.h"

FlowDesigner::FlowDesigner(QWidget *parent)
    : QGraphicsView (parent)
{
    myscene = new Scene(this);
    myscene->setSceneRect(0,0,1000,1000);

    setScene(myscene);
    setAcceptDrops(true);

    setDragMode(QGraphicsView::RubberBandDrag);
}

void FlowDesigner::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}

void FlowDesigner::dropEvent(QDropEvent *event)
{
//    textBrowser->setPlainText(event->mimeData()->text());
//    mimeTypeCombo->clear();
//    mimeTypeCombo->addItems(event->mimeData()->formats());

    //if (event->mimeData()->text() == QString("Flow:Data"))
    {
        QPixmap pix(":/images/flowchart-symbol-data.png");
	if (!pix) {
	    QMessageBox::information(main_window,
	    "Load Error",
	    "Drag&Drop internal resource could not be loaded.");
	    return;
	}

	if (!myscene) {
	    QMessageBox::information(main_window,
	    "Internal Error",
	    "object scene sent error.");
	    return;
	}

	DesignerPixmapItem * pix1 = new
	DesignerPixmapItem(pix,QRect(30,30,100,56),myscene);

/*
	FlowPixmapItem *ptr_pix;
	ptr_pix = reinterpret_cast<FlowPixmapItem *>(myscene->addPixmap(pix));
	if (!ptr_pix) {
	    QMessageBox::information(main_window,
	    "Internal Error 2",
	    "pixmap item pointer == null");
	    return;
	}
*/
        //DesignerRadioButtonItem *radio = new
        //DesignerRadioButtonItem(QString("FooBar"),QRect(30,30,150,40),myscene);

    }
    event->acceptProposedAction();
}
