#include "./Analysis_Selections.h"


// init with the current (base) selections
SelectionAnalysis::SelectionAnalysis()
{
    NofEvents_              = 0;
    eta_                    = 2.1;
    Pt_                     = 55;
    dz_                     = 0.5;
    dxy_                    = 0.5;
    SigmaPtOverPt_          = 0.25;
    Chi2overDof_            = 5;
    NofPixelHits_           = 1;
    NofTrackHits_           = 7;
    FractionOfValidHits_    = 0.8;
    NofDeDxMeasurements_    = 5;
    DeDxStripShapeTest_     = true;
    TrackPtIsolation01_     = 50;
    TrackPtIsolation03_     = 50;
    TrackPtISolation05_     = 50;
    EcaloIsolation01_       = 0.3;
    EcaloIsolation03_       = 0.3;
    EcaloIsolation05_       = 0.3;

    load_NofEvents_              = 0;
    load_eta_                    = 0.;
    load_Pt_                     = 0.;
    load_dz_                     = 0.;
    load_dxy_                    = 0.;
    load_SigmaPtOverPt_          = 0.;
    load_Chi2overDof_            = 0.;
    load_NofPixelHits_           = 0;
    load_NofTrackHits_           = 0;
    load_FractionOfValidHits_    = 0.;
    load_NofDeDxMeasurements_    = 0;
    load_DeDxStripShapeTest_     = false;
    load_TrackPtIsolation01_     = 0.;
    load_TrackPtIsolation03_     = 0.;
    load_TrackPtISolation05_     = 0.;
    load_EcaloIsolation01_       = 0.;
    load_EcaloIsolation03_       = 0.;
    load_EcaloIsolation05_       = 0.;

    Test_   = false;
    AbsoluteEfficiency_ = 1.;

    vect_Variables = NULL;


}

//destructor
SelectionAnalysis::~SelectionAnalysis()
{
    NofEvents_              = 0;
    eta_                    = 0.;
    Pt_                     = 0.;
    dz_                     = 0.;
    dxy_                    = 0.;
    SigmaPtOverPt_          = 0.;
    Chi2overDof_            = 0.;
    NofPixelHits_           = 0;
    NofTrackHits_           = 0;
    FractionOfValidHits_    = 0.;
    NofDeDxMeasurements_    = 0;
    DeDxStripShapeTest_     = false;
    TrackPtIsolation01_     = 0.;
    TrackPtIsolation03_     = 0.;
    TrackPtISolation05_     = 0.;
    EcaloIsolation01_       = 0.;
    EcaloIsolation03_       = 0.;
    EcaloIsolation05_       = 0.;

    load_NofEvents_              = 0;
    load_eta_                    = 0.;
    load_Pt_                     = 0.;
    load_dz_                     = 0.;
    load_dxy_                    = 0.;
    load_SigmaPtOverPt_          = 0.;
    load_Chi2overDof_            = 0.;
    load_NofPixelHits_           = 0;
    load_NofTrackHits_           = 0;
    load_FractionOfValidHits_    = 0.;
    load_NofDeDxMeasurements_    = 0;
    load_DeDxStripShapeTest_     = false;
    load_TrackPtIsolation01_     = 0.;
    load_TrackPtIsolation03_     = 0.;
    load_TrackPtISolation05_     = 0.;
    load_EcaloIsolation01_       = 0.;
    load_EcaloIsolation03_       = 0.;
    load_EcaloIsolation05_       = 0.;

    Test_   = false;
    AbsoluteEfficiency_ = 1.;

    vect_Variables = NULL;


}

