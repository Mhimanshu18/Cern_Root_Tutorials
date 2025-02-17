void tut11()
{
	TH1F *hist = new TH1F("hist", "",  100, 0 , 15);

    TRandom2 *rand  = new TRandom2(3);


	
	fstream file;
    file.open("data3.txt", ios::out);

    for (int i = 0; i < 1000; i++)
    {

        double r = rand->Gaus(5,1);
        file << r << endl;

    }
    file.close();
    
    file.open("data3.txt", ios::in);

    double value;

    while(1)
    {
        file>>value;
        hist->Fill(value);
        if(file.eof()) break;

    }

    file.close();

    hist-> SetFillColor(kGreen-8);
	hist-> GetXaxis()->SetTitle("Distribuition");
	hist-> GetYaxis()->SetTitle("Entries");

	hist-> GetXaxis()->SetTitleSize(0.05);
	hist-> GetYaxis()->SetTitleSize(0.05);
    hist-> GetXaxis()->SetLabelSize(0.05);
	hist-> GetYaxis()->SetLabelSize(0.05);

    TF1 *fit = new TF1("fit", "gaus", 0 , 15);

    fit->SetLineWidth(3);
    fit->SetLineColor(kPink);
    fit->SetLineStyle(2);

    fit->SetParameter(0,40);
    fit->SetParameter(1,5);
    fit->SetParameter(2,1);



	TCanvas *c1= new TCanvas();
    hist->SetStats(0);
    c1->SetTickx();
    c1->SetTicky();
    c1->SetGridx();
    c1->SetGridy();

	hist-> Draw();
    hist->Fit("fit", "R"); //R is Range Flag

    TLegend *leg = new TLegend(0.5, 0.6, 0.8, 0.8);
    leg->SetBorderSize(0);
    leg->AddEntry(hist, "Measured data", "f" );
    leg->AddEntry(fit, "Fit Function", "l" );
    leg->Draw();

    TLine *l = new TLine(0, 20, 15, 20);
    l->SetLineColor(kOrange);
    l->Draw();

    double x0 = 6.3;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);
    TArrow *arr = new TArrow(10, 30, x0, y0);
    arr-> SetLineColor(kBlue);
    arr-> SetLineWidth(2);
    arr-> SetArrowSize(0.02);
    arr-> Draw();
    TLatex *t = new TLatex(10, 30, "Important Point");
    t->Draw();

    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);

    cout << mean/sigma <<endl;


}