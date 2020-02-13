#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>
#include <iterator>
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

#include "Analysis_Selec.h"

using namespace std;

template <typename T>

void ListMap(const T& map)
{
    for(auto& x:map) cout<<x.first<<":"<<x.second<<endl;
    cout<<endl;
}


int main()
{
    Selec sel;
    sel.Configure("config.txt");
    sel.LoadVariables();
    sel.Configure("config_CinematicVar.txt");
    sel.LoadCinematicVariables();
    map<string, double> mapOfValues;

    mapOfValues["pt"]=2.3;
    mapOfValues["eta"]=0.6;
    mapOfValues["dx"]=0.5;
    mapOfValues["StripShapeTest"]=0;
    sel.LoadValues(mapOfValues);

    mapOfValues["pt"]=124;
    mapOfValues["eta"]=1;
    mapOfValues["dx"]=0.5;
    mapOfValues["StripShapeTest"]=1;
    sel.LoadValues(mapOfValues);

    mapOfValues["pt"]=345;
    mapOfValues["eta"]=0.6;
    mapOfValues["dx"]=0.5;
    mapOfValues["StripShapeTest"]=0;
    sel.LoadValues(mapOfValues);

    mapOfValues["pt"]=67;
    mapOfValues["eta"]=3.4;
    mapOfValues["dx"]=0.5;
    mapOfValues["StripShapeTest"]=0;
    sel.LoadValues(mapOfValues);

    for(int i=0;i<sel.GetVectVar().size();i++)
    {
        Variable var = sel.GetVectVar()[i];
        cout<<var.GetName()<<" "<<var.GetNofParticlesPassingCut()<<endl;
    }
    
    sel.SaveHistograms("/eos/user/d/dapparu/thesis/hscp/SelectionAnalysis/results/res.root");




    return 0;
}
