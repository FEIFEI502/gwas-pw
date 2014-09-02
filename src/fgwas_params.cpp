/*
 * fgwas_params.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: pickrell
 */

#include "fgwas_params.h"
using namespace std;

Fgwas_params::Fgwas_params(){
	K = 5000;
	V = 0.1;
	print = false;
	zformat = true;
	wannot.clear();
	dannot.clear();
	distmodels.clear();
	segannot.clear();
	outstem = "fgwas";
	dropchr = false;
	cc = false;
	finemap = false;
	ridge_penalty = 0.2;
	xv = false;
	onlyp = false;
	cond = false;
	testcond_annot = "";
	pairwise = true;
	pheno1 = "NA";
	pheno2 = "NA";
	burnin = 10000;
	nsamp = 100000;
	overlap = false;
	sampfreq = 10;
	MCMC_gauss_SD = sqrt(1.0/5.0);
	//alpha_prop = 50.0;
	for (int i = 0; i < 5; i++) {
		alpha_prior.push_back(0);
	}
	cor = 0;
	Nhap = 0;
}

void Fgwas_params::print_stdout(){
	cout <<"\n\n";
	cout << ":::Parameter settings::::\n";
	cout << ":: Input file: "<< infile << "\n";
	cout << ":: Output stem: "<< outstem << "\n";
	cout << ":: K: " << K << "\n";
	cout << ":: V: " << V << "\n";
	//cout << ":: Ridge penalty: "<< ridge_penalty << "\n";
	//cout << ":: Case-control?: ";
	//if (cc) cout << "yes\n";
	//else cout << "no\n";
	cout << ":: Fine-mapping?: ";
	if (finemap) cout << "yes\n";
	else cout << "no\n";
	cout << ":: Print: ";
	if (print) cout << "yes\n";
	else cout <<"no\n";
	cout << ":: MCMC: ";
	if (MCMC) cout << "yes\n";
	else cout <<"no\n";
	//cout << ":: MCMC_"
	//cout << ":: Onlyp: ";
	//if (onlyp) cout << "yes\n";
	//else cout <<"no\n";
	//cout << ":: 10-fold cross-validation?: ";
	//if (xv) cout << "yes\n";
	//else cout << "no\n";
	//cout << ":: Pairwise?: ";
	//if (pairwise) cout << "yes\n";
	//else cout << "no\n";
	//cout << ":: Drop chromosome: ";
	//if (!dropchr) cout << "None\n";
	//else cout << chrtodrop <<"\n";

	cout << ":: SNP annotations:";
	for (vector<string>::iterator it = wannot.begin(); it != wannot.end(); it++) cout << " "<< *it; cout << "\n";
	cout << ":: Distance models:";
	for (int i = 0; i < dannot.size(); i++)	cout << " " << dannot[i]<< ":" << distmodels[i];  cout << "\n";
	cout << ":: Segment annotation (low quantile, high quantile):";
	for (vector<string>::iterator it = segannot.begin(); it != segannot.end(); it++) cout << " "<< *it<<  " ("<< loquant << " "<< hiquant << ")"; cout << "\n";
	//cout << ":: Conditional analysis of: " << testcond_annot << "\n";
	cout << ":::::::::::::::::::::::::\n";
	cout <<"\n\n";
}
