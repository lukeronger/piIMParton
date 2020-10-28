#include"piIMParton.h"

#include"piIMParton.cpp"


void testPiPDF(){
/*
 * We use the numbering scheme of Monte Carlo by particle data group.
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
 */

	//// using pion PDFs
	piIMParton pipdf;
	pipdf.setDataSet(211);

	TGraph *gxuv = new TGraph();
	TGraph *gxd = new TGraph();
	TGraph *gxdbar = new TGraph();
	TGraph *gxgluon = new TGraph();

	double step = (log(1)-log(1e-3)) / 400.0;
	for(int i=0; i<399; i++){
		double xpi = exp( log(1e-3) + i*step );
		///get xuv at Q2 = 10 GeV2.
		gxuv->SetPoint(i,  xpi,  xpi*(pipdf.getPDF(2, xpi, 10.0) - pipdf.getPDF(-2, xpi, 10.0)) );
		///get xu at Q2 = 10 GeV2.
		gxd->SetPoint(i,  xpi,  xpi*pipdf.getPDF(1, xpi, 10.0) );
		///get xubar at Q2 = 10 GeV2.
		gxdbar->SetPoint(i,  xpi,  xpi*pipdf.getPDF(-1, xpi, 10.0) );
		///get xgluon at Q2 = 10 GeV2.
		gxgluon->SetPoint(i,  xpi,  xpi*pipdf.getPDF(21, xpi, 10.0) );
	}

	/// plotting
	TCanvas *c = new TCanvas("c","c",800,600);
	c->Divide(2,2);
	c->cd(1);
	gxuv->Draw("a l");
	gxuv->SetTitle("xu_{V} of #pi^{+}");
	c->cd(2);
	gxd->Draw("a l");
	gxd->SetTitle("xd of #pi^{+}");
	c->cd(3);
	gxdbar->Draw("a l");
	gxdbar->SetTitle("x#bar{d} of #pi^{+}");
	c->cd(4);
	gxgluon->Draw("a l");
	gxgluon->SetTitle("xgluon of #pi^{+}");




	////
	//// using kaon PDFs
	piIMParton Kaonpdf;
	Kaonpdf.setDataSet(321);

	TGraph *gxuvKaon = new TGraph();
	TGraph *gxsbarKaon = new TGraph();
	TGraph *gxdbarKaon = new TGraph();
	TGraph *gxcharmKaon = new TGraph();

	step = (log(1)-log(1e-3)) / 400.0;
	for(int i=0; i<399; i++){
		double xpi = exp( log(1e-3) + i*step );
		///get xuv at Q2 = 10 GeV2.
		gxuvKaon->SetPoint(i,  xpi,  xpi*(Kaonpdf.getPDF(2, xpi, 10.0) - Kaonpdf.getPDF(-2, xpi, 10.0)) );
		///get xu at Q2 = 10 GeV2.
		gxsbarKaon->SetPoint(i,  xpi,  xpi*Kaonpdf.getPDF(-3, xpi, 10.0) );
		///get xubar at Q2 = 10 GeV2.
		gxdbarKaon->SetPoint(i,  xpi,  xpi*Kaonpdf.getPDF(-1, xpi, 10.0) );
		///get xgluon at Q2 = 10 GeV2.
		gxcharmKaon->SetPoint(i,  xpi,  xpi*Kaonpdf.getPDF(4, xpi, 10.0) );
	}

	/// plotting
	TCanvas *c2 = new TCanvas("c2","c2",800,600);
	c2->Divide(2,2);
	c2->cd(1);
	gxuvKaon->Draw("a l");
	gxuvKaon->SetTitle("xu_{V} of K^{+}");
	c2->cd(2);
	gxsbarKaon->Draw("a l");
	gxsbarKaon->SetTitle("x#bar{s} of K^{+}");
	c2->cd(3);
	gxdbarKaon->Draw("a l");
	gxdbarKaon->SetTitle("x#bar{d} of K^{+}");
	c2->cd(4);
	gxcharmKaon->Draw("a l");
	gxcharmKaon->SetTitle("xcharm of K^{+}");






}


