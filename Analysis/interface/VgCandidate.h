/**
 * \brief Representation of a generic particle.
 * Holds the weigth and the momentum information so
 * that one can apply efficiency scale factors and
 * energy/momentum corrections.
 *
 * Jan Veverka, Caltech, 15 September 2012.
 */

#ifndef Vgamma_Analysis_VgCandidate_h
#define Vgamma_Analysis_VgCandidate_h

#include "TLorentzVector.h"

namespace cit {
  
  class VgCandidate {
  public:
    enum ParticleType {kElectron, kMuon, kPhoton, kCombined};
    // Ctor and dtor
    VgCandidate();
    VgCandidate(VgCandidate const &);
    virtual ~VgCandidate() {}
    // Accessors
    TLorentzVector const & momentum() const {return momentum_      ;}
    TLorentzVector const & p       () const {return momentum_      ;}
    ParticleType           type    () const {return type_          ;}
    double                 weight  () const {return weight_        ;}
    double                 pt      () const {return momentum_.Pt ();}
    double                 eta     () const {return momentum_.Eta();}
    double                 phi     () const {return momentum_.Phi();}
    double                 m       () const {return momentum_.M  ();}
    double                 y       () const {return momentum_.Rapidity();}
    double                 charge  () const {return charge_             ;}
    double                 q       () const {return charge_             ;}
    
    // Setters
    void setMomentum(TLorentzVector const& momentum) {momentum_ = momentum;}
    void setPt(double pt) {momentum_.SetPtEtaPhiM(pt, eta(), phi(), m());}
    void setType(ParticleType type) {type_ = type;}
    void setWeight(double weight) {weight_ = weight;}
    void setCharge(int charge) {charge_ = charge;}
    // Indirect setters
    void scaleWeight(double scaleFactor) {weight_ *= scaleFactor;}
    bool operator==(VgCandidate const & other) const;
    bool operator!=(VgCandidate const & other) const {return !operator==(other);}
  protected:
    TLorentzVector momentum_;
    ParticleType   type_    ;
    double         weight_  ;
    int            charge_  ;
  }; // class VgCandidate
} // namespace cit

#endif
