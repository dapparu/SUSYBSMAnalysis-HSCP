#ifndef SelectionAnalysis_h
#define SelectionAnalysis_h






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

#include "Analysis_Variable.h"

using namespace std;

class SelectionAnalysis
{
    private : 
        int NofEvents_;
        double eta_;
        double Pt_;
        double dz_;
        double dxy_;
        double SigmaPtOverPt_; 
        double chi2overDof_;
        int NofPixelHits_;
        int NofTrackHits_;
        double FractionOfValidHits_;
        int NofDeDxMeasurements_;
        bool DeDxStripShapeTest_;
        double TrackPtIsolation01_;
        double TrackPtIsolation03_;
        double TrackPtIsolation05_;
        double EcaloIsolation01_;
        double EcaloIsolation03_;
        double EcaloIsolation05_;
        
        int load_NofEvents_;
        double load_eta_;
        double load_Pt_;
        double load_dz_;
        double load_dxy_;
        double load_SigmaPtOverPt_; 
        double load_chi2overDof_;
        int load_NofPixelHits_;
        int load_NofTrackHits_;
        double load_FractionOfValidHits_;
        int load_NofDeDxMeasurements_;
        bool load_DeDxStripShapeTest_;
        double load_TrackPtIsolation01_;
        double load_TrackPtIsolation03_;
        double load_TrackPtIsolation05_;
        double load_EcaloIsolation01_;
        double load_EcaloIsolation03_;
        double load_EcaloIsolation05_;

        bool Test_;
        int NofPassingEvents_;
        double AbsoluteEfficiency_;
        double RelativeEfficiency_;
        double AbsoluteUncertainty_;
        double RelativeUncertainty_;

        TH1D h_eta;
        TH1D h_Pt;
        TH1D h_dz;
        TH1D h_dxy;
        TH1D h_SigmaPtOverPt;
        TH1D h_Chi2overDof;
        TH1I h_NofPixelHits;
        TH1I h_NofTrackHits;
        TH1D h_FractionOfValidHits;
        TH1I h_NofDeDxMeasurements;
        TH1C h_DeDxStripShapeTest;
        TH1D h_TrackPtIsolation03;
        TH1D h_EcaloIsolation03;

        vector<Variable> vect_Variables;


    public :

        //constructor + destructor
        SelectionAnalysis();
        ~SelectionAnalysis();
        SelectionAnalysis(int NofEvents,double eta,double Pt,double dz,double dxy,double SigmaPtOverPt,double chi2overDof,int NofPixelHits,int NofTrackHits,double FractionOfValidHits,int NofDeDxMeasurements,bool DeDxStripShapeTest,double TrackPtIsolation01,double TrackPtIsolation03,double TrackPtIsolation05,double EcaloIsolation01,double EcaloIsolation03,double EcaloIsolation05);

        //accessors
        int NofEvents();
        double GetEta();
        double GetPt();
        double Getdz();
        double Getdxy();
        double GetSigmaPtOverPt();
        double GetChi2overDof();
        int GetNofPixelHits();
        int GetNofTrackHits();
        double GetFractionOfValidHits();
        int GetNofDeDxMeasurements();
        bool GetDeDxStripShapeTest();
        double GetTrackPtIsolation01();
        double GetTrackPtIsolation03();
        double GetTrackPtIsolation05();
        double GetEcaloIsolation01();
        double GetEcaloIsolation03();
        double GetEcaloIsolation05();

        //mutators
        void SetNofEvents(int NofEvents);
        void SetEta(double eta);
        void SetPt(double pt);
        void Setdz(double dz);
        void Setdxy(double dxy);
        void SetSigmaPtOverPt(double SigmaPtOverPt);
        void SetChi2overDof(double Chi2overDof);
        void SetNofPixelHits(int NofValidHits);
        void SetNofTrackHits(int NofTrackHits);
        void SetFractionOfValidHits(double FractionOfValidHits);
        void SetNofDeDxMeasurements(int NofDeDxMeasurements);
        void SetDeDxStripShapeTest(bool DeDxStripShapeTest);
        void SetTrackPtIsolation01(double TrackPtIsolation01);
        void SetTrackPtIsolation03(double TrackPtIsolation03);
        void SetTrackPtIsolation05(double TrackPtIsolation05);
        void SetEcaloIsolation01(double EcaloIsolationO1);
        void SetEcaloIsolation03(double EcaloIsolationO3);
        void SetEcaloIsolation05(double EcaloIsolationO5);

        //test -- pass selections
        bool isPassEta();
        bool isPassPt();
        bool isPassdz();
        bool isPassdxy();
        bool isPassSigmaPtOverPt();
        bool isPassChi2overDof();
        bool isPassNofPixelHits();
        bool isPassNofTrackHits();
        bool isPassFractionOfValidHits();
        bool isPassNofDeDxMeasurements();
        bool isPassDeDxStripShapeTest();
        bool isPassTrackPtIsolation01();
        bool isPassTrackPtIsolation03();
        bool isPassTrackPtIsolation05();
        bool isPassEcaloIsolation01();
        bool isPassEcaloIsolation03();
        bool isPassEcaloIsolation05();

        //useful methods
        void Load(int load_NofEvents,double load_eta,double load_Pt,double load_dz,double load_dxy,double load_SigmaPtOverPt,double load_chi2overDof,int load_NofPixelHits,int load_NofTrackHits,double load_FractionOfValidHits,int load_NodDeDxMeasurements,bool load_DeDxStripShapeTest,double load_TrackPtIsolation01,double load_TrackPtIsolation03,double load_TrackPtIsolation05,double load_EcaloIsolation01,double load_EcaloIsolation03,double load_EcaloIsolation05);
        void TotalTest();
        void FillHistograms();
        void SaveHistograms();
        void Display();
        void Compute();
        void SetNoSelections();
        void SetBaseSelections();

        //to use with "Variable" class
        void Configure(string config_file);

};


#endif
