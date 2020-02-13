#ifndef Variable_h
#define Variable_h


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

using namespace std;

class Variable
{
    private :
        
        int indice_;
        string name_;
        double variable_;
        double threshold_;
        char test_;
        TH1D* plotNminus1_;
        string plot_name_;
        int plot_NofBins_;
        double plot_min_;
        double plot_max_;

        int NofParticlesPassingCut_;
    
    public :
        
        Variable();
        ~Variable();
        Variable(int indice,string name,double variable,char test,double threshold,string plot_name,int plot_NofBins,double plot_min,double plot_max);

        int GetIndice();
        string GetName();
        double GetVariable();
        double GetThreshold();
        char GetTest();
        string GetPlotName();
        int GetPlotNofBins();
        double GetPlotMin();
        double GetPlotMax();
        int GetNofParticlesPassingCut();
        TH1D* GetPlotNminus1();

        void SetIndice(int indice);
        void SetName(string name);
        void SetVariable(double variable);
        void SetThreshold(double threshold);
        void SetTest(char test);
        void SetPlotName(string plot_name);
        void SetPlotNofBins(int plot_NofBins);
        void SetPlotMin(double plot_min);
        void SetPlotMax(double plot_max);

        void IncreaseNofParticlesPassingCut();
        void CreateHistogram();
        void FillHistoNminus1(double value);
    
};


#endif
