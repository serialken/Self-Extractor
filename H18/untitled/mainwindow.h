#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "qextserialport.h"

#define PORT_COM_KO "MAUVAIS PORT COM"
#define PORT_COM_CASE "LE NOM DU PORT COM DOIT ETRE EN MAJUSCULE"
#define RECUP_COM_FAILED "RECUPERATION DES DEONNEES FAILED"
#define RECUP_COM_OK "RECUPERATION DES DONNEES OK"
#define PORT_COM_USED "PORT COMM DEJA UTILISE"
#define PARSING_KO "PARSING KO"
#define PARSING_OK "PARSING OK"
#define PARSING "IN OPERATION OF PARSING"
#define DATA "GETTING INFORMATION"
#define DATA_ERR "INVALID BOX"
#define DATA_OK "FICHIER SAUVEGARDE."
#define ENDED "OPERATION PARSING TERMINEE"
#define SAVE_DIR "/result/"
#define PARAM_LIST "Sample\tDate\tTime\twbc\tlym%\tmon%\tgran%\tlym#\tmon#\tgran#\trbc\thgb\thct\tmcv\tmch\tmchc\trdw_sd\trdw_cv\tplt\tmpv\tpdw\tpct\tplcr"
#define SEP "\_"
#define WARNING_BOX "WARNING"
#define CRITICAL_BOX "CRITICAL ERROR"
#define INFORMATION_BOX "INFORMATION"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit        MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void            init_signaux();
    void            init_vars();
    boolean         my_save();
    boolean         Parsing_h18(QString &buffer);
    void            set_sample(QString &buffer);
    void            set_date(QString &buffer);
    void            set_time(QString &buffer);
    int             set_wbc_al(QString &buffer);
    int             set_lym_al(QString &buffer, int idx);
    int             set_mon_al(QString &buffer, int idx);
    int             set_gran_al(QString &buffer, int idx);
    int             set_lym2_al(QString &buffer, int idx);
    int             set_mon2_al(QString &buffer, int idx);
    int             set_gran2_al(QString &buffer, int idx);
    int             set_rbc_al(QString &buffer, int idx);
    int             set_hgb_al(QString &buffer, int idx);
    int             set_hct_al(QString &buffer, int idx);
    int             set_mcv_al(QString &buffer, int idx);
    int             set_mch_al(QString &buffer, int idx);
    int             set_mchc_al(QString &buffer, int idx);
    int             set_rdw_sd_al(QString &buffer, int idx);
    int             set_rdw_cv_al(QString &buffer, int idx);
    int             set_plt(QString &buffer, int idx);
    int             set_mpv(QString &buffer, int idx);
    int             set_pdw(QString &buffer, int idx);
    int             set_pct(QString &buffer, int idx);
    int             set_plcr(QString &buffer, int idx);
    int             set_pb_tech(QString &buffer, int idx);
    int             set_pb_patient(QString &buffer, int idx);

public slots:
    void            SLOT_comm_port();

private:
    Ui::MainWindow  *ui;
    QextSerialPort  *port;
    QString         portName;
    QString         pars;
    QString         sample;
    QString         date;
    QString         time;
    QString         wbc;
    QString         lym;
    QString         mon;
    QString         gran;
    QString         lym2;
    QString         mon2;
    QString         gran2;
    QString         rbc;
    QString         hgb;
    QString         hct;
    QString         mcv;
    QString         mch;
    QString         mchc;
    QString         rdw_sd;
    QString         rdw_cv;
    QString         plt;
    QString         mpv;
    QString         pdw;
    QString         pct;
    QString         plcr;
    QChar           wbc_al;
    QChar           lym_al;
    QChar           mon_al;
    QChar           gran_al;
    QChar           lym2_al;
    QChar           mon2_al;
    QChar           gran2_al;
    QChar           rbc_al;
    QChar           hgb_al;
    QChar           hct_al;
    QChar           mcv_al;
    QChar           mch_al;
    QChar           mchc_al;
    QChar           rdw_sd_al;
    QChar           rdw_cv_al;
    QChar           plt_al;
    QChar           mpv_al;
    QChar           pdw_al;
    QChar           pct_al;
    QChar           plcr_al;
};

#endif // MAINWINDOW_H
