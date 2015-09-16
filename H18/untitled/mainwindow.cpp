#include "mainwindow.h"
#include "ui_mainwindow.h"


boolean             MainWindow::my_save()
{
    QDir current_dir;
    QString tmp;
    QString name_res;
    QString dir_name;
    QString dir_file;
    QFileInfo *my_path;


    current_dir = QDir::currentPath();
    tmp += current_dir.path() + SAVE_DIR;
    my_path = new QFileInfo(tmp);
    if (my_path->exists() == true)
    {
        if (my_path->isDir() == true)
        {
            // ici je vais creer les CSV
            if ((current_dir.cd("result")) == true)
            {
                //changement de rep ok
                name_res += sample + "_" + date + "_" + time ;
                QFile NEW_MY_FILE(current_dir.filePath(name_res));
                if (NEW_MY_FILE.open(QIODevice::WriteOnly))
                {
                    //on va inserer les donnees
                    QTextStream flux(&NEW_MY_FILE);
                    //flux << PARAM_LIST << endl;
                    flux << sample << "\t" << date << "\t" << time << "\t" << wbc << "\t" << lym << "\t" << mon << "\t" << gran << "\t" << lym2 << "\t" << mon2 << "\t" << gran2 << "\t" << rbc << "\t" << hgb << "\t" << hct << "\t" << mcv << "\t" << mch << "\t" << mchc << "\t" << rdw_sd << "\t" << rdw_cv << "\t" << plt << "\t" << mpv << "\t" << pdw << "\t" << pct << "\t" << plcr << endl;
                    NEW_MY_FILE.close();
                    return true;
                }
                else
                {
                    //ouverture fichier foirer so sauvegarde oci ==> msg d'erreur dans  bulle

                    return false;
                }
            }
            else
            {
                //changement de repertoire failed
                return false;
            }
        }
        else
        {

            //le chemin  exist mais c pas un repertoire ==> msg d'erreur dans bulle
            return false;
        }
    }
    else
    {
        // le chemin n'existe pas faudra le creer
        my_path = new QFileInfo(current_dir.path());
        if (current_dir.mkdir("result") == true)
        {
            //la creation du rep a marcher on va y mettre les CSV
            if (current_dir.cd("result") == true)
            {
                //changement de rep ok
                name_res += sample + "_" + date + "_" + time;
                QFile NEW_MY_FILE(current_dir.filePath(name_res));
                if (NEW_MY_FILE.open(QIODevice::ReadWrite))
                {
                    //on va inserer les donnees
                    QTextStream flux(&NEW_MY_FILE);
                    //flux << PARAM_LIST << endl;
                    flux << sample << "\t" << date << "\t" << time << "\t" << wbc << "\t" << lym << "\t" << mon << "\t" << gran << "\t" << lym2 << "\t" << mon2 << "\t" << gran2 << "\t" << rbc << "\t" << hgb << "\t" << hct << "\t" << mcv << "\t" << mch << "\t" << mchc << "\t" << rdw_sd << "\t" << rdw_cv << "\t" << plt << "\t" << mpv << "\t" << pdw << "\t" << pct << "\t" << plcr << endl;
                    NEW_MY_FILE.close();
                    return true;
                }
                else
                {
                    //ouverture fichier foirer so sauvegarde oci ==> msg d'erreur dans un label
                    return false;
                }
            }
            else
            {
                //changement de repertoire a foirer
                return false;
            }
        }
        else
        {
            //la creation du repertoire a foirer du coup la sauvegarde oci ==>msg d'erreur dans un label
            return false;
        }

    }

}

void            MainWindow::set_sample(QString &buffer)
{
    //qDebug() << "I'm sample!\n";
    int idx = 2;
    while (idx != 11)
    {
        sample += buffer[idx];
        idx++;
    }

    ui->L_Sample->setText(sample);
    ui->L_Sample->setReadOnly(true);
}

void            MainWindow::set_date(QString &buffer)
{
    //qDebug() << "I'm date!\n";
    int idx = 11;
    while (idx != 19)
    {
        date += buffer[idx];
        idx++;
    }
    ui->L_Date->setText(date);
    ui->L_Date->setReadOnly(true);
}

void            MainWindow::set_time(QString &buffer)
{
    // qDebug() << "I'm time!\n";
    int idx = 19;
    while (idx != 25)
    {
        time += buffer[idx];
        idx++;
    }
    ui->L_Time->setText(time);
    ui->L_Time->setReadOnly(true);
}

