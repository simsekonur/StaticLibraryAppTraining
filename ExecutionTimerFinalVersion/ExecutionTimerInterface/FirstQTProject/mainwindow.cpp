#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include<unistd.h>
#include"ExecResult.h"
#include<iostream>
#define PORT 8083

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Execution Timer");
    QPixmap bkgnd("/home/onur/Pictures/den.png");
    bkgnd = bkgnd.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,bkgnd);
    this->setPalette(palette);
    QStringList titles;
    titles << "FUNCTION NAME" << "EXECUTION TIME";
    ui->tableWidget->setHorizontalHeaderLabels(titles);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
        int sockfd, connfd, len;
        struct sockaddr_in servaddr, cli;

        // socket create and verification
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket creation");
            exit(0);
        }
        else
            printf("Socket successfully created..\n");
        bzero(&servaddr, sizeof(servaddr));

        // assign IP, PORT
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = (INADDR_ANY);
        servaddr.sin_port = htons(PORT);

        // Binding newly created socket to given IP and verification
        if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
            perror("socket bind failed...\n");

            exit(0);
        }
        else
            printf("Socket successfully binded..\n");

        // Now server is ready to listen and verification
        if ((listen(sockfd, 5)) != 0) {
            perror("Listen failed...\n");
            exit(0);
        }
        else
            printf("Server listening..\n");
        len = sizeof(cli);
        int len2 =sizeof(servaddr);

        // Accept the data packet from client and verification
        connfd = accept(sockfd, (struct sockaddr *)&cli, (socklen_t*)&len);//can also be len2
        if (connfd < 0) {
            printf("server acccept failed...\n");
            exit(0);
        }
        else
            printf("server acccept the client...\n");



        //As an alternative,I will try object version
	int receive;
        int i = 0;
        QString space{": "};
        QString p{") "};
	myExecResult results;
        while ((receive = recv(connfd,(void *)&results,sizeof(results),0) )>0 ){

            //ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,0,new QTableWidgetItem(results.funcName));
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1,1,new QTableWidgetItem(QString::number(results.difference)));

           // ui->listWidget->addItem(QString::number(i+1)+p+ results.funcName +space +QString::number(results.difference));
            std::cout << results.funcName << " : " << results.difference << std::endl;
            i++;

        }


        sleep(3);



}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
}
