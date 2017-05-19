#include "lorentz_vector.h"

#include <cmath>
using std::sqrt;

LorentzVector::LorentzVector (double x0, double x1, double x2, double x3)
    : x0_{x0}, x1_{x1}, x2_{x2}, x3_{x3} {}

LorentzVector::LorentzVector (const LorentzVector &v)
    : x0_{v.x0_}, x1_{v.x1_}, x2_{v.x2_}, x3_{v.x3_} {}

double LorentzVector::Mag2() const
{
    return x0_ * x0_ - x1_ * x1_ - x2_ * x2_ - x3_ * x3_;
}

double LorentzVector::Magnitude() const
{
    double mm = Mag2();
    return mm<0?-sqrt(-mm):sqrt(mm);
}

double LorentzVector::Dot(const LorentzVector &lv) const
{
    return x0_ * lv.x0_ - x1_ * lv.x1_ - x2_ * lv.x2_ - x3_ * lv.x3_;
}

LorentzVector LorentzVector::Boost(double x, double y, double z, double v) const {
  double gamma = 1 / sqrt(1 - v*v);
  double n2 = x*x + y*y + z*z;
  double nx = x / sqrt(n2);
  double ny = y / sqrt(n2);
  double nz = z / sqrt(n2);
  double r_dot_n = - x1_*nx - x2_*ny - x3_*nz;
  return {gamma*(x0_ + r_dot_n*v),
      x1_ - (gamma - 1)*r_dot_n*nx - gamma*x0_*v*nx,
      x2_ - (gamma - 1)*r_dot_n*ny - gamma*x0_*v*ny,
      x3_ - (gamma - 1)*r_dot_n*nz - gamma*x0_*v*nz};
}
    
LorentzVector LorentzVector::Boost(Vector3D vector_3d, double v) const {
  double gamma = 1 / sqrt(1 - v*v);
  double n2 = vector_3d.GetX()*vector_3d.GetX() +
    vector_3d.GetY()*vector_3d.GetY() +
    vector_3d.GetZ()*vector_3d.GetZ();
  double nx = vector_3d.GetX() / sqrt(n2);
  double ny = vector_3d.GetY() / sqrt(n2);
  double nz = vector_3d.GetZ() / sqrt(n2);
  double r_dot_n = - x1_*nx - x2_*ny - x3_*nz;
  return {gamma*(x0_ + r_dot_n*v),
      x1_ - (gamma - 1)*r_dot_n*nx - gamma*x0_*v*nx,
      x2_ - (gamma - 1)*r_dot_n*ny - gamma*x0_*v*ny,
      x3_ - (gamma - 1)*r_dot_n*nz - gamma*x0_*v*nz};

}

LorentzVector LorentzVector::operator*(double lambda) const
{
    return {lambda * x0_, lambda * x1_,
            lambda * x2_, lambda * x3_};
}

LorentzVector operator*(double lambda, const LorentzVector &lv)
{
    return lv * lambda;
}

LorentzVector LorentzVector::operator+(const LorentzVector &rhs) const
{
    return {x0_ + rhs.x0_, x1_ + rhs.x1_,
           x2_ + rhs.x2_, x3_ + rhs.x3_};
}

LorentzVector LorentzVector::operator-() const
{
    return {-x0_, -x1_, -x2_, -x3_};
}

LorentzVector LorentzVector::operator-(const LorentzVector & rhs) const
{
    return {x0_ - rhs.x0_, x1_ - rhs.x1_,
            x2_ - rhs.x2_, x3_ - rhs.x3_};
}

LorentzVector & LorentzVector::operator*= (double lambda)
{
    x0_ *= lambda;
    x1_ *= lambda;
    x2_ *= lambda;
    x3_ *= lambda;
    return *this;
}

LorentzVector & LorentzVector::operator+= (const LorentzVector & rhs)
{
    x0_ += rhs.x0_;
    x1_ += rhs.x1_;
    x2_ += rhs.x2_;
    x3_ += rhs.x3_;
    return *this;
}

LorentzVector & LorentzVector::operator-= (const LorentzVector & rhs)
{
    x0_ -= rhs.x0_;
    x1_ -= rhs.x1_;
    x2_ -= rhs.x2_;
    x3_ -= rhs.x3_;
    return *this;
}

bool LorentzVector::operator!= (const LorentzVector &rhs) const
{
    return !(*this == rhs);
}

bool LorentzVector::operator== (const LorentzVector &rhs) const
{
    return x0_ == rhs.x0_ && x1_ == rhs.x1_ && x2_ == rhs.x2_ && x3_ == rhs.x3_;
}
