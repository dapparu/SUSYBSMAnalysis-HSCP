#include "../interface/Correction.h"

using namespace std;

Correction::Correction()
{
    p0_     = 0.;
    p1_     = 1.;
    p0err_  = 0.;
    p1err_  = 0.;
    chi2_   = 0.;
    Ndf_    = 0;
    Chi2overNdf_ = 1.;
    label_ = 0;
    nstrip_ = 0;
    nstripsat254_   = 0;
    nstripsat255_   = 0;
    moduleGeom_     = 0;
    Rebin_          = 5;
    Range_          = 1;
    for(int label=1;label<22;label++)
    {
        for(int size=3;size<7;size++)
        {
            for(int sat254=0;sat254<size+1;sat254++)
            {
                for(int sat255=0;sat255<size-sat254+1;sat255++)
                {
                    if(label_==label && nstrip_==size && nstripsat254_==sat254 && nstripsat255_==sat255)
                    {
                        p0[label-1][size-3][sat254][sat255]=0.;
                        p1[label-1][size-3][sat254][sat255]=1.;
                        chi2[label-1][size-3][sat254][sat255]=0.;
                    }
                }
            }
        }
    }
}

Correction::Correction(TH2F &histo)
{
    histo_ = &histo;
    p0_     = 0.;
    p1_     = 1.;
    p0err_  = 0.;
    p1err_  = 0.;
    chi2_   = 0.;
    Ndf_    = 0;
    Chi2overNdf_ = 1.;
    label_ = 0;
    nstrip_ = 0;
    nstripsat254_   = 0;
    nstripsat255_   = 0;
    moduleGeom_     = 0;
    Rebin_          = 5;
    Range_          = 1;
    for(int label=1;label<22;label++)
    {
        for(int size=3;size<7;size++)
        {
            for(int sat254=0;sat254<size+1;sat254++)
            {
                for(int sat255=0;sat255<size-sat254+1;sat255++)
                {
                    if(label_==label && nstrip_==size && nstripsat254_==sat254 && nstripsat255_==sat255)
                    {
                        p0[label-1][size-3][sat254][sat255]=0.;
                        p1[label-1][size-3][sat254][sat255]=1.;
                        chi2[label-1][size-3][sat254][sat255]=0.;
                    }
                }
            }
        }
    }
}

Correction::Correction(TH2F &histo,int Rebin,float Range)
{
    histo_ = &histo;
    p0_     = 0.;
    p1_     = 1.;
    p0err_  = 0.;
    p1err_  = 0.;
    chi2_   = 0.;
    Ndf_    = 0;
    Chi2overNdf_ = 1.;
    label_ = 0;
    nstrip_ = 0;
    nstripsat254_   = 0;
    nstripsat255_   = 0;
    moduleGeom_     = 0;
    Rebin_          = Rebin;
    Range_          = Range;
    for(int label=1;label<22;label++)
    {
        for(int size=3;size<7;size++)
        {
            for(int sat254=0;sat254<size+1;sat254++)
            {
                for(int sat255=0;sat255<size-sat254+1;sat255++)
                {
                    if(label_==label && nstrip_==size && nstripsat254_==sat254 && nstripsat255_==sat255)
                    {
                        p0[label-1][size-3][sat254][sat255]=0.;
                        p1[label-1][size-3][sat254][sat255]=1.;
                        chi2[label-1][size-3][sat254][sat255]=0.;
                    }
                }
            }
        }
    }
}

Correction::~Correction()
{

}

void Correction::SetHisto(TH2F &histo)
{
    histo_ = &histo;
    histo_->Write();
}

