#include "Analysis_Variable.h"

Variable::Variable()
{
    indice_     = 0;
    name_       = "";
    variable_   = 0.;
    threshold_  = 0.;
    test_       = '=';
    plotNminus1_    = NULL;
    plot_name_  = "";
    plot_NofBins_   = 0;
    plot_min_   = 0.;
    plot_max_   = 1.;
    NofParticlesPassingCut_  = 0;
}

Variable::~Variable()
{
    indice_     = 0;
    name_       = "";
    variable_   = 0.;
    threshold_  = 0.;
    test_       = '=';
    plotNminus1_    = NULL;
    plot_name_  = "";
    plot_NofBins_   = 0;
    plot_min_   = 0.;
    plot_max_   = 1.;
    NofParticlesPassingCut_  = 0;
}

Variable::Variable(int indice,string name,double variable,char test,double threshold,string plot_name,int plot_NofBins,double plot_min,double plot_max)
{
    indice_     = indice;
    name_       = name;
    variable_   = variable;
    threshold_  = threshold;
    test_       = test;
    plotNminus1_    = NULL;
    plot_name_  = plot_name;
    plot_NofBins_   = plot_NofBins;
    plot_min_   = plot_min;
    plot_max_   = plot_max;
    NofParticlesPassingCut_  = 0;
}

int Variable::GetIndice() {return indice_;}
string Variable::GetName() {return name_;}
double Variable::GetVariable() {return variable_;}
double Variable::GetThreshold() {return threshold_;}
char Variable::GetTest() {return test_;}
string Variable::GetPlotName() {return plot_name_;}
int Variable::GetPlotNofBins() {return plot_NofBins_;}
double Variable::GetPlotMin() {return plot_min_;}
double Variable::GetPlotMax() {return plot_max_;}
int Variable::GetNofParticlesPassingCut() {return NofParticlesPassingCut_;}
TH1D* Variable::GetPlotNminus1() {return plotNminus1_;}

void Variable::SetIndice(int indice) {indice_=indice;}
void Variable::SetName(string name) {name_=name;}
void Variable::SetVariable(double variable) {variable_=variable;}
void Variable::SetThreshold(double threshold) {threshold_=threshold;}
void Variable::SetTest(char test) {test_=test;}
void Variable::SetPlotName(string plot_name) {plot_name_=plot_name;}
void Variable::SetPlotNofBins(int plot_NofBins) {plot_NofBins_=plot_NofBins;}
void Variable::SetPlotMin(double plot_min) {plot_min_=plot_min;}
void Variable::SetPlotMax(double plot_max) {plot_max_=plot_max;}

void Variable::IncreaseNofParticlesPassingCut() {NofParticlesPassingCut_++;}

void Variable::CreateHistogram()
{
    plotNminus1_ = new TH1D(plot_name_.c_str(),plot_name_.c_str(),plot_NofBins_,plot_min_,plot_max_);
}

void Variable::FillHistoNminus1(double value)
{
    plotNminus1_->Fill(value);
}
