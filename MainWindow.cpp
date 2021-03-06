#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DevicesInfoDialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/media/general_icon.png"));

    initQchart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDevices_triggered()
{
    devicesWidget = new DevicesInfoDialog(this, this->myPortAudioWrapper);

    devicesWidget->setWindowTitle( tr(" Audio Devices - "
                                MY_APP_NAME " V" VERSION_OF_APP ));
    devicesWidget->exec();
}


void MainWindow::on_actionRecord_triggered()
{
    myPortAudioWrapper.record();
    plot();
}

void MainWindow::on_actionPlay_triggered()
{
    myPortAudioWrapper.play();
}

void MainWindow::on_actionPlot_triggered()
{

}

void MainWindow::plot()
{
    QList<QPointF> points;
    QPointF p;
    for(int i=0; i<2*5*22050;i+=2){
        p.setX(i);
        p.setY(myPortAudioWrapper.data->recordedSamples[i]);
        points.push_back(p);
//        m_series->replace(i,QPointF(i, myPortAudioWrapper.data->recordedSamples[i]));
    }
    m_series->replace(points);

}

void MainWindow::initQchart()
{
    m_chart = new QChart();
    m_series = new QLineSeries;
    int i;
    for(i=0; i<2*5*22050; i+=2){
//        m_series->append(i);
        m_series->insert(i,QPointF(0,0));
    }

    QChartView *chartView = new QChartView(m_chart);
    chartView->setMinimumSize(800, 600);
    m_chart->addSeries(m_series);qDebug()<<"HERE";
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, i);
    axisX->setLabelFormat("%g");
    axisX->setTitleText("Samples");
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-1, 1);
    axisY->setTitleText("Audio level");
    m_chart->setAxisX(axisX, m_series);
    m_chart->setAxisY(axisY, m_series);
    m_chart->legend()->hide();
    m_chart->setTitle("y(t)");
    QPen pen(Qt::blue);
    pen.setWidth(0.5);
    m_series->setPen(pen);


    setCentralWidget(chartView);

}