void Correction::FillHisto(int label,int nstrip,int nstripsat254,int nstripsat255)//,int modulegeom,bool SameXtalk,bool SaturatedStrip)
{
    float lowedgexu = histo_->GetXaxis()->GetBinCenter(histo_->GetNbinsX());
    float lowedgexd = histo_->GetXaxis()->GetBinCenter(0);
    float lowedgeyu = histo_->GetYaxis()->GetBinCenter(histo_->GetNbinsY());

    float integer=0.9;
    
    int integral = histo_->Integral();
    int countInt=0;
    float ratioIntegral=0.;
    TH2F* histo_clone = (TH2F*) histo_->Clone();
    histo_clone->Reset();
    int x_histo=0;
    int x_low=0;
    while(ratioIntegral<integer)
    {
        x_histo++;
        for(int y_histo=0;y_histo<histo_->GetNbinsY()+2;y_histo++)
        {
            countInt+=histo_->GetBinContent(x_histo,y_histo);
        }
        ratioIntegral=((float)countInt/(float)integral);
        if(ratioIntegral<0.1) x_low++;
    }
    x_low=0;
    for(int i=x_low;i<x_histo;i++)
    {
        float LowEdgeX = histo_->GetXaxis()->GetBinLowEdge(i);
        float WidthX = histo_->GetXaxis()->GetBinWidth(i);
        for(int j=0;j<histo_clone->GetNbinsY()+2;j++)
        {
            float LowEdgeY = histo_->GetXaxis()->GetBinLowEdge(j);
            float WidthY = histo_->GetXaxis()->GetBinWidth(j);
            if(LowEdgeX>LowEdgeY && LowEdgeX<lowedgexu && LowEdgeY<lowedgeyu) // je remplis que la partie sous la diagonale Erec=Eloss
            {
                histo_clone->SetBinContent(i,j,histo_->GetBinContent(i,j));
                histo_clone->SetBinError(i,j,histo_->GetBinError(i,j));
            }
        }
    }

    
    histo_ = histo_clone;
    string first_title = histo_clone->GetTitle();
    first_title+="_NoDiag";
    histo_->SetTitle(first_title.c_str());
    histo_->SetName(first_title.c_str());
    histo_->Write();
}



void Correction::FillProfile() //je recupere un profil de l'histo rempli au prealable
{
    int firstdiv = histo_->GetXaxis()->GetBinCenter(histo_->GetNbinsX())/2;
    int divider = histo_->GetXaxis()->GetBinCenter(histo_->GetNbinsX())/firstdiv;
    historec_ = new TH1F(histo_->GetTitle(),histo_->GetTitle(),histo_->GetNbinsX()/divider,0,histo_->GetXaxis()->GetBinCenter(histo_->GetNbinsX()));
    TH2F* histoclone = (TH2F*) histo_->Clone();
    histoclone->Reset();
    int binrec=0;

    for(int x=1;x<=histo_->GetNbinsX();x++)
    {
        for(int y=1;y<=histo_->GetNbinsY();y++)
        {
            if(histo_->GetBinContent(x,y)>0) histoclone->SetBinContent(x,y,histo_->GetBinContent(x,y));
        }
        if(x%divider==0)
        {
            binrec++;
            float mpv=1.;
            float sigma=0.;
            TH1F* projY = (TH1F*) histoclone->ProjectionY();
            if(projY->GetEntries()>10) 
            {
                int fitStatus = projY->Fit("gaus","QL","");
                TFitResultPtr func_fit = projY->Fit("gaus","QLS","");
                if(fitStatus==0) 
                {
                    mpv=func_fit->Parameter(1);
                    sigma=func_fit->Parameter(2);
                }
                if(mpv<projY->GetMean()+3*projY->GetStdDev() && mpv>projY->GetMean()-3*projY->GetStdDev())
                {
                    historec_->SetBinContent(binrec,mpv);
                    historec_->SetBinError(binrec,sigma/sqrt(projY->GetEntries()));
                }   
                projY->Write();
            }
            histoclone->Reset();
            delete projY;
        }
    }
    delete histoclone;
    delete histo_;
}

void Correction::SetFileAndTreeName(string file_name,string tree_name)
{
    file_ = new TFile(file_name.c_str(),"RECREATE");
    tree_ = new TTree(tree_name.c_str(),tree_name.c_str());
}

void Correction::SetTree(TTree &tree)
{
    tree_ = &tree;
}

void Correction::SetBranch() //j'enregistre les differentes infos d'interet 
{
    tree_->Branch("p0",&p0_,"p0/F");
    tree_->Branch("p1",&p1_,"p1/F");
    tree_->Branch("p0err",&p0err_,"p0err/F");
    tree_->Branch("p1err",&p1err_,"p1err/F");
    tree_->Branch("chi2",&chi2_,"chi2/F");
    tree_->Branch("ndf",&Ndf_,"ndf/I");
    tree_->Branch("chi2overndf",&Chi2overNdf_,"chi2overndf/F");
    tree_->Branch("label",&label_,"label/I");
    tree_->Branch("nstrip",&nstrip_,"nstrip/I");
//    tree_->Branch("histo","TH2F",&histo_,0,0);
//    tree_->Branch("profile","TProfile",&profile_,0,0);
    tree_->Branch("nstripsat254",&nstripsat254_,"nstripsat254/I");
    tree_->Branch("nstripsat255",&nstripsat255_,"nstripsat255/I");
    tree_->Branch("rebin",&Rebin_,"rebin/I");
    tree_->Branch("range",&Range_,"range/F");
}

