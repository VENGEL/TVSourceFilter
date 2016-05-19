#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnGetPath_clicked()
{
    std::string strName;

    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("Allfile(*.*);;txtfile(*.txt)"));

    strName = fileName.toStdString();

    ui->TxtFilePath->setText(strName.c_str());
}

void MainWindow::on_BtnGetInfo_clicked()
{
    std::string name = ui->TxtFilePath->toPlainText().toStdString();
    if (m_Filter.LoadText(name))
    {
        // TODO: Load the urls to table view.
       std::uint32_t UrlCnt = m_Filter.GetUrlCount();
       if (UrlCnt > 0)
       {
            ui->TableInfo->setRowCount(UrlCnt);
            ui->TableInfo->setColumnCount(3);

            std::vector<TVUrl_t>& urls = m_Filter.GetInputUrl();

            for (std::uint32_t i = 0; i < urls.size(); i++)
            {
                ui->TableInfo->setItem(i, 0, new QTableWidgetItem(urls[i].name.c_str()));
                ui->TableInfo->setItem(i, 1, new QTableWidgetItem(urls[i].url.c_str()));
            }
       }
        // TODO: To check the url available.
    }
}
