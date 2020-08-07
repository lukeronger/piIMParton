piIMParton v1.0
-- piIMParton = pion version of I'm Parton

1. Description
This package gives parton distribution functions (PDFs) of the pion
starting from low Q^2 ~ 0.15 GeV^2, which are based on the nonlinear
DGLAP evolution of the nonperturbative input deduced from a maximum
entropy method. Refs. Phys. Lett. B 800 (2020) 135066 [arXiv:1809.01549v5] 

2. Usage
The library consists of a C++ class named piIMParton (read ./piIMParton.h
and ./piIMParton.cpp for details). piIMParton has a method
piIMParton::getPDF(Iparton, X, Q2), which is suggested to be called
in users' programs. Iparton set as -4, -3, -2, -1, 0, 1, 2, 3, 4
corresponds to getting cbar, sbar, dbar, ubar, gluon, u, d, s, c
quark/gluon number density distributions respectively.
(So far, we let the charm quark distribution of pion to be zero!)
The other important method of piIMParton is setDataSet(int).
setDataSet(1) corresponds to use the data set A, and setDataSet(2)
corresponds to use the data set B. (Set B is the default and is suggested.
Look for more details in the reference.)

We also provide methods getXUV(X, Q2), getXDV(X, Q2), getXUSea(X, Q2),
getXDSea(X, Q2), getXSSea(X, Q2), getXCSea(X, Q2) and getXGluon(X, Q2)
to get the up valence quark, down valence quark, up sea quark,
down sea quark, strange sea quark, charm sea quark and gluon distribution
functions respectively. It should be noted that the returned values
are the distributions multiplied by x, for these methods.
(up valence quark = x(u - ubar)
down valence quark = x(d - dbar)
up sea quark = x*2*ubar
down sea quark = x*2*dbar
strange sea quark = x*2*sbar
charm sea quark = x*2*cbar)

./testPiPDF.cpp gives an example to get parton density distributions
of the pion meson. To run the example with ROOT,
>root testPiPDF.cpp

3. Questions
If you have detailed questions concerning these distributions,
or if you find problems/bugs using this package, direct inquires to
rwang@impcas.ac.cn, xchen@impcas.ac.cn, or chdhan@impcas.ac.cn.