int            MainWindow::set_wbc_al(QString &buffer)
{
    // qDebug() << "I'm WBC! ";
    int flag = 0;
    int idx = 25;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        wbc += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            wbc += ",";
        }
        idx++;
        flag++;
    }

    wbc_al = buffer[idx];
    if (wbc_al == 'h')
        ui->Alarm1->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (wbc_al == 'l')
        ui->Alarm1->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_WBC->setText(wbc);
    ui->L_WBC->setReadOnly(true);
    return (idx + 1);
}

int           MainWindow::set_lym_al(QString &buffer, int idx)
{
    //qDebug() << "I'm LYM1! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        lym += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            lym += ",";
        }
        idx++;
        flag++;
    }

    lym_al = buffer[idx];
    if (lym_al == 'h')
        ui->Alarm1_2->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (lym_al == 'l')
        ui->Alarm1_2->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_LYM->setText(lym);
    ui->L_LYM->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_mon_al(QString &buffer, int idx)
{
    // qDebug() << "I'm MON1! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mon += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            mon += ",";
        }
        idx++;
        flag++;
    }

    mon_al = buffer[idx];
    if (mon_al == 'h')
        ui->Alarm1_3->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mon_al == 'l')
        ui->Alarm1_3->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MID->setText(mon);
    ui->L_MID->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_gran_al(QString &buffer, int idx)
{
    // qDebug() << "I'm GRAN1! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        gran += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            gran += ",";
        }
        idx++;
        flag++;
    }

    gran_al = buffer[idx];
    if (gran_al == 'h')
        ui->Alarm1_4->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (gran_al == 'l')
        ui->Alarm1_4->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");

    ui->L_GRAN->setText(gran);
    ui->L_GRAN->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_lym2_al(QString &buffer, int idx)
{
    // qDebug() << "I'm LYM2! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        lym2 += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            lym2 += ",";
        }
        idx++;
        flag++;
    }

    lym2_al = buffer[idx];
    if (lym2_al == 'h')
        ui->Alarm1_4->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (lym2_al == 'l')
        ui->Alarm1_4->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_LYM_2->setText(lym2);
    ui->L_LYM_2->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_mon2_al(QString &buffer, int idx)
{
    //  qDebug() << "I'm MON2! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mon2 += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            mon2 += ",";
                    }
        idx++;
        flag++;
    }

    mon2_al = buffer[idx];
    if (mon2_al == 'h')
        ui->Alarm1_6->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mon2_al == 'l')
        ui->Alarm1_6->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MID_2->setText(mon2);
    ui->L_MID_2->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_gran2_al(QString &buffer, int idx)
{
    // qDebug() << "I'm GRAN2! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        gran2 += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            gran2 += ",";
                    }
        idx++;
        flag++;
    }

    gran2_al = buffer[idx];
    if (gran2_al == 'h')
        ui->Alarm1_7->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (gran2_al == 'l')
        ui->Alarm1_7->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_GRAN_2->setText(gran2);
    ui->L_GRAN_2->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_rbc_al(QString &buffer, int idx)
{
    //  qDebug() << "I'm RBC! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            rbc += ",";
            flag = 1;
        }
        rbc += buffer[idx];
        idx++;
        flag++;
    }

    rbc_al = buffer[idx];
    if (rbc_al == 'h')
        ui->Alarm1_8->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (rbc_al == 'l')
        ui->Alarm1_8->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_RBC->setText(rbc);
    ui->L_RBC->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_hgb_al(QString &buffer, int idx)
{
    // qDebug() << "I'm HGB! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        if ((flag == 2) && (buffer[idx] != '*'))
        {
            hgb += ",";
        }
        hgb += buffer[idx];
        idx++;
        flag++;
    }

    hgb_al = buffer[idx];
    if (hgb_al == 'h')
        ui->Alarm1_9->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (hgb_al == 'l')
        ui->Alarm1_9->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_HGB->setText(hgb);
    ui->L_HGB->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_hct_al(QString &buffer, int idx)
{
    // qDebug() << "I'm HCT! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        hct += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
        {
            hct += ",";
        }
        idx++;
        flag++;
    }

    hct_al = buffer[idx];
    if (hct_al == 'h')
        ui->Alarm1_10->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (hct_al == 'l')
        ui->Alarm1_10->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_HCT->setText(hct);
    ui->L_HCT->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_mcv_al(QString &buffer, int idx)
{
    // qDebug() << "I'm MCV! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mcv += buffer[idx];
        if ((flag == 2) && (buffer[idx] != '*'))
            mcv += ",";
        idx++;
        flag++;
    }

    mcv_al = buffer[idx];
    if (mcv_al == 'h')
        ui->Alarm1_11->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mcv_al == 'l')
        ui->Alarm1_11->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MCV->setText(mcv);
    ui->L_MCV->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_mch_al(QString &buffer, int idx)
{
    // qDebug() << "I'm MCH! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mch += buffer[idx];
        if ((flag == 2) && (buffer[idx] != '*'))
            mch += ",";
        idx++;
        flag++;
    }

    mch_al = buffer[idx];
    if (mch_al == 'h')
        ui->Alarm1_12->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mch_al == 'l')
        ui->Alarm1_12->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MCH->setText(mch);
    ui->L_MCH->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_mchc_al(QString &buffer, int idx)
{
    //qDebug() << "I'm MCHC! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mchc += buffer[idx];
        if ((flag == 2) && (buffer[idx] != '*'))
            mchc += ",";
        idx++;
        flag++;
    }
    mchc_al = buffer[idx];
    if (mchc_al == 'h')
        ui->Alarm1_13->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mchc_al == 'l')
        ui->Alarm1_13->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MCHC->setText(mchc);
    ui->L_MCHC->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_rdw_sd_al(QString &buffer, int idx)
{
    //qDebug() << "I'm RDW SD! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        rdw_sd += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
            rdw_sd += ",";
        idx++;
        flag++;
    }

    rdw_sd_al = buffer[idx];
    if (rdw_sd_al == 'h')
        ui->Alarm1_14->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (rdw_sd_al == 'l')
        ui->Alarm1_14->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_RDW_SD->setText(rdw_sd);
    ui->L_RDW_SD->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_rdw_cv_al(QString &buffer, int idx)
{
    // qDebug() << "I'm RDW CV! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        rdw_cv += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
            rdw_cv += ",";
        idx++;
        flag++;
    }

    rdw_cv_al = buffer[idx];
    if (rdw_cv_al == 'h')
        ui->Alarm1_15->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (rdw_cv_al == 'l')
        ui->Alarm1_15->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_RDW_CV->setText(rdw_cv);
    ui->L_RDW_CV->setReadOnly(true);
    return (idx + 1);
}