void Correction::Write(int label,int nstrip,int nstripsat254,int nstripsat255)
{
    if(historec_->GetEntries()>=3 && (nstripsat254+nstripsat255>0)) //je ne recupere les resultats du fit que pour des profils avec plus de dix entrees et ou il y a eu saturation
    {    
        //TFitResultPtr FitRes_ = profile_->Fit("pol1","SQR","",profile_->GetBinContent(0),Range_*profile_->GetBinContent(profile_->GetNbinsX()));
        TFitResultPtr FitRes_ = historec_->Fit("pol1","SQ","");
        int fitStat = historec_->Fit("pol1","Q","");
        if(fitStat==0)
        {
            p0_     = FitRes_->Parameter(0);
            p1_     = FitRes_->Parameter(1);
            p0err_  = FitRes_->Error(0);
            p1err_  = FitRes_->Error(1);
            chi2_   = FitRes_->Chi2();
            Ndf_    = FitRes_->Ndf();
            Chi2overNdf_ = (float)chi2_/(float)Ndf_;
            float chicalc=0.;
            int nentries=0;
            for(int bin=0;bin<historec_->GetNbinsX();bin++)
            {
                if(historec_->GetBinContent(bin)>0)
                {
                    nentries++;
                    float valueCalc=(historec_->GetXaxis()->GetBinCenter(bin)*p1_+p0_);
                    chicalc+=pow(valueCalc-historec_->GetBinContent(bin),2);
                }
                
            }
            chicalc=(sqrt(chicalc)/nentries);
            chi2_=chicalc;
        }
    //    tree_->Branch("fitresult","TFitResultPtr",&FitRes_,0,0);
    }
    else //si il n'y a pas eu de saturation ou s'il n'y a pas assez d'entrees dans le profil, je parametrise tel qu'il n'y ait pas de changement 
    {
        p0_     = 0.;
        p1_     = 1.;
        p0err_  = 0.;
        p1err_  = 0.;
        chi2_   = 0.;
        Ndf_    = 0;
        Chi2overNdf_ = 0.;
    }
    label_ = label;
    nstrip_ = nstrip;
    nstripsat254_ = nstripsat254;
    nstripsat255_ = nstripsat255;
    tree_->Fill();
    string title = historec_->GetTitle();
    title+="_rec";
    historec_->SetTitle(title.c_str());
    historec_->SetName(title.c_str());
    historec_->Write();
    delete historec_;
}

void Correction::WriteFile()
{
    file_->Write();
    file_->Close();
}

void Correction::ReadLayer()
{
    tree_->SetBranchAddress("p0",&p0_);
    tree_->SetBranchAddress("p1",&p1_);
    tree_->SetBranchAddress("label",&label_);
    tree_->SetBranchAddress("nstrip",&nstrip_);
    tree_->SetBranchAddress("nstripsat254",&nstripsat254_);
    tree_->SetBranchAddress("nstripsat255",&nstripsat255_);
    tree_->SetBranchAddress("chi2overndf",&Chi2overNdf_);
    tree_->SetBranchAddress("rebin",&Rebin_);
    tree_->SetBranchAddress("range",&Range_);
    for(int i=0;i<tree_->GetEntries();i++) //on fait une recherche parmi toutes les categories (prend du temps --> a ameliorer)
    {
        tree_->GetEntry(i);
        for(int label=1;label<22;label++)
        {
            for(int size=3;size<7;size++)
            {
                for(int sat254=0;sat254<size+1;sat254++)
                {
                    for(int sat255=0;sat255<size-sat254+1;sat255++)
                    {
                        if(label_==label && nstrip_==size && nstripsat254_==sat254 && nstripsat255_==sat255)
                        {
                            p0[label-1][size-3][sat254][sat255]=p0_;
                            p1[label-1][size-3][sat254][sat255]=p1_;
                            chi2[label-1][size-3][sat254][sat255]=Chi2overNdf_;
                        }
                    }
                }
            }
        }
    }
    
}