//init with other selections --> not really useful...
SelectionAnalysis::SelectionAnalysis(int NofEvents,double eta,double Pt,double dz,double dxy,double SigmaPtOverPt,double chi2overDof,int NofPixelHits,int NofTrackHits,double FractionOfValidHits,int NodDeDxMeasurements,bool DeDxStripShapeTest,double TrackPtIsolation01,double TrackPtIsolation03,double TrackPtIsolation05,double EcaloIsolation01,double EcaloIsolation03,double EcaloIsolation05)
{
    NofEvents_              = NofEvents;
    eta_                    = eta;
    Pt_                     = Pt;
    dz_                     = dz;
    dxy_                    = dxy;
    SigmaPtOverPt_          = SigmaPtOverPt;
    Chi2overDof_            = chi2overDof;
    NofPixelHits_           = NofPixelHits;
    NofTrackHits_           = NofTrackHits;
    FractionOfValidHits_    = FractionOfValidHits;
    NofDeDxMeasurements     = NodDeDxMeasurements;
    DeDxStripShapeTest_     = DeDxStripShapeTest;
    TrackPtIsolation01_     = TrackPtIsolation01;
    TrackPtIsolation03_     = TrackPtIsolation03;
    TrackPtISolation05_     = TrackPtIsoaltion05;
    EcaloIsolation01_       = EcaloIsolation01;
    EcaloIsolation03_       = EcaloIsolation03;
    EcaloIsolation05_       = EcaloISolation05;

    load_NofEvents_              = 0;
    load_eta_                    = 0.;
    load_Pt_                     = 0.;
    load_dz_                     = 0.;
    load_dxy_                    = 0.;
    load_SigmaPtOverPt_          = 0.;
    load_Chi2overDof_            = 0.;
    load_NofPixelHits_           = 0;
    load_NofTrackHits_           = 0;
    load_FractionOfValidHits_    = 0.;
    load_NofDeDxMeasurements_    = 0;
    load_DeDxStripShapeTest_     = false;
    load_TrackPtIsolation01_     = 0.;
    load_TrackPtIsolation03_     = 0.;
    load_TrackPtISolation05_     = 0.;
    load_EcaloIsolation01_       = 0.;
    load_EcaloIsolation03_       = 0.;
    load_EcaloIsolation05_       = 0.;

     Test_   = false;
    AbsoluteEfficiency_ = 1.;

    vect_Variables = NULL;
}

//mutators --> in order to change one selection and see the impact
void SelectionAnalysis::SetEta(double eta) {eta_    = eta;}
void SelectionAnalysis::SetPt(double Pt) {Pt_   = Pt;}
void SelectionAnalysis::Setdz(double dz) {dz_   = dz;}
void SelectionAnalysis::Setdxy(double dxy) {dxy_     dxy;}
void SelectionAnalysis::SetSigmaPtOverPt(double SigmaPtOverPt) {SigmaPtOverPt_  = SigmaPtOverPt;}
void SelectionAnalysis::SetChi2overDof(double Chi2overDof) {Chi2overDof_    = Chi2overDof;}
void SelectionAnalysis::SetNofPixelHits(int NofPixelHits) {NofPixelHits_    = NofPixelHits;}
void SelectionAnalysis::SetNofTrackHits(int NofTrackHits) {NofTrackHits_    = NofTrackHits;}
void SelectionAnalysis::SetFractionOfValidHits(double FractionOfValidHits) {FractionOfValidHits_    = FractionOfValidHits;}
void SelectionAnalysis::SetNofDeDxMeasurements(int NofDeDxMeasurements) {NofDeDxMeasurements_   = NofDeDxMeasurements;}
void SelectionAnalysis::SetDeDxStripShapeTest(bool DeDxStripShapeTest) {DeDxStripShapeTest_    = DeDxStripShapeTest;}
void SelectionAnalysis::SetTrackPtIsolation01(double TrackPtIsolation01) {TrackPtIsolation01_   = TrackPtIsolation01;}
void SelectionAnalysis::SetTrackPtIsolation03(double TrackPtIsolation01) {TrackPtIsolation03_   = TrackPtIsolation03;}
void SelectionAnalysis::SetTrackPtIsolation05(double TrackPtIsolation05) {TrackPtIsolation05_   = TrackPtIsolation05;}
void SelectionAnalysis::SetEcaloIsolation01(double EcaloIsolation01) {EcaloIsolation01_ = EcaloIsolation01;}
void SelectionAnalysis::SetEcaloIsolation03(double EcaloIsolation03) {EcaloIsolation03_ = EcaloIsolation03;}
void SelectionAnalysis::SetEcaloIsolation05(double EcaloIsolation05) {EcaloIsolation05_ = EcaloIsolation05;}