int             MainWindow::set_plt(QString &buffer, int idx)
{
    // qDebug() << "I'm PLT! ";
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        plt += buffer[idx];
        idx++;
    }

    plt_al = buffer[idx];
    if (plt_al == 'h')
        ui->Alarm1_16->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (plt_al == 'l')
        ui->Alarm1_16->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_PLT->setText(plt);
    ui->L_PLT->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_mpv(QString &buffer, int idx)
{
    // qDebug() << "I'm MPV! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        mpv += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
            mpv += ",";
        idx++;
        flag++;
    }
    mpv_al = buffer[idx];
    if (mpv_al == 'h')
        ui->Alarm1_17->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (mpv_al == 'l')
        ui->Alarm1_17->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_MPV->setText(mpv);
    ui->L_MPV->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_pdw(QString &buffer, int idx)
{
    // qDebug() << "I'm PDW! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        pdw += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
            pdw += ",";
        idx++;
        flag++;
    }

    pdw_al = buffer[idx];
    if (pdw_al == 'h')
        ui->Alarm1_18->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (pdw_al == 'l')
        ui->Alarm1_18->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_PDW->setText(pdw);
    ui->L_PDW->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_pct(QString &buffer, int idx)
{
    // qDebug() << "I'm PCT! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        if ((flag == 2) && (buffer[idx] != '*'))
            pct += ",";
        pct += buffer[idx];
        idx++;
        flag++;
    }
    pct_al = buffer[idx];
    if (pct_al == 'h')
        ui->Alarm1_19->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (pct_al == 'l')
        ui->Alarm1_19->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_PCT->setText(pct);
    ui->L_PCT->setReadOnly(true);
    return (idx + 1);
}

int             MainWindow::set_plcr(QString &buffer, int idx)
{
    //qDebug() << "I'm P-LCR! ";
    int flag = 0;
    while ((buffer[idx] != '#') && (buffer[idx] != 'l') && (buffer[idx] != 'h'))
    {
        plcr += buffer[idx];
        if ((flag == 1) && (buffer[idx] != '*'))
            plcr += ",";
        idx++;
        flag++;
    }
    plcr_al = buffer[idx];
    if (plcr_al == 'h')
        ui->Alarm1_20->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else if (plcr_al == 'l')
        ui->Alarm1_20->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-3921-32.png);");
    ui->L_P_LCR->setText(plcr);
    ui->L_P_LCR->setReadOnly(true);
    return (idx + 1);
}

