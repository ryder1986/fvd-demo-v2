#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "videowidget.h"
#include "videosrc.h"
#include "tool1.h"
class VideoThread:public QThread{
public:
    VideoThread(QString src,VideoWidget *w):vs(src.toStdString().data()),wgt(w)
    {

    }
    void run()
    {
        Mat m;
        while(1){

            bool ret=vs.fetch_frame(m);
            if(ret){

                wgt->update_mat(m);
                //wgt->update();
            }else{
                //prt(info,"2");
               // QThread::msleep(100);
            }
            // QThread::sleep(1);
            //   QThread::msleep(40);

        }
    }
private:
    VideoSrc vs;
    VideoWidget *wgt;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoThread *v;

};

#endif // MAINWINDOW_H
