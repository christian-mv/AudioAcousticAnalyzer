#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DevicesInfoDialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/media/general_icon.png"));

    series = new QLineSeries();
    series->useOpenGL();
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

    for(int i=0; i<myPortAudioWrapper.data->numSamples;i+=2){
        series->append(i, myPortAudioWrapper.data->recordedSamples[i]);
    }


    // Create chart, add data, hide legend, and add axis
    QChart *chart = new QChart();

    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();

    // Customize the title font
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::black));
    chart->setTitle("y(t)");

    // Change the line color and weight
    QPen pen(Qt::blue);
    pen.setWidth(0.5);
    series->setPen(pen);

//    chart->setAnimationOptions(QChart::AllAnimations);

//    // Change the x axis categories
//    QCategoryAxis *axisX = new QCategoryAxis();
//    axisX->append("1986",0);
//    axisX->append("1987",1);
//    axisX->append("1988",2);
//    axisX->append("1989",3);
//    axisX->append("1990",4);
//    axisX->append("1991",5);
//    axisX->append("1992",6);
//    chart->setAxisX(axisX, series);

    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setParent(this);
    setCentralWidget(chartView);
//    chartView->setRenderHint(QPainter::Antialiasing);
    chart->show();
}