int            MainWindow::set_pb_tech(QString &buffer, int idx)
{
    // qDebug() << "I'm Pb technique!\n";
    char c;
    if ((c = buffer[idx++] == 't'))
        ui->Alarm1_21->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_21->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'b'))
        ui->Alarm1_22->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_22->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'c'))
        ui->Alarm1_23->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_23->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'b'))
        ui->Alarm1_24->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_24->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'c'))
        ui->Alarm1_25->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_25->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    return (idx);
}

int             MainWindow::set_pb_patient(QString &buffer, int idx)
{
    char c;
    // qDebug() << "I'm Pb patient!\n";
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_26->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_26->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_27->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_27->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_28->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_28->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_29->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_29->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_30->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_30->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    if ((c = buffer[idx++] == 'r'))
        ui->Alarm1_31->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-4713-32.png);");
    else
        ui->Alarm1_31->setStyleSheet("background-image: url(:/common/imgs/common/imgs/onebit-icone-9483-32.png);");
    return (idx);
}

boolean         MainWindow::Parsing_h18(QString &buffer)
{
    qDebug() << PARSING;
    int idx = 0;
    set_sample(buffer);
    set_date(buffer);
    set_time(buffer);
    idx = set_wbc_al(buffer);
    idx = set_lym_al(buffer, idx);
    idx = set_mon_al(buffer, idx);
    idx = set_gran_al(buffer, idx);
    idx = set_lym2_al(buffer, idx);
    idx = set_mon2_al(buffer, idx);
    idx = set_gran2_al(buffer, idx);
    idx = set_rbc_al(buffer, idx);
    idx = set_hgb_al(buffer, idx);
    idx = set_hct_al(buffer, idx);
    idx = set_mcv_al(buffer, idx);
    idx = set_mch_al(buffer, idx);
    idx = set_mchc_al(buffer, idx);
    idx = set_rdw_sd_al(buffer, idx);
    idx = set_rdw_cv_al(buffer, idx);
    idx = set_plt(buffer, idx);
    idx = set_mpv(buffer, idx);
    idx = set_pdw(buffer, idx);
    idx = set_pct(buffer, idx);
    idx = set_plcr(buffer, idx);
    idx = set_pb_tech(buffer, idx + 8);
    idx = set_pb_patient(buffer, idx + 8);
    ui->progressBar->setValue(70);
    return true;
}

