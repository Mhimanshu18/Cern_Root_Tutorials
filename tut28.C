void tut28()
{
    TCanvas *c1 = new TCanvas();
    
    TH1F *hist = new TH1F("hist", "Histogram", 100, -5, 5);

    gSystem->Unlink("tut28.gif");

    TRandom *r1 = new TRandom();

    for (int i = 0; i < 1e5; i++)
    {

        double val = r1->Gaus();
        hist->Fill(val);

        if(i%100 == 0)
            hist->Draw();
            hist->Fit("gaus");
            c1->Modified();
            c1->Update();
            c1->Print("tut28.gif+");
        //sleep(1);
    }
}