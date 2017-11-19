#include "ctdialog.h"
#include <QPushButton>
#include <titlebar.h>
#include <innerdialog.h>
#include <QPainter>
CTDialog::CTDialog(QWidget *parent) :
    QDialog(parent)
{

    isMoving = false;
    
    this->setContentsMargins(0,0,0,0);
    
    this->layout = new QGridLayout(this);
    this->layout->setMargin(4);
    this->layout->setSpacing(0);
    this->layout->setSizeConstraint(QLayout::SetMinimumSize);
    
    this->titlebar = new TitleBar(this);
    this->layout->addWidget(this->titlebar);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->client = new InnerDialog(this);
    this->client->setMouseTracking(true);

    this->client->setWindowFlags(Qt::FramelessWindowHint|Qt::CustomizeWindowHint);

    this->layout->addWidget(this->client);
    connect(this->client,SIGNAL(finished(int)),this,SLOT(done(int)));
    connect(this->client,SIGNAL(accepted()),this,SLOT(accept()));
    connect(this->client,SIGNAL(rejected()),this,SLOT(reject()));

    m_mouse_down = false;
    setMouseTracking(true);
    this->client->show();
}

CTDialog::~CTDialog()
{
    delete this->titlebar;
    delete this->client;
    delete this->layout;
}

InnerDialog *CTDialog::clientWnd()
{
    return this->client;
}

TitleBar * CTDialog::titleBar()
{
    return this->titlebar;
}


void CTDialog::setWindowTitle(const QString &title)
{
    this->titleBar()->setTitle(title);
    this->QDialog::setWindowTitle(title);
}


void CTDialog::mousePressEvent(QMouseEvent *e)
{
    m_old_pos = e->pos();
    m_mouse_down = e->button() == Qt::LeftButton;
    if(m_mouse_down){
        int x = e->x();
        int y = e->y();
        QRect r = rect();
        left = qAbs(x - r.left()) <= 5;
        right = qAbs(x - r.right()) <= 5;
        bottom = qAbs(y - r.bottom()) <= 5;
    }

    //qDebug("MouseDown");
}

void CTDialog::mouseMoveEvent(QMouseEvent *e)
{
    
    if(isMoving)
        return ;
    if(this->isMaximized())
        return;
    static int i = 0;
    //qDebug("MouseMove %d",i++);
    int x = e->x();
    int y = e->y();

    if (m_mouse_down) {
        int dx = x - m_old_pos.x();
        int dy = y - m_old_pos.y();

        QRect preGeometry;
        QRect g = geometry();
        preGeometry = g;
        
        if(right){
            bool right_invalid_move = this->width()  <= this->minimumWidth() && dx < 0 
                    || this->width() >= this->maximumWidth()  && dx >0;
            if(!right_invalid_move) {
                g.setRight(g.right() + dx);
                m_old_pos.setX(e->x());
                qDebug("%d:%d",this->width(),this->maximumWidth());
            }   
        }


        if(left){
            bool left_invalid_move = this->width() -dx/*加dx是为了提前计算是否移动*/ <= this->minimumWidth() && dx > 0
                    || this->width() >= this->maximumWidth() + dx && dx < 0;
            if(!left_invalid_move) {
                g.setLeft(g.left() + dx);
                //g.setRight(preGeometry.right());
                m_old_pos.setX(e->x() - dx);
                
                qDebug("e->x %d",e->x());
            }
        }
        
        if(bottom) {
            bool bottom_invalid_move = this->height()  <= this->minimumHeight() && dy <0
                || this->height() >= this->maximumHeight()  && dy > 0;
            if(!bottom_invalid_move) {
                g.setBottom(g.bottom() + dy);
                m_old_pos.setY( e->y() );
            }
            //m_old_pos.setY(e->y());
        }
        isMoving = true;
        
        setGeometry(g);
        this->update();
        isMoving = false;


        //m_old_pos = QPoint(!left ? e->x() : m_old_pos.x(), e->y());
    } else {
        QRect r = rect();
        int left = qAbs(x - r.left()) <= 5;
        int right = qAbs(x - r.right()) <= 5;
        int bottom = qAbs(y - r.bottom()) <= 5;
        bool hor = left | right;
        if (left && bottom) {
            setCursor(Qt::SizeBDiagCursor);
        } else if(right && bottom) {
            setCursor(Qt::SizeFDiagCursor);
        } else if (hor) {
            setCursor(Qt::SizeHorCursor);
        } else if (bottom) {
            setCursor(Qt::SizeVerCursor);
        } else {
            setCursor(Qt::ArrowCursor);
        }

    }
}

void CTDialog::mouseReleaseEvent(QMouseEvent *e)
{
    m_mouse_down = false;
    left = false;
    right = false;
    bottom = false;

}

void CTDialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(0xA0,0xA0,0xA0));
    painter.setPen(pen);
    painter.drawRect(0,0,this->width()-1,this->height()-1);
    painter.end();

}
