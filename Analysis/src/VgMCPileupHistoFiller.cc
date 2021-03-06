/**
 * Implementation of the VgMCPileupHistoFiller class.
 * \author Jan Veverka, Caltech
 * \date 08 September 2012
 */

#include <iostream>
#include "TDirectory.h"
#include "TMath.h"
#include "Vgamma/Analysis/interface/VgMCPileupHistoFiller.h"

using namespace std;
using cit::VgMCPileupHistoFiller;

/**
 * Ctor.
 */
VgMCPileupHistoFiller::VgMCPileupHistoFiller() : VgHistoFillerBase()
{} // 


/**
 * Dtor.
 */
VgMCPileupHistoFiller::~VgMCPileupHistoFiller() {}


/**
 * Books the histograms.
 */
void
VgMCPileupHistoFiller::bookHistograms()
{
  TDirectory * cwd = gDirectory;
  if (cwd->GetDirectory("Pileup")) cwd->cd("Pileup");
  else cwd->mkdir("Pileup")->cd();

  histos_["nPU0"] = new TH1F(
    "nPU0", "Early OOT Pileup;True number of interactions;Events / 1", 
    101, -0.5, 100.5
  );
  
//   histos_["nPU1"] = new TH1F(
//     "nPU1", "In-Time Pileup;True number of interactions;Events / 1", 
//     101, -0.5, 100.5
//   );
//   
//   histos_["nPU2"] = new TH1F(
//     "nPU2", "Late OOT Pileup;True number of interactions;Events / 1", 
//     101, -0.5, 100.5
//   );
//   
//   histos_["nPU0v1"] = new TH2F(
//     "nPU0v1", 
//     "True number of interactions;Early OOT Pileup;In-Time Pileup;Events", 
//     31, -0.5, 61.5, 31, -0.5, 61.3
//   );
//   
//   histos_["nPU0v2"] = new TH2F(
//     "nPU0v2", 
//     "True number of interactions;Early OOT Pileup;Late OOT Pileup;Events",
//     31, -0.5, 61.5, 31, -0.5, 61.3
//   );
//   
//   histos_["nPU1v2"] = new TH2F(
//     "nPU1v2", 
//     "True number of interactions;In-Time Pileup;Late OOT Pileup;Events", 
//     31, -0.5, 61.5, 31, -0.5, 61.3
//   );
//   
//   histos_["nPV"] = new TH1F(
//     "nPV", "Reconstructed Primary Vertices;Number of Vertices;Events / 1", 
//     101, -0.5, 100.5
//   );

  cwd->cd();

} // VgMCPileupHistoFiller::bookHistograms(..)


/**
 * Fills the histograms.
 */
void
VgMCPileupHistoFiller::fillHistograms(cit::VgEvent const& event)
{
  cit::VgAnalyzerTree const & t = event.tree();
  double wgt = event.weight();
  histos_["nPU0"]->Fill(t.nPU[0], wgt); 
//   histos_["nPU1"]->Fill(t.nPU[1]);
//   histos_["nPU2"]->Fill(t.nPU[2]);
// 
//   histos_["nPU0v1"]->Fill(t.nPU[0], t.nPU[1]);
//   histos_["nPU0v2"]->Fill(t.nPU[0], t.nPU[2]);
//   histos_["nPU1v2"]->Fill(t.nPU[1], t.nPU[2]);
  // loopOverObjects();  
} // VgMCPileupHistoFiller::fillHistograms(..)