void        MainWindow::init_vars()
{
    portName.clear();
    pars.clear();
    sample.clear();
    date.clear();
    time.clear();
    wbc.clear();
    lym.clear();
    mon.clear();
    gran.clear();
    lym2.clear();
    mon2.clear();
    gran2.clear();
    rbc.clear();
    hgb.clear();
    hct.clear();
    mcv.clear();
    mch.clear();
    mchc.clear();
    rdw_sd.clear();
    rdw_cv.clear();
    plt.clear();
    mpv.clear();
    pdw.clear();
    pct.clear();
    plcr.clear();
    wbc_al = '\0';
    lym_al = '\0';
    mon_al = '\0';
    gran_al = '\0';
    lym2_al = '\0';
    mon2_al = '\0';
    gran2_al = '\0';
    rbc_al = '\0';
    hgb_al = '\0';
    hct_al = '\0';
    mcv_al = '\0';
    mch_al = '\0';
    mchc_al = '\0';
    rdw_sd_al = '\0';
    rdw_cv_al = '\0';
    plt_al = '\0';
    mpv_al = '\0';
    pdw_al = '\0';
    pct_al = '\0';
    plcr_al = '\0';
    ui->Alarm1->setStyleSheet("");
    ui->Alarm1_10->setStyleSheet("");
    ui->Alarm1_11->setStyleSheet("");
    ui->Alarm1_12->setStyleSheet("");
    ui->Alarm1_13->setStyleSheet("");
    ui->Alarm1_14->setStyleSheet("");
    ui->Alarm1_15->setStyleSheet("");
    ui->Alarm1_16->setStyleSheet("");
    ui->Alarm1_17->setStyleSheet("");
    ui->Alarm1_18->setStyleSheet("");
    ui->Alarm1_19->setStyleSheet("");
    ui->Alarm1_2->setStyleSheet("");
    ui->Alarm1_20->setStyleSheet("");
    ui->Alarm1_21->setStyleSheet("");
    ui->Alarm1_22->setStyleSheet("");
    ui->Alarm1_23->setStyleSheet("");
    ui->Alarm1_24->setStyleSheet("");
    ui->Alarm1_25->setStyleSheet("");
    ui->Alarm1_26->setStyleSheet("");
    ui->Alarm1_27->setStyleSheet("");
    ui->Alarm1_28->setStyleSheet("");
    ui->Alarm1_29->setStyleSheet("");
    ui->Alarm1_3->setStyleSheet("");
    ui->Alarm1_30->setStyleSheet("");
    ui->Alarm1_31->setStyleSheet("");
    ui->Alarm1_4->setStyleSheet("");
    ui->Alarm1_5->setStyleSheet("");
    ui->Alarm1_6->setStyleSheet("");
    ui->Alarm1_7->setStyleSheet("");
    ui->Alarm1_8->setStyleSheet("");
    ui->Alarm1_9->setStyleSheet("");
    ui->L_Sample->setText(sample);
    ui->L_Date->setText(date);
    ui->L_Time->setText(time);
    ui->L_WBC->setText(wbc);
    ui->L_LYM->setText(lym);
    ui->L_MID->setText(mon);
    ui->L_GRAN->setText(gran);
    ui->L_LYM_2->setText(lym2);
    ui->L_MID_2->setText(mon2);
    ui->L_GRAN_2->setText(gran2);
    ui->L_RBC->setText(rbc);
    ui->L_HGB->setText(hgb);
    ui->L_HCT->setText(hct);
    ui->L_MCV->setText(mcv);
    ui->L_MCH->setText(mch);
    ui->L_MCHC->setText(mchc);
    ui->L_RDW_SD->setText(rdw_sd);
    ui->L_RDW_CV->setText(rdw_cv);
    ui->L_PLT->setText(plt);
    ui->L_MPV->setText(mpv);
    ui->L_PDW->setText(pdw);
    ui->L_PCT->setText(pct);
    ui->L_P_LCR->setText(plcr);
}

void            MainWindow::SLOT_comm_port()
{
    init_vars();
    QString port_com = ui->L_PORT_COM->text();
    if (qstrncmp(port_com.toStdString().c_str(), "COM", 3) == 0){
        QextSerialPort *port = new QextSerialPort();
        port->setPortName(port_com);
        port->open(QIODevice::ReadOnly);
        port->setFlowControl(FLOW_OFF);
        port->setParity(PAR_NONE);
        port->setDataBits(DATA_8);
        port->setStopBits(STOP_1);
        port->setBaudRate(BAUD9600);
        pars.clear();
        if ((port->isOpen()) == true)
        {
            ui->progressBar->setValue(10);
            int idx = 0;
            qint64 lineLength = 0;
            while (1)
            {
                int numBytes = port->bytesAvailable();
                if (numBytes > 0)
                {
                    char buff[numBytes];
                    if ((lineLength = port->read(buff, numBytes)) == -1)
                        break;
                    buff[lineLength] = '\0';
                    pars += buff;
                    if (idx == 0)
                        idx = 1;
                }
                if ((numBytes == 0) && (idx == 1))
                {
                    qDebug() << pars;
                    if (Parsing_h18(pars) == true)
                    {
                        if (my_save() == true)
                        {
                            port->close();
                            ui->progressBar->setValue(100);
                            //QMessageBox::information(this, INFORMATION_BOX,"EXTRACTION COMPLETED.");
                        }
                        else
                        {
                            port->close();
                            QMessageBox::critical(this, CRITICAL_BOX,"Failed to save file.");
                        }
                    }
                    else
                    {
                        QMessageBox::critical(this, CRITICAL_BOX,PARSING_KO);
                        port->close();
                    }
                    break;
                }
            }
            port->close();
        }
        else
            QMessageBox::warning(this, WARNING_BOX,PORT_COM_USED);
    }
    else if (qstrncmp(port_com.toStdString().c_str(), "com", 3) == 0)
    {
        QMessageBox::warning(this, WARNING_BOX,PORT_COM_CASE);
    }
    else
        QMessageBox::warning(this, WARNING_BOX,PORT_COM_KO);
    ui->progressBar->setValue(100);
}

void        MainWindow::init_signaux()
{
    QObject::connect(ui->GO, SIGNAL(clicked()), this, SLOT(SLOT_comm_port()));
    ui->progressBar->setValue(0);
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_signaux();
    ui->frame_to_hide->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}