//accessors
double SelectionAnalysis::GetEta() {return eta_;}
double SelectionAnalysis::GetPt() {return Pt_;}
double SelectionAnalysis::Getdz() {return dz_;}
double SelectionAnalysis::Getdxy() {return dxy_;}
double SelectionAnalysis::GetSigmaPtOverPt() {return SigmaPtOverPt_;}
double SelectionAnalysis::GetChi2overDof() {return Chi2overDof_;}
int SelectionAnalysis::GetNofPixelHits() {return NofPixelHits_;}
int SelectionAnalysis::GetNofTrackHits() {return NofTrackHits_;}
double SelectionAnalysis::GetFractionOfValidHits() {return FractionOfValidHits_;}
int SelectionAnalysis::NofDeDxMeasurements() {return NofDeDxMeasurements_;}
bool SelectionAnalysis::GetDeDxStripShapeTest() {return DeDxStripShapeTest_;}
double SelectionAnalysis::GetTrackPtIsolation01() {return TrackPtIsolation01_;}
double SelectionAnalysis::GetTrackPtIsolation03() {return TrackPtIsolation03_;}
double SelectionAnalysis::GetTrackPtIsolation05() {return TrackPtIsolation05_;}
double SelectionAnalysis::GetEcaloIsolation01() {return EcaloIsolation01_;}
double SelectionAnalysis::GetEcaloIsolation03() {return EcaloIsolation03_;}
double SelectionAnalysis::GetEcaloIsolation05() {return EcaloIsolation05_;}


//test -- pass selections
bool SelectionAnalysis::isPassEta() {load_eta_<eta_ ? return true : return false;}
bool SelectionAnalysis::isPassPt() {load_Pt_<Pt_ ? return true : return false;}
bool SelectionAnalysis::isPassdz() {load_dz_<dz_ ? return true : return false;}
bool SelectionAnalysis::isPassdxy() {load_dxy_<dxy_ ? return true : return false;}
bool SelectionAnalysis::isPassSigmaPtOverPt() {load_SigmaPtOverPt_<SigmaPtOverPt_ ? return true : return false;}
bool SelectionAnalysis::isPassChi2overDof() {load_Chi2overDof_<Chi2overDof_ ? return true : return false;}
bool SelectionAnalysis::isPassNofPixelHits() {load_NofPixeHits_>NofPixelHits_ ? return true : return false;}
bool SelectionAnalysis::isPassNofTrackHits() {load_NofTrackHits_>NofTrackHits_ ? return true : return false;}
bool SelectionAnalysis::isPassFractionOfValidHits() {load_FractionOfValidHits_>FractionOfValidHits_ ? return true : return false;}
bool SelectionAnalysis::isPassNofDeDxMeasurements() {load_NofDeDxMeasurements_>NofDeDxMeasurements_ ? return true : return false;}
bool SelectionAnalysis::isPassDeDxStripShapeTest() {load_DeDxStripShapeTest_==DeDxStripShapeTest_ ? return true : return false;}
bool SelectionAnalysis::isPassTrackPtIsolation01() {load_TrackPtIsolation01_<TrackPtIsolation01_ ? return true : return false;}
bool SelectionAnalysis::isPassTrackPtIsolation03() {load_TrackPtIsolation03_<TrackPtIsolation03_ ? return true : return false;}
bool SelectionAnalysis::isPassTrackPtIsolation05() {load_TrackPtIsolation05_<TrackPtIsolation05_ ? return true : return false;}
bool SelectionAnalysis::isPassEcaloIsolation01() {load_EcaloIsolation01_<EcaloIsolation01_ ? return true : return false;}
bool SelectionAnalysis::isPassEcaloIsolation03() {load_EcaloIsolation03_<EcaloIsolation03_ ? return true : return false;}
bool SelectionAnalysis::isPassEcaloIsolation05() {load_EcaloIsolation05_<EcaloIsolation05_ ? return true : return false;}




//useful methods

