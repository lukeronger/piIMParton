piIMParton v1.1
-- piIMParton = pion&kaon version of I'm Parton

1. Description
This package gives parton distribution functions (PDFs) of the pion and the kaon
starting from low Q^2 ~ 0.15 GeV^2, which are based on a global analysis of the
Drell-Yan data and the leading neutron deep inelastic scattering of e-p collision.
The nonlinear DGLAP equations and the nonperturbative input deduced from a maximum
entropy method are used in the global analysis. Refs.: arXiv:2010.14284,
and Phys. Lett. B 800 (2020) 135066 [arXiv:1809.01549v5] 

2. Usage
The library consists of a C++ class named piIMParton (read ./piIMParton.h and 
./piIMParton.cpp for details). piIMParton has a method piIMParton::getPDF(Iparton, X, Q2),
which is suggested to be called in the users' programs.
Iparton set as -4, -3, -2, -1, 1, 2, 3, 4, 21
corresponds to getting cbar, sbar, ubar, dbar, d, u, s, c, gluon
quark/gluon number density distributions respectively.
(So far, we let the charm quark distribution of the pion and the kaon to be zero!)
The other important method of piIMParton is setDataSet(int).
setDataSet(211) corresponds to use the data of the pion,
and setDataSet(321) corresponds to use the data of the kaon.

We use the numbering scheme of Monte Carlo by particle data group.
 * pion^+ --> 211
 * kaon^+ --> 321
 * d quark          -->  1
 * dbar (antiquark) --> -1
 * u quark          -->  2
 * ubar (antiquark) --> -2
 * s quark          -->  3
 * sbar (antiquark) --> -3
 * c quark          -->  4
 * cbar (antiquark) --> -4
 * gluon            --> 21

./testPiPDF.cpp gives an example to get parton momentum distributions
of the pion and the kaon. To run the example with ROOT,
>root testPiPDF.cpp

3. Questions
If you have detailed questions concerning these distributions,
or if you find problems/bugs using this package, direct inquires to
rwang@impcas.ac.cn, xchen@impcas.ac.cn, or chdhan@impcas.ac.cn.
