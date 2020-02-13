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

class Selec
{
    private :
        string config_file;
        std::vector<Variable> vect_Var;
        std::vector<Variable> vect_CinematicVar;
        std::map<std::string,bool> mapOfBool;
        bool* tableOfBool;

        int NofParticlesPassingCut;
        int NofParticlesPassingNminus1;
        int NofParticlesPassingInOrderUpToCut;

    public : 
        Selec();
        ~Selec();
        Selec(string file_name);
        void Configure(string file_name);
        void LoadVariables();
        void LoadCinematicVariables();
        std::vector<Variable> GetVectVar();
        std::vector<Variable> GetVectCinematicVar();
        bool BoolNminus1(bool* tableOfBool,int sizeOfTable,int skip);
        void LoadValues(std::map<std::string,double> mapOfValues);
        bool isPass(double var,char test,double threshold);
        std::map<string,bool> GetMapOfBool();
        bool* GetTableOfBool();
        void SaveHistograms(string file_name);

};
