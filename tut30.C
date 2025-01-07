void tut30()
{
    TH1F *hist = new TH1F("hist", "Histogram; x title; y title", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist", "Histogram; x title; y title", 100, -10, 10);


    hist->FillRandom("gaus");
    hist2->FillRandom("gaus");
    TH1F *hist3 = new TH1F();

    *hist3 = (*hist)/(*hist2);



    TCanvas *c1 = new TCanvas();

    hist3->Draw();
}