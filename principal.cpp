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
    m_ptInicial = event->pos();
}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
    m_ptFinal = event->pos();
    QPen pincel;
    //pincel.setColor(Qt::red);
    m_painter->setPen(pincel);
    m_painter->drawLine(m_ptInicial, m_ptFinal);
    //Redibujar la intefaz garfica.
    update();
    m_ptInicial = m_ptFinal;
}


void Principal::on_actionGuardar_triggered()
{

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
    //Grear el archivo a partir de nombre arrojado por el cuadro de dialogo.
    QFile f(fileName);
    //Crar el objeto QTexStream (permitir ecribir sobre el archivo).
    QTextStream out(&f);
    //Guaradr el conteido del testo del resutado en el archivo.

    //Cerrar el archivo.
    f.close();
    ui->statusbar->showMessage("Archivo guarda en" + fileName,3000);
}

void Principal::on_actionColor_triggered()
{
    QColor color;
   color = QColorDialog::getColor(Qt::white, this);
   update();
}

void Principal::on_actionAncho_triggered()
{
    int n = QInputDialog::getInt(this, "Ancho de Principal", "Ingrese el ancho del pincel de Dibujo");
    ui->actionAncho->setText(QString::number(n));
}
