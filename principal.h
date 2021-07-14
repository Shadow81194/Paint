#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QDir>
#include <QFileDialog>
#include <QColorDialog>
#include <QInputDialog>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void on_actionGuardar_triggered();

    void on_actionSalir_triggered();

    void on_actionGuardar_2_triggered();

    void on_actionColor_triggered();

    void on_actionAncho_triggered();

private:
    Ui::Principal *ui;
    QImage *m_imagen; //Imagen sobre la cual se va adibujar.
    QPainter *m_painter; //El objeto painter.
    QPoint m_ptInicial;  //Punto Inicial para dibujar.
    QPoint m_ptFinal;    //Punto Final para dibujar.
};
#endif // PRINCIPAL_H
