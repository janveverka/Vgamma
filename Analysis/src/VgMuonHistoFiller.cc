/**
 * Implementation of the VgMuonHistoFiller class.
 * \author Jan Veverka, Caltech
 * \date 08 September 2012
 */

#include <iostream>
#include "TMath.h"
#include "Vgamma/Analysis/interface/VgMuonHistoFiller.h"

using namespace std;
using cit::VgMuonHistoFiller;

/**
 * Ctor.
 */
VgMuonHistoFiller::VgMuonHistoFiller(VgAnalyzerTree const& tree,
                                     HistoCollection & histos) :
  VgHistoFillerBase(tree, histos)
{} // Default ctor.


/**
 * Dtor.
 */
VgMuonHistoFiller::~VgMuonHistoFiller() {}


/**
 * Books the histograms.
 */
void
VgMuonHistoFiller::bookHistograms()
{
  histos_["muN"] = new TH1F("muN", ";Muon Multiplicity;Events / 1", 
                            51, -0.5, 50.5);
  histos_["muPt"] = new TH1F("muPt", ";Muon P_{T} (GeV);Events / GeV", 
                             100, 0, 100.);
  histos_["muEta"] = new TH1F("muEta", ";Muon #eta;Events / 0.1", 
                              60, -3, 3);
  histos_["muPhi"] = new TH1F("muPhi", ";Muon #phi;Events / #frac{#pi}{50}", 
                              100, -TMath::Pi(), TMath::Pi());
} // VgMuonHistoFiller::bookHistograms(..)


/**
 * Fills the histograms.
 */
void
VgMuonHistoFiller::fillHistograms(cit::VgEvent const& event)
{
  cit::VgLeafCandidates const & muons = event.muons();
  histos_["muN"]->Fill(muons.size());
  /// Loop over muons
  for (cit::VgLeafCandidates::const_iterator mu = muons.begin();
       mu != muons.end(); ++mu) {
    fillCand(*mu);
  } /// Loop over muons  
} // VgMuonHistoFiller::fillHistograms(..)


/**
 * Fills the histograms for object with index i.
 */
void
VgMuonHistoFiller::fillCand(cit::VgLeafCandidate const & mu)
{
  // LeafCand const & mu = dynamic_cast<LeafCand const &>(cand);
  // unsigned i = mu.key();
  double wgt = mu.weight();
  histos_["muPt" ]->Fill(mu.pt (), wgt);
  histos_["muEta"]->Fill(mu.eta(), wgt);
  histos_["muPhi"]->Fill(mu.phi(), wgt);
} // VgMuonHistoFiller::fillObjectWithIndex(..)

