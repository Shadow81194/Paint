#include "principal.h"
#include "ui_principal.h"
#include <QtDebug>
#include <QTextStream>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Instancia del objeto de la imagen
    m_imagen = new QImage(this->size(), QImage::Format_ARGB32_Premultiplied);
    //Rellenar de blanco.
    m_imagen->fill(Qt::white);
    //Instanciar el objeto painter
    m_painter = new QPainter(m_imagen);

}

Principal::~Principal()
{
    delete ui;
}
/**
 * @brief Principal::paintEvent Se ejecutal cada vez que se redibuja la intefaz
 * @param event
 */
void Principal::paintEvent(QPaintEvent *event)
{
    //Crar otro painter (Local).
    QPainter painter(this);
    //Dibujar la imagen.
    painter.drawImage(0,0, *m_imagen);
    //Aceptar el evento.
    event->accept();
}

void Principal::mousePressEvent(QMouseEvent *event)
{
    if(m_opcion == 1){
        m_ptInicial = event->pos();
    }else if (m_opcion == 2){
        if(m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar lineas
            QPen princel;
            princel.setColor(m_Color);
            m_painter->setPen(princel);
            princel.setWidth(m_Ancho);
            m_painter->drawLine(m_ptInicial, m_ptFinal);
            update();
        }
        m_toogle = !m_toogle;
    }else if (m_opcion == 3){
        if(m_toogle){
            m_ptInicial = event->pos();
        }else {
            m_ptFinal = event->pos();
            //Dibujar Retangulo.
            int ancho = m_ptFinal.x() - m_ptInicial.x();
            int alto = m_ptFinal.y() - m_ptFinal.x();

            QPen princel;
            princel.setColor(m_Color);
            m_painter->setPen(princel);
            princel.setWidth(m_Ancho);
            m_painter->drawRect(m_ptInicial.x(), m_ptInicial.y(), ancho, alto);
            //Redibujar la interfac grafica.
            update();
        }
    }else if(m_opcion==4){
        if(m_toogle){
            m_ptInicial = event->pos();
        }else{
            m_ptFinal = event->pos();
            //Creando un circulo
            int anchox=m_ptFinal.x()-m_ptInicial.x();
            int anchoy=m_ptFinal.y()-m_ptInicial.y();

            QPen pincel;
            pincel.setColor(m_Color);
            m_painter->setPen(pincel);
            pincel.setWidth(m_Ancho);
            m_painter->drawEllipse(m_ptInicial.x(),m_ptInicial.y(),anchox,anchoy);

            //Redibujar la interfaz grafica
            update();
        }
    }
    m_toogle = !m_toogle;
}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
    if(m_opcion == 1){
        m_ptFinal = event->pos();
        //Dibujar lineas
        QPen pincel;
        pincel.setColor(m_Color);
        pincel.setWidth(m_Ancho);
        m_painter->setPen(pincel);
        m_painter->drawLine(m_ptInicial, m_ptFinal);
    }
    //Redibujar la intefaz garfica.
    update();
    m_ptInicial = m_ptFinal;
}

void Principal::on_actionGuardar_triggered()
{
    this->nuevo();
}

void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_actionGuardar_2_triggered()
{
    //Crear un objeto Qdir a partir del direcion del usario
    QDir directorio = QDir::home();
    //Agregrar al path absoluto del objeto, un nombre por defeto del archivo
    QString pathArchivo = directorio.absolutePath() + "/sin_nombre.jpg";
    //Abrir un cuadro de dialogo para selecionar el nombre y ubicacion del archivo y guardar.
    QString fileName = QFileDialog::getSaveFileName(this, "* Un nombre para la Ventana *",
                                                    pathArchivo,
                                                    "Archivo imagen (*.jpg)");
    m_imagen->save(fileName);
    ui->statusbar->showMessage("Archivo guarda en" + fileName,3000);
}

void Principal::on_actionColor_triggered()
{
    m_Color = QColorDialog::getColor(Qt::white, this);
}

void Principal::on_actionAncho_triggered()
{
    m_Ancho = QInputDialog::getInt(this,
                                   "Ancho de Principal",
                                   "Ingrese el ancho del pincel de Dibujo",
                                   m_Ancho,
                                   1, 100);
}

void Principal::on_actionLibre_triggered()
{
    m_opcion = 1;
}

void Principal::on_actionLinias_triggered()
{
    m_opcion = 2;
}

void Principal::on_actionRectangulos_triggered()
{
    m_opcion = 3;
}

void Principal::on_actionCircular_triggered()
{
     m_opcion = 4;
}
void Principal::nuevo()
{

}


