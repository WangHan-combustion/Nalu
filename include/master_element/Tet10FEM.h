/*------------------------------------------------------------------------*/
/*  Copyright 2014 Sandia Corporation.                                    */
/*  This software is released under the license detailed                  */
/*  in the file, LICENSE, which is located in the top-level Nalu          */
/*  directory structure                                                   */
/*------------------------------------------------------------------------*/


#ifndef Tet10FEM_h
#define Tet10FEM_h

#include<master_element/MasterElement.h>

namespace sierra{
namespace nalu{

// Tet 10 FEM
class Tet10FEM : public MasterElement
{
public:

  Tet10FEM();
  virtual ~Tet10FEM();
  
  // define the quadrature rule
  const bool fifteenPt_;
  
  // NGP-ready methods first
  void determinant_fem(
    SharedMemView<DoubleType**>&coords,
    SharedMemView<DoubleType***>&deriv,
    SharedMemView<DoubleType*>&det_j) final;

  void grad_op_fem(
    SharedMemView<DoubleType**>&coords,
    SharedMemView<DoubleType***>&gradop,
    SharedMemView<DoubleType***>&deriv,
    SharedMemView<DoubleType*>&det_j) final;

  void shifted_grad_op_fem(
    SharedMemView<DoubleType**>&coords,
    SharedMemView<DoubleType***>&gradop,
    SharedMemView<DoubleType***>&deriv,
    SharedMemView<DoubleType*>&det_j) final;

  void shape_fcn(
    SharedMemView<DoubleType**> &shpfc) final;

  void shifted_shape_fcn(
    SharedMemView<DoubleType**> &shpfc) final;

  // non-NGP  
  void shape_fcn(
    double *shpfc);

  void shifted_shape_fcn(
    double *shpfc);

  void general_shape_fcn(
    const int numIp,
    const double *isoParCoord,
    double *shpfc);

  void gij(
    const double *coords,
    double *gupperij,
    double *glowerij,
    double *deriv);

  double isInElement(
    const double *elemNodalCoord,
    const double *pointCoord,
    double *isoParCoord);

  void interpolatePoint(
    const int &ncomp_field,
    const double *isoParCoord,
    const double *field,
    double *result);

  void tet10_fem_shape_fcn(
    const int  &numIp,
    const double *isoParCoord,
    SharedMemView<DoubleType**> shpfc);

  void tet10_fem_shape_fcn(
    const int  &numIp,
    const double *isoParCoord,
    double *shpfc);

  void tet10_derivative(
    const int  &npts,
    const double *intgLoc, 
    double *deriv);

  double parametric_distance(
    const double *x);
};
    
} // namespace nalu
} // namespace Sierra

#endif
