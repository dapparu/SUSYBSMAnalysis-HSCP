#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TChain.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "THStack.h"
#include "TProfile.h"
#include "TFitResult.h"
#include "TCanvas.h"
#include "TLine.h"
#include "TStyle.h"
#include "TEfficiency.h"
#include "TText.h"
#include "TLegend.h"
#include "TMath.h"
#include "Rtypes.h"
#include "TLatex.h"
#include "TMathText.h"

//#include "../interface/Builder.h"

using namespace std;

class Correction
{

    private: 
        TFile* file_;
        TTree* tree_;
        float p0_;
        float p1_;
        float p0err_;
        float p1err_;
        float chi2_;
        int Ndf_;
        float Chi2overNdf_;
        int label_;
        int nstrip_;
        int nstripsat254_;
        int nstripsat255_;
        int moduleGeom_;
        //TProfile* historec_;
        TH2F* histo_;
        TH1F* historec_;
        
        float p0[21][4][7][7];
        float p1[21][4][7][7];
        float chi2[21][4][7][7];

        int Rebin_;
        float Range_;

    public:
        Correction();
        Correction(TH2F &histo);
        Correction(TH2F &histo,int Rebin,float Range);
        ~Correction();
        float CalibCharge(int entry,float charge);
        void FillHisto(int label,int nstrip,int nstripsat254,int nstripsat255);//,int modulegeom,bool SameXtalk=false,bool SaturatedStrip=true);
        void SetFileAndTreeName(string file_name,string tree_name);
        void SetTree(TTree &tree);
        void SetBranch();
        void Write(int Label,int nstrip,int nstripsat254,int nstripsat255);
        void WriteFile();
        void ReadLayer();
        void ReadModulGeom();
        void FillProfile();
        void FitProfile();
        void SetHisto(TH2F &histo);
        float ChargeCorr(float charge,int Label,int nstrip,int nstripsat254,int nstripsat255);
        bool TestCorr(int Label,int nstrip,int nstripsat254,int nstripsat255);
        void SetRebin(int Rebin);
        void SetRange(float Range);

};