void Correction::ReadModulGeom()
{
    tree_->SetBranchAddress("p0",&p0_);
    tree_->SetBranchAddress("p1",&p1_);
    tree_->SetBranchAddress("label",&label_);
    tree_->SetBranchAddress("nstrip",&nstrip_);
    tree_->SetBranchAddress("nstripsat254",&nstripsat254_);
    tree_->SetBranchAddress("nstripsat255",&nstripsat255_);
    tree_->SetBranchAddress("chi2overndf",&Chi2overNdf_);
    tree_->SetBranchAddress("rebin",&Rebin_);
    tree_->SetBranchAddress("range",&Range_);
    for(int i=0;i<tree_->GetEntries();i++) //on fait une recherche parmi toutes les categories (prend du temps --> a ameliorer)
    {
        tree_->GetEntry(i);
        for(int label=1;label<15;label++)
        {
            for(int size=3;size<7;size++)
            {
                for(int sat254=0;sat254<size+1;sat254++)
                {
                    for(int sat255=0;sat255<size-sat254+1;sat255++)
                    {
                        if(label_==label && nstrip_==size && nstripsat254_==sat254 && nstripsat255_==sat255)
                        {
                            p0[label-1][size-3][sat254][sat255]=p0_;
                            p1[label-1][size-3][sat254][sat255]=p1_;
                            chi2[label-1][size-3][sat254][sat255]=Chi2overNdf_;
                        }
                    }
                }
            }
        }
    }
    
}

float Correction::CalibCharge(int entry,float charge)
{
    if(entry==0) return charge;
    else
    { 
    tree_->SetBranchAddress("p0",&p0_);
    tree_->SetBranchAddress("p1",&p1_);
    tree_->GetEntry(entry);
    return -(p0_-charge)/p1_;
    }
    
}

float Correction::ChargeCorr(float charge,int label,int nstrip,int nstripsat254,int nstripsat255)
{   
    bool test=true;
    if(nstrip>=6) nstrip=6; //inclusif pour le nombre de strips du cluster 
    if(nstripsat254>=2 && nstripsat255==0) nstripsat254=2; //inclusif pour le nombre de strips saturees 
    if(nstripsat255>=2 && nstripsat254==0) nstripsat255=2;
    int nstripsat = nstripsat254+nstripsat255;

    if(label>=5 && nstripsat>=2) test=false;
    if(nstrip==3 && nstripsat>=2) test=false;
    if(label>=5 && label <=7 && nstripsat==1) 
    {
        if(nstrip>=5) nstrip=5;
    }
    float p0Calc=p0[label-1][nstrip-3][nstripsat254][nstripsat255];
    float p1Calc=p1[label-1][nstrip-3][nstripsat254][nstripsat255];
    float res=0;

    if(test) res=(charge-p0Calc)/p1Calc;
    return res;

}

bool Correction::TestCorr(int label,int nstrip,int nstripsat254,int nstripsat255)
{
    bool test=false;
    if((chi2[label-1][nstrip-3][nstripsat254][nstripsat255]>0 && chi2[label-1][nstrip-3][nstripsat254][nstripsat255]<=5 && p1[label-1][nstrip-3][nstripsat254][nstripsat255]>0.02)) test=true;
    return test;
}

/*float Correction::ChargeCorr(float charge,int label,int nstrip,int nstripsat254,int nstripsat255)
{
    float res=charge;
    tree_->SetBranchAddress("p0",&p0_);
    tree_->SetBranchAddress("p1",&p1_);
    tree_->SetBranchAddress("label",&label_);
    tree_->SetBranchAddress("nstrip",&nstrip_);
    tree_->SetBranchAddress("nstripsat254",&nstripsat254_);
    tree_->SetBranchAddress("nstripsat255",&nstripsat255_);
    tree_->SetBranchAddress("chi2overndf",&Chi2overNdf_);
    tree_->SetBranchAddress("rebin",&Rebin_);
    tree_->SetBranchAddress("range",&Range_);
    for(int i=0;i<tree_->GetEntries();i++) //on fait une recherche parmi toutes les categories (prend du temps --> a ameliorer)
    {
        tree_->GetEntry(i);
        if(nstrip>=6) nstrip=6; //inclusif pour le nombre de strips du cluster 
        if(nstripsat254>=2) nstripsat254=2; //inclusif pour le nombre de strips saturees 
        if(nstripsat255>=2) nstripsat255=2;
        if(label==label_ && nstrip==nstrip_ && nstripsat254==nstripsat254_ && nstripsat255==nstripsat255_ && p1_>0) //Chi2overNdf_<=) 
        {res=(charge-p0_)/p1_;} //ici on peut effectuer notre selection sur la qualite des ajustements effectuees
    }
    return res;
}*/

void Correction::SetRebin(int Rebin)
{
    Rebin_ = Rebin;
}

void Correction::SetRange(float Range)
{
    Range_ = Range;
}
