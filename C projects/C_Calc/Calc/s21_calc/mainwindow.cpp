#include "mainwindow.h"

#include "ui_mainwindow.h"
extern "C" {
#include "../s21_calc.c"
#include "../s21_calc.h"
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() { ui->lineEdit_2->insert("1"); }

void MainWindow::on_pushButton_2_clicked() { ui->lineEdit_2->insert("2"); }

void MainWindow::on_pushButton_3_clicked() { ui->lineEdit_2->insert("3"); }

void MainWindow::on_pushButton_4_clicked() { ui->lineEdit_2->insert("4"); }

void MainWindow::on_pushButton_5_clicked() { ui->lineEdit_2->insert("5"); }

void MainWindow::on_pushButton_6_clicked() { ui->lineEdit_2->insert("6"); }

void MainWindow::on_pushButton_7_clicked() { ui->lineEdit_2->insert("7"); }

void MainWindow::on_pushButton_8_clicked() { ui->lineEdit_2->insert("8"); }

void MainWindow::on_pushButton_9_clicked() { ui->lineEdit_2->insert("9"); }

void MainWindow::on_pushButton_0_clicked() { ui->lineEdit_2->insert("0"); }

void MainWindow::on_pushButton_11_clicked() { ui->lineEdit_2->insert("("); }

void MainWindow::on_pushButton_12_clicked() { ui->lineEdit_2->insert(")"); }

void MainWindow::on_pushButton_10_clicked() { ui->lineEdit_2->backspace(); }

void MainWindow::on_pushButton_1_clicked() { ui->lineEdit_2->insert("."); }

void MainWindow::on_pushButton_13_clicked() { ui->lineEdit_2->insert("mod"); }

void MainWindow::on_pushButton_14_clicked() { ui->lineEdit_2->insert("+"); }

void MainWindow::on_pushButton_15_clicked() { ui->lineEdit_2->insert("-"); }

void MainWindow::on_pushButton_16_clicked() { ui->lineEdit_2->insert("*"); }

void MainWindow::on_pushButton_17_clicked() { ui->lineEdit_2->insert("/"); }

void MainWindow::on_pushButton_18_clicked() { ui->lineEdit_2->insert("^"); }

void MainWindow::on_pushButton_20_clicked() { ui->lineEdit_2->insert("cos"); }

void MainWindow::on_pushButton_21_clicked() { ui->lineEdit_2->insert("sin"); }

void MainWindow::on_pushButton_22_clicked() { ui->lineEdit_2->insert("tan"); }

void MainWindow::on_pushButton_23_clicked() { ui->lineEdit_2->insert("ln"); }

void MainWindow::on_pushButton_24_clicked() { ui->lineEdit_2->insert("log"); }

void MainWindow::on_pushButton_25_clicked() { ui->lineEdit_2->insert("acos"); }

void MainWindow::on_pushButton_26_clicked() { ui->lineEdit_2->insert("asin"); }

void MainWindow::on_pushButton_27_clicked() { ui->lineEdit_2->insert("atan"); }

void MainWindow::on_pushButton_28_clicked() {
  ui->lineEdit_2->insert("sqrt");
  ui->lineEdit_2->insert("qwe");
}

void MainWindow::on_pushButton_19_clicked() {
  QString str_1 = ui->lineEdit_2->text();
  char cstr[260] = "";
  strcpy(cstr, str_1.toLatin1().constData());
  //    std::string str_c = str_1.toStdString();
  //    char *cstr = new char(str_c.length()+1);
  //    strcpy(cstr,str_c.c_str());
  QString q_x = ui->doubleSpinBox_5->text();
  std::string str_x = q_x.toStdString();
  double x = atof(str_x.c_str());
  char *check = parse(cstr, x);
  ui->lineEdit_2->clear();
  ui->lineEdit_2->insert(check);
  free(check);
}

void MainWindow::on_pushButton_29_clicked() { ui->lineEdit_2->insert("x"); }

void MainWindow::on_pushButton_30_clicked() { ui->lineEdit_2->clear(); }

void MainWindow::on_pushButton_31_clicked() {
  QString a_X = ui->doubleSpinBox->text();
  std::string str_aX = a_X.toStdString();
  double aX(std::stod(str_aX));
  QString b_X = ui->doubleSpinBox_2->text();
  std::string str_bX = b_X.toStdString();
  double bX(std::stod(str_bX));
  QString a_Y = ui->doubleSpinBox_3->text();
  std::string str_aY = a_Y.toStdString();
  double aY(std::stod(str_aY));
  QString b_Y = ui->doubleSpinBox_4->text();
  std::string str_bY = b_Y.toStdString();
  double bY(std::stod(str_bY));
  double h = 0.001;
  int n = (bX - aX) / h + 2;
  QVector<double> x(n - 1), y(n - 1);
  QString str_fun = ui->lineEdit_2->text();
  char c_str[260] = "";
  strcpy(c_str, str_fun.toLatin1().constData());
  int i = 0;
  int flag = 0;
  std::string check_x;
  for (float X = aX; X <= bX; X += h, X = round(X * 1000000) / 1000000) {
    char *check = parse(c_str, X);
    if (strcmp(check, "Wrong") != 0 &&
        strcmp(check, "Oshibka vichisleniya") != 0) {
      double X_1(std::stod(check));
      if (X_1 != 0 && X != 0) {
        x[i] = X;
        y[i] = X_1;
        i++;
        flag = 1;
      }
    }
    free(check);
  }
  if (flag == 1) {
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(aX, bX);
    ui->widget->yAxis->setRange(aY, bY);
    ui->widget->replot();
  }
}
