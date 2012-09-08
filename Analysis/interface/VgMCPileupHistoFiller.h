/**
 * \class VgMCPileupHistoFiller
 * 
 * \brief Fills MC-only pileup Vgamma histograms.
 * 
 * \author Jan Veverka, Caltech 
 * \date 08 September 2012
 */
#ifndef Vgamma_Analysis_VgMCPileupHistoFiller_h
#define Vgamma_Analysis_VgMCPileupHistoFiller_h

#include "Vgamma/Analysis/interface/VgHistoFillerBase.h"

//_____________________________________________________________________
namespace cit {
  
  class VgMCPileupHistoFiller : public VgHistoFillerBase {
  public:
    VgMCPileupHistoFiller(VgAnalyzerTree const& tree,
                        HistoCollection & histos,
                        const Int_t * numObjects = 0);
    ~VgMCPileupHistoFiller();
    void bookHistograms();
    void fillHistograms();
    void fillObjectWithIndex(UInt_t i);
  }; // class VgMCPileupHistoFiller
  
} // namespace cit

#endif // #ifndef Vgamma_Analysis_VgMCPileupHistoFiller_h