void SelectionAnalysis::Load(int load_NofEvents,double load_eta,double load_Pt,double load_dz,double load_dxy,double load_SigmaPtOverPt,double load_chi2overDof,int load_NofPixelHits,int load_NofTrackHits,double load_FractionOfValidHits,int load_NodDeDxMeasurements,bool load_DeDxStripShapeTest,double load_TrackPtIsolation01,double load_TrackPtIsolation03,double load_TrackPtIsolation05,double load_EcaloIsolation01,double load_EcaloIsolation03,double load_EcaloIsolation05)
{
    load_NofEvents_              = load_NofEvents;
    load_eta_                    = load_eta;
    load_Pt_                     = load_Pt;
    load_dz_                     = load_dz;
    load_dxy_                    = load_dxy;
    load_SigmaPtOverPt_          = load_SigmaPtOverPt;
    load_Chi2overDof_            = load_chi2overDof;
    load_NofPixelHits_           = load_NofPixelHits;
    load_NofTrackHits_           = load_NofTrackHits;
    load_FractionOfValidHits_    = load_FractionOfValidHits;
    load_NofDeDxMeasurements     = load_NodDeDxMeasurements;
    load_DeDxStripShapeTest_     = load_DeDxStripShapeTest;
    load_TrackPtIsolation01_     = load_TrackPtIsolation01;
    load_TrackPtIsolation03_     = load_TrackPtIsolation03;
    load_TrackPtISolation05_     = load_TrackPtIsoaltion05;
    load_EcaloIsolation01_       = load_EcaloIsolation01;
    load_EcaloIsolation03_       = load_EcaloIsolation03;
    load_EcaloIsolation05_       = load_EcaloISolation05;

}

void SelectionAnalysis::TotalTest()
{
    (isPassEta() && isPassPt() && isPassdz() && isPassdxy() && isPassSigmaPtOverPt() && isPassChi2overDof() && isPassNofPixelHits() && isPassNofTrackHits() && isPassFractionOfValidHits() && isPassNofDeDxMeasurements() && isPassDeDxStripShapeTest() && isPassTrackPtIsolation03() && isPassEcaloIsolation03()) ? Test_=true : Test_=false;
}

void SelectionAnalysis::FillHistograms()
{

}

void SelectionAnalysis::SaveHistograms()
{

}

void SelectionAnalysis::Display()
{

}

void SelectionAnalysis::Compute()
{
   if(Test_) NofPassingEvents_++;
   RelativeEfficiency = (double)NofEvents_/(double)NofPassingEvents_*AbsoluteEfficiency;
   AbsoluteEfficiency = (double)NofPassingEvents/(double)NofEvents_;

}

void SelectionAnalysis::SetBaseSelections()
{
    NofEvents_              = 0;
    eta_                    = 2.1;
    Pt_                     = 55;
    dz_                     = 0.5;
    dxy_                    = 0.5;
    SigmaPtOverPt_          = 0.25;
    Chi2overDof_            = 5;
    NofPixelHits_           = 1;
    NofTrackHits_           = 7;
    FractionOfValidHits_    = 0.8;
    NofDeDxMeasurements_    = 5;
    DeDxStripShapeTest_     = true;
    TrackPtIsolation01_     = 50;
    TrackPtIsolation03_     = 50;
    TrackPtISolation05_     = 50;
    EcaloIsolation01_       = 0.3;
    EcaloIsolation03_       = 0.3;
    EcaloIsolation05_       = 0.3;
}

void SelectionAnalysis::SetNoSelections()
{
    NofEvents_              = 0;
    eta_                    = 9999.;
    Pt_                     = 0.;
    dz_                     = 9999.;
    dxy_                    = 9999.;
    SigmaPtOverPt_          = 9999.;
    Chi2overDof_            = 9999.;
    NofPixelHits_           = -1;
    NofTrackHits_           = -1;
    FractionOfValidHits_    = 0.;
    NofDeDxMeasurements_    = -1;
    DeDxStripShapeTest_     = true;
    TrackPtIsolation01_     = 9999.;
    TrackPtIsolation03_     = 9999.;
    TrackPtISolation05_     = 9999.;
    EcaloIsolation01_       = 9999.;
    EcaloIsolation03_       = 9999.;
    EcaloIsolation05_       = 9999.;
}

void SelectionAnalysis::Configure(string config_file)
{
    std::ifstream ifile;
    ifile.open(config_file,std::ifstream::in);
    int indice=-1;
    string name="";
    string variable="";
    double threshold=0.;
    char test="";
    while(!ifile.eof())
    {
        ifile>>indice;
        ifile>>name;
        ifile>>variable;
        ifile>>threshold;
        ifile>>test;
        Variable var(indice,name,variable,threshold,test);
        vect_Variables.push_back(var);
    }
}
    Test_   = false;
    AbsoluteEfficiency_ = 1.;

    vect_Variables = NULL;


}

